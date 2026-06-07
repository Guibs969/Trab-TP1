#ifndef ISERVICOPESSOA_HPP
#define ISERVICOPESSOA_HPP

#include "../Entidades/Pessoa.hpp"
#include "../Dominios/Email.hpp"
#include "../Dominios/Senha.hpp"
#include <vector>

/**
 * @brief Interface para o serviço de gestão de pessoas.
 * * Define o contrato para as operações de lógica de negócio relacionadas
 * com o registo, autenticação e manutenção de utilizadores no sistema.
 */
class IServicoPessoa {
public:
    /**
     * @brief Regista uma nova pessoa no sistema.
     * @param p Objeto instanciado da classe Pessoa contendo os dados válidos.
     * @return true se o registo for efetuado com sucesso.
     * @return false se já existir uma pessoa com o mesmo e-mail ou ocorrer um erro.
     */
    virtual bool cadastrar(const Pessoa& p) = 0;

    /**
     * @brief Autentica um utilizador verificando as suas credenciais.
     * @param email Objeto de domínio contendo o e-mail do utilizador.
     * @param senha Objeto de domínio contendo a palavra-passe do utilizador.
     * @return true se as credenciais corresponderem a um registo válido.
     * @return false caso contrário.
     */
    virtual bool autenticar(const Email& email, const Senha& senha) const = 0;

    /**
     * @brief Atualiza os dados de uma pessoa existente.
     * @param p Objeto Pessoa contendo os novos dados a atualizar.
     * @return true se a atualização for bem-sucedida.
     * @return false se a pessoa não for encontrada.
     */
    virtual bool atualizar(const Pessoa& p) = 0;

    /**
     * @brief Exclui o registo de uma pessoa com base no seu e-mail.
     * @param email E-mail identificador da pessoa a ser removida.
     * @return true se a exclusão for efetuada com sucesso.
     * @return false se a pessoa não existir no sistema.
     */
    virtual bool excluir(const Email& email) = 0;

    /**
     * @brief Recupera os dados de uma pessoa específica.
     * @param email E-mail da pessoa a ser pesquisada.
     * @param p Referência para o objeto Pessoa onde os dados serão carregados.
     * @return true se a pessoa for encontrada.
     * @return false se a pessoa não existir.
     */
    virtual bool buscar(const Email& email, Pessoa& p) const = 0;

    /**
     * @brief Lista todas as pessoas registadas no sistema.
     * @return std::vector<Pessoa> Vetor contendo todos os registos de pessoas.
     */
    virtual std::vector<Pessoa> listar() const = 0;

    /**
     * @brief Verifica a existência de uma pessoa através do seu e-mail.
     * @param email E-mail a ser verificado.
     * @return true se a pessoa já estiver registada.
     * @return false caso contrário.
     */
    virtual bool existe(const Email& email) const = 0;

    /// @brief Destrutor virtual padrão para garantir a correta destruição de subclasses.
    virtual ~IServicoPessoa() = default;
};

#endif // ISERVICOPESSOA_HPP