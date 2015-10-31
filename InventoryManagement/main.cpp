// main.cpp
//
// Author:      Bryce Kinney & Massimo Cannavo
//
// Description: The Inventory Management program will be initialized in the main
//              method. The main method is the starting state for the execution
//              of the program. It is also the final state for the termination
//              of the application.

#include "loginDialog.h"
#include <QApplication>

// The entry point for the application. The gui will be instantiated to render
// the design of the application. Once the gui is rendered the program will
// listen to specific events and will respond with the desired operation. The
// gui will be rerendered depending on the selection. Certain selections will
// change the state of the gui and it is therefore inevitable that the
// rerendering of the gui takes place.
//
// args:
//    argc    (int):   The number of command line arguments supplied.
//    argv[]  (char*): The values of the command line arguments supplied.
int main(int argc, char* argv[])
{
    QApplication gui(argc, argv);

    LoginDialog login;
    login.show();

    return gui.exec();
}
