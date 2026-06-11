#include "Email.hpp"


void Email::setValor(const std::string& valor) {
    if (valor.empty()) {
        throw std::invalid_argument("Email invalido: nao pode ser vazio.");
    }
    this->valor = valor;
}

std::string Email::getValor() const {
    return valor;
}
