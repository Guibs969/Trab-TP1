#include "Tempo.hpp"

void Tempo::setValor(int valor) {
    if (valor < 1 || valor > 365) {
        throw std::invalid_argument("Tempo invalido: deve ser entre 1 e 365.");
    }
    this->valor = valor;
}

int Tempo::getValor() const {
    return valor;
}
