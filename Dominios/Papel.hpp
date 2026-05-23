#ifndef PAPEL_HPP
#define PAPEL_HPP

#include <string>
#include <stdexcept>

/**
 * @brief Classe de domínio para representar o papel de uma pessoa no projeto.
 */
class Papel {
private:
    std::string valor;
public:
    /**
     * @brief Define o valor do papel.
     * @param valor Papel no formato válido.
     * @throw std::invalid_argument se o valor for inválido.
     */
    void setValor(const std::string& valor);

    /**
     * @brief Retorna o valor do papel.
     * @return std::string
     */
    std::string getValor() const;
};

#endif // PAPEL_HPP
