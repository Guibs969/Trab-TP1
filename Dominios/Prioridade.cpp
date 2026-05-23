#include "Prioridade.hpp"
#include <algorithm>

void Prioridade::setValor(const std::string& valor) {
    std::string upper;
    upper.reserve(valor.size());
    for (char c : valor) {
        upper.push_back(static_cast<char>(std::toupper(static_cast<unsigned char>(c))));
    }

    if (upper == "ALTA" || upper == "MEDIA" || upper == "BAIXA") {
        this->valor = upper;
        return;
    }
    throw std::invalid_argument("Prioridade invalida: deve ser ALTA, MEDIA ou BAIXA.");
}

std::string Prioridade::getValor() const {
    return valor;
}
