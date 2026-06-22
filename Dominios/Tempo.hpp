#ifndef TEMPO_HPP
#define TEMPO_HPP

#include <stdexcept>

/**
 * @brief Classe de domínio para representar um tempo em dias.
 */
class Tempo {
private:
    int valor = 0;
public:
    /**
     * @brief Define o valor do tempo.
     * @param valor é um número inteiro entre 1 e 365.
     * @throw std::invalid_argument Exceção é lançada caso seja inserido número fora do intervalo específicado.
     */
    void setValor(int valor);

    /**
     * @brief Retorna o valor do tempo.
     * @return int
     */
    int getValor() const;
};

#endif // TEMPO_HPP
