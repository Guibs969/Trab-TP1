#include "HistoriaDeUsuario.hpp"

void HistoriaDeUsuario::setCodigo(const Codigo& codigo) {
    this->codigo = codigo;
}

Codigo HistoriaDeUsuario::getCodigo() const {
    return codigo;
}

void HistoriaDeUsuario::setTitulo(const Texto& titulo) {
    this->titulo = titulo;
}

Texto HistoriaDeUsuario::getTitulo() const {
    return titulo;
}

void HistoriaDeUsuario::setPapel(const Texto& papel) {
    this->papel = papel;
}

Texto HistoriaDeUsuario::getPapel() const {
    return papel;
}

void HistoriaDeUsuario::setAcao(const Texto& acao) {
    this->acao = acao;
}

Texto HistoriaDeUsuario::getAcao() const {
    return acao;
}

void HistoriaDeUsuario::setValor(const Texto& valor) {
    this->valor = valor;
}

Texto HistoriaDeUsuario::getValor() const {
    return valor;
}

void HistoriaDeUsuario::setEstimativa(const Tempo& estimativa) {
    this->estimativa = estimativa;
}

Tempo HistoriaDeUsuario::getEstimativa() const {
    return estimativa;
}

void HistoriaDeUsuario::setPrioridade(const Prioridade& prioridade) {
    this->prioridade = prioridade;
}

Prioridade HistoriaDeUsuario::getPrioridade() const {
    return prioridade;
}

void HistoriaDeUsuario::setEstado(const Estado& estado) {
    this->estado = estado;
}

Estado HistoriaDeUsuario::getEstado() const {
    return estado;
}

void HistoriaDeUsuario::setCodigoProjeto(const Codigo& codigoProjeto) {
    this->codigoProjeto = codigoProjeto;
}

Codigo HistoriaDeUsuario::getCodigoProjeto() const {
    return codigoProjeto;
}

void HistoriaDeUsuario::atribuirDesenvolvedor(const Email& desenvolvedor) {
    this->desenvolvedor = desenvolvedor;
    temDesenvolvedor = true;
}

void HistoriaDeUsuario::removerDesenvolvedor() {
    temDesenvolvedor = false;
}

bool HistoriaDeUsuario::possuiDesenvolvedor() const {
    return temDesenvolvedor;
}

Email HistoriaDeUsuario::getDesenvolvedor() const {
    return desenvolvedor;
}
