#include "Senha.hpp"

void Senha::setValor(const std::string& valor) {
    // Removida validacao restritiva: agora aceita qualquer valor
    this->valor = valor;
}

std::string Senha::getValor() const {
    return valor;
}
