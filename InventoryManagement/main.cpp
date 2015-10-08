#include "homepage.h"
#include "loginDialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication gui(argc, argv);
    HomePage w;

    LoginDialog l;
    l.show();

    return gui.exec();
}
