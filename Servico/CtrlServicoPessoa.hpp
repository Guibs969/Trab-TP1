#ifndef CTRLSERVICOPESSOA_HPP
#define CTRLSERVICOPESSOA_HPP

#include "../Interfaces/IServicoPessoa.hpp"
#include "ContainerPessoa.hpp"

/**
 * @brief Controlador da camada de serviço para Pessoa.
 */
class CtrlServicoPessoa : public IServicoPessoa {
private:
    ContainerPessoa container;
public:
    bool cadastrar(const Pessoa& p) override;
    bool autenticar(const Email& email, const Senha& senha) const override;
    bool atualizar(const Pessoa& p) override;
    bool excluir(const Email& email) override;
    bool buscar(const Email& email, Pessoa& p) const override;
    std::vector<Pessoa> listar() const override;
    bool existe(const Email& email) const override;
};

#endif // CTRLSERVICOPESSOA_HPP
