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
    void setCodigo(const Codigo& codigo);
    Codigo getCodigo() const;

    void setObjetivo(const Texto& objetivo);
    Texto getObjetivo() const;

    void setCapacidade(const Tempo& capacidade);
    Tempo getCapacidade() const;

    void setCodigoProjeto(const Codigo& codigoProjeto);
    Codigo getCodigoProjeto() const;

    bool adicionarHistoria(const Codigo& codigoHistoria);
    bool removerHistoria(const Codigo& codigoHistoria);
    std::vector<Codigo> getHistorias() const;
};

#endif // PLANODESPRINT_HPP
