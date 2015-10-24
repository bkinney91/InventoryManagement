/********************************************************************************
** Form generated from reading UI file 'loginDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *usernameLabel;
    QLineEdit *usernameInput;
    QHBoxLayout *horizontalLayout_2;
    QLabel *passwordLabel;
    QLineEdit *passwordInput;
    QVBoxLayout *verticalLayout_2;
    QPushButton *loginButton;
    QPushButton *cancelButton;
    QLabel *loginResult;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(425, 182);
        gridLayout = new QGridLayout(LoginDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        usernameLabel = new QLabel(LoginDialog);
        usernameLabel->setObjectName(QStringLiteral("usernameLabel"));

        horizontalLayout->addWidget(usernameLabel);

        usernameInput = new QLineEdit(LoginDialog);
        usernameInput->setObjectName(QStringLiteral("usernameInput"));
        usernameInput->setClearButtonEnabled(true);

        horizontalLayout->addWidget(usernameInput);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        passwordLabel = new QLabel(LoginDialog);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));

        horizontalLayout_2->addWidget(passwordLabel);

        passwordInput = new QLineEdit(LoginDialog);
        passwordInput->setObjectName(QStringLiteral("passwordInput"));
        passwordInput->setEchoMode(QLineEdit::Password);
        passwordInput->setClearButtonEnabled(true);

        horizontalLayout_2->addWidget(passwordInput);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        loginButton = new QPushButton(LoginDialog);
        loginButton->setObjectName(QStringLiteral("loginButton"));

        verticalLayout_2->addWidget(loginButton);

        cancelButton = new QPushButton(LoginDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        verticalLayout_2->addWidget(cancelButton);


        horizontalLayout_3->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        loginResult = new QLabel(LoginDialog);
        loginResult->setObjectName(QStringLiteral("loginResult"));
        loginResult->setFrameShape(QFrame::Box);
        loginResult->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(loginResult, 1, 0, 1, 1);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Dialog", 0));
        usernameLabel->setText(QApplication::translate("LoginDialog", "Username:", 0));
        passwordLabel->setText(QApplication::translate("LoginDialog", "  Password:", 0));
        loginButton->setText(QApplication::translate("LoginDialog", "Login", 0));
        cancelButton->setText(QApplication::translate("LoginDialog", "Cancel", 0));
        loginResult->setText(QApplication::translate("LoginDialog", "[+]Status", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
