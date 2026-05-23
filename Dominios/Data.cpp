#include "Data.hpp"
#include <stdexcept>
#include <string>

static bool ehBissexto(int ano) {
    return (ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0);
}

void Data::setValor(const std::string& valor) {
    size_t primeiro = valor.find('/');
    size_t segundo = valor.find('/', primeiro == std::string::npos ? std::string::npos : primeiro + 1);
    if (primeiro == std::string::npos || segundo == std::string::npos) {
        throw std::invalid_argument("Data invalida: formato deve ser DD/MM/AAAA.");
    }

    std::string diaStr = valor.substr(0, primeiro);
    std::string mesStr = valor.substr(primeiro + 1, segundo - primeiro - 1);
    std::string anoStr = valor.substr(segundo + 1);

    if (diaStr.empty() || mesStr.empty() || anoStr.empty()) {
        throw std::invalid_argument("Data invalida: dia, mes e ano sao obrigatorios.");
    }

    int dia = std::stoi(diaStr);
    int mes = std::stoi(mesStr);
    int ano = std::stoi(anoStr);

    if (ano < 2000 || ano > 2999) {
        throw std::invalid_argument("Data invalida: ano deve estar entre 2000 e 2999.");
    }
    if (mes < 1 || mes > 12) {
        throw std::invalid_argument("Data invalida: mes deve estar entre 01 e 12.");
    }

    int maxDia = 31;
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        maxDia = 30;
    } else if (mes == 2) {
        maxDia = ehBissexto(ano) ? 29 : 28;
    }

    if (dia < 1 || dia > maxDia) {
        throw std::invalid_argument("Data invalida: dia fora do intervalo para o mes informado.");
    }

    this->valor = valor;
}

std::string Data::getValor() const {
    return valor;
}
