#include "Data.hpp"

/**
 * @brief Implementação do método setValor.
 */
void Data::setValor(const std::string& valor) {
    this->valor = valor;
}

/**
 * @brief Implementação do método getValor.
 */
std::string Data::getValor() const {
    return valor;
}
