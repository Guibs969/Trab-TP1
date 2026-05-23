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
    void setCodigo(const Codigo& codigo);
    Codigo getCodigo() const;

    void setNome(const Nome& nome);
    Nome getNome() const;

    void setInicio(const Data& inicio);
    Data getInicio() const;

    void setTermino(const Data& termino);
    Data getTermino() const;

    void setProprietario(const Email& proprietario);
    Email getProprietario() const;

    void setMestreScrum(const Email& mestreScrum);
    Email getMestreScrum() const;

    bool adicionarPlano(const Codigo& codigoPlano);
    bool adicionarHistoria(const Codigo& codigoHistoria);
    std::vector<Codigo> getPlanos() const;
    std::vector<Codigo> getHistorias() const;
};

#endif // PROJETO_HPP
