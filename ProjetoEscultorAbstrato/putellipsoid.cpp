#include <iostream>
#include <cmath>

#include "putellipsoid.h"

PutEllipsoid::PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a){
    this->xcenter=xcenter;
    this->ycenter=ycenter;
    this->zcenter=zcenter;
    this->rx=rx;
    this->ry=ry;
    this->rz=rz;
    this->r=r; this->g=g; this->b=b; this->a=a;
}

PutEllipsoid::~PutEllipsoid(){
    std::cout << "Destrutor do PutEllipsoid \n";
}

void PutEllipsoid::draw(Sculptor &t){
    int i,j,k;
    t.setColor(r, g, b, a);
        for(i=(xcenter-rx); i<=(xcenter+rx); i++){
            for(j=(ycenter-ry); j<=(ycenter+ry); j++){
                for(k=(zcenter-rz); k<=(zcenter+rz); k++){
                    if(pow(float(i-xcenter)/float(rx),2) + pow(float(j-ycenter)/float(ry),2) + pow(float(k-zcenter)/float(rz),2) <= 1){
                        t.putVoxel(i,j,k);
                }
            }
        }
    }
}
