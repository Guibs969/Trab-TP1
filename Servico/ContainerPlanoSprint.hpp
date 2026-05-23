#ifndef CONTAINERPLANOSPRINT_HPP
#define CONTAINERPLANOSPRINT_HPP

#include "../Entidades/PlanoDeSprint.hpp"
#include <vector>

/**
 * @brief Container simples para armazenamento de planos de sprint.
 */
class ContainerPlanoSprint {
private:
    std::vector<PlanoDeSprint> planos;
public:
    bool existe(const Codigo& codigo) const;
    bool inserir(const PlanoDeSprint& plano);
    bool atualizar(const PlanoDeSprint& plano);
    bool remover(const Codigo& codigo);
    bool buscar(const Codigo& codigo, PlanoDeSprint& plano) const;
    std::vector<PlanoDeSprint> listar() const;
};

#endif // CONTAINERPLANOSPRINT_HPP
