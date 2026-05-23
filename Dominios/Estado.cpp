#include "Estado.hpp"
#include <algorithm>

void Estado::setValor(const std::string& valor) {
    std::string upper;
    upper.reserve(valor.size());
    for (char c : valor) {
        upper.push_back(static_cast<char>(std::toupper(static_cast<unsigned char>(c))));
    }

    if (upper == "A FAZER" || upper == "FAZENDO" || upper == "FEITO") {
        this->valor = upper;
        return;
    }
    throw std::invalid_argument("Estado invalido: deve ser A FAZER, FAZENDO ou FEITO.");
}

std::string Estado::getValor() const {
    return valor;
}
