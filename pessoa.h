#ifndef PESSOA_H
#define PESSOA_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class pessoa
{
private:
    QString nome;
    QString genero;
    int idade;
    float imc;
    float altura;
    float peso;
    int plano;
    float pesoMinimo;
    float pesoMaximo;

public:
    pessoa();
    void CalcularImc();
    QString getNome() const;
    void setNome(const QString &value);
    QString getGenero() const;
    void setGenero(const QString &value);
    int getIdade() const;
    void setIdade(int value);
    float getAltura() const;
    void setAltura(float value);
    float getPeso() const;
    void setPeso(float value);
    float getImc() const;
    void setImc(float value);
    int getPlano() const;
    void setPlano(int value);
    void recomend();
    float getPesoMaximo() const;
    void setPesoMaximo(float value);
    float getPesoMinimo() const;
    void setPesoMinimo(float value);
};

#endif // PESSOA_H
