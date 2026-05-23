#include "ContainerPlanoSprint.hpp"

bool ContainerPlanoSprint::existe(const Codigo& codigo) const {
    for (const auto& plano : planos) {
        if (plano.getCodigo().getValor() == codigo.getValor()) {
            return true;
        }
    }
    return false;
}

bool ContainerPlanoSprint::inserir(const PlanoDeSprint& plano) {
    if (existe(plano.getCodigo())) {
        return false;
    }
    planos.push_back(plano);
    return true;
}

bool ContainerPlanoSprint::atualizar(const PlanoDeSprint& plano) {
    for (auto& existente : planos) {
        if (existente.getCodigo().getValor() == plano.getCodigo().getValor()) {
            existente = plano;
            return true;
        }
    }
    return false;
}

bool ContainerPlanoSprint::remover(const Codigo& codigo) {
    for (auto it = planos.begin(); it != planos.end(); ++it) {
        if (it->getCodigo().getValor() == codigo.getValor()) {
            planos.erase(it);
            return true;
        }
    }
    return false;
}

bool ContainerPlanoSprint::buscar(const Codigo& codigo, PlanoDeSprint& plano) const {
    for (const auto& existente : planos) {
        if (existente.getCodigo().getValor() == codigo.getValor()) {
            plano = existente;
            return true;
        }
    }
    return false;
}

std::vector<PlanoDeSprint> ContainerPlanoSprint::listar() const {
    return planos;
}
