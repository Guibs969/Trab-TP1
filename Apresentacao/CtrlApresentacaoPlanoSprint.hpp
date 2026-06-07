#ifndef CTRLAPRESENTACAOPLANOSPRINT_HPP
#define CTRLAPRESENTACAOPLANOSPRINT_HPP

#include "../Interfaces/IServicoPlanoSprint.hpp"
#include "../Dominios/Email.hpp"
#include <string>

/**
 * @brief Controlador da camada de apresentação para Planos de Sprint.
 */
class CtrlApresentacaoPlanoSprint {
private:
    IServicoPlanoSprint* servicoPlano = nullptr;
    std::string lerLinha(const std::string& prompt) const;
    int lerInteiroSeguro(const std::string& prompt) const;
public:
    void setServicoPlano(IServicoPlanoSprint* servico);
    void executar(const Email& usuarioAtual);
    void cadastrarPlano(const Email& usuarioAtual);
    void listarPlanos() const;
    void listarPlanosPorProjeto() const;
};

#endif // CTRLAPRESENTACAOPLANOSPRINT_HPP