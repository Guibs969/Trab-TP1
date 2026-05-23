#include "Email.hpp"
#include <algorithm>
#include <cctype>

static bool ehLetraOuDigito(char c) {
    return std::isalpha(static_cast<unsigned char>(c)) || std::isdigit(static_cast<unsigned char>(c));
}

static bool ehLocalValido(const std::string& local) {
    if (local.empty() || local.size() > 64) {
        return false;
    }
    if (local.front() == '.' || local.front() == '-' || local.back() == '.' || local.back() == '-') {
        return false;
    }
    for (size_t i = 0; i < local.size(); ++i) {
        char c = local[i];
        if (std::islower(static_cast<unsigned char>(c)) || std::isdigit(static_cast<unsigned char>(c))) {
            continue;
        }
        if (c == '.' || c == '-') {
            if (i + 1 >= local.size()) {
                return false;
            }
            char next = local[i + 1];
            if (!ehLetraOuDigito(next)) {
                return false;
            }
            continue;
        }
        return false;
    }
    return true;
}

static bool ehParteDominioValida(const std::string& parte) {
    if (parte.empty() || parte.size() > 63) {
        return false;
    }
    if (parte.front() == '-' || parte.back() == '-') {
        return false;
    }
    for (char c : parte) {
        if (std::islower(static_cast<unsigned char>(c)) || std::isdigit(static_cast<unsigned char>(c))) {
            continue;
        }
        if (c == '-') {
            continue;
        }
        return false;
    }
    return true;
}

void Email::setValor(const std::string& valor) {
    auto posArroba = valor.find('@');
    if (posArroba == std::string::npos || valor.find('@', posArroba + 1) != std::string::npos) {
        throw std::invalid_argument("Email invalido: formato deve conter exatamente um @.");
    }

    std::string local = valor.substr(0, posArroba);
    std::string dominio = valor.substr(posArroba + 1);
    if (!ehLocalValido(local)) {
        throw std::invalid_argument("Email invalido: parte local com formato incorreto.");
    }

    if (dominio.empty() || dominio.size() > 255) {
        throw std::invalid_argument("Email invalido: dominio vazio ou muito longo.");
    }

    size_t inicio = 0;
    bool dominioValido = false;
    while (inicio < dominio.size()) {
        size_t fim = dominio.find('.', inicio);
        if (fim == std::string::npos) {
            fim = dominio.size();
        }
        std::string parte = dominio.substr(inicio, fim - inicio);
        if (!ehParteDominioValida(parte)) {
            throw std::invalid_argument("Email invalido: parte do dominio com formato incorreto.");
        }
        dominioValido = true;
        inicio = fim + 1;
    }

    if (!dominioValido) {
        throw std::invalid_argument("Email invalido: dominio invalido.");
    }

    this->valor = valor;
}

std::string Email::getValor() const {
    return valor;
}
