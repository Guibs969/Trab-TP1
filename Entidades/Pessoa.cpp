#include "Pessoa.hpp"

/**
 * @brief Implementação dos métodos de Pessoa.
 */
void Pessoa::setNome(const std::string& nome) {
    this->nome = nome;
}

std::string Pessoa::getNome() const {
    return nome;
}

void Pessoa::setEmail(const std::string& email) {
    this->email = email;
}

std::string Pessoa::getEmail() const {
    return email;
}
