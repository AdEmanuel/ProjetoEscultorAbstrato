#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <math.h>
#include <vector>
#include <queue>
#include "sculptor.h"

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx;
    ny = _ny;
    nz = _nz;

    v = new Voxel**[nx];
        for(int i=0; i<nx; i++){
            v[i] = new Voxel*[ny];
                for(int j=0; j<ny; j++){
                    v[i][j] = new Voxel[nz];
                }
        }

    for (int i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
            for (int k = 0; k < nz; k++){
                v[i][j][k].isOn = false;
            }
        }
    }
    cout << "Construtor Ok!" << endl;
}

Sculptor::~Sculptor(){

    if(nx==0||ny==0||nz==0){
        cout << "Destrutor falhou \n";
        return;
    }

    delete [] v[0][0];
    delete [] v[0];
    delete [] v;

    cout << "Destrutor ok" << endl;
}

void Sculptor::setColor(float r, float g, float b, float alpha){
    this->r = r; //componente correspondente à cor vermelha.
    this->g = g; //componente correspondente à cor verde.
    this->b = b; //componente correspondente à cor azul.
    this->a = alpha; //componente correspondente à opacidade.
}

void Sculptor::putVoxel(int x, int y, int z){
    if(x>=0 && x<nx &&
       y>=0 && y<ny &&
       z>=0 && x<nz){
        v[x][y][z].isOn = true;  //o voxel será exibido no escultor.
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
    }
}

void Sculptor::cutVoxel(int x, int y, int z){
    if(x>=0 && x<nx &&
       y>=0 && y<ny &&
       z>=0 && x<nz){
        v[x][y][z].isOn = false; //o voxel não será exibido no escultor.
    }
}

void Sculptor::writeOFF(char *filename){
    int NVoxels = 0, NVertices, NFaces;
    float faces = 0;

    ofstream fout;

    fout.open(filename);
    if (!fout.is_open()){
       exit(1);
       cout << "Não foi possivel gravar no arquivo";
    }

    fout << "OFF \n";

    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if (v[i][j][k].isOn == true){
                    NVoxels++;
                }
            }
        }
    }

    NVertices = 8*NVoxels;
    NFaces = 6*NVoxels;

    fout << NVertices << " " << NFaces << " " << 0 << endl;

    //Vertices do cubo sendo inseridos no aqruivo OFF
    for(int i=0; i<nz; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nx; k++){
                if(v[i][j][k].isOn){
                    fout << i-0.5 << " " << j+0.5 << " " << k-0.5 << endl
                         << i-0.5 << " " << j-0.5 << " " << k-0.5 << endl
                         << i+0.5 << " " << j-0.5 << " " << k-0.5 << endl
                         << i+0.5 << " " << j+0.5 << " " << k-0.5 << endl
                         << i-0.5 << " " << j+0.5 << " " << k+0.5 << endl
                         << i-0.5 << " " << j-0.5 << " " << k+0.5 << endl
                         << i+0.5 << " " << j-0.5 << " " << k+0.5 << endl
                         << i+0.5 << " " << j+0.5 << " " << k+0.5 << endl;
                 }
            }
        }
    }
    //Faces do cubo sendo inseridos no arquivo OFF
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                if(v[i][j][k].isOn){
                    fout << 4 << " " << 0+faces << " " << 3+faces << " " << 2+faces << " " << 1+faces << " "
                         << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl
                         << 4 << " " << 4+faces << " " << 5+faces << " " << 6+faces << " " << 7+faces<< " "
                         << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl
                         << 4 << " " << 0+faces << " " << 1+faces << " " << 5+faces << " " << 4+faces << " "
                         << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl
                         << 4 << " " << 0+faces << " " << 4+faces << " " << 7+faces << " " << 3+faces << " "
                         << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl
                         << 4 << " " << 3+faces << " " << 7+faces << " " << 6+faces << " " << 2+faces << " "
                         << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl
                         << 4 << " " << 1+faces << " " << 2+faces << " " << 6+faces << " " << 5+faces<< " "
                         << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    faces = faces+8;

                 }
            }
        }
    }

    fout.close();
}

void Sculptor::limpaVoxels(void){
     queue<int> q;
     int x, y, z;
     int lx,ly,lz;
     for(x=1; x<nx-1; x++){
       for(y=1; y<ny-1; y++){
         for(z=1; z<nz-1; z++){
           if((v[x][y][z].isOn == true) &&
              (v[x+1][y][z].isOn == true) &&
              (v[x-1][y][z].isOn == true) &&
              (v[x][y+1][z].isOn == true) &&
              (v[x][y-1][z].isOn == true) &&
              (v[x][y][z+1].isOn == true) &&
              (v[x][y][z-1].isOn == true)){
             q.push(x);
             q.push(y);
             q.push(z);
           }
         }
       }
     }
     while(!q.empty()){
       lx=q.front(); q.pop();
       ly=q.front(); q.pop();
       lz=q.front(); q.pop();
       v[lx][ly][lz].isOn = false;
     }
}

