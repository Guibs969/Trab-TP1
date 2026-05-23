#include "CtrlServicoPessoa.hpp"

bool CtrlServicoPessoa::cadastrar(const Pessoa& p) {
    if (container.existe(p.getEmail())) {
        return false;
    }
    return container.inserir(p);
}

bool CtrlServicoPessoa::autenticar(const Email& email, const Senha& senha) const {
    Pessoa pessoa;
    if (!container.buscar(email, pessoa)) {
        return false;
    }
    return pessoa.getSenha().getValor() == senha.getValor();
}

bool CtrlServicoPessoa::atualizar(const Pessoa& p) {
    return container.atualizar(p);
}

bool CtrlServicoPessoa::excluir(const Email& email) {
    return container.remover(email);
}

bool CtrlServicoPessoa::buscar(const Email& email, Pessoa& p) const {
    return container.buscar(email, p);
}

std::vector<Pessoa> CtrlServicoPessoa::listar() const {
    return container.listar();
}

bool CtrlServicoPessoa::existe(const Email& email) const {
    return container.existe(email);
}
