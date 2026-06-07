#ifndef IAPRESENTACAOSISTEMA_HPP
#define IAPRESENTACAOSISTEMA_HPP

/**
 * @brief Interface para a camada de apresentação principal.
 * * Centraliza e orquestra a comunicação entre a interface do utilizador (UI) e 
 * os subsistemas de apresentação especializados.
 */
class IApresentacaoSistema {
public:
    /**
     * @brief Inicia a execução do fluxo principal da interface do sistema.
     * * Este método é responsável por manter o loop principal de iteração 
     * com o utilizador e a renderização do menu principal.
     */
    virtual void executar() = 0;
    
    /// @brief Destrutor virtual padrão.
    virtual ~IApresentacaoSistema() = default;
};

#endif // IAPRESENTACAOSISTEMA_HPP