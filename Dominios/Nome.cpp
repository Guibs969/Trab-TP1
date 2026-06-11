#include "Nome.hpp"
#include <cctype>

void Nome::setValor(const std::string& valor) {
    if (valor.empty()) {
        throw std::invalid_argument("Nome invalido: nao pode ser vazio.");
    }
    this->valor = valor;
}

std::string Nome::getValor() const {
    return valor;
}
