#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED
#include <string>
#include <stdexcept>

using namespace std;

class DominioString {
private:
std::string valor;
virtual void validar(string) = 0; // Método abstrato.
public:
void setValor(string); // Método para atribuir valor.
string getValor() const; // Método para recuperar valor.
};

inline string DominioString::getValor() const{ // Implementação de método.
 return valor;
}

class Codigo: public DominioString{
private:
void validar(string);
static const int LIMITE = 5; //tamanho maximo yeah
public:


};

class Data: public DominioString{
private:
void validar(string);
static const int LIMITE = 11; //tamanho maximo yeah
public:
};

class Email: public DominioString{
private:
void validar(string);
static const int LIMITE1 = 64;
static const int LIMITE2 = 255;
public:
};

class Estado: public DominioString{
private:
void validar(string);
    static const string ESTADO1;
    static const string ESTADO2;
    static const string ESTADO3;
public:
};

class Papel: public DominioString{
private:
void validar(string);
    static const string ESTADO1;
    static const string ESTADO2;
    static const string ESTADO3;
public:
};

class Prioridade: public DominioString{
private:
void validar(string);
    static const string ESTADO1;
    static const string ESTADO2;
    static const string ESTADO3;
public:
};











#endif // DOMINIOS_HPP_INCLUDED
