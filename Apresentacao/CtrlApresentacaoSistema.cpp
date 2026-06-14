#include "CtrlApresentacaoSistema.hpp"
#include <iostream>

CtrlApresentacaoSistema::CtrlApresentacaoSistema(IServicoPessoa* servicoPessoa,
                                                IServicoProjeto* servicoProjeto,
                                                IServicoPlanoSprint* servicoPlano,
                                                IServicoHistoriaUsuario* servicoHistoria)
    : servicoPessoa(servicoPessoa), servicoProjeto(servicoProjeto), 
      servicoPlano(servicoPlano), servicoHistoria(servicoHistoria) {
    
    // Injeta os servicos nos sub-controladores
    ctrlPessoa.setServicoPessoa(servicoPessoa);
    ctrlProjeto.setServicoProjeto(servicoProjeto);
    ctrlPlano.setServicoPlano(servicoPlano);
    ctrlHistoria.setServicoHistoria(servicoHistoria);
}

std::string CtrlApresentacaoSistema::lerLinha(const std::string& prompt) const {
    std::cout << prompt;
    std::string linha;
    std::getline(std::cin, linha);
    return linha;
}

void CtrlApresentacaoSistema::executar() {
    while (true) {
        if (!autenticado) {
            std::cout << "\n=== SISTEMA DE GESTAO AGILE ===\n";
            std::cout << "1 - Autenticar (Login)\n";
            std::cout << "2 - Cadastrar novo usuario\n";
            std::cout << "0 - Sair\n";
            std::string opcao = lerLinha("Escolha: ");

            if (opcao == "0") {
                std::cout << "Encerrando o sistema.\n";
                break;
            }
            else if (opcao == "1") autenticarUsuario();
            else if (opcao == "2") ctrlPessoa.cadastrar();
            else std::cout << "Opcao invalida.\n";
        } else {
            std::cout << "\n=== MENU PRINCIPAL ===\n";
            std::cout << "Usuario logado: " << usuarioAtual.getValor() << "\n";
            std::cout << "1 - Modulo de Projetos\n";
            std::cout << "2 - Modulo de Planos de Sprint\n";
            std::cout << "3 - Modulo de Historias de Usuario\n";
            std::cout << "4 - Modulo de Pessoas (Minha Conta / Listas)\n";
            std::cout << "8 - Logout\n";
            std::cout << "0 - Sair do Sistema\n";
            std::string opcao = lerLinha("Escolha um modulo: ");

            if (opcao == "0") {
                std::cout << "Encerrando o sistema.\n";
                break;
            }
            else if (opcao == "1") ctrlProjeto.executar(usuarioAtual);
            else if (opcao == "2") ctrlPlano.executar(usuarioAtual);
            else if (opcao == "3") ctrlHistoria.executar(usuarioAtual);
            else if (opcao == "4") ctrlPessoa.executarLogado(usuarioAtual);
            else if (opcao == "8") logout();
            else std::cout << "Opcao invalida.\n";
        }
    }
}
void CtrlApresentacaoSistema::autenticarUsuario() {
    try {
        Email email;
        email.setValor(lerLinha("Email: "));
        Senha senha;
        senha.setValor(lerLinha("Senha: "));

        if (servicoPessoa->autenticar(email, senha)) {
            autenticado = true;
            usuarioAtual = email;
            std::cout << "Autenticacao realizada com sucesso!\n";
        } else {
            std::cout << "Falha na autenticacao. Email ou senha invalidos.\n";
        }
    } catch (const std::invalid_argument& erro) {
        std::cout << "Erro de validacao: " << erro.what() << "\n";
    }
}

void CtrlApresentacaoSistema::logout() {
    autenticado = false;
    usuarioAtual = Email();
    std::cout << "Logout realizado.\n";
}