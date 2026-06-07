#include "CtrlApresentacaoPlanoSprint.hpp"
#include "../Entidades/PlanoDeSprint.hpp"
#include "../Dominios/Codigo.hpp"
#include "../Dominios/Texto.hpp"
#include "../Dominios/Tempo.hpp"
#include <iostream>
#include <stdexcept>

void CtrlApresentacaoPlanoSprint::setServicoPlano(IServicoPlanoSprint* servico) {
    servicoPlano = servico;
}

std::string CtrlApresentacaoPlanoSprint::lerLinha(const std::string& prompt) const {
    std::cout << prompt;
    std::string linha;
    std::getline(std::cin, linha);
    return linha;
}

int CtrlApresentacaoPlanoSprint::lerInteiroSeguro(const std::string& prompt) const {
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

void CtrlApresentacaoPlanoSprint::executar(const Email& usuarioAtual) {
    while (true) {
        std::cout << "\n--- SUBMENU: PLANOS DE SPRINT ---\n";
        std::cout << "1 - Cadastrar Plano de Sprint\n";
        std::cout << "2 - Listar todos os Planos\n";
        std::cout << "3 - Listar Planos por Projeto\n";
        std::cout << "0 - Voltar ao Menu Principal\n";
        std::string op = lerLinha("Escolha: ");

        if (op == "0") break;
        else if (op == "1") cadastrarPlano(usuarioAtual);
        else if (op == "2") listarPlanos();
        else if (op == "3") listarPlanosPorProjeto();
        else std::cout << "Opcao invalida.\n";
    }
}

void CtrlApresentacaoPlanoSprint::cadastrarPlano(const Email& usuarioAtual) {
    if (servicoPlano == nullptr) {
        std::cout << "Erro: Servico de plano nao configurado.\n";
        return;
    }

    try {
        std::cout << "\n--- Cadastrar Plano de Sprint ---\n";
        Codigo codigo;
        codigo.setValor(lerLinha("Codigo do plano (2 letras + 3 digitos): "));
        Texto objetivo;
        objetivo.setValor(lerLinha("Objetivo: "));
        
        Tempo capacidade;
        // Uso da validação inteira segura blindada contra caracteres
        capacidade.setValor(lerInteiroSeguro("Capacidade (1-365): "));
        
        Codigo codigoProjeto;
        codigoProjeto.setValor(lerLinha("Codigo do projeto associado: "));

        PlanoDeSprint plano;
        plano.setCodigo(codigo);
        plano.setObjetivo(objetivo);
        plano.setCapacidade(capacidade);
        plano.setCodigoProjeto(codigoProjeto);

        if (servicoPlano->cadastrar(plano)) {
            std::cout << "Plano de sprint cadastrado com sucesso!\n";
        } else {
            std::cout << "Falha no cadastro de plano. Verifique se o codigo ja existe ou se o projeto e valido.\n";
        }
    } catch (const std::invalid_argument& erro) {
        std::cout << "Erro de validacao: " << erro.what() << "\n";
    }
}

void CtrlApresentacaoPlanoSprint::listarPlanos() const {
    if (servicoPlano == nullptr) return;

    auto planos = servicoPlano->listar();
    if (planos.empty()) {
        std::cout << "Nenhum plano de sprint cadastrado.\n";
        return;
    }
    std::cout << "\n--- PLANOS DE SPRINT CADASTRADOS ---\n";
    for (const auto& plano : planos) {
        std::cout << "Codigo: " << plano.getCodigo().getValor()
                  << " | Projeto: " << plano.getCodigoProjeto().getValor()
                  << " | Capacidade: " << plano.getCapacidade().getValor()
                  << " | Objetivo: " << plano.getObjetivo().getValor() << "\n";
    }
}

void CtrlApresentacaoPlanoSprint::listarPlanosPorProjeto() const {
    if (servicoPlano == nullptr) return;

    try {
        Codigo codigo;
        codigo.setValor(lerLinha("Codigo do projeto: "));
        auto planos = servicoPlano->listarPorProjeto(codigo);
        if (planos.empty()) {
            std::cout << "Nenhum plano encontrado para este projeto.\n";
            return;
        }
        std::cout << "\nPlanos associados ao projeto:\n";
        for (const auto& plano : planos) {
            std::cout << "Codigo: " << plano.getCodigo().getValor()
                      << " | Objetivo: " << plano.getObjetivo().getValor() << "\n";
        }
    } catch (const std::invalid_argument& erro) {
        std::cout << "Erro de validacao: " << erro.what() << "\n";
    }
}