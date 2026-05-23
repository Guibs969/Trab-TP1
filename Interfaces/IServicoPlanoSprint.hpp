#ifndef ISERVICOPLANOSPRINT_HPP
#define ISERVICOPLANOSPRINT_HPP

#include "../Entidades/PlanoDeSprint.hpp"
#include "../Dominios/Codigo.hpp"
#include <vector>

/**
 * @brief Interface para serviços de plano de sprint.
 */
class IServicoPlanoSprint {
public:
    virtual bool cadastrar(const PlanoDeSprint& plano) = 0;
    virtual bool atualizar(const PlanoDeSprint& plano) = 0;
    virtual bool excluir(const Codigo& codigo) = 0;
    virtual bool buscar(const Codigo& codigo, PlanoDeSprint& plano) const = 0;
    virtual std::vector<PlanoDeSprint> listar() const = 0;
    virtual std::vector<PlanoDeSprint> listarPorProjeto(const Codigo& codigoProjeto) const = 0;
    virtual bool existe(const Codigo& codigo) const = 0;
    virtual ~IServicoPlanoSprint() = default;
};

#endif // ISERVICOPLANOSPRINT_HPP
