#include "Senha.hpp"
#include <cctype>

static bool ehLetra(char c) {
    return std::isalpha(static_cast<unsigned char>(c));
}

static bool ehDigito(char c) {
    return std::isdigit(static_cast<unsigned char>(c));
}

static bool ehMinuscula(char c) {
    return std::islower(static_cast<unsigned char>(c));
}

static bool ehMaiuscula(char c) {
    return std::isupper(static_cast<unsigned char>(c));
}

void Senha::setValor(const std::string& valor) {
    if (valor.size() != 6) {
        throw std::invalid_argument("Senha invalida: deve ter exatamente 6 caracteres.");
    }

    bool temMinuscula = false;
    bool temMaiuscula = false;
    bool temDigito = false;

    for (size_t i = 0; i < valor.size(); ++i) {
        char c = valor[i];
        if (!ehLetra(c) && !ehDigito(c)) {
            throw std::invalid_argument("Senha invalida: apenas letras e digitos sao permitidos.");
        }
        if (ehMinuscula(c)) {
            temMinuscula = true;
        }
        if (ehMaiuscula(c)) {
            temMaiuscula = true;
        }
        if (ehDigito(c)) {
            temDigito = true;
        }
        if (i + 1 < valor.size()) {
            char proximo = valor[i + 1];
            if ((ehLetra(c) && ehLetra(proximo)) || (ehDigito(c) && ehDigito(proximo))) {
                throw std::invalid_argument("Senha invalida: letras e digitos devem alternar.");
            }
        }
    }

    if (!temMinuscula || !temMaiuscula || !temDigito) {
        throw std::invalid_argument("Senha invalida: deve conter minuscula, maiuscula e digito.");
    }

    this->valor = valor;
}

std::string Senha::getValor() const {
    return valor;
}
