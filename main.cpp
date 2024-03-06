#include <QApplication>
#include "bildbetrachter.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Bildbetrachter *betrachter = new Bildbetrachter();
    betrachter->show();

    return app.exec();
}
