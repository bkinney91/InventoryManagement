#include "homepage.h"
#include "loginDialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HomePage w;
    w.show();

    LoginDialog l;
    l.show();

    return a.exec();
}
