#include "CtrlServicoHistoriaUsuario.hpp"
#include <algorithm>

CtrlServicoHistoriaUsuario::CtrlServicoHistoriaUsuario(const IServicoProjeto* servicoProjeto,
                                                     IServicoPlanoSprint* servicoPlano,
                                                     IServicoPessoa* servicoPessoa)
    : servicoProjeto(servicoProjeto), servicoPlano(servicoPlano), servicoPessoa(servicoPessoa) {
}

bool CtrlServicoHistoriaUsuario::cadastrar(const HistoriaDeUsuario& historia) {
    if (container.existe(historia.getCodigo())) {
        return false;
    }
    if (servicoProjeto == nullptr) {
        return false;
    }

    Projeto projeto;
    if (!servicoProjeto->buscar(historia.getCodigoProjeto(), projeto)) {
        return false;
    }

    if (historia.getEstado().getValor() != "A FAZER") {
        return false;
    }

    if (historia.possuiDesenvolvedor()) {
        Pessoa desenvolvedor;
        if (!servicoPessoa->buscar(historia.getDesenvolvedor(), desenvolvedor)) {
            return false;
        }
        if (desenvolvedor.getPapel().getValor() != "DESENVOLVEDOR") {
            return false;
        }
    }

    return container.inserir(historia);
}

bool CtrlServicoHistoriaUsuario::atualizar(const HistoriaDeUsuario& historia) {
    if (!container.existe(historia.getCodigo())) {
        return false;
    }
    return container.atualizar(historia);
}

bool CtrlServicoHistoriaUsuario::excluir(const Codigo& codigo) {
    if (!container.existe(codigo)) {
        return false;
    }
    if (servicoPlano != nullptr) {
        for (auto& plano : servicoPlano->listar()) {
            if (plano.removerHistoria(codigo)) {
                servicoPlano->atualizar(plano);
            }
        }
    }
    return container.remover(codigo);
}

bool CtrlServicoHistoriaUsuario::buscar(const Codigo& codigo, HistoriaDeUsuario& historia) const {
    return container.buscar(codigo, historia);
}

std::vector<HistoriaDeUsuario> CtrlServicoHistoriaUsuario::listar() const {
    return container.listar();
}

std::vector<HistoriaDeUsuario> CtrlServicoHistoriaUsuario::listarPorProjeto(const Codigo& codigoProjeto) const {
    std::vector<HistoriaDeUsuario> resultado;
    for (const auto& historia : container.listar()) {
        if (historia.getCodigoProjeto().getValor() == codigoProjeto.getValor()) {
            resultado.push_back(historia);
        }
    }
    return resultado;
}

std::vector<HistoriaDeUsuario> CtrlServicoHistoriaUsuario::listarPorPlano(const Codigo& codigoPlano) const {
    std::vector<HistoriaDeUsuario> resultado;
    if (servicoPlano == nullptr) {
        return resultado;
    }
    PlanoDeSprint plano;
    if (!servicoPlano->buscar(codigoPlano, plano)) {
        return resultado;
    }
    for (const auto& codigoHistoria : plano.getHistorias()) {
        HistoriaDeUsuario historia;
        if (container.buscar(codigoHistoria, historia)) {
            resultado.push_back(historia);
        }
    }
    return resultado;
}

std::vector<HistoriaDeUsuario> CtrlServicoHistoriaUsuario::listarPorPessoa(const Email& email) const {
    std::vector<HistoriaDeUsuario> resultado;
    for (const auto& historia : container.listar()) {
        if (historia.possuiDesenvolvedor() && historia.getDesenvolvedor().getValor() == email.getValor()) {
            resultado.push_back(historia);
        }
    }
    return resultado;
}

bool CtrlServicoHistoriaUsuario::existe(const Codigo& codigo) const {
    return container.existe(codigo);
}

bool CtrlServicoHistoriaUsuario::atribuirDesenvolvedor(const Codigo& codigoHistoria, const Email& email) {
    HistoriaDeUsuario historia;
    if (!container.buscar(codigoHistoria, historia)) {
        return false;
    }
    if (servicoPessoa == nullptr) {
        return false;
    }
    Pessoa desenvolvedor;
    if (!servicoPessoa->buscar(email, desenvolvedor)) {
        return false;
    }
    if (desenvolvedor.getPapel().getValor() != "DESENVOLVEDOR") {
        return false;
    }
    historia.atribuirDesenvolvedor(email);
    return container.atualizar(historia);
}

bool CtrlServicoHistoriaUsuario::removerDesenvolvedor(const Codigo& codigoHistoria) {
    HistoriaDeUsuario historia;
    if (!container.buscar(codigoHistoria, historia)) {
        return false;
    }
    if (!historia.possuiDesenvolvedor()) {
        return false;
    }
    historia.removerDesenvolvedor();
    return container.atualizar(historia);
}

bool CtrlServicoHistoriaUsuario::alterarEstado(const Codigo& codigoHistoria, const Estado& estado) {
    HistoriaDeUsuario historia;
    if (!container.buscar(codigoHistoria, historia)) {
        return false;
    }
    historia.setEstado(estado);
    return container.atualizar(historia);
}
