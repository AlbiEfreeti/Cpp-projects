#ifndef BILDBETRACHTER_H
#define BILDBETRACHTER_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTimer>

class Bildbetrachter : public QWidget
{
    Q_OBJECT
public:
    Bildbetrachter();

private slots:
    void naechstesBild();
    void beenden();

private:
    QLabel *bildLabel;
    QPushButton *beendenButton;
    QTimer *bildWechselTimer;

    QStringList bildDateien;
    int aktuellesBildIndex;

    void ladeBild(QString datei);
};

#endif // BILDBETRACHTER_H
