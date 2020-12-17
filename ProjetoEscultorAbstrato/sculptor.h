#ifndef SCULPTOR_H
#define SCULPTOR_H
/**
 * @brief O struct Voxel cria uma entidade em três dimensões.
 * @param r é a componente resposável pela cor vermelha.
 * @param g é a componente resposável pela cor verde.
 * @param b é a componente resposável pela cor blue.
 * @param a é a componente resposável pela transparência.
 * @param isOn é a componente resposável pela construção ou não do Voxel.
 */
struct Voxel {
  float r,g,b; // Cores.
  float a; // Transparência.
  bool isOn; // Incluir ou não.
};

/**
 * @brief A classe Sculptor é resposnsável por criar e prover funções capazes de manipular uma matriz de Voxels.
 */
class Sculptor {
protected:
    /**
       * @brief v é uma matriz tridimensional, formada a partir de um ponteiro para ponteiro para ponteiro para Voxel.
       */
      Voxel ***v; // Matriz 3D.
      /**
       * @brief nx armazena a quantidadede de elementos na direção x da matriz.
       */
      int nx;
      /**
       * @brief ny armazena a quantidadede de elementos na direção y da matriz.
       */
      int ny;
      /**
       * @brief nz armazena a quantidadede de elementos na direção z da matriz.
       */
      int nz;
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
   * @brief A função Sculptor aloca uma matriz para o ambiente onde serão esculpidos os objetos.
   * @param _nx é o valor referente a dimensão do objeto na direção x.
   * @param _ny é o valor referente a dimensão do objeto na direção y.
   * @param _nz é o valor referente a dimensão do objeto na direção z.
   */
  Sculptor(int _nx, int _ny, int _nz);
  /**
   * @brief A função ~Sculptor é o destructor da função <b>Sculptor</b>.
   * @sa Sculptor.
   */
  ~Sculptor();
  /**
   * @brief A função setColor atribui as cores ao objeto que será esculpido.
   * @brief O valor das cores é um número float que pode variar de 0 à 1, que representam, respectivamente, ausência ou valor máximo de cor.
   * @param r é o parâmetro com o valor correspondente à cor <b>Vermelha</b>;
   * @param g é o parâmetro com o valor correspondente à cor <b>Verde</b>;
   * @param b é o parâmetro com o valor correspondente à cor <b>Azul</b>;
   */
  void setColor(float r, float g, float b, float alpha);
  /**
     * @brief A função putVoxel cria um Voxel no ambiente, na posição definida pelo usuário.
     * @param x é o parâmetro com o valor da coordenada x;
     * @param y é o parâmetro com o valor da coordenada y;
     * @param z é o parâmetro com o valor da coordenada z;
     */
  void putVoxel(int x, int y, int z);
  /**
     * @brief A função cutVoxel remove um Voxel na posição definida pelo usuário.
     * @brief Os parâmetros utilizados por esta função são os mesmos da <b>putVoxel</b>.
     * @sa putVoxel
     */
  void cutVoxel(int x, int y, int z);
  /**
   * @brief Criar arquivo para leitura do desenho, contendo as dimensões e as cores utilizando.
   */
  void writeOFF(char* filename);
  /**
   * @brief Função responsável por remover os voxels que ficam "escondido" atrás de outros voxels, que acabam sobrecarregando a figura.
   */
  void limpaVoxels();

};

#endif // SCULPTOR_H
