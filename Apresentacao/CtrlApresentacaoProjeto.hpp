#ifndef CTRLAPRESENTACAOPROJETO_HPP
#define CTRLAPRESENTACAOPROJETO_HPP

#include "../Interfaces/IServicoProjeto.hpp"
#include "../Dominios/Email.hpp"
#include <string>

class CtrlApresentacaoProjeto {
private:
    IServicoProjeto* servicoProjeto = nullptr;
    std::string lerLinha(const std::string& prompt) const;
public:
    void setServicoProjeto(IServicoProjeto* servico);
    void executar(const Email& usuarioAtual);
    void cadastrarProjeto(const Email& usuarioAtual);
    void listarProjetos() const;
    void listarProjetosPorPessoa() const;
};

#endif