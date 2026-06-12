#include "Data.hpp"
#include <stdexcept>
#include <string>
#include <cctype>

static bool ehBissexto(int ano) {
    return (ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0);
}

void Data::setValor(const std::string& valor) {
    // 1. Verifica o tamanho exato da string (ex: 13/04/2026 tem 10 caracteres)
    if (valor.length() != 10) {
        throw std::invalid_argument("Data invalida: formato deve ter exatamente 10 caracteres (DD/MM/AAAA).");
    }

    // 2. Verifica se as barras estao no local correto
    if (valor[2] != '/' || valor[5] != '/') {
        throw std::invalid_argument("Data invalida: formato deve ser DD/MM/AAAA.");
    }

    // 3. Verifica se os demais caracteres sao apenas digitos
    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) continue; // Pula as barras
        if (!std::isdigit(static_cast<unsigned char>(valor[i]))) {
            throw std::invalid_argument("Data invalida: dia, mes e ano devem conter apenas numeros.");
        }
    }

    // Como já garantimos que são números, o std::stoi é 100% seguro aqui
    int dia = std::stoi(valor.substr(0, 2));
    int mes = std::stoi(valor.substr(3, 2));
    int ano = std::stoi(valor.substr(6, 4));

    // 4. Validação das Regras de Negócio (Limites)
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