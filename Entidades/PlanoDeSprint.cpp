#include "PlanoDeSprint.hpp"

void PlanoDeSprint::setCodigo(const Codigo& codigo) {
    this->codigo = codigo;
}

Codigo PlanoDeSprint::getCodigo() const {
    return codigo;
}

void PlanoDeSprint::setObjetivo(const Texto& objetivo) {
    this->objetivo = objetivo;
}

Texto PlanoDeSprint::getObjetivo() const {
    return objetivo;
}

void PlanoDeSprint::setCapacidade(const Tempo& capacidade) {
    this->capacidade = capacidade;
}

Tempo PlanoDeSprint::getCapacidade() const {
    return capacidade;
}

void PlanoDeSprint::setCodigoProjeto(const Codigo& codigoProjeto) {
    this->codigoProjeto = codigoProjeto;
}

Codigo PlanoDeSprint::getCodigoProjeto() const {
    return codigoProjeto;
}

bool PlanoDeSprint::adicionarHistoria(const Codigo& codigoHistoria) {
    for (const auto& existente : historias) {
        if (existente.getValor() == codigoHistoria.getValor()) {
            return false;
        }
    }
    historias.push_back(codigoHistoria);
    return true;
}

bool PlanoDeSprint::removerHistoria(const Codigo& codigoHistoria) {
    for (auto it = historias.begin(); it != historias.end(); ++it) {
        if (it->getValor() == codigoHistoria.getValor()) {
            historias.erase(it);
            return true;
        }
    }
    return false;
}

std::vector<Codigo> PlanoDeSprint::getHistorias() const {
    return historias;
}
