#include "VineCopulaCPP_header.hpp"

void PairCopulaAIC_Rotated_Obs(double *AIC, double *theta,int family, int rotation, double *U,double *V,unsigned int n)
{
    std::vector<double> bounds(120);
    LoadDefaultBounds(&bounds[0]);
    PairCopulaAIC_Rotated_Obs(&bounds[0],AIC,theta,family,rotation,U,V,n);
    
    return;
}

void PairCopulaAIC_Rotated_Obs(double *bounds,double *AIC, double *theta,int family, int rotation, double *U,double *V,unsigned int n)
{
    PairCopulaFit_Rotated_Obs(bounds,theta,family,rotation,U,V,n);
    
    double CLL = PairCopulaNegLL_Rotated_Obs(family,rotation,theta,U,V,n);
            
    switch(family){
        case 3: case 4: case 5: case 6: case 12: case 16: case 17: case 19:
        {
            //*AIC = 2*CLL+4;
            *AIC = 2*CLL+4+12/(n-3);
            break;
        }
        case 18:
        {
            //*AIC = 2*CLL+6;
            *AIC = 2*CLL+6+24/(n-4);
            break;
        }
        default:
        {
            //*AIC = 2*CLL+2;
            *AIC = 2*CLL+2+4/(n-2);
            break;
        }
    }
    
    return;
}

void PairCopulaAIC(double *AIC, double *theta,int family, int rotation, double *U,double *V,unsigned int n)
{
    std::vector<double> bounds(120);
    LoadDefaultBounds(&bounds[0]);
    PairCopulaAIC(&bounds[0],AIC,theta,family,rotation,U,V,n);
    
    return;
}

void PairCopulaAIC(double *bounds,double *AIC, double *theta,int family, int rotation, double *U,double *V,unsigned int n)
{
    PairCopulaFit(theta,family,rotation,U,V,n);
    
    double CLL = PairCopulaNegLL_Rotated_Obs(family,rotation,theta,U,V,n);
            
    switch(family){
        case 3: case 4: case 5: case 6: case 12: case 16: case 17: case 19:
        {
            //*AIC = 2*CLL+4;
            *AIC = 2*CLL+4+12/(n-3);
            break;
        }
        case 18:
        {
            //*AIC = 2*CLL+6;
            *AIC = 2*CLL+6+24/(n-4);
            break;
        }
        default:
        {
            //*AIC = 2*CLL+2;
            *AIC = 2*CLL+2+4/(n-2);
            break;
        }
    }
    
    return;
}

void PairCopulaAIC(double *AIC, double *theta,int family, double *U,double *V,unsigned int n)
{
    std::vector<double> bounds(120);
    LoadDefaultBounds(&bounds[0]);
    PairCopulaAIC(&bounds[0],AIC,theta,family,U,V,n);
    
    return;
}

void PairCopulaAIC(double *bounds, double *AIC, double *theta,int family, double *U,double *V,unsigned int n)
{
    PairCopulaFit(bounds,theta,family,U,V,n);
    
    double CLL = PairCopulaNegLL(family,theta,U,V,n);
            
    switch(family){
        case 3: case 4: case 5: case 6: case 12: case 16: case 17: case 19:
        {
            //*AIC = 2*CLL+4;
            *AIC = 2*CLL+4+12/(n-3);
            break;
        }
        case 18:
        {
            //*AIC = 2*CLL+6;
            *AIC = 2*CLL+6+24/(n-4);
            break;
        }
        default:
        {
            //*AIC = 2*CLL+2;
            *AIC = 2*CLL+2+4/(n-2);
            break;
        }
    }
    
    return;
}
