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
     ///* @brief Define o valor do código.
     * @param valor 5 caracteres, sendo letras maiúsculas(A-Z)os dois primeiros caracteres e os três últimos sendo dígitos(0-9).
     * @throw std::invalid_argument Exceção é lançada caso as especificações acima não sejam atendidas.
     */
    void setValor(const std::string& valor);

    /**
     * @brief Retorna o valor do código.
     * @return std::string
     */
    std::string getValor() const;
};

#endif // CODIGO_HPP
