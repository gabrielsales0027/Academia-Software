#include "pessoa.h"


QString pessoa::getNome() const
{
    return nome;
}

void pessoa::setNome(const QString &value)
{
    nome = value;
}

QString pessoa::getGenero() const
{
    return genero;
}

void pessoa::setGenero(const QString &value)
{
    genero = value;
}

int pessoa::getIdade() const
{
    return idade;
}

void pessoa::setIdade(int value)
{
    idade = value;
}

float pessoa::getAltura() const
{
    return altura;
}

void pessoa::setAltura(float value)
{
    altura = value;
}

float pessoa::getPeso() const
{
    return peso;
}

void pessoa::setPeso(float value)
{
    peso = value;
}

//pessoa::pessoa(QString n, QString g, int i, float a, float b)
//{
//    nome=n;
 //   genero=g;
 //   idade=i;
 //   altura=a;
 //   peso=b;
  //  CalcularImc();
//}

float pessoa::getImc() const
{
    return imc;
}

void pessoa::setImc(float value)
{
    imc = value;
}

int pessoa::getPlano() const
{
    return plano;
}

void pessoa::setPlano(int value)
{   if(value == 0) {
    plano = 1;
    }
    if(value == 1) {
        plano = 3;
        }
    if(value == 2) {
        plano = 6;
        }
    if(value == 3) {
        plano = 9;
        }
    if(value == 4) {
        plano = 12;
    }
}

void pessoa::recomend()
{
    pesoMaximo = 24.9*altura*altura;
    pesoMinimo = 18.5*altura*altura;
}

float pessoa::getPesoMaximo() const
{
    return pesoMaximo;
}

void pessoa::setPesoMaximo(float value)
{
    pesoMaximo = value;
}

float pessoa::getPesoMinimo() const
{
    return pesoMinimo;
}

void pessoa::setPesoMinimo(float value)
{
    pesoMinimo = value;
}

pessoa::pessoa()
{

}

void pessoa::CalcularImc()
{
    imc = (peso)/(altura*altura);
}
