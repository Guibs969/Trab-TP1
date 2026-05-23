#ifndef ISERVICOPESSOA_HPP
#define ISERVICOPESSOA_HPP

#include "../Entidades/Pessoa.hpp"
#include "../Dominios/Email.hpp"
#include "../Dominios/Senha.hpp"
#include <vector>

/**
 * @brief Interface para serviço de pessoa.
 */
class IServicoPessoa {
public:
    virtual bool cadastrar(const Pessoa& p) = 0;
    virtual bool autenticar(const Email& email, const Senha& senha) const = 0;
    virtual bool atualizar(const Pessoa& p) = 0;
    virtual bool excluir(const Email& email) = 0;
    virtual bool buscar(const Email& email, Pessoa& p) const = 0;
    virtual std::vector<Pessoa> listar() const = 0;
    virtual bool existe(const Email& email) const = 0;
    virtual ~IServicoPessoa() = default;
};

#endif // ISERVICOPESSOA_HPP
