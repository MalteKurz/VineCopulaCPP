#include "VineCopulaCPP_header.hpp"

void PairCopulaRand(int family, int rotation, const double *theta, double *U, double *V, unsigned int n)
{     
    // If the function is called without any seed, a random seed (using the current system time) is generated
    unsigned int i;
    boost::mt19937 gen;
    gen.seed(time(0));
    std::stringstream RNG_State;
    RNG_State << gen;
    
    std::vector<unsigned int> SeedState(624);
    double state;
    
    for (i=0;i<624;i++)
    {
        RNG_State >> state;
        SeedState[i] = (unsigned int) state;
    }
    
    PairCopulaRand(SeedState, family, rotation, theta, U, V, n);
    
    return;
}

void PairCopulaRand(int family, const double *theta, double *U, double *V, unsigned int n)
{
    // If the function is called without any seed, a random seed (using the current system time) is generated
    unsigned int i;
    boost::mt19937 gen;
    gen.seed(time(0));
    std::stringstream RNG_State;
    RNG_State << gen;
    
    std::vector<unsigned int> SeedState(624);
    double state;
    
    for (i=0;i<624;i++)
    {
        RNG_State >> state;
        SeedState[i] = (unsigned int) state;
    }
    
    PairCopulaRand(SeedState, family, theta, U, V, n);
    
    return;
}



void PairCopulaRand(std::vector<unsigned int>& SeedState, int family, int rotation, const double *theta, double *U, double *V, unsigned int n)
{
    unsigned int i;
    
    boost::mt19937 gen;
    // Load the state
    std::stringstream RNG_State_In;
    std::copy(SeedState.begin(), SeedState.end(), std::ostream_iterator<unsigned int>(RNG_State_In, " "));
    RNG_State_In>>gen;
    
    boost::uniform_01 <> URAND;
    
    boost::variate_generator <boost::mt19937&, boost::uniform_01 <> > RAND(gen,URAND);
    
    for (i=0;i<n;i++)
    {
        U[i] = RAND();
        V[i] = RAND();
    }
    
    // Save the state
    double state;
    std::stringstream RNG_State_Out;
    
    RNG_State_Out << gen;
    for (i=0;i<624;i++)
    {
        RNG_State_Out >> state;
        SeedState[i] =  (unsigned int) state;
    }
    
    switch(family){
        case 0:
        {
            // Indep
            break;
        }
        default:
        {
            // AMH, AsymFGM, BB6, BB7, Gaussian, Gumbel, IteratedFGM, Joe, Plackett, Tawn1, Tawn2, Tawn, t
            if(rotation>0)
            {
                std::vector<double> U1(n),V1(n);
                
                Rotate_Obs(U,V,&U1[0],&V1[0],rotation,n);
                PairCopulaInvHfun_Rotated_Obs(family, rotation, theta, &U1[0], &V1[0], U, n);
            }
            else
            {
                PairCopulaInvHfun(family, rotation, theta, U, V, U, n);
            }
            break;
        }
        
    }
    
    return;
    
}

void PairCopulaRand(std::vector<unsigned int>& SeedState, int family, const double *theta, double *U, double *V, unsigned int n)
{
    unsigned int i;
    
    boost::mt19937 gen;
    // Load the state
    std::stringstream RNG_State_In;
    std::copy(SeedState.begin(), SeedState.end(), std::ostream_iterator<unsigned int>(RNG_State_In, " "));
    RNG_State_In>>gen;
    
    boost::uniform_01 <> URAND;
    
    boost::variate_generator <boost::mt19937&, boost::uniform_01 <> > RAND(gen,URAND);
    
    for (i=0;i<n;i++)
    {
        U[i] = RAND();
        V[i] = RAND();
    }
    
    // Save the state
    double state;
    std::stringstream RNG_State_Out;
    
    RNG_State_Out << gen;
    for (i=0;i<624;i++)
    {
        RNG_State_Out >> state;
        SeedState[i] =  (unsigned int) state;
    }
    
    switch(family){
        case 0:
        {
            // Indep
            break;
        }
        default:
        {
            // AMH, AsymFGM, BB6, BB7, Gaussian, Gumbel, IteratedFGM, Joe, Plackett, Tawn1, Tawn2, Tawn, t
            PairCopulaInvHfun(family, theta, U, V, U, n);
            break;
        }
        
    }
    
    return;
    
}
