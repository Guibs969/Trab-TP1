#include "Papel.hpp"
#include <algorithm>
#include <cctype>

void Papel::setValor(const std::string& valor) {
    if (valor.empty()) {
        throw std::invalid_argument("Papel invalido: nao pode ser vazio.");
    }
    this->valor = valor;
}

std::string Papel::getValor() const {
    return valor;
}
