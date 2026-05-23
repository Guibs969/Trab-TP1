#include "ContainerPessoa.hpp"
#include <algorithm>

bool ContainerPessoa::existe(const Pessoa& p) const {
    return existe(p.getEmail());
}

bool ContainerPessoa::existe(const Email& email) const {
    auto it = std::find_if(pessoas.begin(), pessoas.end(), [&](const Pessoa& existente) {
        return existente.getEmail().getValor() == email.getValor();
    });
    return it != pessoas.end();
}

bool ContainerPessoa::inserir(const Pessoa& p) {
    if (existe(p)) {
        return false;
    }
    pessoas.push_back(p);
    return true;
}

bool ContainerPessoa::atualizar(const Pessoa& p) {
    for (auto& existente : pessoas) {
        if (existente.getEmail().getValor() == p.getEmail().getValor()) {
            existente = p;
            return true;
        }
    }
    return false;
}

bool ContainerPessoa::remover(const Email& email) {
    auto it = std::find_if(pessoas.begin(), pessoas.end(), [&](const Pessoa& existente) {
        return existente.getEmail().getValor() == email.getValor();
    });
    if (it == pessoas.end()) {
        return false;
    }
    pessoas.erase(it);
    return true;
}

bool ContainerPessoa::buscar(const Email& email, Pessoa& pessoa) const {
    auto it = std::find_if(pessoas.begin(), pessoas.end(), [&](const Pessoa& existente) {
        return existente.getEmail().getValor() == email.getValor();
    });
    if (it == pessoas.end()) {
        return false;
    }
    pessoa = *it;
    return true;
}

std::vector<Pessoa> ContainerPessoa::listar() const {
    return pessoas;
}
