#ifndef CTRLAPRESENTACAOPESSOA_HPP
#define CTRLAPRESENTACAOPESSOA_HPP

#include "../Interfaces/IServicoPessoa.hpp"
#include <string>

class CtrlApresentacaoPessoa {
private:
    IServicoPessoa* servicoPessoa = nullptr;
    std::string lerLinha(const std::string& prompt) const;
public:
    void setServicoPessoa(IServicoPessoa* servico);
    void cadastrar();
    void executarLogado(const Email& usuarioAtual);
    void listarPessoas() const;
    void atualizarPessoa(const Email& usuarioAtual);
    void excluirPessoa(const Email& usuarioAtual);
};

#endif