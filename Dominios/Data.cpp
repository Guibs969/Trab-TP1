#include "Data.hpp"
#include <stdexcept>
#include <string>

void Data::setValor(const std::string& valor) {
    if (valor.empty()) {
        throw std::invalid_argument("Data invalida: nao pode ser vazia.");
    }
    this->valor = valor;
}

std::string Data::getValor() const {
    return valor;
}
