#include "CtrlApresentacaoPessoa.hpp"
#include "../Entidades/Pessoa.hpp"
#include "../Dominios/Email.hpp"
#include "../Dominios/Nome.hpp"
#include "../Dominios/Senha.hpp"
#include "../Dominios/Papel.hpp"
#include <iostream>

void CtrlApresentacaoPessoa::setServicoPessoa(IServicoPessoa* servico) {
    servicoPessoa = servico;
}

void CtrlApresentacaoPessoa::executar() {
    if (servicoPessoa == nullptr) {
        std::cout << "Servico de pessoa nao configurado.\n";
        return;
    }

    try {
        std::cout << "=== Cadastro de Pessoa ===\n";
        Nome nome;
        Email email;
        Senha senha;
        Papel papel;
        std::string entrada;

        std::cout << "Informe o nome: ";
        std::getline(std::cin, entrada);
        nome.setValor(entrada);

        std::cout << "Informe o email: ";
        std::getline(std::cin, entrada);
        email.setValor(entrada);

        std::cout << "Informe a senha: ";
        std::getline(std::cin, entrada);
        senha.setValor(entrada);

        std::cout << "Informe o papel: ";
        std::getline(std::cin, entrada);
        papel.setValor(entrada);

        Pessoa pessoa;
        pessoa.setNome(nome);
        pessoa.setEmail(email);
        pessoa.setSenha(senha);
        pessoa.setPapel(papel);

        bool cadastrado = servicoPessoa->cadastrar(pessoa);
        if (cadastrado) {
            std::cout << "Pessoa cadastrada com sucesso!\n";
        } else {
            std::cout << "Falha no cadastro. Verifique os dados ou se o email ja existe.\n";
        }
    } catch (const std::invalid_argument& erro) {
        std::cout << "Erro de validacao: " << erro.what() << "\n";
    }
}
