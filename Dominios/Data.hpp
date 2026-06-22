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
     * @param valor Data em formato string, na ordem DIA/MÊS/ANO.
     * @param DIA é número de 1 a 31.
     * @param MÊS é número 01,02,03,04,05,06,07,08,09,10,11 ou 12.
     * @param ANO é número de 2000 a 2999.
     * @param anos bissextos são considerados.
     * @throw std::invalid_argument Exceção é lançada se formato DD/MM/AAAA não for seguido.
     * @throw std::invalid_argument Exceção é lançada se dia, mês ou ano não forem inseridos.
     * @throw std::invalid_argument Exceção é lançada caso ano não esteja entre 2000 e 2999.
     * @throw std::invalid_argument Exceção é lançada caso mês não esteja entre 01 e 12.
     * @throw std::invalid_argument Exceção é lançada caso dia inserido esteja fora do intervalo para o mês inserido.
     */
    void setValor(const std::string& valor);

    /**
     * @brief Retorna o valor da data.
     * @return std::string
     */
    std::string getValor() const;
};

#endif // DATA_HPP
