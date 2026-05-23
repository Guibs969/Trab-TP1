#ifndef CONTAINERHISTORIADEUSUARIO_HPP
#define CONTAINERHISTORIADEUSUARIO_HPP

#include "../Entidades/HistoriaDeUsuario.hpp"
#include <vector>

/**
 * @brief Container simples para armazenamento de histórias de usuário.
 */
class ContainerHistoriaUsuario {
private:
    std::vector<HistoriaDeUsuario> historias;
public:
    bool existe(const Codigo& codigo) const;
    bool inserir(const HistoriaDeUsuario& historia);
    bool atualizar(const HistoriaDeUsuario& historia);
    bool remover(const Codigo& codigo);
    bool buscar(const Codigo& codigo, HistoriaDeUsuario& historia) const;
    std::vector<HistoriaDeUsuario> listar() const;
};

#endif // CONTAINERHISTORIADEUSUARIO_HPP
