#ifndef ESTADO_HPP
#define ESTADO_HPP

#include <string>
#include <stdexcept>

/**
 * @brief Classe de domínio para representar o estado de uma história de usuário.
 */
class Estado {
private:
    std::string valor;
public:
    /**
     * @brief Define o valor do estado.
     * @param valor Estado no formato válido.
     * @throw std::invalid_argument se o valor for inválido.
     */
    void setValor(const std::string& valor);

    /**
     * @brief Retorna o valor do estado.
     * @return std::string
     */
    std::string getValor() const;
};

#endif // ESTADO_HPP
