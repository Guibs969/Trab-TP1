#include "CtrlApresentacaoProjeto.hpp"
#include "../Entidades/Projeto.hpp"
#include "../Dominios/Codigo.hpp"
#include "../Dominios/Nome.hpp"
#include "../Dominios/Data.hpp"
#include "../Dominios/Email.hpp"
#include <iostream>
#include <stdexcept>

void CtrlApresentacaoProjeto::setServicoProjeto(IServicoProjeto* servico) {
    servicoProjeto = servico;
}

std::string CtrlApresentacaoProjeto::lerLinha(const std::string& prompt) const {
    std::cout << prompt;
    std::string linha;
    std::getline(std::cin, linha);
    return linha;
}

void CtrlApresentacaoProjeto::executar(const Email& usuarioAtual) {
    while (true) {
        std::cout << "\n--- SUBMENU: PROJETOS ---\n";
        std::cout << "1 - Cadastrar Projeto\n";
        std::cout << "2 - Listar todos os Projetos\n";
        std::cout << "3 - Listar Projetos por Pessoa\n";
        std::cout << "0 - Voltar\n";
        std::string op = lerLinha("Escolha: ");

        if (op == "0") break;
        else if (op == "1") cadastrarProjeto(usuarioAtual);
        else if (op == "2") listarProjetos();
        else if (op == "3") listarProjetosPorPessoa();
        else std::cout << "Opcao invalida.\n";
    }
}

void CtrlApresentacaoProjeto::cadastrarProjeto(const Email& usuarioAtual) {
    if (servicoProjeto == nullptr) {
        std::cout << "Erro: Servico de projeto nao configurado.\n";
        return;
    }

    try {
        std::cout << "\n--- Cadastrar Novo Projeto ---\n";
        Codigo codigo;
        codigo.setValor(lerLinha("Codigo do projeto (2 letras + 3 digitos): "));
        Nome nome;
        nome.setValor(lerLinha("Nome do projeto: "));
        Data inicio;
        inicio.setValor(lerLinha("Data de inicio (DD/MM/AAAA): "));
        Data termino;
        termino.setValor(lerLinha("Data de termino (DD/MM/AAAA): "));

        Projeto projeto;
        projeto.setCodigo(codigo);
        projeto.setNome(nome);
        projeto.setInicio(inicio);
        projeto.setTermino(termino);
        
        // O proprietario do projeto e automaticamente quem esta logado criando o projeto
        projeto.setProprietario(usuarioAtual);
        // Nao pergunta o email do Mestre Scrum para simplificar
        // Se necessario, pode ser atribuido depois por outro fluxo

        if (servicoProjeto->cadastrar(projeto)) {
            std::cout << "Projeto cadastrado com sucesso!\n";
        } else {
            std::cout << "Falha no cadastro de projeto. Verifique se o codigo ja existe ou se o proprietario/mestre scrum estao cadastrados corretamente.\n";
        }
    } catch (const std::invalid_argument& erro) {
        std::cout << "Erro de validacao: " << erro.what() << "\n";
    }
}

void CtrlApresentacaoProjeto::listarProjetos() const {
    if (servicoProjeto == nullptr) {
        std::cout << "Erro: Servico de projeto nao configurado.\n";
        return;
    }

    auto projetos = servicoProjeto->listar();
    if (projetos.empty()) {
        std::cout << "Nenhum projeto cadastrado no sistema.\n";
        return;
    }
    
    std::cout << "\n--- PROJETOS CADASTRADOS ---\n";
    for (const auto& projeto : projetos) {
        std::string mestre = projeto.getMestreScrum().getValor();
        if (mestre.empty()) {
            mestre = "Nenhum";
        }
        std::cout << "Codigo: " << projeto.getCodigo().getValor()
                  << " | Nome: " << projeto.getNome().getValor()
                  << " | Proprietario: " << projeto.getProprietario().getValor()
                  << " | Mestre Scrum: " << mestre << "\n";
    }
}

void CtrlApresentacaoProjeto::listarProjetosPorPessoa() const {
    if (servicoProjeto == nullptr) {
        std::cout << "Erro: Servico de projeto nao configurado.\n";
        return;
    }

    try {
        std::cout << "\n--- Buscar Projetos por Pessoa ---\n";
        Email email;
        email.setValor(lerLinha("Email da pessoa: "));
        
        auto projetos = servicoProjeto->listarProjetosPorPessoa(email);
        if (projetos.empty()) {
            std::cout << "Nenhum projeto encontrado associado a este email (como Proprietario ou Mestre Scrum).\n";
            return;
        }
        
        std::cout << "\nProjetos encontrados:\n";
        for (const auto& projeto : projetos) {
            std::cout << "Codigo: " << projeto.getCodigo().getValor()
                      << " | Nome: " << projeto.getNome().getValor() << "\n";
        }
    } catch (const std::invalid_argument& erro) {
        std::cout << "Erro de validacao: " << erro.what() << "\n";
    }
}