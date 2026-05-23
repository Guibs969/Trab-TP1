#ifndef CONTAINERPROJETO_HPP
#define CONTAINERPROJETO_HPP

#include "../Entidades/Projeto.hpp"
#include <vector>

/**
 * @brief Container simples para armazenamento de projetos.
 */
class ContainerProjeto {
private:
    std::vector<Projeto> projetos;
public:
    bool existe(const Codigo& codigo) const;
    bool inserir(const Projeto& projeto);
    bool atualizar(const Projeto& projeto);
    bool remover(const Codigo& codigo);
    bool buscar(const Codigo& codigo, Projeto& projeto) const;
    std::vector<Projeto> listar() const;
};

#endif // CONTAINERPROJETO_HPP
