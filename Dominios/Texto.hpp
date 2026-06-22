#ifndef TEXTO_HPP
#define TEXTO_HPP

#include <string>
#include <stdexcept>

/**
 * @brief Classe de domínio para representar texto formatado.
 */
class Texto {
private:
    std::string valor;
public:
    /**
     * @brief Define o valor do texto.
     * @param valor Texto no formato válido.
     * @brief Caracter pode ser letra(a-z ou A-Z), dígito(0-9), vírgula, ponto ou espaço em branco.
     * @brief vírgula não pode ser seguida por vírgula ou ponto; ponto não pode ser seguido por vírgula ou ponto; espaço em branco é seguido por letra ou dígito
     * @brief Primeiro e último caracter não pode ser vírgula, ponto ou espaço em branco.
     * @throw std::invalid_argument Exceção é lançada caso tamanho do texto esteja fora do intervalo específicado.
     * @throw std::invalid_argument Exceção é lançada caso texto inicie ou termine com espaço, vírgula ou ponto.
     * @throw std::invalid_argument Exceção é lançada caso vírgula seja seguida por vírgula ou ponto seja seguido por ponto.
     * @throw std::invalid_argument Exceção é lançada caso espaço não seja seguido por letra ou dígito.
     * @throw std::invalid_argument Exceção é lançada caso seja inserido caractere diferente de letra, dígito, espaço, vírgula ou ponto.
     */
    void setValor(const std::string& valor);

    /**
     * @brief Retorna o valor do texto.
     * @return std::string
     */
    std::string getValor() const;
};

#endif // TEXTO_HPP
