#include "bildbetrachter.h"
#include <QPixmap>

Bildbetrachter::Bildbetrachter()
{
    resize(500, 280);
    setWindowTitle("Bilderschau");

    bildLabel = new QLabel(this);
    bildLabel->setGeometry(10, 10, 480, 240);

    beendenButton = new QPushButton("Beenden", this);
    beendenButton->setGeometry(10, 250, 70, 30);
    connect(beendenButton, SIGNAL(clicked()), this, SLOT(beenden()));

    bildDateien << "C:/Users/49178/OneDrive/Desktop/Academy C++/Einsendeaufgabe 11/bild1.jpeg" << "C:/Users/49178/OneDrive/Desktop/Academy C++/Einsendeaufgabe 11/bild2.jpeg"; //Bilder Beispiel
    aktuellesBildIndex = 0;

    ladeBild(bildDateien[aktuellesBildIndex]);

    bildWechselTimer = new QTimer(this);
    connect(bildWechselTimer, SIGNAL(timeout()), this, SLOT(naechstesBild()));
    bildWechselTimer->start(5000); // Wechsel alle 5 Sekunden
}

void Bildbetrachter::ladeBild(QString datei)
{
    QPixmap bild;
    if (bild.load(datei))
    {
        bildLabel->setPixmap(bild.scaled(bildLabel->size(), Qt::KeepAspectRatio));
    }
}

void Bildbetrachter::naechstesBild()
{
    aktuellesBildIndex = (aktuellesBildIndex + 1) % bildDateien.size();
    ladeBild(bildDateien[aktuellesBildIndex]);
}

void Bildbetrachter::beenden()
{
    close();
}
