#ifndef IAPRESENTACAOSISTEMA_HPP
#define IAPRESENTACAOSISTEMA_HPP

/**
 * @brief Interface para a camada de apresentação principal.
 */
class IApresentacaoSistema {
public:
    virtual void executar() = 0;
    virtual ~IApresentacaoSistema() = default;
};

#endif // IAPRESENTACAOSISTEMA_HPP
