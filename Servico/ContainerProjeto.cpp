#include "ContainerProjeto.hpp"

bool ContainerProjeto::existe(const Codigo& codigo) const {
    for (const auto& projeto : projetos) {
        if (projeto.getCodigo().getValor() == codigo.getValor()) {
            return true;
        }
    }
    return false;
}

bool ContainerProjeto::inserir(const Projeto& projeto) {
    if (existe(projeto.getCodigo())) {
        return false;
    }
    projetos.push_back(projeto);
    return true;
}

bool ContainerProjeto::atualizar(const Projeto& projeto) {
    for (auto& existente : projetos) {
        if (existente.getCodigo().getValor() == projeto.getCodigo().getValor()) {
            existente = projeto;
            return true;
        }
    }
    return false;
}

bool ContainerProjeto::remover(const Codigo& codigo) {
    for (auto it = projetos.begin(); it != projetos.end(); ++it) {
        if (it->getCodigo().getValor() == codigo.getValor()) {
            projetos.erase(it);
            return true;
        }
    }
    return false;
}

bool ContainerProjeto::buscar(const Codigo& codigo, Projeto& projeto) const {
    for (const auto& existente : projetos) {
        if (existente.getCodigo().getValor() == codigo.getValor()) {
            projeto = existente;
            return true;
        }
    }
    return false;
}

std::vector<Projeto> ContainerProjeto::listar() const {
    return projetos;
}
