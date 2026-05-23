#ifndef CONTAINERPESSOA_HPP
#define CONTAINERPESSOA_HPP

#include "../Entidades/Pessoa.hpp"
#include <vector>

/**
 * @brief Container simples para armazenamento de pessoas.
 */
class ContainerPessoa {
private:
    std::vector<Pessoa> pessoas;
public:
    bool existe(const Pessoa& p) const;
    bool existe(const Email& email) const;
    bool inserir(const Pessoa& p);
    bool atualizar(const Pessoa& p);
    bool remover(const Email& email);
    bool buscar(const Email& email, Pessoa& pessoa) const;
    std::vector<Pessoa> listar() const;
};

#endif // CONTAINERPESSOA_HPP
