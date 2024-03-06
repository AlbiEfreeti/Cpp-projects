#include "kundeliste.h"
#include <QTableView>

//der Konstruktor
//er erstellt den kompletten Inhalt
KundeListe::KundeListe()
{
    //den Fenstertitel setzen
    setWindowTitle("Listenanzeige Kunden");
    //das Modell erstellen
    QSqlTableModel *modell = new QSqlTableModel(this);
    //die Tabelle setzen
    modell->setTable("kunden");
    //die Texte für die Spaltenköpfe setzen
    modell->setHeaderData(0, Qt::Horizontal, "ID");
    modell->setHeaderData(1, Qt::Horizontal, "Vorname");
    modell->setHeaderData(2, Qt::Horizontal, "Name");
    modell->setHeaderData(3, Qt::Horizontal, "Strasse");
    modell->setHeaderData(4, Qt::Horizontal, "PLZ");
    modell->setHeaderData(5, Qt::Horizontal, "Ort");
    modell->setHeaderData(6, Qt::Horizontal, "Telefon");

    //die Daten beschaffen
    modell->select();

    //die TableView erstellen
    QTableView *ansicht = new QTableView(this);
    //mit dem Modell verbinden
    ansicht->setModel(modell);
    //die Spalte für die ID ausblenden
    ansicht->hideColumn(0);

    //die Breite der Spalten an den Inhalt anpassen
    ansicht->resizeColumnsToContents();
    //die Größe setzen
    ansicht->resize(500,300);

    //Einsendeaufgabe 17.3: bearbeiten in der Liste deaktivieren
    ansicht->setEditTriggers(QAbstractItemView::NoEditTriggers);
}