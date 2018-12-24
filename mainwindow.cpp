#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pessoa.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   for(int i = 0;i<5;i++){
       if(i==0){
       ui->caixa->addItem(QString::number(i+1) + " Mês");
       }
       else{
     ui->caixa->addItem(QString::number(i*3) + " Meses");
       }

}
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ColocarNaTabela(pessoa p, int row)
{
    ui->tabela->setItem(row,0,new QTableWidgetItem(p.getNome()));
    ui->tabela->setItem(row,1,new QTableWidgetItem(QString::number(p.getIdade())));
    ui->tabela->setItem(row,2,new QTableWidgetItem(QString::number(p.getAltura())));
    ui->tabela->setItem(row,3,new QTableWidgetItem(QString::number(p.getPeso())));
    ui->tabela->setItem(row,4,new QTableWidgetItem(p.getGenero()));
    ui->tabela->setItem(row,5,new QTableWidgetItem(QString::number(p.getImc())));
}

void MainWindow::ColocarNaTabela2(int row,int pos)
{
    ui->tabela2->setItem(row,0,new QTableWidgetItem(rica[pos].getNome()));
    ui->tabela2->setItem(row,1,new QTableWidgetItem(QString::number(rica[pos].getPlano())+" Meses"));
    ui->tabela2->setItem(row,2,new QTableWidgetItem(QString::number(rica[pos].getImc())));


    qDebug()<<"O peso ideal do usuário é entre:"<<rica[pos].getPesoMinimo()  << "e"<< rica[pos].getPesoMaximo();
    ui->recomendacao->setText("O peso ideal do usuário é entre:" + QString::number(rica[pos].getPesoMinimo())+ " e " +QString::number(rica[pos].getPesoMaximo()));
}

void MainWindow::atualizarestatisticas()
{
    rica.acimaDoPeso();
    ui->mostrar2->setText(QString::number(rica.getAcima_do_peso(),'i',0));
    ui->mostrar1->setText(QString::number(rica.size(),'i',0));
    ui->mostrar3->setText(QString::number(rica.maiorImc(),'f',4));
    ui->mostrar4->setText(QString::number(rica.saldo(),'f',4));
    rica.setAcima_do_peso(0);
}

void MainWindow::on_cadastrar_clicked()
{
    if(ui->linha1->text().size() != 0 && ui->linha2->text().size() != 0 && ui->linha3->text().size() != 0 && ui->linha4->text().size() != 0){
        fulano.setNome(ui->linha1->text());
        fulano.setPeso(ui->linha2->text().toFloat());
        fulano.setAltura(ui->linha3->text().toFloat());
        fulano.setIdade(ui->linha4->text().toInt());
        fulano.CalcularImc();
        fulano.recomend();

        int qnt_row = ui->tabela->rowCount();

        ui->tabela->insertRow(qnt_row);
        ColocarNaTabela(fulano, qnt_row);

        ui->linha1->clear();
        ui->linha2->clear();
        ui->linha3->clear();
        ui->linha4->clear();

        int t = ui->caixa->currentIndex();
        qDebug() << t;
        fulano.setPlano(t);
        rica.inserirPessoa(fulano);

       // fulano.setPlano(ui->caixa->currentText());

        atualizarestatisticas();
    }
}

void MainWindow::on_sexfemin_clicked()
{
    QString temporaria = "Feminino";
    fulano.setGenero(temporaria);

}


void MainWindow::on_sexmasc_clicked()
{
    QString temporaria = "Masculino";
    fulano.setGenero(temporaria);
}


void MainWindow::on_porNome_clicked()
{
    ui->tabela->clearContents();

    rica.ordenarNome();
    for(int i = 0; i<rica.size(); i++){
        ColocarNaTabela(rica[i], i);
    }
}

void MainWindow::on_porImc_clicked()
{
    ui->tabela->clearContents();
    rica.ordenarImc();
    for(int i = 0; i<rica.size();i++){
        ColocarNaTabela(rica[i],i);
    }
}

void MainWindow::on_pushButton_clicked()
{
    int pos;
    if(ui->pesquisar->text().size() != 0){
        QString temp = ui->pesquisar->text();
        pos = rica.find(temp);
        qDebug()<< pos;
        if(pos >= 0 ){
            int qnt_row = ui->tabela2->rowCount();
            ui->tabela2->insertRow(qnt_row);
            qDebug()<<  rica[pos].getPesoMinimo() << rica[pos].getPesoMaximo();
            ColocarNaTabela2(qnt_row,pos);
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tabela->clearContents();
    rica.clear();
}


void MainWindow::salvar()
{

    QString nomeArquivo = QFileDialog::getSaveFileName(this,"Lista de Alunos","","Texto Puro(*.txt);;Arquivos Separado por Vírgulas(*.csv)");
    if( GerenciadordeArquivos::salvarTurma(nomeArquivo,rica) ){
        QMessageBox::information(this, "Salvar turma","Dados Salvos com Sucesso");
    }else{
        QMessageBox::information(this, "Salvar turma","Não foi possível salvar os dados");
    }

}

void MainWindow::carregar()
{
    QString nomeArquivo = QFileDialog::getOpenFileName(this,"Lista de Alunos","","Texto Puro(*.txt);;Arquivos Separado por Vírgulas(*.csv)");
    rica.clear();

    if(GerenciadordeArquivos::carregarTurma(nomeArquivo,rica)){

        ui->tabela->clearContents();
        for(int i=0;i<rica.size();i++){

            if(i >= ui->tabela->rowCount())
                ui->tabela->insertRow(i);

            ColocarNaTabela(rica[i],i);
        }

    }else{
        QMessageBox::information(this, "Carregar turma","Não foi possível carregar os dados");
    }

}

