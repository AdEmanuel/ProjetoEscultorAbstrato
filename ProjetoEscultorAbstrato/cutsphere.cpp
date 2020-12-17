#include <iostream>
#include <cmath>

#include "cutsphere.h"

CutSphere::CutSphere(int xcenter, int ycenter, int zcenter, int radius){
    this->xcenter=xcenter;
    this->ycenter=ycenter;
    this->zcenter=zcenter;
    this->radius=radius;
}

CutSphere::~CutSphere(){
    std::cout<< "Destrutor do CutSphete \n";
}

void CutSphere::draw(Sculptor &t){
    int i,j,k;

    double rd=radius/2.0;
    //Variáveis que representam a distânica do centro da esfera para o Voxel.
    double dist;
    for(i=0; i<(2*xcenter); i++){
        for(j=0; j<(2*ycenter); j++){
            for(k=0; k<(2*zcenter); k++){
                //Equação da esfera.
                dist = (i-xcenter/2.0) * (i-xcenter/2.0 ) / (rd*rd) +
                       (j-ycenter/2.0) * (j-ycenter/2.0) / (rd*rd) +
                       (k-zcenter/2.0) * (k-zcenter/2.0 ) / (rd*rd);
               //Caso a distância seja menor que 1, isso significa que a equação é respeitada e os valores são coerentes, portanto é habilitada a presença de um Voxel no local.
                if(dist<=1.0){
                    t.cutVoxel(i,j,k);;
                }
            }
        }
    }
}

