#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "figurageometrica.h"
#include "sculptor.h"
/**
 * @brief A classe PutVoxel desenha um voxel no ambiente.
 */

class PutVoxel : public FiguraGeometrica{
    /**
     * @brief x é o valor da posição x onde o voxel será desenhado.
     */
    int x;
    /**
     * @brief y é o valor da posição y onde o voxel será desenhado.
     */
    int y;
    /**
     * @brief z é o valor da posição z onde o voxel será desenhado.
     */
    int z;
public:
    /**
     * @brief PutVoxel é uma classe que desenha um voxel no ambiente.
     * @param r armazena o valor referenete a cor vermelha..
     * @param g armazena o valor referenete a cor verde.
     * @param b armazena o valor referenete a cor azul.
     * @param a armazena o valor referenete a transparência.
     */
    PutVoxel(int x, int y, int z, float r, float g, float b, float a);
    /**
     * @brief~PutVoxel é o destructor da função <b>PutVoxel</b>.
     * @sa PutVoxel.
     */
    ~PutVoxel(){}
    /**
     * @brief draw é a função que permite que o objeto da classe se desenhe.
     * @param t guarda o endereço do objeto que irá se desenhar.
     */
    void draw(Sculptor &t);
};

#endif // PUTVOXEL_H
