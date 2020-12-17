#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "figurageometrica.h"
#include "sculptor.h"
/**
 * @brief A classe PutSphere especifica uma esfera para ser desenhada.
 */
class PutSphere : public FiguraGeometrica{
    /**
     * @brief xcenter é o parâmetro com o valor do centro da esfera na coordenada x.
     */
    int xcenter;
    /**
     * @brief ycenter é o parâmetro com o valor do centro da esfera na coordenada y.
     */
    int ycenter;
    /**
     * @brief zcenter é o parâmetro com o valor do centro da esfera na coordenada z.
     */
    int zcenter;
    /**
     * @brief radius é o parâmetro com o valor do raio da esfera.
     */
    int radius;
public:
   /**
    * @brief A função putSphere cria uma entidade de Voxels no formato de uma esfera.
    * @param r armazena o valor referenete a cor vermelha..
    * @param g armazena o valor referenete a cor verde.
    * @param b armazena o valor referenete a cor azul.
    * @param a armazena o valor referenete a transparência.
    */
    PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
    /**
     * @brief~PutSphere é o destructor da função <b>PutSphere</b>.
     * @sa PutSphere.
     */
    ~PutSphere();
    /**
     * @brief draw é a função que permite que o objeto da classe se desenhe.
     * @param t guarda o endereço do objeto que irá se desenhar.
     */
    void draw(Sculptor &t);
};

#endif // PUTSPHERE_H
