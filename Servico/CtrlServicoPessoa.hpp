#ifndef CTRLSERVICOPESSOA_HPP
#define CTRLSERVICOPESSOA_HPP

#include "../Interfaces/IServicoPessoa.hpp"

/**
 * @brief Controlador da camada de serviço para Pessoa.
 */
class CtrlServicoPessoa : public IServicoPessoa {
public:
    /**
     * @brief Cadastra uma pessoa.
     * @param p Pessoa a ser cadastrada.
     * @return true se cadastrado com sucesso.
     */
    bool cadastrar(Pessoa p) override;
};

#endif // CTRLSERVICOPESSOA_HPP
