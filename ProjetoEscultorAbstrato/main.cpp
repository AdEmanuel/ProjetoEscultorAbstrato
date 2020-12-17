#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>

#include <sstream>

#include "sculptor.h"
#include "figurageometrica.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"

using namespace std;

int main(){

    Sculptor *sculptor;
            vector<FiguraGeometrica*> figs;
            fstream fin;
            string s;
            stringstream ss;

            fin.open("escultura.txt");
            if(!fin.is_open()){
                cout<<"Erro ao abrir o arquivo ou arquivo inexistente"<<endl;
                exit(0);
            }
            else{
                cout<<"Arquivo aberto com sucesso!"<<endl;
            }
            while(fin.good()){
                getline(fin, s);
                ss.clear();
                ss.str(s);
                ss>>s;
                cout << s << endl;

                if(s.compare("dim")==0){
                    int x, y, z;
                    ss >> x >> y >> z;
                    sculptor = new Sculptor(x, y, z);

                }
                else if(s.compare("putvoxel")==0){
                    int x,y,z;
                    float r, g, b, a;
                    ss >> x >> y >> z >> r >> g >> b >> a;
                    figs.push_back(new PutVoxel(x,y,z,r,g,b,a));
                }
                else if(s.compare("cutvoxel")==0){
                    int x,y,z;
                    float r, g, b, a;
                    ss >> x >> y >> z >> r >> g >> b >> a;
                    figs.push_back(new CutVoxel(x,y,z,r,g,b,a));
                }
                else if(s.compare("putbox")==0){
                    int x0, x1, y0, y1, z0, z1;
                    float r, g, b, a;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                    figs.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
                }
                else if(s.compare("cutbox")==0){
                    int x0,x1,y0,y1,z0,z1;
                    float r, g, b, a;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                    figs.push_back(new CutBox(x0,x1,y0,y1,z0,z1,r,g,b,a));
                }
                else if(s.compare("putsphere")==0){
                    int xcenter, ycenter, zcenter, radius;
                    float r, g, b, a;
                    ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
                    figs.push_back(new PutSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));
                }
                else if(s.compare("cutsphere")==0){
                    int xcenter, ycenter, zcenter, radius;
                    ss >> xcenter >> ycenter >> zcenter >> radius;
                    figs.push_back(new CutSphere(xcenter, ycenter, zcenter, radius));
                }
                else if(s.compare("putellipsoid")==0){
                    int xcenter, ycenter ,zcenter, rx, ry, rz;
                    float r, g, b, a;
                    ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
                    figs.push_back(new PutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));
                }
                else if(s.compare("cutellipsoid")==0){
                    int xcenter, ycenter ,zcenter, rx, ry, rz;
                    ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
                    figs.push_back(new CutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));
                }

            }
            for(unsigned int i = 0; i < figs.size();i++){
                figs[i]->draw(*sculptor);
            }
            sculptor->limpaVoxels();
            fin.close();
            sculptor->writeOFF((char*)"escultura.OFF");

            return 0;
}
