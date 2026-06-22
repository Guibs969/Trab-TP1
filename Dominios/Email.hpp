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
     * @param valor Email no formato específicado.
     * @param parte-local pode conter letra(a-z),dígito(0-9)ou ponto(.)ou hífen(-); não pode iniciar ou terminar com ponto ou hífen; ponto ou hífen deve ser seguido por letra(s) ou digíto(s).Comprimento máximo de 64 caracteres.
     * @param domínio é composto por uma ou mais partes separadas por ponto(.); cada parte pode conter letra(a-z), dígito(0-9) ou hífen(-); não pode iniciar ou terminar com hífen.Comprimento máximo de 255 caracteres.
     * @throw std::invalid_argument Exceção é lançada caso haja mais de um "@"
     * @throw std::invalid_argument Exceção é lançada caso parte-local esteja com formato incorreto.
     * @throw std::invalid_argument Exceção é lançada caso domínio esteja vazio ou for muito longo.
     * @throw std::invalid_argument Exceção é lançada caso parte do domínio esteja com formato incorreto.
     */
    void setValor(const std::string& valor);

    /**
     * @brief Retorna o valor do email.
     * @return std::string
     */
    std::string getValor() const;
};

#endif // EMAIL_HPP
