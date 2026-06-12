#include "Papel.hpp"
#include <stdexcept>

void Papel::setValor(const std::string& valor) {
    if (valor != "DESENVOLVEDOR" && 
        valor != "MESTRE SCRUM" && 
        valor != "PROPRIETARIO DE PRODUTO") {
        
        throw std::invalid_argument("Papel invalido: deve ser exatamente 'DESENVOLVEDOR', 'MESTRE SCRUM' ou 'PROPRIETARIO DE PRODUTO' (tudo em letras maiusculas).");
    }

    this->valor = valor;
}

std::string Papel::getValor() const {
    return valor;
}