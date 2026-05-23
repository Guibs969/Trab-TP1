#ifndef CTRLAPRESENTACAOSISTEMA_HPP
#define CTRLAPRESENTACAOSISTEMA_HPP

#include "IApresentacaoSistema.hpp"
#include "../Interfaces/IServicoPessoa.hpp"
#include "../Interfaces/IServicoProjeto.hpp"
#include "../Interfaces/IServicoPlanoSprint.hpp"
#include "../Interfaces/IServicoHistoriaUsuario.hpp"
#include "../Dominios/Email.hpp"

/**
 * @brief Controlador principal da camada de apresentação.
 */
class CtrlApresentacaoSistema : public IApresentacaoSistema {
private:
    IServicoPessoa* servicoPessoa;
    IServicoProjeto* servicoProjeto;
    IServicoPlanoSprint* servicoPlano;
    IServicoHistoriaUsuario* servicoHistoria;
    bool autenticado = false;
    Email usuarioAtual;

    void exibirMenu() const;
    std::string lerLinha(const std::string& prompt) const;
    bool usuarioAutenticado() const;
    void registrarPessoa();
    void autenticarUsuario();
    void cadastrarProjeto();
    void cadastrarPlano();
    void cadastrarHistoria();
    void listarPessoas() const;
    void listarProjetos() const;
    void listarPlanos() const;
    void listarHistorias() const;
    void listarProjetosPorPessoa() const;
    void listarHistoriasPorProjeto() const;
    void listarPlanosPorProjeto() const;
    void listarHistoriasPorPlano() const;
    void listarHistoriasPorPessoa() const;
    void atribuirHistoria();
    void removerDesenvolvedor();
    void alterarEstadoHistoria();
    void atualizarPessoa();
    void excluirPessoa();
    void logout();
public:
    CtrlApresentacaoSistema(IServicoPessoa* servicoPessoa,
                             IServicoProjeto* servicoProjeto,
                             IServicoPlanoSprint* servicoPlano,
                             IServicoHistoriaUsuario* servicoHistoria);
    void executar() override;
};

#endif // CTRLAPRESENTACAOSISTEMA_HPP
