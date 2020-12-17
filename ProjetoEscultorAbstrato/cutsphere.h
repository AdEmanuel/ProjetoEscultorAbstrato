#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief A classe CutSphere especifica uma esfera para ser desenhada.
 */

class CutSphere : public FiguraGeometrica{
    int xcenter;
    int ycenter;
    int zcenter;
    int radius;
public:
    /**
     * @brief CutSphere remove(ou corta) uma sequência de Voxels no formato de uma esfera.
     * @param xcenter é o parâmetro com o valor do centro da esfera na coordenada x.
     * @param ycenter é o parâmetro com o valor do centro da esfera na coordenada y.
     * @param zcenter é o parâmetro com o valor do centro da esfera na coordenada z.
     * @param radius é o parâmetro com o valor do raio da esfera.
     */
    CutSphere(int xcenter, int ycenter, int zcenter, int radius);
    /**
     * @brief CutSphere é o destrutor da função <b>CutSphere</b>.
     * @sa CutSphere.
    */
    ~CutSphere();
    /**
     * @brief draw é a função que permite que o objeto da classe se desenhe.
     * @param t guarda o endereço do objeto que irá se desenhar.
     */
    void draw(Sculptor &t);
};

#endif // CUTSPHERE_H
