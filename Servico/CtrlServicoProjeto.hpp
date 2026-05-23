#ifndef CTRLSERVICOPROJETO_HPP
#define CTRLSERVICOPROJETO_HPP

#include "../Interfaces/IServicoProjeto.hpp"
#include "ContainerProjeto.hpp"
#include "../Interfaces/IServicoPessoa.hpp"

/**
 * @brief Controlador da camada de serviço para Projeto.
 */
class CtrlServicoProjeto : public IServicoProjeto {
private:
    ContainerProjeto container;
    const IServicoPessoa* servicoPessoa;
public:
    explicit CtrlServicoProjeto(const IServicoPessoa* servicoPessoa);
    bool cadastrar(const Projeto& projeto) override;
    bool atualizar(const Projeto& projeto) override;
    bool excluir(const Codigo& codigo) override;
    bool buscar(const Codigo& codigo, Projeto& projeto) const override;
    std::vector<Projeto> listar() const override;
    std::vector<Projeto> listarProjetosPorPessoa(const Email& email) const override;
    bool existe(const Codigo& codigo) const override;
};

#endif // CTRLSERVICOPROJETO_HPP
