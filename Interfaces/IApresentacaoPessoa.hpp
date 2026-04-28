#ifndef IAPRESENTACAOPESSOA_HPP
#define IAPRESENTACAOPESSOA_HPP

/**
 * @brief Interface para apresentação de pessoa.
 */
class IApresentacaoPessoa {
public:
    /**
     * @brief Executa o fluxo de apresentação.
     */
    virtual void executar() = 0;

    /// @brief Destrutor virtual.
    virtual ~IApresentacaoPessoa() = default;
};

#endif // IAPRESENTACAOPESSOA_HPP
