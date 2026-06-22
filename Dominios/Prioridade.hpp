#ifndef PRIORIDADE_HPP
#define PRIORIDADE_HPP

#include <string>
#include <stdexcept>

/**
 * @brief Classe de domínio para representar a prioridade de uma história de usuário.
 */
class Prioridade {
private:
    std::string valor;
public:
    /**
     * @brief Define o valor da prioridade.
     * @param valor Prioridade no formato válido.
     * @brief Strings válidas aceitas pelo método dessa classe são: "ALTA", "MEDIA" E "BAIXA".
     * @throw std::invalid_argument Exceção é lançada caso string inserida for diferente das strings específicadas acima.
     */
    void setValor(const std::string& valor);

    /**
     * @brief Retorna o valor da prioridade.
     * @return std::string
     */
    std::string getValor() const;
};

#endif // PRIORIDADE_HPP
