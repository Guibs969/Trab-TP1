#ifndef CTRLAPRESENTACAOSISTEMA_HPP
#define CTRLAPRESENTACAOSISTEMA_HPP

#include "IApresentacaoSistema.hpp"
#include "CtrlApresentacaoPessoa.hpp"
#include "CtrlApresentacaoProjeto.hpp"
#include "CtrlApresentacaoPlanoSprint.hpp"
#include "CtrlApresentacaoHistoriaUsuario.hpp"

#include "../Interfaces/IServicoPessoa.hpp"
#include "../Interfaces/IServicoProjeto.hpp"
#include "../Interfaces/IServicoPlanoSprint.hpp"
#include "../Interfaces/IServicoHistoriaUsuario.hpp"
#include "../Dominios/Email.hpp"
#include <string>

/**
 * @brief Controlador principal (Hub). Gerencia autenticação e roteamento.
 */
class CtrlApresentacaoSistema : public IApresentacaoSistema {
private:
    // Serviços originais
    IServicoPessoa* servicoPessoa;
    IServicoProjeto* servicoProjeto;
    IServicoPlanoSprint* servicoPlano;
    IServicoHistoriaUsuario* servicoHistoria;

    // Sub-controladores modulares
    CtrlApresentacaoPessoa ctrlPessoa;
    CtrlApresentacaoProjeto ctrlProjeto;
    CtrlApresentacaoPlanoSprint ctrlPlano;
    CtrlApresentacaoHistoriaUsuario ctrlHistoria;

    bool autenticado = false;
    Email usuarioAtual;

    std::string lerLinha(const std::string& prompt) const;
    void autenticarUsuario();
    void logout();

public:
    // Construtor mantido igual para não quebrar o main.cpp
    CtrlApresentacaoSistema(IServicoPessoa* servicoPessoa,
                             IServicoProjeto* servicoProjeto,
                             IServicoPlanoSprint* servicoPlano,
                             IServicoHistoriaUsuario* servicoHistoria);
    void executar() override;
};

#endif // CTRLAPRESENTACAOSISTEMA_HPP