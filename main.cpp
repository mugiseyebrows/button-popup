#include <QApplication>

#include "host.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Host host;
    host.show();

    return a.exec();
}
