//           a8888b.
//          d888888b.
//          8P"YP"Y88
//          8|o||o|88
//          8'    .88
//          8`._.' Y8.
//         d/      `8b.
//        dP   .    Y8b.
//       d8:'  "  `::88b
//      d8"         'Y88b
//      :8P    '      :888
//       8a.   :     _a88P
//     ._/"Yaa_:   .| 88P|
//jgs  \    YP"    `| 8P  `.
//a:f  /     \.___.d|    .'
//     `--..__)8888P`._.'
//
// Author:      Massimo Cannavo
//
// Description: The header definition for the login dialog. The user will be
//              prompted with a dialog to login into the inventory management
//              system. On success login, the graphical user interface (gui)
//              of the inventory management system will be executed.

#ifndef LOGIN_DIALOG_H
#define LOGIN_DIALOG_H

#include <QDialog>
#include <QtSql>
#include <QFileInfo>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class LoginDialog;
}

// The login dialog consists of a QDialog that creates the interface for the
// gui dialog. The QDialog class renders the gui of the dialog on the screen.
class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0); // Construct the login dialog.
    ~LoginDialog();                            // Destruct the login dialog.

private slots:
    void on_loginButton_clicked();  // Slot for the login button clicked signal.
    void on_cancelButton_clicked(); // Slot for the cancel button clicked signal.

private:
    Ui::LoginDialog *ui;

    QSqlDatabase posDatabase; // The connection to the pos database.
    QString pathDatabase;     // The path of the database.
};

#endif // DIALOG_H
