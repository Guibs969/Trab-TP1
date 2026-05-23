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
     * @throw std::invalid_argument se o formato for inválido.
     */
    void setValor(const std::string& valor);

    /**
     * @brief Retorna o valor da senha.
     * @return std::string
     */
    std::string getValor() const;
};

#endif // SENHA_HPP
