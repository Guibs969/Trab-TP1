#ifndef TEXTO_HPP
#define TEXTO_HPP

#include <string>
#include <stdexcept>

/**
 * @brief Classe de domínio para representar texto formatado.
 */
class Texto {
private:
    std::string valor;
public:
    /**
     * @brief Define o valor do texto.
     * @param valor Texto no formato válido.
     * @throw std::invalid_argument se o formato for inválido.
     */
    void setValor(const std::string& valor);

    /**
     * @brief Retorna o valor do texto.
     * @return std::string
     */
    std::string getValor() const;
};

#endif // TEXTO_HPP
