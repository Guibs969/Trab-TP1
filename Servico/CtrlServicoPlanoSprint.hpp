#ifndef CTRLSERVICOPLANOSPRINT_HPP
#define CTRLSERVICOPLANOSPRINT_HPP

#include "../Interfaces/IServicoPlanoSprint.hpp"
#include "ContainerPlanoSprint.hpp"
#include "../Interfaces/IServicoProjeto.hpp"

/**
 * @brief Controlador da camada de serviço para PlanoDeSprint.
 */
class CtrlServicoPlanoSprint : public IServicoPlanoSprint {
private:
    ContainerPlanoSprint container;
    const IServicoProjeto* servicoProjeto;
public:
    explicit CtrlServicoPlanoSprint(const IServicoProjeto* servicoProjeto);
    bool cadastrar(const PlanoDeSprint& plano) override;
    bool atualizar(const PlanoDeSprint& plano) override;
    bool excluir(const Codigo& codigo) override;
    bool buscar(const Codigo& codigo, PlanoDeSprint& plano) const override;
    std::vector<PlanoDeSprint> listar() const override;
    std::vector<PlanoDeSprint> listarPorProjeto(const Codigo& codigoProjeto) const override;
    bool existe(const Codigo& codigo) const override;
};

#endif // CTRLSERVICOPLANOSPRINT_HPP
