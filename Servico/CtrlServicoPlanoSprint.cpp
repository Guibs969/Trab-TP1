#include "CtrlServicoPlanoSprint.hpp"
#include <stdexcept>
#include <string>

static int converteDataParaDia(const std::string& data) {
    size_t primeiro = data.find('/');
    size_t segundo = data.find('/', primeiro + 1);
    int dia = std::stoi(data.substr(0, primeiro));
    int mes = std::stoi(data.substr(primeiro + 1, segundo - primeiro - 1));
    int ano = std::stoi(data.substr(segundo + 1));

    int dias = dia;
    int meses[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0)) {
        meses[1] = 29;
    }
    for (int m = 1; m < mes; ++m) {
        dias += meses[m - 1];
    }
    return dias + (ano - 2000) * 365 + ((ano - 2000 + 3) / 4) - ((ano - 2000 + 99) / 100) + ((ano - 2000 + 399) / 400);
}

static int calculaDuracaoDoProjeto(const Projeto& projeto) {
    int inicio = converteDataParaDia(projeto.getInicio().getValor());
    int termino = converteDataParaDia(projeto.getTermino().getValor());
    return termino - inicio + 1;
}

CtrlServicoPlanoSprint::CtrlServicoPlanoSprint(const IServicoProjeto* servicoProjeto)
    : servicoProjeto(servicoProjeto) {
}

bool CtrlServicoPlanoSprint::cadastrar(const PlanoDeSprint& plano) {
    if (container.existe(plano.getCodigo())) {
        return false;
    }
    if (servicoProjeto == nullptr) {
        return false;
    }

    Projeto projeto;
    if (!servicoProjeto->buscar(plano.getCodigoProjeto(), projeto)) {
        return false;
    }

    int duracao = calculaDuracaoDoProjeto(projeto);
    int somaCapacidades = 0;
    for (const auto& existente : listarPorProjeto(projeto.getCodigo())) {
        somaCapacidades += existente.getCapacidade().getValor();
    }

    if (somaCapacidades + plano.getCapacidade().getValor() > duracao) {
        return false;
    }

    return container.inserir(plano);
}

bool CtrlServicoPlanoSprint::atualizar(const PlanoDeSprint& plano) {
    if (!container.existe(plano.getCodigo())) {
        return false;
    }
    return container.atualizar(plano);
}

bool CtrlServicoPlanoSprint::excluir(const Codigo& codigo) {
    return container.remover(codigo);
}

bool CtrlServicoPlanoSprint::buscar(const Codigo& codigo, PlanoDeSprint& plano) const {
    return container.buscar(codigo, plano);
}

std::vector<PlanoDeSprint> CtrlServicoPlanoSprint::listar() const {
    return container.listar();
}

std::vector<PlanoDeSprint> CtrlServicoPlanoSprint::listarPorProjeto(const Codigo& codigoProjeto) const {
    std::vector<PlanoDeSprint> resultado;
    for (const auto& plano : container.listar()) {
        if (plano.getCodigoProjeto().getValor() == codigoProjeto.getValor()) {
            resultado.push_back(plano);
        }
    }
    return resultado;
}

bool CtrlServicoPlanoSprint::existe(const Codigo& codigo) const {
    return container.existe(codigo);
}
