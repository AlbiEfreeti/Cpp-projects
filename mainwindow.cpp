#include "mainwindow.h"
#include "ui_mainwindow.h"
//die Header-Datei für das Kundenformular
#include "kundeneu.h"
//die Header-Datei für die Kundenliste
#include "kundeliste.h"
//die Header-Datei für die Einzelanzeige der Kunden
#include "kundeeinzel.h"
//die Header-Datei für das Fahrzeugformular
#include "fahrzeugneu.h"
//die Header-Datei für die Fahrzeugliste
#include "fahrzeugliste.h"
//die Header-Datei für die Einzelanzeige der Fahrzeuge
#include "fahrzeugeinzel.h"
//die Header-Datei für den Vertrag
#include "vertrag.h"
//die Header-Datei für die Rückgabe
#include "rueckgabe.h"
//die Header-Datei für die Reservierung
#include "reservierung.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dbVerbunden = dbVerbinden();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//die Methode stellt die Verbindung zur Datenbank her
bool MainWindow::dbVerbinden()
{
    bool gelungen = true;
    //die Verbindung zur Datenbank herstellen
    datenbank = QSqlDatabase::addDatabase("QSQLITE");
    datenbank.setDatabaseName("C:/Users/49178/OneDrive/Desktop/sqlite/sqlite-tools-win32-x86-3350400/auto2030.db");

    //konnte die Datenbank geöffnet werden?
    //wenn nicht, geben wir eine Meldung aus
    if (datenbank.open() == false)
    {
        //den Fehler beschaffen wir uns im Klartext
        QString fehler = datenbank.lastError().text();
        QMessageBox::critical(this, "Fehler", "Die Datenbank konnte nicht geöffnet werden.\nGrund: " + fehler);
        gelungen = false;
    }
    //sonst aktivieren wir die Prüfungen für Schlüsselverletzungen
    else
    {
        //die Abfrage über eine Instanz der Klasse QSqlQuery ausführen
        QSqlQuery abfrage(datenbank);
        abfrage.exec("PRAGMA foreign_keys = ON");
    }

    return gelungen;
}

//die Slots
void MainWindow::on_buttonListenAnzeigeKunde_clicked()
{
    //wenn eine Verbindung zu Datenbank besteht
    if (dbVerbunden == true)
    {
        //den Dialog anzeigen
        KundeListe *formKundeListe = new KundeListe();
        formKundeListe->show();
    }
}

void MainWindow::on_buttonEinzelAnzeigeKunde_clicked()
{
    //wenn eine Verbindung zu Datenbank besteht
    if (dbVerbunden == true)
    {
        //das Formular anzeigen
        KundeEinzel *formKundeEinzel = new KundeEinzel();
        formKundeEinzel->show();
    }
}

void MainWindow::on_buttonNeuerEintragKunde_clicked()
{
    //wenn eine Verbindung zu Datenbank besteht
    if (dbVerbunden == true)
    {
        //das Formular anzeigen
        KundeNeu *formKundeNeu = new KundeNeu();
        formKundeNeu->show();
    }
}

void MainWindow::on_buttonListenAnzeigeFahrzeug_clicked()
{
    //wenn eine Verbindung zu Datenbank besteht
    if (dbVerbunden == true)
    {
        //den Dialog anzeigen
        FahrzeugListe *formFahrzeugListe = new FahrzeugListe();
        formFahrzeugListe->show();
    }
}

void MainWindow::on_buttonEinzelAnzeigeFahrzeug_clicked()
{
    //wenn eine Verbindung zu Datenbank besteht
    if (dbVerbunden == true)
    {
        //den Dialog anzeigen
        FahrzeugEinzel *formFahrzeugEinzel = new FahrzeugEinzel();
        formFahrzeugEinzel->show();
    }
}

void MainWindow::on_buttonNeuerEintragFahrzeug_clicked()
{
    //wenn eine Verbindung zu Datenbank besteht
    if (dbVerbunden == true)
    {
        //den Dialog anzeigen
        FahrzeugNeu *formFahrzeugNeu = new FahrzeugNeu();
        formFahrzeugNeu->show();
    }
}


void MainWindow::on_buttonAusleihe_clicked()
{
    //wenn eine Verbindung zu Datenbank besteht
    if (dbVerbunden == true)
    {
        //den Dialog anzeigen
        Vertrag *ausleihe= new Vertrag();
        ausleihe->show();
    }
}

void MainWindow::on_buttonRueckgabe_clicked()
{
    //wenn eine Verbindung zu Datenbank besteht
    if (dbVerbunden == true)
    {
        //den Dialog anzeigen
        Rueckgabe *rueckgabe= new Rueckgabe();
        rueckgabe->show();
    }
}

void MainWindow::on_buttonReservierung_clicked()
{
    //wenn eine Verbindung zu Datenbank besteht
    if (dbVerbunden == true)
    {
        //den Dialog anzeigen
        Reservierung *reservierung= new Reservierung();
        reservierung->show();
    }
}




//die überschriebene Methode beim Schließen des Fensters
void MainWindow::closeEvent(QCloseEvent *)
{
    //die Datenbankverbindung schließen
    datenbank.close();
}
