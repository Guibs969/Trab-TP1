#ifndef NOME_HPP
#define NOME_HPP

#include <string>
#include <stdexcept>

/**
 * @brief Classe de domínio para representar um nome válido.
 */
class Nome {
private:
    std::string valor;
public:
    /**
     * @brief Define o valor do nome.
     * @param valor Nome no formato válido.
     * @brief Texto com até 10 caracteres.
     * @brief Caracter pode ser letra maiúscula(A-Z), letra minúscula(a-z) ou espaço em branco; espaço em branco é seguido por letra; o primeiro e o último caracter não podem ser espaços em branco.
     * @throw std::invalid_argument Exceção é lançada caso tamanho do nome não esteja no intervalo entre 1 e 10 caracteres.
     * @throw std::invalid_argument Exceção é lançada caso nome inicie ou termine com um espaço.
     * @throw std::invalid_argument Exceção é lançada caso um espaço não seja seguido por uma letra.
     * @throw std::invalid_argument Exceção é lançada caso algum caracter não for uma letra ou um espaço.
     */
    void setValor(const std::string& valor);

    /**
     * @brief Retorna o valor do nome.
     * @return std::string
     */
    std::string getValor() const;
};

#endif // NOME_HPP
