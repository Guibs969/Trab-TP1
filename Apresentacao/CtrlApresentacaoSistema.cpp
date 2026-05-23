#include "CtrlApresentacaoSistema.hpp"
#include "CtrlApresentacaoPessoa.hpp"
#include "../Dominios/Codigo.hpp"
#include "../Dominios/Data.hpp"
#include "../Dominios/Nome.hpp"
#include "../Dominios/Senha.hpp"
#include "../Dominios/Papel.hpp"
#include "../Dominios/Texto.hpp"
#include "../Dominios/Tempo.hpp"
#include "../Dominios/Prioridade.hpp"
#include "../Dominios/Estado.hpp"
#include <iostream>

CtrlApresentacaoSistema::CtrlApresentacaoSistema(IServicoPessoa* servicoPessoa,
                                                IServicoProjeto* servicoProjeto,
                                                IServicoPlanoSprint* servicoPlano,
                                                IServicoHistoriaUsuario* servicoHistoria)
    : servicoPessoa(servicoPessoa), servicoProjeto(servicoProjeto), servicoPlano(servicoPlano), servicoHistoria(servicoHistoria) {
}

void CtrlApresentacaoSistema::executar() {
    while (true) {
        exibirMenu();
        std::string opcao = lerLinha("Escolha uma opcao: ");
        if (opcao == "0") {
            std::cout << "Encerrando o sistema.\n";
            break;
        }
        if (opcao == "1") {
            registrarPessoa();
        } else if (opcao == "2") {
            autenticarUsuario();
        } else if (opcao == "3") {
            cadastrarProjeto();
        } else if (opcao == "4") {
            cadastrarPlano();
        } else if (opcao == "5") {
            cadastrarHistoria();
        } else if (opcao == "6") {
            listarPessoas();
        } else if (opcao == "7") {
            listarProjetos();
        } else if (opcao == "8") {
            listarPlanos();
        } else if (opcao == "9") {
            listarHistorias();
        } else if (opcao == "10") {
            listarProjetosPorPessoa();
        } else if (opcao == "11") {
            listarHistoriasPorProjeto();
        } else if (opcao == "12") {
            listarPlanosPorProjeto();
        } else if (opcao == "13") {
            listarHistoriasPorPlano();
        } else if (opcao == "14") {
            listarHistoriasPorPessoa();
        } else if (opcao == "15") {
            atribuirHistoria();
        } else if (opcao == "16") {
            removerDesenvolvedor();
        } else if (opcao == "17") {
            alterarEstadoHistoria();
        } else if (opcao == "18") {
            atualizarPessoa();
        } else if (opcao == "19") {
            excluirPessoa();
        } else if (opcao == "20") {
            logout();
        } else {
            std::cout << "Opcao invalida. Tente novamente.\n";
        }
    }
}

void CtrlApresentacaoSistema::exibirMenu() const {
    std::cout << "\n=== Menu do Sistema ===\n";
    std::cout << "Usuario autenticado: " << (autenticado ? usuarioAtual.getValor() : "nenhum") << "\n";
    std::cout << "1 - Registrar usuario\n";
    std::cout << "2 - Autenticar usuario\n";
    std::cout << "3 - Cadastrar projeto\n";
    std::cout << "4 - Cadastrar plano de sprint\n";
    std::cout << "5 - Cadastrar historia de usuario\n";
    std::cout << "6 - Listar pessoas\n";
    std::cout << "7 - Listar projetos\n";
    std::cout << "8 - Listar planos de sprint\n";
    std::cout << "9 - Listar historias de usuario\n";
    std::cout << "10 - Listar projetos por pessoa\n";
    std::cout << "11 - Listar historias por projeto\n";
    std::cout << "12 - Listar planos por projeto\n";
    std::cout << "13 - Listar historias por plano\n";
    std::cout << "14 - Listar historias por pessoa\n";
    std::cout << "15 - Atribuir desenvolvedor a historia\n";
    std::cout << "16 - Remover desenvolvedor de historia\n";
    std::cout << "17 - Alterar estado de historia\n";
    std::cout << "18 - Atualizar pessoa\n";
    std::cout << "19 - Excluir pessoa\n";
    std::cout << "20 - Logout\n";
    std::cout << "0 - Sair\n";
}

std::string CtrlApresentacaoSistema::lerLinha(const std::string& prompt) const {
    std::cout << prompt;
    std::string linha;
    std::getline(std::cin, linha);
    return linha;
}

bool CtrlApresentacaoSistema::usuarioAutenticado() const {
    if (!autenticado) {
        std::cout << "Usuario nao autenticado. Execute a autenticacao primeiro.\n";
    }
    return autenticado;
}

void CtrlApresentacaoSistema::registrarPessoa() {
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

void CtrlApresentacaoSistema::cadastrarProjeto() {
    if (!usuarioAutenticado()) {
        return;
    }
    Pessoa usuario;
    if (!servicoPessoa->buscar(usuarioAtual, usuario)) {
        std::cout << "Usuario autenticado nao encontrado.\n";
        return;
    }
    if (usuario.getPapel().getValor() != "PROPRIETARIO DE PRODUTO") {
        std::cout << "Apenas Proprietario de Produto pode criar projeto.\n";
        return;
    }

    try {
        Codigo codigo;
        codigo.setValor(lerLinha("Codigo do projeto (2 letras + 3 digitos): "));
        Nome nome;
        nome.setValor(lerLinha("Nome do projeto: "));
        Data inicio;
        inicio.setValor(lerLinha("Data de inicio (DD/MM/AAAA): "));
        Data termino;
        termino.setValor(lerLinha("Data de termino (DD/MM/AAAA): "));
        Email mestreScrum;
        mestreScrum.setValor(lerLinha("Email do Mestre Scrum: "));

        Projeto projeto;
        projeto.setCodigo(codigo);
        projeto.setNome(nome);
        projeto.setInicio(inicio);
        projeto.setTermino(termino);
        projeto.setProprietario(usuarioAtual);
        projeto.setMestreScrum(mestreScrum);

        if (servicoProjeto->cadastrar(projeto)) {
            std::cout << "Projeto cadastrado com sucesso!\n";
        } else {
            std::cout << "Falha no cadastro de projeto. Verifique se o codigo ja existe ou se o mestre scrum esta cadastrado com o papel correto.\n";
        }
    } catch (const std::invalid_argument& erro) {
        std::cout << "Erro de validacao: " << erro.what() << "\n";
    }
}

void CtrlApresentacaoSistema::cadastrarPlano() {
    if (!usuarioAutenticado()) {
        return;
    }
    Pessoa usuario;
    if (!servicoPessoa->buscar(usuarioAtual, usuario)) {
        std::cout << "Usuario autenticado nao encontrado.\n";
        return;
    }
    if (usuario.getPapel().getValor() != "MESTRE SCRUM") {
        std::cout << "Apenas Mestre Scrum pode criar plano de sprint.\n";
        return;
    }

    try {
        Codigo codigo;
        codigo.setValor(lerLinha("Codigo do plano (2 letras + 3 digitos): "));
        Texto objetivo;
        objetivo.setValor(lerLinha("Objetivo: "));
        Tempo capacidade;
        capacidade.setValor(std::stoi(lerLinha("Capacidade (1-365): ")));
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

void CtrlApresentacaoSistema::cadastrarHistoria() {
    if (!usuarioAutenticado()) {
        return;
    }
    Pessoa usuario;
    if (!servicoPessoa->buscar(usuarioAtual, usuario)) {
        std::cout << "Usuario autenticado nao encontrado.\n";
        return;
    }
    if (usuario.getPapel().getValor() != "PROPRIETARIO DE PRODUTO") {
        std::cout << "Apenas Proprietario de Produto pode criar historia de usuario.\n";
        return;
    }

    try {
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
        estimativa.setValor(std::stoi(lerLinha("Estimativa (1-365): ")));
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

void CtrlApresentacaoSistema::listarPessoas() const {
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

void CtrlApresentacaoSistema::listarProjetos() const {
    auto projetos = servicoProjeto->listar();
    if (projetos.empty()) {
        std::cout << "Nenhum projeto cadastrado.\n";
        return;
    }
    std::cout << "PROJETOS CADASTRADOS:\n";
    for (const auto& projeto : projetos) {
        std::cout << "Codigo: " << projeto.getCodigo().getValor()
                  << " | Nome: " << projeto.getNome().getValor()
                  << " | Proprietario: " << projeto.getProprietario().getValor()
                  << " | Mestre Scrum: " << projeto.getMestreScrum().getValor() << "\n";
    }
}

void CtrlApresentacaoSistema::listarPlanos() const {
    auto planos = servicoPlano->listar();
    if (planos.empty()) {
        std::cout << "Nenhum plano de sprint cadastrado.\n";
        return;
    }
    std::cout << "PLANOS DE SPRINT CADASTRADOS:\n";
    for (const auto& plano : planos) {
        std::cout << "Codigo: " << plano.getCodigo().getValor()
                  << " | Projeto: " << plano.getCodigoProjeto().getValor()
                  << " | Capacidade: " << plano.getCapacidade().getValor()
                  << " | Objetivo: " << plano.getObjetivo().getValor() << "\n";
    }
}

void CtrlApresentacaoSistema::listarHistorias() const {
    auto historias = servicoHistoria->listar();
    if (historias.empty()) {
        std::cout << "Nenhuma historia de usuario cadastrada.\n";
        return;
    }
    std::cout << "HISTORIAS DE USUARIO CADASTRADAS:\n";
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

void CtrlApresentacaoSistema::listarProjetosPorPessoa() const {
    try {
        Email email;
        email.setValor(lerLinha("Email da pessoa: "));
        auto projetos = servicoProjeto->listarProjetosPorPessoa(email);
        if (projetos.empty()) {
            std::cout << "Nenhum projeto encontrado para esta pessoa.\n";
            return;
        }
        for (const auto& projeto : projetos) {
            std::cout << "Codigo: " << projeto.getCodigo().getValor()
                      << " | Nome: " << projeto.getNome().getValor() << "\n";
        }
    } catch (const std::invalid_argument& erro) {
        std::cout << "Erro de validacao: " << erro.what() << "\n";
    }
}

void CtrlApresentacaoSistema::listarHistoriasPorProjeto() const {
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

void CtrlApresentacaoSistema::listarPlanosPorProjeto() const {
    try {
        Codigo codigo;
        codigo.setValor(lerLinha("Codigo do projeto: "));
        auto planos = servicoPlano->listarPorProjeto(codigo);
        if (planos.empty()) {
            std::cout << "Nenhum plano encontrado para este projeto.\n";
            return;
        }
        for (const auto& plano : planos) {
            std::cout << "Codigo: " << plano.getCodigo().getValor()
                      << " | Objetivo: " << plano.getObjetivo().getValor() << "\n";
        }
    } catch (const std::invalid_argument& erro) {
        std::cout << "Erro de validacao: " << erro.what() << "\n";
    }
}

void CtrlApresentacaoSistema::listarHistoriasPorPlano() const {
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

void CtrlApresentacaoSistema::listarHistoriasPorPessoa() const {
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

void CtrlApresentacaoSistema::atribuirHistoria() {
    if (!usuarioAutenticado()) {
        return;
    }
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

void CtrlApresentacaoSistema::removerDesenvolvedor() {
    if (!usuarioAutenticado()) {
        return;
    }
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

void CtrlApresentacaoSistema::alterarEstadoHistoria() {
    if (!usuarioAutenticado()) {
        return;
    }
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

void CtrlApresentacaoSistema::atualizarPessoa() {
    if (!usuarioAutenticado()) {
        return;
    }
    try {
        Email email;
        email.setValor(lerLinha("Email da pessoa a atualizar: "));
        Pessoa pessoa;
        if (!servicoPessoa->buscar(email, pessoa)) {
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

void CtrlApresentacaoSistema::excluirPessoa() {
    if (!usuarioAutenticado()) {
        return;
    }
    try {
        Email email;
        email.setValor(lerLinha("Email da pessoa a excluir: "));
        if (servicoPessoa->excluir(email)) {
            std::cout << "Pessoa excluida com sucesso.\n";
        } else {
            std::cout << "Falha ao excluir pessoa. Verifique se o email existe.\n";
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
