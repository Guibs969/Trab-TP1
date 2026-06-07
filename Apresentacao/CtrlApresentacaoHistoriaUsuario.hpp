#ifndef CTRLAPRESENTACAOHISTORIAUSUARIO_HPP
#define CTRLAPRESENTACAOHISTORIAUSUARIO_HPP

#include "../Interfaces/IServicoHistoriaUsuario.hpp"
#include "../Dominios/Email.hpp"
#include <string>

/**
 * @brief Controlador da camada de apresentação para Histórias de Usuário.
 */
class CtrlApresentacaoHistoriaUsuario {
private:
    IServicoHistoriaUsuario* servicoHistoria = nullptr;
    std::string lerLinha(const std::string& prompt) const;
    int lerInteiroSeguro(const std::string& prompt) const;
public:
    void setServicoHistoria(IServicoHistoriaUsuario* servico);
    void executar(const Email& usuarioAtual);
    void cadastrarHistoria(const Email& usuarioAtual);
    void listarHistorias() const;
    void listarHistoriasPorProjeto() const;
    void listarHistoriasPorPlano() const;
    void listarHistoriasPorPessoa() const;
    void atribuirHistoria();
    void removerDesenvolvedor();
    void alterarEstadoHistoria();
};

#endif // CTRLAPRESENTACAOHISTORIAUSUARIO_HPP