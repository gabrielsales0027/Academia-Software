#ifndef ACADEMIA_H
#define ACADEMIA_H

#include <QVector>
#include <pessoa.h>
#include <numeric>
#include <algorithm>
#include <pessoa.h>
class academia : public pessoa
{
private:
    QVector<pessoa> gym;
    int acima_do_peso = 0;
    double mensalidade = 80;
public:
    academia();
    void inserirPessoa(const pessoa p);
    void acimaDoPeso();
    float maiorImc();
    float saldo();
    void clear();
    int size();
    int find(QString nome);
    int getAcima_do_peso() const;
    void setAcima_do_peso(int value);
    void ordenarNome();
    void ordenarImc();
    pessoa operator[](int i);
};

#endif // ACADEMIA_H
