#include "Texto.hpp"
#include <cctype>

void Texto::setValor(const std::string& valor) {
    if (valor.empty() || valor.size() > 40) {
        throw std::invalid_argument("Texto invalido: tamanho deve ser entre 1 e 40 caracteres.");
    }
    if (valor.front() == ' ' || valor.front() == ',' || valor.front() == '.' ||
        valor.back() == ' ' || valor.back() == ',' || valor.back() == '.') {
        throw std::invalid_argument("Texto invalido: nao pode iniciar ou terminar com espaco, virgula ou ponto.");
    }

    for (size_t i = 0; i < valor.size(); ++i) {
        char c = valor[i];
        if (std::isalpha(static_cast<unsigned char>(c)) || std::isdigit(static_cast<unsigned char>(c))) {
            continue;
        }
        if (c == ',' || c == '.' || c == ' ') {
            if (i + 1 >= valor.size()) {
                continue;
            }
            char proximo = valor[i + 1];
            if (c == ',' || c == '.') {
                if (proximo == ',' || proximo == '.' ) {
                    throw std::invalid_argument("Texto invalido: virgula e ponto nao podem ser seguidos por virgula ou ponto.");
                }
            }
            if (c == ' ') {
                if (!std::isalpha(static_cast<unsigned char>(proximo)) && !std::isdigit(static_cast<unsigned char>(proximo))) {
                    throw std::invalid_argument("Texto invalido: espaco deve ser seguido por letra ou digito.");
                }
            }
            continue;
        }
        throw std::invalid_argument("Texto invalido: caracteres permitidos sao letras, digitos, virgula, ponto e espaco.");
    }
    this->valor = valor;
}

std::string Texto::getValor() const {
    return valor;
}
