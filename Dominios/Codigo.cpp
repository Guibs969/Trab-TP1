#include "Codigo.hpp"
#include <cctype>

/**
 * @brief Implementação do método setValor.
 */
void Codigo::setValor(const std::string& valor) {
    if (valor.size() != 5 ||
        !isupper(valor[0]) || !isupper(valor[1]) ||
        !isdigit(valor[2]) || !isdigit(valor[3]) || !isdigit(valor[4])) {
        throw std::invalid_argument("Codigo deve ter 2 letras maiúsculas seguidas de 3 dígitos.");
    }
    this->valor = valor;
}

/**
 * @brief Implementação do método getValor.
 */
std::string Codigo::getValor() const {
    return valor;
}
