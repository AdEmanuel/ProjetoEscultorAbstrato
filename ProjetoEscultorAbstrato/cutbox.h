#ifndef CUTBOX_H
#define CUTBOX_H

#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief A classe CutBox especifica uma caixa para ser desenhada.
 */
class CutBox : public FiguraGeometrica{
    int x0;
    int x1;
    int y0;
    int y1;
    int z0;
    int z1;
public:
    /**
     * @brief CutBox é uma classe que remove uma sequência de Voxels no formato de um cubo.
     * @param x0 é o parâmetro com o valor da coordenada x que delimita o início da construção do cubo.
     * @param x1 é o parâmetro com o valor da coordenada x que delimita o fim da construção do cubo.
     * @param y0 é o parâmetro com o valor da coordenada y que delimita o início da construção do cubo.
     * @param y1 é o parâmetro com o valor da coordenada y que delimita o fim da construção do cubo.
     * @param z0 é o parâmetro com o valor da coordenada z que delimita o início da construção do cubo.
     * @param z1 é o parâmetro com o valor da coordenada z que delimita o fim da construção do cubo.
     * @param r armazena o valor referenete a cor vermelha.
     * @param g armazena o valor referenete a cor verde.
     * @param b armazena o valor referenete a cor azul.
     * @param a armazena o valor referenete a transparência.
     */
    CutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);
    /**
     * @brief ~CutBox é o destrutor da função <b>CutBox</b>.
     * @sa CutBox.
     */
    ~CutBox();
    /**
     * @brief draw é a função que permite que o objeto da classe se desenhe.
     * @param t guarda o endereço do objeto que irá se desenhar.
     */
    void draw(Sculptor &t);
};

#endif // CUTBOX_H
