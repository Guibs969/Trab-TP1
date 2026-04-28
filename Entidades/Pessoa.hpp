#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>

/**
 * @brief Classe de entidade para representar uma pessoa.
 */
class Pessoa {
private:
    std::string nome;
    std::string email;
public:
    /**
     * @brief Define o nome da pessoa.
     */
    void setNome(const std::string& nome);

    /**
     * @brief Retorna o nome da pessoa.
     */
    std::string getNome() const;

    /**
     * @brief Define o email da pessoa.
     */
    void setEmail(const std::string& email);

    /**
     * @brief Retorna o email da pessoa.
     */
    std::string getEmail() const;
};

#endif // PESSOA_HPP
