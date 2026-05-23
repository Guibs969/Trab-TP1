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
     * @throw std::invalid_argument se o valor for inválido.
     */
    void setValor(const std::string& valor);

    /**
     * @brief Retorna o valor da prioridade.
     * @return std::string
     */
    std::string getValor() const;
};

#endif // PRIORIDADE_HPP
