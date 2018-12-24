#ifndef GERENCIADORDEARQUIVOS_H
#define GERENCIADORDEARQUIVOS_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <QDebug>

#include "academia.h"
#include "pessoa.h"

class GerenciadordeArquivos
{
public:
    GerenciadordeArquivos();
    static bool salvarTurma(QString &arquivo, academia &academia);
    static bool carregarTurma(QString &arquivo, academia &academia);
};

#endif // GERENCIADORDEARQUIVOS_H
