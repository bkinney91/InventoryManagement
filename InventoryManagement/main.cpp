#include "homepage.h"
#include "loginDialog"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HomePage w;
    w.show();

    LoginDialog d;
    d.show();

    return a.exec();
}
