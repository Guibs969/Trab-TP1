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
    void setNome(const Nome& nome);
    Nome getNome() const;

    void setEmail(const Email& email);
    Email getEmail() const;

    void setSenha(const Senha& senha);
    Senha getSenha() const;

    void setPapel(const Papel& papel);
    Papel getPapel() const;
};

#endif // PESSOA_HPP
