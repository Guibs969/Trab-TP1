#ifndef CTRLSERVICOHISTORIADEUSUARIO_HPP
#define CTRLSERVICOHISTORIADEUSUARIO_HPP

#include "../Interfaces/IServicoHistoriaUsuario.hpp"
#include "ContainerHistoriaUsuario.hpp"
#include "../Interfaces/IServicoProjeto.hpp"
#include "../Interfaces/IServicoPlanoSprint.hpp"
#include "../Interfaces/IServicoPessoa.hpp"

/**
 * @brief Controlador da camada de serviço para HistoriaDeUsuario.
 */
class CtrlServicoHistoriaUsuario : public IServicoHistoriaUsuario {
private:
    ContainerHistoriaUsuario container;
    const IServicoProjeto* servicoProjeto;
    IServicoPlanoSprint* servicoPlano;
    IServicoPessoa* servicoPessoa;
public:
    CtrlServicoHistoriaUsuario(const IServicoProjeto* servicoProjeto,
                               IServicoPlanoSprint* servicoPlano,
                               IServicoPessoa* servicoPessoa);
    bool cadastrar(const HistoriaDeUsuario& historia) override;
    bool atualizar(const HistoriaDeUsuario& historia) override;
    bool excluir(const Codigo& codigo) override;
    bool buscar(const Codigo& codigo, HistoriaDeUsuario& historia) const override;
    std::vector<HistoriaDeUsuario> listar() const override;
    std::vector<HistoriaDeUsuario> listarPorProjeto(const Codigo& codigoProjeto) const override;
    std::vector<HistoriaDeUsuario> listarPorPlano(const Codigo& codigoPlano) const override;
    std::vector<HistoriaDeUsuario> listarPorPessoa(const Email& email) const override;
    bool existe(const Codigo& codigo) const override;
    bool atribuirDesenvolvedor(const Codigo& codigoHistoria, const Email& email) override;
    bool removerDesenvolvedor(const Codigo& codigoHistoria) override;
    bool alterarEstado(const Codigo& codigoHistoria, const Estado& estado) override;
};

#endif // CTRLSERVICOHISTORIADEUSUARIO_HPP
