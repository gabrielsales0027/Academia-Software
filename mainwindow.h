#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <pessoa.h>
#include <academia.h>
#include <QDebug>
#include <QVector>
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QComboBox>
#include <gerenciadordearquivos.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    academia rica;
    pessoa fulano;
    Ui::MainWindow *ui;
    void ColocarNaTabela(pessoa p, int row);
    void ColocarNaTabela2(int row, int pos);
    void atualizarestatisticas();
    void mostrarDetalhes();
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_cadastrar_clicked();
    void on_sexfemin_clicked();
    void on_sexmasc_clicked();

    void on_porNome_clicked();
    void on_porImc_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void salvar();
    void carregar();
};

#endif // MAINWINDOW_H
