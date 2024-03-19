#include "vectorapp.h"
#include "ui_vectorapp.h"

#include <QMessageBox>

//EINSENDEAUFGABE 18.1 Beschreibung: Ich wollte mein Programm simpel halten. Die Eingabe der Werte im Hauptfenster erfolgt ueber den User. Man kann so viele Werte eingeben
//wie man moechte, es wird auch geprueft, ob es Integers sind oder nicht. Dann gibt es eine Funktion um den Vorgang wieder zu loeschen. Ich arbeite hier mit Vektoren und
//dessen Bibliothek, ich finde es so am einfachsten. Um den Vektor zu sortieren erstelle ich einen neuen Vektor, die Duplikate werden entfernt. Zum Schluss werden die
//geordneten Integer Werte in einem Listenfeld angezeigt.

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_enter_clicked()
{
    QString input = ui->lineEdit->text();
        bool ok;
        int value = input.toInt(&ok);

        if (ok) {

            enteredIntegers.push_back(value);

            QMessageBox::information(this, "Integer Entered", "Integer has been saved.");
        } else {

            QMessageBox::warning(this, "Invalid Input", "Please enter a valid integer.");
        }


        ui->lineEdit->clear();
}



void MainWindow::on_delete_2_clicked()
{
    //loescht alle Elemente im Vektor
    enteredIntegers.clear();
    QMessageBox::information(this, "Deleted", "All Elements have been deleted.");
    ui->output->clear();

}


void MainWindow::on_sortdisplay_clicked()
{

        std::sort(enteredIntegers.begin(), enteredIntegers.end());


        std::vector<int> uniqueSortedIntegers; //neuer Vektor


        for (int i = 0; i < enteredIntegers.size(); ++i) {

            if (i == 0 || enteredIntegers[i] != enteredIntegers[i - 1]) {
                uniqueSortedIntegers.push_back(enteredIntegers[i]);
            }


           ui->output->clear();


           for (int i = 0; i < uniqueSortedIntegers.size(); ++i) {
                    ui->output->append(QString::number(uniqueSortedIntegers[i]));
}
}
}
