#ifndef CTRLAPRESENTACAOPESSOA_HPP
#define CTRLAPRESENTACAOPESSOA_HPP

#include "../Interfaces/IApresentacaoPessoa.hpp"
#include "../Interfaces/IServicoPessoa.hpp"

/**
 * @brief Controlador da camada de apresentação para Pessoa.
 */
class CtrlApresentacaoPessoa : public IApresentacaoPessoa {
private:
    IServicoPessoa* servicoPessoa;
public:
    /**
     * @brief Define o serviço de pessoa.
     */
    void setServicoPessoa(IServicoPessoa* servico);

    /**
     * @brief Executa o fluxo de apresentação.
     */
    void executar() override;
};

#endif // CTRLAPRESENTACAOPESSOA_HPP
