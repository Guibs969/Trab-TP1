#ifndef PROJETO_HPP
#define PROJETO_HPP

#include "../Dominios/Codigo.hpp"
#include "../Dominios/Nome.hpp"
#include "../Dominios/Data.hpp"
#include "../Dominios/Email.hpp"
#include <vector>

/**
 * @brief Classe de entidade para representar um projeto.
 */
class Projeto {
private:
    Codigo codigo;
    Nome nome;
    Data inicio;
    Data termino;
    Email proprietario;
    Email mestreScrum;
    std::vector<Codigo> planos;
    std::vector<Codigo> historias;
public:
    /**
     * @brief Define o código identificador do projeto.
     * @param codigo Objeto contendo o código válido.
     */
    void setCodigo(const Codigo& codigo);

    /**
     * @brief Retorna o código identificador do projeto.
     * @return Codigo Objeto contendo o código do projeto.
     */
    Codigo getCodigo() const;

    /**
     * @brief Define o nome do projeto.
     * @param nome Objeto contendo o nome válido.
     */
    void setNome(const Nome& nome);

    /**
     * @brief Retorna o nome do projeto.
     * @return Nome Objeto contendo o nome do projeto.
     */
    Nome getNome() const;

    /**
     * @brief Define a data de início do projeto.
     * @param inicio Objeto contendo a data de início.
     */
    void setInicio(const Data& inicio);

    /**
     * @brief Retorna a data de início do projeto.
     * @return Data Objeto contendo a data de início.
     */
    Data getInicio() const;

    /**
     * @brief Define a data de término do projeto.
     * @param termino Objeto contendo a data de término.
     */
    void setTermino(const Data& termino);

    /**
     * @brief Retorna a data de término do projeto.
     * @return Data Objeto contendo a data de término.
     */
    Data getTermino() const;

    /**
     * @brief Define o e-mail do proprietário do projeto (Product Owner).
     * @param proprietario Objeto contendo o e-mail do proprietário.
     */
    void setProprietario(const Email& proprietario);

    /**
     * @brief Retorna o e-mail do proprietário do projeto.
     * @return Email Objeto contendo o e-mail do proprietário.
     */
    Email getProprietario() const;

    /**
     * @brief Define o e-mail do Scrum Master (Mestre Scrum) do projeto.
     * @param mestreScrum Objeto contendo o e-mail do Scrum Master.
     */
    void setMestreScrum(const Email& mestreScrum);

    /**
     * @brief Retorna o e-mail do Scrum Master do projeto.
     * @return Email Objeto contendo o e-mail do Scrum Master.
     */
    Email getMestreScrum() const;

    /**
     * @brief Associa um novo plano de sprint ao projeto, evitando duplicatas.
     * @param codigoPlano Objeto contendo o código do plano de sprint.
     * @return true se o plano foi adicionado com sucesso.
     * @return false se o plano já estiver associado ao projeto.
     */
    bool adicionarPlano(const Codigo& codigoPlano);

    /**
     * @brief Associa uma nova história de usuário ao projeto, evitando duplicatas.
     * @param codigoHistoria Objeto contendo o código da história de usuário.
     * @return true se a história foi adicionada com sucesso.
     * @return false se a história já estiver associada ao projeto.
     */
    bool adicionarHistoria(const Codigo& codigoHistoria);

    /**
     * @brief Retorna a lista de códigos de planos de sprint associados.
     * @return std::vector<Codigo> Vetor contendo os códigos dos planos.
     */
    std::vector<Codigo> getPlanos() const;

    /**
     * @brief Retorna a lista de códigos de histórias de usuário associadas.
     * @return std::vector<Codigo> Vetor contendo os códigos das histórias.
     */
    std::vector<Codigo> getHistorias() const;
};

#endif // PROJETO_HPP