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

std::string CtrlApresentacaoPessoa::lerLinha(const std::string& prompt) const {
    std::cout << prompt;
    std::string linha;
    std::getline(std::cin, linha);
    return linha;
}

void CtrlApresentacaoPessoa::cadastrar() {
    try {
        Nome nome;
        nome.setValor(lerLinha("Nome (ate 10 caracteres): "));
        Email email;
        email.setValor(lerLinha("Email: "));
        Senha senha;
        senha.setValor(lerLinha("Senha (6 caracteres, alternando letras e digitos): "));
        Papel papel;
        papel.setValor(lerLinha("Papel (DESENVOLVEDOR, MESTRE SCRUM, PROPRIETARIO DE PRODUTO): "));

        Pessoa pessoa;
        pessoa.setNome(nome);
        pessoa.setEmail(email);
        pessoa.setSenha(senha);
        pessoa.setPapel(papel);

        if (servicoPessoa->cadastrar(pessoa)) {
            std::cout << "Pessoa cadastrada com sucesso!\n";
        } else {
            std::cout << "Falha no cadastro: email ja cadastrado ou dados invalidos.\n";
        }
    } catch (const std::invalid_argument& erro) {
        std::cout << "Erro de validacao: " << erro.what() << "\n";
    }
}

void CtrlApresentacaoPessoa::executarLogado(const Email& usuarioAtual) {
    while (true) {
        std::cout << "\n--- SUBMENU: PESSOAS ---\n";
        std::cout << "1 - Listar pessoas cadastradas\n";
        std::cout << "2 - Atualizar meus dados\n";
        std::cout << "3 - Excluir minha conta\n";
        std::cout << "0 - Voltar ao Menu Principal\n";
        std::string op = lerLinha("Escolha: ");

        if (op == "0") break;
        else if (op == "1") listarPessoas();
        else if (op == "2") atualizarPessoa(usuarioAtual);
        else if (op == "3") excluirPessoa(usuarioAtual);
    }
}

void CtrlApresentacaoPessoa::listarPessoas() const {
    auto pessoas = servicoPessoa->listar();
    if (pessoas.empty()) {
        std::cout << "Nenhuma pessoa cadastrada.\n";
        return;
    }
    std::cout << "PESSOAS CADASTRADAS:\n";
    for (const auto& pessoa : pessoas) {
        std::cout << "Email: " << pessoa.getEmail().getValor()
                  << " | Nome: " << pessoa.getNome().getValor()
                  << " | Papel: " << pessoa.getPapel().getValor() << "\n";
    }
}

void CtrlApresentacaoPessoa::atualizarPessoa(const Email& usuarioAtual) {
    try {
        Pessoa pessoa;
        if (!servicoPessoa->buscar(usuarioAtual, pessoa)) {
            std::cout << "Pessoa nao encontrada.\n";
            return;
        }

        Nome nome;
        nome.setValor(lerLinha("Novo nome: "));
        Senha senha;
        senha.setValor(lerLinha("Nova senha: "));
        Papel papel;
        papel.setValor(lerLinha("Novo papel: "));

        pessoa.setNome(nome);
        pessoa.setSenha(senha);
        pessoa.setPapel(papel);

        if (servicoPessoa->atualizar(pessoa)) {
            std::cout << "Pessoa atualizada com sucesso.\n";
        } else {
            std::cout << "Falha ao atualizar pessoa.\n";
        }
    } catch (const std::invalid_argument& erro) {
        std::cout << "Erro de validacao: " << erro.what() << "\n";
    }
}

void CtrlApresentacaoPessoa::excluirPessoa(const Email& usuarioAtual) {
    try {
        // Como o menu diz "Excluir minha conta", removemos o prompt antigo que pedia e-mail e usamos direto o usuarioAtual
        if (servicoPessoa->excluir(usuarioAtual)) {
            std::cout << "Pessoa excluida com sucesso. Recomenda-se realizar o logout ou reiniciar a sessao.\n";
        } else {
            std::cout << "Falha ao excluir pessoa.\n";
        }
    } catch (const std::invalid_argument& erro) {
        std::cout << "Erro de validacao: " << erro.what() << "\n";
    }
}