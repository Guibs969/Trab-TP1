#ifndef ISERVICOPROJETO_HPP
#define ISERVICOPROJETO_HPP

#include "../Entidades/Projeto.hpp"
#include "../Dominios/Codigo.hpp"
#include "../Dominios/Email.hpp"
#include <vector>

/**
 * @brief Interface para o serviço de gestão de projetos.
 */
class IServicoProjeto {
public:
    /**
     * @brief Regista um novo projeto no sistema.
     * @param projeto Objeto da classe Projeto contendo os dados válidos.
     * @return true se o projeto for criado com sucesso.
     * @return false se já existir um projeto com o mesmo código.
     */
    virtual bool cadastrar(const Projeto& projeto) = 0;

    /**
     * @brief Atualiza os dados de um projeto existente.
     * @param projeto Objeto Projeto com os dados atualizados.
     * @return true se for atualizado com sucesso.
     * @return false se o projeto não existir.
     */
    virtual bool atualizar(const Projeto& projeto) = 0;

    /**
     * @brief Exclui um projeto através do seu código identificador.
     * @param codigo Código do projeto a ser removido.
     * @return true se a remoção for bem-sucedida.
     * @return false se o código não for encontrado.
     */
    virtual bool excluir(const Codigo& codigo) = 0;

    /**
     * @brief Procura e recupera os detalhes de um projeto específico.
     * @param codigo Código do projeto a ser procurado.
     * @param projeto Referência para a entidade onde os dados serão preenchidos.
     * @return true se o projeto for encontrado.
     * @return false caso contrário.
     */
    virtual bool buscar(const Codigo& codigo, Projeto& projeto) const = 0;

    /**
     * @brief Retorna uma lista de todos os projetos cadastrados.
     * @return std::vector<Projeto> Vetor contendo todos os projetos.
     */
    virtual std::vector<Projeto> listar() const = 0;

    /**
     * @brief Lista todos os projetos associados a uma pessoa específica (como proprietário ou scrum master).
     * @param email E-mail da pessoa a pesquisar.
     * @return std::vector<Projeto> Vetor de projetos vinculados ao utilizador.
     */
    virtual std::vector<Projeto> listarProjetosPorPessoa(const Email& email) const = 0;

    /**
     * @brief Verifica se um projeto está registado no sistema.
     * @param codigo Código a ser verificado.
     * @return true se existir.
     * @return false caso contrário.
     */
    virtual bool existe(const Codigo& codigo) const = 0;

    /// @brief Destrutor virtual padrão.
    virtual ~IServicoProjeto() = default;
};

#endif // ISERVICOPROJETO_HPP