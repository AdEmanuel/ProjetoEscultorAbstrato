#include <iostream>
#include <cmath>

#include "cutellipsoid.h"

CutEllipsoid::CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    this->xcenter=xcenter;
    this->ycenter=ycenter;
    this->zcenter=zcenter;
    this->rx=rx;
    this->ry=ry;
    this->rz=rz;
}

CutEllipsoid::~CutEllipsoid(){
    std::cout << "Destrutor do CutEllipsoid \n";
}

void CutEllipsoid::draw(Sculptor &t){
    int i,j,k;

    //Variaveis para armazenarem os raios, assim, efetuando a transformação de int para double.
    double _rx=rx/2.0,_ry=ry/2.0,_rz=rz/2.0;
    // Variáveis que representam a distânica do centro do elipsóide para o Voxel.
    double dist;
    for(i=0;i<xcenter+rx;i++){
        for(j=0;j<ycenter+ry;j++){
            for(k=0;k<zcenter+rz;k++){
                //Equação do elipsóide.
                dist = (i-xcenter/2.0) * (i-xcenter/2.0) / (_rx*_rx) +
                (j-ycenter/2.0) * (j-ycenter/2.0) / (_ry*_ry) +
                (k-zcenter/2.0) * (k-zcenter/2.0) / (_rz*_rz);
            // Caso as condições sejam verdadeira, isso significa que a equação é respeitada e os valores são coerentes, portanto é habilitada a presença de um Voxel no local.
                if((dist<=1) && (i<xcenter+rx && i>=0) && (j<ycenter+ry && j>=0) && (k<zcenter+rz && k>=0)){
                    t.cutVoxel(i,j,k);
                }
            }
        }
    }
}

