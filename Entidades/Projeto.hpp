#ifndef PROJETO_HPP
#define PROJETO_HPP

#include "../Dominios/Codigo.hpp"
#include <string>

/**
 * @brief Classe de entidade para representar um projeto.
 */
class Projeto {
private:
    Codigo codigo;
    std::string nome;
    std::string inicio;
    std::string termino;
public:
    /**
     * @brief Define o código do projeto.
     */
    void setCodigo(const Codigo& codigo);

    /**
     * @brief Retorna o código do projeto.
     */
    Codigo getCodigo() const;

    /**
     * @brief Define o nome do projeto.
     */
    void setNome(const std::string& nome);

    /**
     * @brief Retorna o nome do projeto.
     */
    std::string getNome() const;

    /**
     * @brief Define a data de início.
     */
    void setInicio(const std::string& inicio);

    /**
     * @brief Retorna a data de início.
     */
    std::string getInicio() const;

    /**
     * @brief Define a data de término.
     */
    void setTermino(const std::string& termino);

    /**
     * @brief Retorna a data de término.
     */
    std::string getTermino() const;
};

#endif // PROJETO_HPP
