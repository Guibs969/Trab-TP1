#include "Codigo.hpp"
#include <cctype>

/**
 * @brief Implementacao do metodo setValor.
 */
void Codigo::setValor(const std::string& valor) {
    if (valor.size() != 5 ||
        !isupper(valor[0]) || !isupper(valor[1]) ||
        !isdigit(valor[2]) || !isdigit(valor[3]) || !isdigit(valor[4])) {
        throw std::invalid_argument("Codigo deve ter 2 letras maiusculas seguidas de 3 digitos.");
    }
    this->valor = valor;
}

/**
 * @brief Implementacao do metodo getValor.
 */
std::string Codigo::getValor() const {
    return valor;
}
