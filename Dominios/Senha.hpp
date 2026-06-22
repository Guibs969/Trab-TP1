#ifndef SENHA_HPP
#define SENHA_HPP

#include <string>
#include <stdexcept>

/**
 * @brief Classe de domínio para representar uma senha válida.
 */
class Senha {
private:
    std::string valor;
public:
    /**
     * @brief Define o valor da senha.
     * @param valor Senha no formato válido.
     * @brief Caracter pode ser letra(a-z ou A-Z) ou dígito(0-9); letra não pode ser seguida por letra, dígito não pode ser seguido por dígito.
     * @brief Deve existir pelo menos uma letra minúscula(a-z), uma letra maiúscula(A-Z) e um dígito(0-9).
     * @throw std::invalid_argument Exceção é lançada caso tamanho da senha seja diferente de 6 caracteres.
     * @throw std::invalid_argument Exceção é lançada caso sejam inseridos caracteres que não sejam letras ou dígitos.
     * @throw std::invalid_argument Exceção é lançada caso hajam letras seguidas por letras ou dígitos seguidos por dígitos.
     * @throw std::invalid_argument Exceção é lançada caso senha não contenha pelo menos uma letra maiúscula, uma minúscula e um dígito.
     */
    void setValor(const std::string& valor);

    /**
     * @brief Retorna o valor da senha.
     * @return std::string
     */
    std::string getValor() const;
};

#endif // SENHA_HPP
