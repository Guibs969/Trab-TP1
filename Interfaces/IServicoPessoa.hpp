#ifndef ISERVICOPESSOA_HPP
#define ISERVICOPESSOA_HPP

#include "../Entidades/Pessoa.hpp"

/**
 * @brief Interface para serviço de pessoa.
 */
class IServicoPessoa {
public:
    /**
     * @brief Cadastra uma pessoa.
     * @param p Pessoa a ser cadastrada.
     * @return true se cadastrado com sucesso.
     */
    virtual bool cadastrar(Pessoa p) = 0;

    /// @brief Destrutor virtual.
    virtual ~IServicoPessoa() = default;
};

#endif // ISERVICOPESSOA_HPP
