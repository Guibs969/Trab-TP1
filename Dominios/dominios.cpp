#include "dominios.hpp"
#include <stdexcept>
#include <cctype>


void DominioString::setValor(string valor) {
 validar(valor);
 this->valor = valor;
}

void Codigo::validar(string valor){
// Implementar código de validação.
//codigo de 5 caracteres
// Lançar exceção quando o valor for inválido.
    if (valor.size() != 5 ||
        !isupper(valor[0]) || !isupper(valor[1]) ||
        !isdigit(valor[2]) || !isdigit(valor[3]) || !isdigit(valor[4])) {
        throw std::invalid_argument("Codigo deve ter 2 letras maiúsculas seguidas de 3 dígitos.");
    }
}

bool bissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

void Data::validar(string valor){
int mes = stoi(valor.substr(3, 2));
int dia = stoi(valor.substr(0, 2));
int ano = stoi(valor.substr(6, 4));

if (mes > 12 || mes < 1 || ano > 2999 || ano < 2000 || dia < 1 || dia > 31){
    throw std::invalid_argument("Data Invalida");
}
if(mes ==  4 || mes == 6 || mes == 9 || mes == 11){
if (dia > 30){
throw std::invalid_argument("Dia Nao Corresponde");
}
}
else if (mes == 2){
    if (bissexto(ano)){ //se o ano é bissexto, tem 29
if (dia > 29){
throw std::invalid_argument("Fevereiro Bissexto");
}
    }
else{
    if (dia > 28){
throw std::invalid_argument("Fevereiro Não Bissexto");
    }
}
}
}





void Email::validar(string valor) {

    if (valor.size() > 319) {
        throw invalid_argument("Muito longo");
    }

    // Encontrar '@'
    int posicao = -1;
    for (int i = 0; i < valor.size(); i++) {
        if (valor[i] == '@') {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        throw invalid_argument("Sem arroba");
    }

    // ======================
    // PARTE LOCAL
    // ======================

    if (posicao == 0) {
        throw invalid_argument("Parte local vazia");
    }

    if (valor[0] == '.' || valor[0] == '-') {
        throw invalid_argument("Inicio invalido");
    }

    if (valor[posicao - 1] == '.' || valor[posicao - 1] == '-') {
        throw invalid_argument("Fim da parte local invalido");
    }

    if (posicao > 64) {
        throw invalid_argument("Parte local muito longa");
    }

    for (int i = 0; i < posicao; i++) {

        if (!(isalpha(valor[i]) || isdigit(valor[i]) || valor[i] == '.' || valor[i] == '-')) {
            throw invalid_argument("Caractere invalido na parte local");
        }

        // '.' ou '-' deve ser seguido por letra ou digito
        if (valor[i] == '.' || valor[i] == '-') {
            if (i + 1 >= posicao || !(isalpha(valor[i + 1]) || isdigit(valor[i + 1]))) {
                throw invalid_argument("'.' ou '-' mal posicionado na parte local");
            }
        }
    }

    // ======================
    // DOMÍNIO
    // ======================

    if (posicao == valor.size() - 1) {
        throw invalid_argument("Dominio vazio");
    }

    int inicioDominio = posicao + 1;
    int tamanhoDominio = valor.size() - inicioDominio;

    if (tamanhoDominio > 255) {
        throw invalid_argument("Dominio muito longo");
    }

    if (valor[inicioDominio] == '-') {
        throw invalid_argument("Dominio comeca com '-'");
    }

    if (valor.back() == '-') {
        throw invalid_argument("Dominio termina com '-'");
    }

    for (int i = inicioDominio; i < valor.size(); i++) {

        if (!(isalpha(valor[i]) || isdigit(valor[i]) || valor[i] == '.' || valor[i] == '-')) {
            throw invalid_argument("Caractere invalido no dominio");
        }

        // '.' ou '-' deve ser seguido por letra ou digito
        if (valor[i] == '.' || valor[i] == '-') {
            if (i + 1 >= valor.size() || !(isalpha(valor[i + 1]) || isdigit(valor[i + 1]))) {
                throw invalid_argument("'.' ou '-' mal posicionado no dominio");
            }
        }
    }
}

const string Estado::ESTADO1 = "A FAZER";
const string Estado::ESTADO2 = "FAZENDO";
const string Estado::ESTADO3 = "FEITO";

void Estado::validar(string valor){
    if ((valor != ESTADO1) && (valor != ESTADO2) && (valor != ESTADO3)){
        throw invalid_argument("Estado Indefinido");
    }
}

const string Papel::ESTADO1 = "DESENVOLVEDOR";
const string Papel::ESTADO2 = "MESTRE SCRUM";
const string Papel::ESTADO3 = "PROPRIETARIO DE PRODUTO";

void Papel::validar(string valor){
    if ((valor != ESTADO1) && (valor != ESTADO2) && (valor != ESTADO3)){
        throw invalid_argument("Estado Indefinido");
    }
}

const string Prioridade::ESTADO1 = "ALTA";
const string Prioridade::ESTADO2 = "MEDIA";
const string Prioridade::ESTADO3 = "BAIXA";

void Prioridade::validar(string valor){
    if ((valor != ESTADO1) && (valor != ESTADO2) && (valor != ESTADO3)){
        throw invalid_argument("Estado Indefinido");
    }
}



