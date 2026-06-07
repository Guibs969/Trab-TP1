#ifndef PLANODESPRINT_HPP
#define PLANODESPRINT_HPP

#include "../Dominios/Codigo.hpp"
#include "../Dominios/Texto.hpp"
#include "../Dominios/Tempo.hpp"
#include <vector>

/**
 * @brief Classe de entidade para representar um plano de sprint.
 */
class PlanoDeSprint {
private:
    Codigo codigo;
    Texto objetivo;
    Tempo capacidade;
    Codigo codigoProjeto;
    std::vector<Codigo> historias;
public:
    /**
     * @brief Define o código identificador do plano de sprint.
     * @param codigo Objeto contendo o código válido.
     */
    void setCodigo(const Codigo& codigo);

    /**
     * @brief Retorna o código identificador do plano de sprint.
     * @return Codigo Objeto contendo o código do plano.
     */
    Codigo getCodigo() const;

    /**
     * @brief Define o texto descritivo do objetivo da sprint.
     * @param objetivo Objeto contendo a descrição do objetivo.
     */
    void setObjetivo(const Texto& objetivo);

    /**
     * @brief Retorna o objetivo da sprint.
     * @return Texto Objeto contendo a descrição do objetivo.
     */
    Texto getObjetivo() const;

    /**
     * @brief Define a capacidade de tempo estimada para a sprint.
     * @param capacidade Objeto contendo o tempo total de capacidade.
     */
    void setCapacidade(const Tempo& capacidade);

    /**
     * @brief Retorna a capacidade de tempo da sprint.
     * @return Tempo Objeto contendo o tempo de capacidade.
     */
    Tempo getCapacidade() const;

    /**
     * @brief Define o código do projeto ao qual esta sprint pertence.
     * @param codigoProjeto Objeto contendo o código do projeto pai.
     */
    void setCodigoProjeto(const Codigo& codigoProjeto);

    /**
     * @brief Retorna o código do projeto associado à sprint.
     * @return Codigo Objeto contendo o código do projeto pai.
     */
    Codigo getCodigoProjeto() const;

    /**
     * @brief Insere uma história de usuário na lista da sprint se ela não existir.
     * @param codigoHistoria Objeto contendo o código da história.
     * @return true se adicionado com sucesso.
     * @return false se a história já constar na lista.
     */
    bool adicionarHistoria(const Codigo& codigoHistoria);

    /**
     * @brief Remove uma história de usuário cadastrada na sprint.
     * @param codigoHistoria Objeto contendo o código da história a ser removida.
     * @return true se encontrada e removida com sucesso.
     * @return false se a história não pertencer a este plano.
     */
    bool removerHistoria(const Codigo& codigoHistoria);

    /**
     * @brief Retorna todas as histórias vinculadas a este plano de sprint.
     * @return std::vector<Codigo> Vetor contendo os códigos das histórias.
     */
    std::vector<Codigo> getHistorias() const;
};

#endif // PLANODESPRINT_HPP