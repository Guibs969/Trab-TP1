#ifndef ISERVICOHISTORIADEUSUARIO_HPP
#define ISERVICOHISTORIADEUSUARIO_HPP

#include "../Entidades/HistoriaDeUsuario.hpp"
#include "../Dominios/Codigo.hpp"
#include "../Dominios/Email.hpp"
#include <vector>

/**
 * @brief Interface para serviços de história de usuário.
 */
class IServicoHistoriaUsuario {
public:
    virtual bool cadastrar(const HistoriaDeUsuario& historia) = 0;
    virtual bool atualizar(const HistoriaDeUsuario& historia) = 0;
    virtual bool excluir(const Codigo& codigo) = 0;
    virtual bool buscar(const Codigo& codigo, HistoriaDeUsuario& historia) const = 0;
    virtual std::vector<HistoriaDeUsuario> listar() const = 0;
    virtual std::vector<HistoriaDeUsuario> listarPorProjeto(const Codigo& codigoProjeto) const = 0;
    virtual std::vector<HistoriaDeUsuario> listarPorPlano(const Codigo& codigoPlano) const = 0;
    virtual std::vector<HistoriaDeUsuario> listarPorPessoa(const Email& email) const = 0;
    virtual bool existe(const Codigo& codigo) const = 0;
    virtual bool atribuirDesenvolvedor(const Codigo& codigoHistoria, const Email& email) = 0;
    virtual bool removerDesenvolvedor(const Codigo& codigoHistoria) = 0;
    virtual bool alterarEstado(const Codigo& codigoHistoria, const Estado& estado) = 0;
    virtual ~IServicoHistoriaUsuario() = default;
};

#endif // ISERVICOHISTORIADEUSUARIO_HPP
