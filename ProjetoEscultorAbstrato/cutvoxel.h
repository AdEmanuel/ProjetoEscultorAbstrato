#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief A classe CutVoxel especifica um Voxel para ser desenhado.
 */

class CutVoxel : public FiguraGeometrica{
    int x;
    int y;
    int z;
public:
    /**
     * @brief CutVoxel é uma função que remove um Voxel na posição definida pelo usuário.
     * @param x é o valor da posição x onde o voxel será desenhado.
     * @param y é o valor da posição y onde o voxel será desenhado.
     * @param z é o valor da posição z onde o voxel será desenhado.
     * @param r armazena o valor referenete a cor vermelha.
     * @param g armazena o valor referenete a cor verde.
     * @param b armazena o valor referenete a cor azul.
     * @param a armazena o valor referenete a transparência.
     */
    CutVoxel(int x, int y, int z, float r, float g, float b, float a);
    /**
     * @brief CutVoxel é o destrutor da função <b>CutVoxel</b>.
     * @sa CutVoxel.
    */
    ~CutVoxel(){}
    /**
     * @brief draw é a função que permite que o objeto da classe se desenhe.
     * @param t guarda o endereço do objeto que irá se desenhar.
     */
    void draw(Sculptor &t);
};

#endif // CUTVOXEL_H
