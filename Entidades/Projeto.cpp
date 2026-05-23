#include "Projeto.hpp"

void Projeto::setCodigo(const Codigo& codigo) {
    this->codigo = codigo;
}

Codigo Projeto::getCodigo() const {
    return codigo;
}

void Projeto::setNome(const Nome& nome) {
    this->nome = nome;
}

Nome Projeto::getNome() const {
    return nome;
}

void Projeto::setInicio(const Data& inicio) {
    this->inicio = inicio;
}

Data Projeto::getInicio() const {
    return inicio;
}

void Projeto::setTermino(const Data& termino) {
    this->termino = termino;
}

Data Projeto::getTermino() const {
    return termino;
}

void Projeto::setProprietario(const Email& proprietario) {
    this->proprietario = proprietario;
}

Email Projeto::getProprietario() const {
    return proprietario;
}

void Projeto::setMestreScrum(const Email& mestreScrum) {
    this->mestreScrum = mestreScrum;
}

Email Projeto::getMestreScrum() const {
    return mestreScrum;
}

bool Projeto::adicionarPlano(const Codigo& codigoPlano) {
    for (const auto& plano : planos) {
        if (plano.getValor() == codigoPlano.getValor()) {
            return false;
        }
    }
    planos.push_back(codigoPlano);
    return true;
}

bool Projeto::adicionarHistoria(const Codigo& codigoHistoria) {
    for (const auto& historia : historias) {
        if (historia.getValor() == codigoHistoria.getValor()) {
            return false;
        }
    }
    historias.push_back(codigoHistoria);
    return true;
}

std::vector<Codigo> Projeto::getPlanos() const {
    return planos;
}

std::vector<Codigo> Projeto::getHistorias() const {
    return historias;
}
