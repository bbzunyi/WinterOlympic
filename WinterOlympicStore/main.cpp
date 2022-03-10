#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qputenv("QT_MAC_WANTS_LAYER", "1");
    Login w;
    w.show();
    return a.exec();
}
