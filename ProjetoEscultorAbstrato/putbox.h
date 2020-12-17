#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"

/**
 * @brief A classe PutBox especifica uma caixa para ser desenhada.
 */
class PutBox : public FiguraGeometrica{

protected:
    /**
     * @brief x0 é o parâmetro com o valor do centro da elipsóide na coordenada x.
     */
    int x0;
    /**
     * @brief x1 é o parâmetro com o valor do centro da elipsóide na coordenada y.
     */
    int x1;
    /**
     * @brief y0 é o parâmetro com o valor do centro da elipsóide na coordenada z.
     */
    int y0;
    /**
     * @brief y1 é o parâmetro com o valor do raio da elipsóide na coordenada x.
     */
    int y1;
    /**
     * @brief z0 é o parâmetro com o valor do raio da elipsóide na coordenada y.
     */
    int z0;
    /**
     * @brief z1 é o parâmetro com o valor do raio da elipsóide na coordenada z.
     */
    int z1;
    /**
     * @brief r armazena o valor referenete a cor vermelha.
     */
    float r;
    /**
     * @brief g armazena o valor referenete a cor verde.
     */
    float g;
    /**
     * @brief b armazena o valor referenete a cor azul.
     */
    float b;
    /**
     * @brief a armazena o valor referenete a transparência.
     */
    float a;

public:
    /**
     * @brief A função putBox cria uma entidade de Voxels no formato de uma cubo.
     * @brief Esta função utiliza os valores de índice 0 como iniciadores, que vão até os valores de índice 1, em cada uma das coordena
     */
    PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);
    /**
     * @brief~PutBox é o destructor da função <b>PutBox</b>.
     * @sa PutBox.
     */
    ~PutBox();
    /**
     * @brief draw é a função que permite que o objeto da classe se desenhe.
     * @param t guarda o endereço do objeto que irá se desenhar.
     */
    void draw(Sculptor &t);

};



#endif // PUTBOX_H
