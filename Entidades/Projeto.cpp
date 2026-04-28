#include "Projeto.hpp"

/**
 * @brief Implementação dos métodos de Projeto.
 */
void Projeto::setCodigo(const Codigo& codigo) {
    this->codigo = codigo;
}

Codigo Projeto::getCodigo() const {
    return codigo;
}

void Projeto::setNome(const std::string& nome) {
    this->nome = nome;
}

std::string Projeto::getNome() const {
    return nome;
}

void Projeto::setInicio(const std::string& inicio) {
    this->inicio = inicio;
}

std::string Projeto::getInicio() const {
    return inicio;
}

void Projeto::setTermino(const std::string& termino) {
    this->termino = termino;
}

std::string Projeto::getTermino() const {
    return termino;
}
