#include "Papel.hpp"
#include <algorithm>
#include <cctype>

void Papel::setValor(const std::string& valor) {
    std::string upper;
    upper.reserve(valor.size());
    for (char c : valor) {
        upper.push_back(static_cast<char>(std::toupper(static_cast<unsigned char>(c))));
    }

    if (upper == "DESENVOLVEDOR" || upper == "MESTRE SCRUM" || upper == "PROPRIETARIO DE PRODUTO") {
        this->valor = upper;
        return;
    }

    throw std::invalid_argument("Papel invalido: deve ser DESENVOLVEDOR, MESTRE SCRUM ou PROPRIETARIO DE PRODUTO.");
}

std::string Papel::getValor() const {
    return valor;
}
