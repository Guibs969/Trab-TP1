#include "CtrlServicoProjeto.hpp"

CtrlServicoProjeto::CtrlServicoProjeto(const IServicoPessoa* servicoPessoa)
    : servicoPessoa(servicoPessoa) {
}

bool CtrlServicoProjeto::cadastrar(const Projeto& projeto) {
    if (container.existe(projeto.getCodigo())) {
        return false;
    }

    if (servicoPessoa == nullptr) {
        return false;
    }

    // Quem cria projeto ja e o proprietario, nao precisa verificar papel
    Pessoa proprietario;
    if (!servicoPessoa->buscar(projeto.getProprietario(), proprietario)) {
        return false;
    }

    // Mestre Scrum e opcional: so valida se foi informado (nao vazio)
    std::string emailMestre = projeto.getMestreScrum().getValor();
    if (!emailMestre.empty()) {
        Pessoa mestre;
        if (!servicoPessoa->buscar(projeto.getMestreScrum(), mestre)) {
            return false;
        }
    }

    return container.inserir(projeto);
}

bool CtrlServicoProjeto::atualizar(const Projeto& projeto) {
    if (!container.existe(projeto.getCodigo())) {
        return false;
    }
    return container.atualizar(projeto);
}

bool CtrlServicoProjeto::excluir(const Codigo& codigo) {
    return container.remover(codigo);
}

bool CtrlServicoProjeto::buscar(const Codigo& codigo, Projeto& projeto) const {
    return container.buscar(codigo, projeto);
}

std::vector<Projeto> CtrlServicoProjeto::listar() const {
    return container.listar();
}

std::vector<Projeto> CtrlServicoProjeto::listarProjetosPorPessoa(const Email& email) const {
    std::vector<Projeto> resultado;
    for (const auto& projeto : container.listar()) {
        if (projeto.getProprietario().getValor() == email.getValor() ||
            projeto.getMestreScrum().getValor() == email.getValor()) {
            resultado.push_back(projeto);
        }
    }
    return resultado;
}

bool CtrlServicoProjeto::existe(const Codigo& codigo) const {
    return container.existe(codigo);
}
