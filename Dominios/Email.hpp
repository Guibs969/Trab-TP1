#ifndef EMAIL_HPP
#define EMAIL_HPP

#include <string>
#include <stdexcept>

/**
 * @brief Classe de domínio para representar um endereço de email válido.
 */
class Email {
private:
    std::string valor;
public:
    /**
     * @brief Define o valor do email.
     * @param valor Email no formato válido.
     * @throw std::invalid_argument se o formato for inválido.
     */
    void setValor(const std::string& valor);

    /**
     * @brief Retorna o valor do email.
     * @return std::string
     */
    std::string getValor() const;
};

#endif // EMAIL_HPP
