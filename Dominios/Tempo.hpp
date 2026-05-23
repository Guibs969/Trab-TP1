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
     * @param valor Tempo em dias.
     * @throw std::invalid_argument se o valor for inválido.
     */
    void setValor(int valor);

    /**
     * @brief Retorna o valor do tempo.
     * @return int
     */
    int getValor() const;
};

#endif // TEMPO_HPP
