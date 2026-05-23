#ifndef ISERVICOPROJETO_HPP
#define ISERVICOPROJETO_HPP

#include "../Entidades/Projeto.hpp"
#include "../Dominios/Codigo.hpp"
#include "../Dominios/Email.hpp"
#include <vector>

/**
 * @brief Interface para serviços de projeto.
 */
class IServicoProjeto {
public:
    virtual bool cadastrar(const Projeto& projeto) = 0;
    virtual bool atualizar(const Projeto& projeto) = 0;
    virtual bool excluir(const Codigo& codigo) = 0;
    virtual bool buscar(const Codigo& codigo, Projeto& projeto) const = 0;
    virtual std::vector<Projeto> listar() const = 0;
    virtual std::vector<Projeto> listarProjetosPorPessoa(const Email& email) const = 0;
    virtual bool existe(const Codigo& codigo) const = 0;
    virtual ~IServicoProjeto() = default;
};

#endif // ISERVICOPROJETO_HPP
