#include "cutvoxel.h"

CutVoxel::CutVoxel(int x, int y, int z, float r, float g, float b, float a){
    this->x=x, this->y=y, this->x=z;
    this->r=r, this->g=g, this->b=b, this->a=a;
}

void CutVoxel::draw(Sculptor &t){
    t.setColor(r,g,b,a);
    t.cutVoxel(x,y,z);
}

