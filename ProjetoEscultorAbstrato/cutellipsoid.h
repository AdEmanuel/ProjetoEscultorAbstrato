#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief A classe CutEllipsoid especifica um elipsoide para ser desenhado.
 */
class CutEllipsoid : public FiguraGeometrica{
    int xcenter;
    int ycenter;
    int zcenter;
    int rx;
    int ry;
    int rz;
public:
    /**
     * @brief CutEllipsoid remove(ou corta) uma sequência de Voxels no formato de um elipsóide.
     * @param xcenter é o parâmetro com o valor do centro da elipsóide na coordenada x.
     * @param ycenter é o parâmetro com o valor do centro da elipsóide na coordenada y.
     * @param zcenter é o parâmetro com o valor do centro da elipsóide na coordenada z.
     * @param rx é o parâmetro com o valor do raio da elipsóide na coordenada x.
     * @param ry é o parâmetro com o valor do raio da elipsóide na coordenada y.
     * @param rz é o parâmetro com o valor do raio da elipsóide na coordenada z.
     */
    CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    /**
     * @brief CutEllipsoid é o destrutor da função <b>CutEllipsoid</b>.
     * @sa CutEllipsoid.
    */
    ~CutEllipsoid();
    /**
     * @brief draw é a função que permite que o objeto da classe se desenhe.
     * @param t guarda o endereço do objeto que irá se desenhar.
     */
    void draw(Sculptor &t);
};

#endif // CUTELLIPSOID_H
