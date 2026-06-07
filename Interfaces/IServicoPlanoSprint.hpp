#ifndef ISERVICOPLANOSPRINT_HPP
#define ISERVICOPLANOSPRINT_HPP

#include "../Entidades/PlanoDeSprint.hpp"
#include "../Dominios/Codigo.hpp"
#include <vector>

/**
 * @brief Interface para o serviço de planos de sprint.
 */
class IServicoPlanoSprint {
public:
    /**
     * @brief Cadastra um novo plano de sprint.
     * @param plano Entidade PlanoDeSprint a ser inserida.
     * @return true se o cadastro for bem-sucedido.
     * @return false em caso de falha (ex: código duplicado).
     */
    virtual bool cadastrar(const PlanoDeSprint& plano) = 0;

    /**
     * @brief Atualiza um plano de sprint existente.
     * @param plano Entidade com os dados modificados.
     * @return true se a atualização for realizada.
     * @return false se o plano não for encontrado.
     */
    virtual bool atualizar(const PlanoDeSprint& plano) = 0;

    /**
     * @brief Exclui um plano de sprint a partir do seu código.
     * @param codigo Código do plano a ser removido.
     * @return true se excluído com sucesso.
     * @return false se o registo não existir.
     */
    virtual bool excluir(const Codigo& codigo) = 0;

    /**
     * @brief Procura por um plano de sprint.
     * @param codigo Código do plano.
     * @param plano Referência onde o resultado será carregado.
     * @return true se localizado.
     * @return false caso não seja encontrado.
     */
    virtual bool buscar(const Codigo& codigo, PlanoDeSprint& plano) const = 0;

    /**
     * @brief Lista globalmente todos os planos de sprint do sistema.
     * @return std::vector<PlanoDeSprint> Lista contendo os planos.
     */
    virtual std::vector<PlanoDeSprint> listar() const = 0;

    /**
     * @brief Retorna os planos de sprint associados a um projeto específico.
     * @param codigoProjeto Código do projeto pai.
     * @return std::vector<PlanoDeSprint> Vetor filtrado pelos planos desse projeto.
     */
    virtual std::vector<PlanoDeSprint> listarPorProjeto(const Codigo& codigoProjeto) const = 0;

    /**
     * @brief Valida se um determinado plano de sprint já existe.
     * @param codigo Código identificador.
     * @return true se o código já constar no sistema.
     * @return false caso contrário.
     */
    virtual bool existe(const Codigo& codigo) const = 0;

    /// @brief Destrutor virtual padrão.
    virtual ~IServicoPlanoSprint() = default;
};

#endif // ISERVICOPLANOSPRINT_HPP