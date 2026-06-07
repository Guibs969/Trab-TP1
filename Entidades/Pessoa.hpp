#ifndef PESSOA_HPP
#define PESSOA_HPP

#include "../Dominios/Email.hpp"
#include "../Dominios/Nome.hpp"
#include "../Dominios/Senha.hpp"
#include "../Dominios/Papel.hpp"

/**
 * @brief Classe de entidade para representar uma pessoa.
 */
class Pessoa {
private:
    Nome nome;
    Email email;
    Senha senha;
    Papel papel;
public:
    /**
     * @brief Define o nome da pessoa.
     * @param nome Objeto instanciado da classe de domínio Nome.
     */
    void setNome(const Nome& nome);

    /**
     * @brief Retorna o nome da pessoa.
     * @return Nome Objeto contendo o nome da pessoa.
     */
    Nome getNome() const;

    /**
     * @brief Define o e-mail da pessoa.
     * @param email Objeto instanciado da classe de domínio Email.
     */
    void setEmail(const Email& email);

    /**
     * @brief Retorna o e-mail da pessoa.
     * @return Email Objeto contendo o e-mail da pessoa.
     */
    Email getEmail() const;

    /**
     * @brief Define a senha da pessoa.
     * @param senha Objeto instanciado da classe de domínio Senha.
     */
    void setSenha(const Senha& senha);

    /**
     * @brief Retorna a senha da pessoa.
     * @return Senha Objeto contendo a senha da pessoa.
     */
    Senha getSenha() const;

    /**
     * @brief Define o papel/cargo da pessoa no sistema.
     * @param papel Objeto instanciado da classe de domínio Papel.
     */
    void setPapel(const Papel& papel);

    /**
     * @brief Retorna o papel/cargo da pessoa.
     * @return Papel Objeto contendo o papel da pessoa.
     */
    Papel getPapel() const;
};

#endif // PESSOA_HPP