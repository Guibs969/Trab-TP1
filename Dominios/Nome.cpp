#include "Nome.hpp"
#include <cctype>

void Nome::setValor(const std::string& valor) {
    if (valor.empty() || valor.size() > 10) {
        throw std::invalid_argument("Nome invalido: tamanho deve ser entre 1 e 10 caracteres.");
    }
    if (valor.front() == ' ' || valor.back() == ' ') {
        throw std::invalid_argument("Nome invalido: nao pode iniciar ou terminar com espaco.");
    }
    for (size_t i = 0; i < valor.size(); ++i) {
        char c = valor[i];
        if (std::isalpha(static_cast<unsigned char>(c))) {
            continue;
        }
        if (c == ' ') {
            if (i + 1 >= valor.size() || !std::isalpha(static_cast<unsigned char>(valor[i + 1]))) {
                throw std::invalid_argument("Nome invalido: espaco deve ser seguido por letra.");
            }
            continue;
        }
        throw std::invalid_argument("Nome invalido: caracteres permitidos sao letras e espacos.");
    }
    this->valor = valor;
}

std::string Nome::getValor() const {
    return valor;
}
