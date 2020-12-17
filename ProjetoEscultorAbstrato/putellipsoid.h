#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "figurageometrica.h"
#include "sculptor.h"
/**
 * @brief A classe PutEllipsoid especifica uma elipsoide para ser desenhada.
 */
class PutEllipsoid : public FiguraGeometrica{
    /**
     * @brief xcenter é o parâmetro com o valor do centro da elipsóide na coordenada x.
     */
    int xcenter;
    /**
     * @brief ycenter é o parâmetro com o valor do centro da elipsóide na coordenada y.
     */
    int ycenter;
    /**
     * @brief zcenter é o parâmetro com o valor do centro da elipsóide na coordenada z.
     */
    int zcenter;
    /**
     * @brief rx é o parâmetro com o valor do raio da elipsóide na coordenada x.
     */
    int rx;
    /**
     * @brief ry é o parâmetro com o valor do raio da elipsóide na coordenada y.
     */
    int ry;
    /**
     * @brief rz é o parâmetro com o valor do raio da elipsóide na coordenada z.
     */
    int rz;
public:
    /**
     * @brief A função putEllipsoid cria uma entidade de Voxels no formato de um elipsoide.
     * @param r armazena o valor referenete a cor vermelha.
     * @param g armazena o valor referenete a cor verde.
     * @param b armazena o valor referenete a cor azul.
     * @param a armazena o valor referenete a transparência.
     */
    PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);
    /**
     * @brief~PutEllipsoid é o destructor da função <b>PutEllipsoid</b>.
     * @sa PutEllipsoid.
     */
    ~PutEllipsoid();
    void draw(Sculptor &t);
};

#endif // PUTELLIPSOID_H
