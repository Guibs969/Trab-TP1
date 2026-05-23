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
    void setCodigo(const Codigo& codigo);
    Codigo getCodigo() const;

    void setTitulo(const Texto& titulo);
    Texto getTitulo() const;

    void setPapel(const Texto& papel);
    Texto getPapel() const;

    void setAcao(const Texto& acao);
    Texto getAcao() const;

    void setValor(const Texto& valor);
    Texto getValor() const;

    void setEstimativa(const Tempo& estimativa);
    Tempo getEstimativa() const;

    void setPrioridade(const Prioridade& prioridade);
    Prioridade getPrioridade() const;

    void setEstado(const Estado& estado);
    Estado getEstado() const;

    void setCodigoProjeto(const Codigo& codigoProjeto);
    Codigo getCodigoProjeto() const;

    void atribuirDesenvolvedor(const Email& desenvolvedor);
    void removerDesenvolvedor();
    bool possuiDesenvolvedor() const;
    Email getDesenvolvedor() const;
};

#endif // HISTORIADEUSUARIO_HPP
