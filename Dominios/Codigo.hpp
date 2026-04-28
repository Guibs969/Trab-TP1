#ifndef CODIGO_HPP
#define CODIGO_HPP

#include <string>
#include <stdexcept>

/**
 * @brief Classe de domínio para representar um código.
 */
class Codigo {
private:
    std::string valor;
public:
    /**
     * @brief Define o valor do código.
     * @param valor Código no formato: 2 letras maiúsculas + 3 dígitos.
     * @throw std::invalid_argument se o formato for inválido.
     */
    void setValor(const std::string& valor);

    /**
     * @brief Retorna o valor do código.
     * @return std::string
     */
    std::string getValor() const;
};

#endif // CODIGO_HPP
