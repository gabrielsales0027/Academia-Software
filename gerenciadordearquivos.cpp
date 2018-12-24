#include "gerenciadordearquivos.h"

GerenciadordeArquivos::GerenciadordeArquivos()
{

}

bool GerenciadordeArquivos::salvarTurma(QString &arquivo, academia &academia)
{
    QFile file(arquivo);

    if(!file.open(QIODevice::WriteOnly)){
        return false;
    }

    QTextStream out(&file);

    for(int i=0;i<academia.size();i++){
        out << academia[i].getNome()<<","<<academia[i].getImc()<<"\n";
    }

    file.close();
    return true;
}

bool GerenciadordeArquivos::carregarTurma(QString &arquivo,academia &academia)
{
    QFile file(arquivo);

    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }

    QTextStream in(&file);

    QString linha;

    while(!in.atEnd()){
        linha = in.readLine();

        QStringList dados = linha.split(",");

        pessoa a;
        a.setNome(dados[0]);
        a.setImc(dados[1].toFloat());
        academia.inserirPessoa(a);

    }
    return true;
}
