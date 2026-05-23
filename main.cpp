#include "Apresentacao/CtrlApresentacaoSistema.hpp"
#include "Servico/CtrlServicoPessoa.hpp"
#include "Servico/CtrlServicoProjeto.hpp"
#include "Servico/CtrlServicoPlanoSprint.hpp"
#include "Servico/CtrlServicoHistoriaUsuario.hpp"

int main() {
    CtrlServicoPessoa servicoPessoa;
    CtrlServicoProjeto servicoProjeto(&servicoPessoa);
    CtrlServicoPlanoSprint servicoPlano(&servicoProjeto);
    CtrlServicoHistoriaUsuario servicoHistoria(&servicoProjeto, &servicoPlano, &servicoPessoa);

    CtrlApresentacaoSistema apresentacao(&servicoPessoa, &servicoProjeto, &servicoPlano, &servicoHistoria);
    apresentacao.executar();

    return 0;
}
