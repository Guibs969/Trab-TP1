#include "CtrlApresentacaoHistoriaUsuario.hpp"
#include "../Entidades/HistoriaDeUsuario.hpp"
#include "../Dominios/Codigo.hpp"
#include "../Dominios/Texto.hpp"
#include "../Dominios/Tempo.hpp"
#include "../Dominios/Prioridade.hpp"
#include "../Dominios/Estado.hpp"
#include <iostream>
#include <stdexcept>

void CtrlApresentacaoHistoriaUsuario::setServicoHistoria(IServicoHistoriaUsuario* servico) {
    servicoHistoria = servico;
}

std::string CtrlApresentacaoHistoriaUsuario::lerLinha(const std::string& prompt) const {
    std::cout << prompt;
    std::string linha;
    std::getline(std::cin, linha);
    return linha;
}

int CtrlApresentacaoHistoriaUsuario::lerInteiroSeguro(const std::string& prompt) const {
    int valor = 0;
    while (true) {
        std::cout << prompt;
        std::string linha;
        std::getline(std::cin, linha);
        try {
            valor = std::stoi(linha);
            break;
        } catch (const std::invalid_argument&) {
            std::cout << "Erro: Entrada invalida. Digite apenas numeros inteiros.\n";
        } catch (const std::out_of_range&) {
            std::cout << "Erro: Numero muito grande. Tente novamente.\n";
        }
    }
    return valor;
}

void CtrlApresentacaoHistoriaUsuario::executar(const Email& usuarioAtual) {
    while (true) {
        std::cout << "\n--- SUBMENU: HISTORIAS DE USUARIO ---\n";
        std::cout << "1 - Cadastrar Historia de Usuario\n";
        std::cout << "2 - Listar todas as Historias\n";
        std::cout << "3 - Listar Historias por Projeto\n";
        std::cout << "4 - Listar Historias por Plano de Sprint\n";
        std::cout << "5 - Listar Historias por Desenvolvedor\n";
        std::cout << "6 - Atribuir Desenvolvedor a uma Historia\n";
        std::cout << "7 - Remover Desenvolvedor de uma Historia\n";
        std::cout << "8 - Alterar Estado de uma Historia\n";
        std::cout << "0 - Voltar ao Menu Principal\n";
        std::string op = lerLinha("Escolha: ");

        if (op == "0") break;
        else if (op == "1") cadastrarHistoria(usuarioAtual);
        else if (op == "2") listarHistorias();
        else if (op == "3") listarHistoriasPorProjeto();
        else if (op == "4") listarHistoriasPorPlano();
        else if (op == "5") listarHistoriasPorPessoa();
        else if (op == "6") atribuirHistoria();
        else if (op == "7") removerDesenvolvedor();
        else if (op == "8") alterarEstadoHistoria();
        else std::cout << "Opcao invalida.\n";
    }
}

void CtrlApresentacaoHistoriaUsuario::cadastrarHistoria(const Email& usuarioAtual) {
    if (servicoHistoria == nullptr) return;

    try {
        std::cout << "\n--- Cadastrar Historia de Usuario ---\n";
        Codigo codigo;
        codigo.setValor(lerLinha("Codigo da historia (2 letras + 3 digitos): "));
        Texto titulo;
        titulo.setValor(lerLinha("Titulo: "));
        Texto papel;
        papel.setValor(lerLinha("Papel da historia: "));
        Texto acao;
        acao.setValor(lerLinha("Acao: "));
        Texto valor;
        valor.setValor(lerLinha("Valor: "));
        
        Tempo estimativa;
        // Uso da validação inteira segura
        estimativa.setValor(lerInteiroSeguro("Estimativa (1-365): "));
        
        Prioridade prioridade;
        prioridade.setValor(lerLinha("Prioridade (ALTA, MEDIA, BAIXA): "));
        Estado estado;
        estado.setValor("A FAZER");
        Codigo codigoProjeto;
        codigoProjeto.setValor(lerLinha("Codigo do projeto associado: "));

        HistoriaDeUsuario historia;
        historia.setCodigo(codigo);
        historia.setTitulo(titulo);
        historia.setPapel(papel);
        historia.setAcao(acao);
        historia.setValor(valor);
        historia.setEstimativa(estimativa);
        historia.setPrioridade(prioridade);
        historia.setEstado(estado);
        historia.setCodigoProjeto(codigoProjeto);

        if (servicoHistoria->cadastrar(historia)) {
            std::cout << "Historia de usuario cadastrada com sucesso!\n";
        } else {
            std::cout << "Falha no cadastro de historia. Verifique se o codigo ja existe e se o projeto e valido.\n";
        }
    } catch (const std::invalid_argument& erro) {
        std::cout << "Erro de validacao: " << erro.what() << "\n";
    }
}

void CtrlApresentacaoHistoriaUsuario::listarHistorias() const {
    if (servicoHistoria == nullptr) return;

    auto historias = servicoHistoria->listar();
    if (historias.empty()) {
        std::cout << "Nenhuma historia de usuario cadastrada.\n";
        return;
    }
    std::cout << "\n--- HISTORIAS CADASTRADAS ---\n";
    for (const auto& historia : historias) {
        std::cout << "Codigo: " << historia.getCodigo().getValor()
                  << " | Projeto: " << historia.getCodigoProjeto().getValor()
                  << " | Titulo: " << historia.getTitulo().getValor()
                  << " | Estado: " << historia.getEstado().getValor();
        if (historia.possuiDesenvolvedor()) {
            std::cout << " | Desenvolvedor: " << historia.getDesenvolvedor().getValor();
        }
        std::cout << "\n";
    }
}

void CtrlApresentacaoHistoriaUsuario::listarHistoriasPorProjeto() const {
    if (servicoHistoria == nullptr) return;
    try {
        Codigo codigo;
        codigo.setValor(lerLinha("Codigo do projeto: "));
        auto historias = servicoHistoria->listarPorProjeto(codigo);
        if (historias.empty()) {
            std::cout << "Nenhuma historia encontrada para este projeto.\n";
            return;
        }
        for (const auto& historia : historias) {
            std::cout << "Codigo: " << historia.getCodigo().getValor()
                      << " | Titulo: " << historia.getTitulo().getValor() << "\n";
        }
    } catch (const std::invalid_argument& erro) {
        std::cout << "Erro de validacao: " << erro.what() << "\n";
    }
}

void CtrlApresentacaoHistoriaUsuario::listarHistoriasPorPlano() const {
    if (servicoHistoria == nullptr) return;
    try {
        Codigo codigo;
        codigo.setValor(lerLinha("Codigo do plano: "));
        auto historias = servicoHistoria->listarPorPlano(codigo);
        if (historias.empty()) {
            std::cout << "Nenhuma historia associada a este plano.\n";
            return;
        }
        for (const auto& historia : historias) {
            std::cout << "Codigo: " << historia.getCodigo().getValor()
                      << " | Titulo: " << historia.getTitulo().getValor() << "\n";
        }
    } catch (const std::invalid_argument& erro) {
        std::cout << "Erro de validacao: " << erro.what() << "\n";
    }
}

void CtrlApresentacaoHistoriaUsuario::listarHistoriasPorPessoa() const {
    if (servicoHistoria == nullptr) return;
    try {
        Email email;
        email.setValor(lerLinha("Email do desenvolvedor: "));
        auto historias = servicoHistoria->listarPorPessoa(email);
        if (historias.empty()) {
            std::cout << "Nenhuma historia associada a esta pessoa.\n";
            return;
        }
        for (const auto& historia : historias) {
            std::cout << "Codigo: " << historia.getCodigo().getValor()
                      << " | Titulo: " << historia.getTitulo().getValor() << "\n";
        }
    } catch (const std::invalid_argument& erro) {
        std::cout << "Erro de validacao: " << erro.what() << "\n";
    }
}

void CtrlApresentacaoHistoriaUsuario::atribuirHistoria() {
    if (servicoHistoria == nullptr) return;
    try {
        Codigo codigoHistoria;
        codigoHistoria.setValor(lerLinha("Codigo da historia: "));
        Email email;
        email.setValor(lerLinha("Email do desenvolvedor: "));

        if (servicoHistoria->atribuirDesenvolvedor(codigoHistoria, email)) {
            std::cout << "Desenvolvedor atribuido com sucesso.\n";
        } else {
            std::cout << "Falha ao atribuir desenvolvedor. Verifique codigo da historia e papel do usuario.\n";
        }
    } catch (const std::invalid_argument& erro) {
        std::cout << "Erro de validacao: " << erro.what() << "\n";
    }
}

void CtrlApresentacaoHistoriaUsuario::removerDesenvolvedor() {
    if (servicoHistoria == nullptr) return;
    try {
        Codigo codigoHistoria;
        codigoHistoria.setValor(lerLinha("Codigo da historia: "));
        if (servicoHistoria->removerDesenvolvedor(codigoHistoria)) {
            std::cout << "Desenvolvedor removido com sucesso.\n";
        } else {
            std::cout << "Falha ao remover desenvolvedor. Verifique o codigo da historia.\n";
        }
    } catch (const std::invalid_argument& erro) {
        std::cout << "Erro de validacao: " << erro.what() << "\n";
    }
}

void CtrlApresentacaoHistoriaUsuario::alterarEstadoHistoria() {
    if (servicoHistoria == nullptr) return;
    try {
        Codigo codigoHistoria;
        codigoHistoria.setValor(lerLinha("Codigo da historia: "));
        Estado estado;
        estado.setValor(lerLinha("Novo estado (A FAZER, FAZENDO, FEITO): "));

        if (servicoHistoria->alterarEstado(codigoHistoria, estado)) {
            std::cout << "Estado alterado com sucesso.\n";
        } else {
            std::cout << "Falha ao alterar estado. Verifique o codigo da historia.\n";
        }
    } catch (const std::invalid_argument& erro) {
        std::cout << "Erro de validacao: " << erro.what() << "\n";
    }
}