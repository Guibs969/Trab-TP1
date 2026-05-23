#include "ContainerHistoriaUsuario.hpp"

bool ContainerHistoriaUsuario::existe(const Codigo& codigo) const {
    for (const auto& historia : historias) {
        if (historia.getCodigo().getValor() == codigo.getValor()) {
            return true;
        }
    }
    return false;
}

bool ContainerHistoriaUsuario::inserir(const HistoriaDeUsuario& historia) {
    if (existe(historia.getCodigo())) {
        return false;
    }
    historias.push_back(historia);
    return true;
}

bool ContainerHistoriaUsuario::atualizar(const HistoriaDeUsuario& historia) {
    for (auto& existente : historias) {
        if (existente.getCodigo().getValor() == historia.getCodigo().getValor()) {
            existente = historia;
            return true;
        }
    }
    return false;
}

bool ContainerHistoriaUsuario::remover(const Codigo& codigo) {
    for (auto it = historias.begin(); it != historias.end(); ++it) {
        if (it->getCodigo().getValor() == codigo.getValor()) {
            historias.erase(it);
            return true;
        }
    }
    return false;
}

bool ContainerHistoriaUsuario::buscar(const Codigo& codigo, HistoriaDeUsuario& historia) const {
    for (const auto& existente : historias) {
        if (existente.getCodigo().getValor() == codigo.getValor()) {
            historia = existente;
            return true;
        }
    }
    return false;
}

std::vector<HistoriaDeUsuario> ContainerHistoriaUsuario::listar() const {
    return historias;
}
