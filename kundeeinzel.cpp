#include "kundeeinzel.h"
#include "ui_kundeeinzel.h"
#include <QtSql>
#include <QMessageBox>

//der Konstruktor
//er verbindet das Formular mit der Oberfläche und stellt die Verbindungen her
KundeEinzel::KundeEinzel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KundeEinzel)
{
    ui->setupUi(this);
    verbindungenHerstellen();
    datenMappen();
}

KundeEinzel::~KundeEinzel()
{
    delete ui;
}

void KundeEinzel::verbindungenHerstellen()
{
    //die Verbindungen herstellen
    connect(ui->actionGanz_nach_vorne, SIGNAL(triggered(bool)), this, SLOT(ganzNachVorne()));
    connect(ui->actionEinen_nach_vorne, SIGNAL(triggered(bool)), this, SLOT(einenNachVorne()));
    connect(ui->actionEinen_nach_hinten, SIGNAL(triggered(bool)), this, SLOT(einenNachHinten()));
    connect(ui->actionGanz_nach_hinten, SIGNAL(triggered(bool)), this, SLOT(ganzNachHinten()));
    connect(ui->actionL_schen, SIGNAL(triggered(bool)), this, SLOT(loeschen()));
}
//17.3 Einsendeaufgabe
void KundeEinzel::loeschen()
{
    // Prüfen, ob alle erforderlichen Felder gefüllt sind
    if (ui->lineEditVorname->text().isEmpty() ||
        ui->lineEditName->text().isEmpty() ||
        ui->lineEditStrasse->text().isEmpty() ||
        ui->lineEditPLZ->text().isEmpty() ||
        ui->lineEditOrt->text().isEmpty() ||
        ui->lineEditTelefon->text().isEmpty())
    {
        QMessageBox::warning(this, "Warnung", "Bitte füllen Sie alle Felder aus.");
        return;
    }

    //den aktuellen Index merken
    int index = mapper->currentIndex();
    //den Eintrag löschen
    modell->removeRow(mapper->currentIndex());
    //die Änderungen übernehmen
    mapper->submit();
    //die Daten neu beschaffen
    modell->select();
    //wieder zum ursprünglichen Datensatz gehen
    //aber nur dann, wenn nicht der letzte gelöscht wurde
    //wenn der letzte Datensatz gelöscht wurde, gehen wir zum neuen "letzten"
    if (index < modell->rowCount())
        mapper->setCurrentIndex(index);
    else
        mapper->toLast();
}

void KundeEinzel::datenMappen()
{
    //das Modell erstellen
    modell = new QSqlTableModel(this);
    //die Tabelle setzen
    modell->setTable("kunden");
    //die Daten beschaffen
    modell->select();

    //die Verbindungen zwischen den Widgets und den Daten herstellen
    mapper = new QDataWidgetMapper(this);
    mapper->setModel(modell);
    mapper->addMapping(ui->lineEditID, 0);
    mapper->addMapping(ui->lineEditVorname, 1);
    mapper->addMapping(ui->lineEditName, 2);
    mapper->addMapping(ui->lineEditStrasse, 3);
    mapper->addMapping(ui->lineEditPLZ, 4);
    mapper->addMapping(ui->lineEditOrt, 5);
    mapper->addMapping(ui->lineEditTelefon, 6);

    //Änderungen sollen automatisch übernommen werden
    mapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    //zum ersten Datensatz gehen
    mapper->toFirst();
}

//die Slots zum Navigieren
//ganz nach vorne springen
void KundeEinzel::ganzNachVorne()
{
    mapper->toFirst();
}

//einen nach vorne springen
void KundeEinzel::einenNachVorne()
{
    mapper->toPrevious();
}

//einen nach hinten springen
void KundeEinzel::einenNachHinten()
{
    mapper->toNext();
}

//ganz nach hinten springen
void KundeEinzel::ganzNachHinten()
{
    mapper->toLast();
}

