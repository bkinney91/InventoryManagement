#include "loginDialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication gui(argc, argv);

    LoginDialog l;
    l.show();

    return gui.exec();
}
