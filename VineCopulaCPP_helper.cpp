#include "VineCopulaCPP_header.hpp"

void Rotate_Obs(double *U,double *V, int rotation, unsigned int n)
{
    unsigned int i;
    
    switch(rotation){
        case 0:
        {
            break;
        }
        case 90:
        {
            for (i=0;i<n;i++) U[i]=1-U[i];
            break;
        }
        case 180:
        {
            for (i=0;i<n;i++)
            {
                U[i]=1-U[i];
                V[i]=1-V[i];
            }
            break;
        }
        case 270:
        {
            for (i=0;i<n;i++) V[i]=1-V[i];
            break;
        }
        default:
        {
            //mexErrMsgTxt( "Unknown rotation degree. Please choose either 0, 90, 180 or 270.");
        }
    }
}

void Rotate_Obs(double *U, double *V, double *U1, double *V1,int rotation, unsigned int n)
{
    unsigned int i;
    
    switch(rotation){
        case 0:
        {
            break;
        }
        case 90:
        {
            for (i=0;i<n;i++) 
            {
                U1[i]=1-U[i];
                V1[i] = V[i];
            }
            break;
        }
        case 180:
        {
            for (i=0;i<n;i++)
            {
                U1[i]=1-U[i];
                V1[i]=1-V[i];
            }
            break;
        }
        case 270:
        {
            for (i=0;i<n;i++)
            {
                U1[i] = U[i];
                V1[i]=1-V[i];
            }
            break;
        }
        default:
        {
            //mexErrMsgTxt( "Unknown rotation degree. Please choose either 0, 90, 180 or 270.");
        }
    }
}

void LoadDefaultBounds(double *bounds)
{ 
    int i=0;
    // Indep
    int j=0;
    bounds[j*6] = NAN; // lb1
    bounds[j*6+1] = NAN; // ub1
    bounds[j*6+2] = NAN; // lb2
    bounds[j*6+3] = NAN; // ub2
    bounds[j*6+4] = NAN; // lb3
    bounds[j*6+5] = NAN; // ub3
    // AMH
    j=1;
    bounds[j*6] = -1; // lb1
    bounds[j*6+1] = 1; // ub1
    for (i=2;i<6;i++)
    {
        bounds[j*6+i] = NAN;
    }
    // AsymFGM
    j=2;
    bounds[j*6] = 0; // lb1
    bounds[j*6+1] = 1; // ub1
    for (i=2;i<6;i++)
    {
        bounds[j*6+i] = NAN;
    }
    // BB1
    j=3;
    bounds[j*6] = 0; // lb1
    bounds[j*6+1] = 6; // ub1
    bounds[j*6+2] = 1; // lb2
    bounds[j*6+3] = 6; // ub2
    for (i=4;i<6;i++)
    {
        bounds[j*6+i] = NAN;
    }
    // BB6
    j=4;
    bounds[j*6] = 1; // lb1
    bounds[j*6+1] = 6; // ub1
    bounds[j*6+2] = 1; // lb2
    bounds[j*6+3] = 6; // ub2
    for (i=4;i<6;i++)
    {
        bounds[j*6+i] = NAN;
    }
    // BB7
    j=5;
    bounds[j*6] = 1; // lb1
    bounds[j*6+1] = 6; // ub1
    bounds[j*6+2] = 0.001; // lb2
    bounds[j*6+3] = 6; // ub2
    for (i=4;i<6;i++)
    {
        bounds[j*6+i] = NAN;
    }
    // BB8
    j=6;
    bounds[j*6] = 1; // lb1
    bounds[j*6+1] = 6; // ub1
    bounds[j*6+2] = 0.001; // lb2
    bounds[j*6+3] = 1; // ub2
    for (i=4;i<6;i++)
    {
        bounds[j*6+i] = NAN;
    }
    // Clayton
    j=7;
    bounds[j*6] = 0; // lb1
    bounds[j*6+1] = HUGE_VAL; // ub1
    for (i=2;i<6;i++)
    {
        bounds[j*6+i] = NAN;
    }
    // FGM
    j=8;
    bounds[j*6] = -1; // lb1
    bounds[j*6+1] = 1; // ub1
    for (i=2;i<6;i++)
    {
        bounds[j*6+i] = NAN;
    }
    // Frank
    j=9;
    bounds[j*6] = -30; // lb1
    bounds[j*6+1] = 30; // ub1
    for (i=2;i<6;i++)
    {
        bounds[j*6+i] = NAN;
    }
    // Gaussian
    j=10;
    bounds[j*6] = -0.999; // lb1
    bounds[j*6+1] = 0.999; // ub1
    for (i=2;i<6;i++)
    {
        bounds[j*6+i] = NAN;
    }
    // Gumbel
    j=11;
    bounds[j*6] = 1; // lb1
    bounds[j*6+1] = HUGE_VAL; // ub1
    for (i=2;i<6;i++)
    {
        bounds[j*6+i] = NAN;
    }
    // IteratedFGM
    j=12;
    bounds[j*6] = -1; // lb1
    bounds[j*6+1] = 1; // ub1
    bounds[j*6+2] = -1; // lb2
    bounds[j*6+3] = 1; // ub2
    for (i=4;i<6;i++)
    {
        bounds[j*6+i] = NAN;
    }
    // Joe
    j=13;
    bounds[j*6] = 1; // lb1
    bounds[j*6+1] = HUGE_VAL; // ub1
    for (i=2;i<6;i++)
    {
        bounds[j*6+i] = NAN;
    }
    // PartialFrank
    j=14;
    bounds[j*6] = 0; // lb1
    bounds[j*6+1] = 30; // ub1
    for (i=2;i<6;i++)
    {
        bounds[j*6+i] = NAN;
    }
    // Plackett
    j=15;
    bounds[j*6] = 0.001; // lb1
    bounds[j*6+1] = HUGE_VAL; // ub1
    for (i=2;i<6;i++)
    {
        bounds[j*6+i] = NAN;
    }
    // Tawn1
    j=16;
    bounds[j*6] = 1.001; // lb1
    bounds[j*6+1] = 20; // ub1
    bounds[j*6+2] = 0.001; // lb2
    bounds[j*6+3] = 0.999; // ub2
    for (i=4;i<6;i++)
    {
        bounds[j*6+i] = NAN;
    }
    // Tawn2
    j=17;
    bounds[j*6] = 1.001; // lb1
    bounds[j*6+1] = 20; // ub1
    bounds[j*6+2] = 0.001; // lb2
    bounds[j*6+3] = 0.999; // ub2
    for (i=4;i<6;i++)
    {
        bounds[j*6+i] = NAN;
    }
    // Tawn
    j=18;
    bounds[j*6] = 1.001; // lb1
    bounds[j*6+1] = 20; // ub1
    bounds[j*6+2] = 0.001; // lb2
    bounds[j*6+3] = 0.999; // ub2
    bounds[j*6+4] = 0.001; // lb3
    bounds[j*6+5] = 0.999; // ub3
    // t
    j=19;
    bounds[j*6] = -0.999; // lb1
    bounds[j*6+1] = 0.999; // ub1
    bounds[j*6+2] = 1; // lb2
    bounds[j*6+3] = 30; // ub2
    for (i=4;i<6;i++)
    {
        bounds[j*6+i] = NAN;
    }
    
    return;
}

/*void LogRand(double *X, double theta, unsigned int n)
{
    boost::mt19937 gen;
    // Load the state
    std::ifstream fi("Seed.dat");
    fi>>gen;
    fi.close();
    boost::uniform_01<boost::mt19937&> RAND(gen);
    
    double p,q,r,V,U;
    unsigned int i;
    
    p = -expm1(-theta);
    r = log(1-p);
    for (i=0;i<n;i++)
    {
        V=RAND();
        if (V<p)
        {
            U=RAND();
            q=-expm1(r*U);
            if (V<pow(q,2))
            {
                X[i] = floor(1+log(V)/log(q));
            }
            else
            {
                if (V<q)
                {
                    X[i]=2;
                }
            }
        }
        else
        {
            X[i] = 1;
        }
    }
    
    // Save the state
    std::ofstream fo("Seed.dat",
            std::ios_base::out);
    fo<<gen;
    fo.close();
}


void StableRand(double *X, double alpha, double beta, double gamma, double delta, unsigned int n)
{
    boost::mt19937 gen;
    // Load the state
    std::ifstream fi("Seed.dat");
    fi>>gen;
    fi.close();
    
    boost::uniform_01 <> URAND;
    boost::exponential_distribution <> ERAND(1);
    
    boost::variate_generator <boost::mt19937&, boost::uniform_01 <> > RAND(gen,URAND);
    boost::variate_generator <boost::mt19937&, boost::exponential_distribution <> > RAND1(gen,ERAND);
    

    double U,E,Z;
    unsigned int i;
    
    if (alpha != 1)
    {
        double B,S;
        B = atan(beta*tan(M_PI*alpha/2))/alpha;
        S = pow(1+pow(beta,2)*pow(tan(M_PI/2*alpha),2),(1/2/alpha));
        for (i=0;i<n;i++)
        {
            U = M_PI*(RAND()-0.5);
            E = RAND1();
            Z = S*(sin(alpha)*(U+B))/(pow(cos(U),(1/alpha)))*(pow(cos(U-alpha*(U+B))/E,((1-alpha)/alpha)));
            X[i] = gamma*Z+delta;
        }
    }
    else
    {
        for (i=0;i<n;i++)
        {
            U = M_PI*(RAND()-0.5);
            E = RAND1();
            Z = 2/M_PI*(M_PI/2+beta*U)*tan(U)-beta*log((M_PI/2*E*cos(U))/(M_PI/2+beta*U));
            X[i] = gamma*Z+delta+beta*2/M_PI*gamma*log(gamma);
        }
    }
    
    // Save the state
    std::ofstream fo("Seed.dat",
            std::ios_base::out);
    fo<<gen;
    fo.close();
}*/
