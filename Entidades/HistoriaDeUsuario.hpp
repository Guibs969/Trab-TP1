#ifndef HISTORIADEUSUARIO_HPP
#define HISTORIADEUSUARIO_HPP

#include "../Dominios/Codigo.hpp"
#include "../Dominios/Texto.hpp"
#include "../Dominios/Tempo.hpp"
#include "../Dominios/Prioridade.hpp"
#include "../Dominios/Estado.hpp"
#include "../Dominios/Email.hpp"

/**
 * @brief Classe de entidade para representar uma história de usuário.
 */
class HistoriaDeUsuario {
private:
    Codigo codigo;
    Texto titulo;
    Texto papel;
    Texto acao;
    Texto valor;
    Tempo estimativa;
    Prioridade prioridade;
    Estado estado;
    Codigo codigoProjeto;
    Email desenvolvedor;
    bool temDesenvolvedor = false;
public:
    /**
     * @brief Define o código identificador da história.
     * @param codigo Objeto contendo o código válido.
     */
    void setCodigo(const Codigo& codigo);

    /**
     * @brief Retorna o código identificador da história.
     * @return Codigo Objeto contendo o código da história.
     */
    Codigo getCodigo() const;

    /**
     * @brief Define o título descritivo da história.
     * @param titulo Objeto contendo o título formatado.
     */
    void setTitulo(const Texto& titulo);

    /**
     * @brief Retorna o título da história de usuário.
     * @return Texto Objeto contendo o título.
     */
    Texto getTitulo() const;

    /**
     * @brief Define o papel do ator na história (Ex: "Como um...").
     * @param papel Objeto contendo a definição do papel.
     */
    void setPapel(const Texto& papel);

    /**
     * @brief Retorna o papel do ator da história.
     * @return Texto Objeto contendo o papel.
     */
    Texto getPapel() const;

    /**
     * @brief Define a ação esperada na história (Ex: "Eu quero...").
     * @param acao Objeto contendo a descrição da ação.
     */
    void setAcao(const Texto& acao);

    /**
     * @brief Retorna a ação esperada na história.
     * @return Texto Objeto contendo a ação.
     */
    Texto getAcao() const;

    /**
     * @brief Define o valor de negócio gerado (Ex: "Para que eu possa...").
     * @param valor Objeto contendo a descrição da justificativa de valor.
     */
    void setValor(const Texto& valor);

    /**
     * @brief Retorna o valor de negócio da história.
     * @return Texto Objeto contendo o valor.
     */
    Texto getValor() const;

    /**
     * @brief Define o tempo de estimativa de esforço/desenvolvimento.
     * @param estimativa Objeto contendo o tempo estimado.
     */
    void setEstimativa(const Tempo& estimativa);

    /**
     * @brief Retorna a estimativa de tempo da história.
     * @return Tempo Objeto contendo a estimativa.
     */
    Tempo getEstimativa() const;

    /**
     * @brief Define o nível de prioridade da história de usuário.
     * @param prioridade Objeto contendo a classificação de prioridade.
     */
    void setPrioridade(const Prioridade& prioridade);

    /**
     * @brief Retorna o nível de prioridade da história.
     * @return Prioridade Objeto contendo a prioridade.
     */
    Prioridade getPrioridade() const;

    /**
     * @brief Define o estado atual de desenvolvimento (Ex: ToDo, In Progress, Done).
     * @param estado Objeto contendo o estado atual.
     */
    void setEstado(const Estado& estado);

    /**
     * @brief Retorna o estado atual da história.
     * @return Estado Objeto contendo o estado.
     */
    Estado getEstado() const;

    /**
     * @brief Define o código do projeto ao qual esta história está vinculada.
     * @param codigoProjeto Objeto contendo o código do projeto pai.
     */
    void setCodigoProjeto(const Codigo& codigoProjeto);

    /**
     * @brief Retorna o código do projeto pai associado.
     * @return Codigo Objeto contendo o código do projeto.
     */
    Codigo getCodigoProjeto() const;

    /**
     * @brief Atribui um desenvolvedor responsável à história e ativa a flag interna.
     * @param desenvolvedor Objeto contendo o e-mail válido do desenvolvedor.
     */
    void atribuirDesenvolvedor(const Email& desenvolvedor);

    /**
     * @brief Desvincula o desenvolvedor atual e desativa a flag de controle.
     */
    void removerDesenvolvedor();

    /**
     * @brief Verifica se a história possui um desenvolvedor atribuído.
     * @return true se houver desenvolvedor responsável vinculado.
     * @return false se a história estiver sem atribuição.
     */
    bool possuiDesenvolvedor() const;

    /**
     * @brief Retorna o e-mail do desenvolvedor responsável, caso exista.
     * @return Email Objeto contendo o e-mail do desenvolvedor.
     */
    Email getDesenvolvedor() const;
};

#endif // HISTORIADEUSUARIO_HPP