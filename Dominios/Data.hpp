#ifndef DATA_HPP
#define DATA_HPP

#include <string>

/**
 * @brief Classe de domínio para representar uma data.
 */
class Data {
private:
    std::string valor; ///< Data em formato string (placeholder)
public:
    /**
     * @brief Define o valor da data.
     * @param valor Data em formato string.
     */
    void setValor(const std::string& valor);

    /**
     * @brief Retorna o valor da data.
     * @return std::string
     */
    std::string getValor() const;
};

#endif // DATA_HPP
