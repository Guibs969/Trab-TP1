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
     * @brief Strings válidas aceitas pelo método dessa classe são: "DESENVOLVEDOR", "MESTRE SCRUM", "PROPRIETARIO DE PRODUTO".
     * @throw std::invalid_argument Exceção é lançada caso string inserida for diferente das strings específicadas acima.
     */
    void setValor(const std::string& valor);

    /**
     * @brief Retorna o valor do papel.
     * @return std::string
     */
    std::string getValor() const;
};

#endif // PAPEL_HPP
