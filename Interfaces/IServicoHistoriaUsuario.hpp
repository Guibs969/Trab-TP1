#ifndef ISERVICOHISTORIADEUSUARIO_HPP
#define ISERVICOHISTORIADEUSUARIO_HPP

#include "../Entidades/HistoriaDeUsuario.hpp"
#include "../Dominios/Codigo.hpp"
#include "../Dominios/Email.hpp"
#include <vector>

/**
 * @brief Interface para o serviço de histórias de utilizador.
 */
class IServicoHistoriaUsuario {
public:
    /**
     * @brief Cria uma nova história de utilizador.
     * @param historia Objeto contendo os dados da história.
     * @return true em caso de sucesso.
     * @return false caso o código já exista ou falhe outra restrição.
     */
    virtual bool cadastrar(const HistoriaDeUsuario& historia) = 0;

    /**
     * @brief Efetua alterações numa história de utilizador existente.
     * @param historia Objeto com os novos atributos.
     * @return true se conseguir atualizar.
     * @return false se a história não for localizada.
     */
    virtual bool atualizar(const HistoriaDeUsuario& historia) = 0;

    /**
     * @brief Remove a história identificada pelo código.
     * @param codigo Código identificador.
     * @return true se a remoção for bem-sucedida.
     * @return false caso o código não exista.
     */
    virtual bool excluir(const Codigo& codigo) = 0;

    /**
     * @brief Procura uma história e carrega os seus dados na referência.
     * @param codigo Código da história.
     * @param historia Referência recetora dos dados.
     * @return true se a entidade for encontrada.
     * @return false caso contrário.
     */
    virtual bool buscar(const Codigo& codigo, HistoriaDeUsuario& historia) const = 0;

    /**
     * @brief Obtém todas as histórias registadas.
     * @return std::vector<HistoriaDeUsuario> Lista completa de histórias.
     */
    virtual std::vector<HistoriaDeUsuario> listar() const = 0;

    /**
     * @brief Lista histórias pertencentes ao backlog de um determinado projeto.
     * @param codigoProjeto Código do projeto pai.
     * @return std::vector<HistoriaDeUsuario> Vetor de histórias do projeto.
     */
    virtual std::vector<HistoriaDeUsuario> listarPorProjeto(const Codigo& codigoProjeto) const = 0;

    /**
     * @brief Lista as histórias associadas a um plano de sprint específico.
     * @param codigoPlano Código do plano de sprint.
     * @return std::vector<HistoriaDeUsuario> Vetor de histórias ativas nesse sprint.
     */
    virtual std::vector<HistoriaDeUsuario> listarPorPlano(const Codigo& codigoPlano) const = 0;

    /**
     * @brief Recupera todas as histórias cujo desenvolvimento está atribuído a um utilizador.
     * @param email E-mail do programador.
     * @return std::vector<HistoriaDeUsuario> Vetor contendo as atribuições ativas.
     */
    virtual std::vector<HistoriaDeUsuario> listarPorPessoa(const Email& email) const = 0;

    /**
     * @brief Verifica a existência prévia de uma história.
     * @param codigo Código de pesquisa.
     * @return true se existir, false caso não exista.
     */
    virtual bool existe(const Codigo& codigo) const = 0;

    /**
     * @brief Atribui a responsabilidade de uma história a um programador.
     * @param codigoHistoria Código da história de utilizador.
     * @param email E-mail do utilizador a assumir o desenvolvimento.
     * @return true se a atribuição for feita com sucesso.
     */
    virtual bool atribuirDesenvolvedor(const Codigo& codigoHistoria, const Email& email) = 0;

    /**
     * @brief Remove o vínculo entre a história e o seu atual programador.
     * @param codigoHistoria Código da história afetada.
     * @return true se removido com sucesso.
     */
    virtual bool removerDesenvolvedor(const Codigo& codigoHistoria) = 0;

    /**
     * @brief Modifica o estado de evolução da história (ex: 'To Do', 'Doing', 'Done').
     * @param codigoHistoria Código da história.
     * @param estado Objeto de domínio indicando o novo estado.
     * @return true se o estado for alterado.
     */
    virtual bool alterarEstado(const Codigo& codigoHistoria, const Estado& estado) = 0;

    /// @brief Destrutor virtual padrão.
    virtual ~IServicoHistoriaUsuario() = default;
};

#endif // ISERVICOHISTORIADEUSUARIO_HPP