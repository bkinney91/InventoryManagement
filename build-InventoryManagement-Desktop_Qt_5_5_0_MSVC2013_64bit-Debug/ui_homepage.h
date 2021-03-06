/********************************************************************************
** Form generated from reading UI file 'homepage.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGE_H
#define UI_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomePage
{
public:
    QAction *actionExit;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *Dashboard;
    QLabel *MTDLabel;
    QLabel *OrdersLabel;
    QLabel *ProfitLabel;
    QListWidget *OutOfStockList;
    QLabel *OutOfStockLabel;
    QLabel *OrderDisplay;
    QLabel *SalesDisplay;
    QLabel *OverheadLabel;
    QLabel *ValueLabel;
    QLabel *OverheadCostLabel;
    QLabel *OverheadNetLabel;
    QWidget *Inventory;
    QTableView *inventoryTable;
    QPushButton *addRecord;
    QPushButton *removeRecord;
    QWidget *Reports;
    QWidget *Administration;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HomePage)
    {
        if (HomePage->objectName().isEmpty())
            HomePage->setObjectName(QStringLiteral("HomePage"));
        HomePage->resize(903, 630);
        actionExit = new QAction(HomePage);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(HomePage);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 901, 571));
        Dashboard = new QWidget();
        Dashboard->setObjectName(QStringLiteral("Dashboard"));
        MTDLabel = new QLabel(Dashboard);
        MTDLabel->setObjectName(QStringLiteral("MTDLabel"));
        MTDLabel->setGeometry(QRect(20, 30, 281, 41));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        MTDLabel->setFont(font);
        MTDLabel->setLineWidth(1);
        OrdersLabel = new QLabel(Dashboard);
        OrdersLabel->setObjectName(QStringLiteral("OrdersLabel"));
        OrdersLabel->setGeometry(QRect(30, 100, 61, 16));
        QFont font1;
        font1.setPointSize(12);
        OrdersLabel->setFont(font1);
        ProfitLabel = new QLabel(Dashboard);
        ProfitLabel->setObjectName(QStringLiteral("ProfitLabel"));
        ProfitLabel->setGeometry(QRect(30, 160, 47, 13));
        ProfitLabel->setFont(font1);
        OutOfStockList = new QListWidget(Dashboard);
        OutOfStockList->setObjectName(QStringLiteral("OutOfStockList"));
        OutOfStockList->setGeometry(QRect(30, 310, 671, 192));
        OutOfStockLabel = new QLabel(Dashboard);
        OutOfStockLabel->setObjectName(QStringLiteral("OutOfStockLabel"));
        OutOfStockLabel->setGeometry(QRect(30, 230, 281, 41));
        OutOfStockLabel->setFont(font);
        OutOfStockLabel->setLineWidth(1);
        OrderDisplay = new QLabel(Dashboard);
        OrderDisplay->setObjectName(QStringLiteral("OrderDisplay"));
        OrderDisplay->setGeometry(QRect(110, 100, 141, 16));
        OrderDisplay->setFont(font1);
        SalesDisplay = new QLabel(Dashboard);
        SalesDisplay->setObjectName(QStringLiteral("SalesDisplay"));
        SalesDisplay->setGeometry(QRect(100, 160, 91, 16));
        SalesDisplay->setFont(font1);
        OverheadLabel = new QLabel(Dashboard);
        OverheadLabel->setObjectName(QStringLiteral("OverheadLabel"));
        OverheadLabel->setGeometry(QRect(400, 30, 281, 41));
        OverheadLabel->setFont(font);
        OverheadLabel->setLineWidth(1);
        ValueLabel = new QLabel(Dashboard);
        ValueLabel->setObjectName(QStringLiteral("ValueLabel"));
        ValueLabel->setGeometry(QRect(420, 100, 61, 16));
        ValueLabel->setFont(font1);
        OverheadCostLabel = new QLabel(Dashboard);
        OverheadCostLabel->setObjectName(QStringLiteral("OverheadCostLabel"));
        OverheadCostLabel->setGeometry(QRect(420, 150, 61, 16));
        OverheadCostLabel->setFont(font1);
        OverheadNetLabel = new QLabel(Dashboard);
        OverheadNetLabel->setObjectName(QStringLiteral("OverheadNetLabel"));
        OverheadNetLabel->setGeometry(QRect(420, 200, 61, 16));
        OverheadNetLabel->setFont(font1);
        tabWidget->addTab(Dashboard, QString());
        Inventory = new QWidget();
        Inventory->setObjectName(QStringLiteral("Inventory"));
        inventoryTable = new QTableView(Inventory);
        inventoryTable->setObjectName(QStringLiteral("inventoryTable"));
        inventoryTable->setGeometry(QRect(0, 0, 901, 371));
        addRecord = new QPushButton(Inventory);
        addRecord->setObjectName(QStringLiteral("addRecord"));
        addRecord->setGeometry(QRect(10, 390, 75, 23));
        removeRecord = new QPushButton(Inventory);
        removeRecord->setObjectName(QStringLiteral("removeRecord"));
        removeRecord->setGeometry(QRect(100, 390, 75, 23));
        tabWidget->addTab(Inventory, QString());
        Reports = new QWidget();
        Reports->setObjectName(QStringLiteral("Reports"));
        tabWidget->addTab(Reports, QString());
        Administration = new QWidget();
        Administration->setObjectName(QStringLiteral("Administration"));
        tabWidget->addTab(Administration, QString());
        HomePage->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(HomePage);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 903, 21));
        HomePage->setMenuBar(menuBar);
        mainToolBar = new QToolBar(HomePage);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        HomePage->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(HomePage);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        HomePage->setStatusBar(statusBar);

        retranslateUi(HomePage);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(HomePage);
    } // setupUi

    void retranslateUi(QMainWindow *HomePage)
    {
        HomePage->setWindowTitle(QApplication::translate("HomePage", "HomePage", 0));
        actionExit->setText(QApplication::translate("HomePage", "Exit", 0));
#ifndef QT_NO_TOOLTIP
        Dashboard->setToolTip(QApplication::translate("HomePage", "<html><head/><body><p>Dashboard</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        MTDLabel->setText(QApplication::translate("HomePage", "Month To Date", 0));
        OrdersLabel->setText(QApplication::translate("HomePage", "Orders", 0));
        ProfitLabel->setText(QApplication::translate("HomePage", "Sales", 0));
        OutOfStockLabel->setText(QApplication::translate("HomePage", "Out of Stock Items", 0));
        OrderDisplay->setText(QApplication::translate("HomePage", "Order Display", 0));
        SalesDisplay->setText(QApplication::translate("HomePage", "SalesDisplay", 0));
        OverheadLabel->setText(QApplication::translate("HomePage", "Overhead", 0));
        ValueLabel->setText(QApplication::translate("HomePage", "Value", 0));
        OverheadCostLabel->setText(QApplication::translate("HomePage", "Cost", 0));
        OverheadNetLabel->setText(QApplication::translate("HomePage", "Net", 0));
        tabWidget->setTabText(tabWidget->indexOf(Dashboard), QApplication::translate("HomePage", "Dashboard", 0));
        addRecord->setText(QApplication::translate("HomePage", "Add Item", 0));
        removeRecord->setText(QApplication::translate("HomePage", "Remove Item", 0));
        tabWidget->setTabText(tabWidget->indexOf(Inventory), QApplication::translate("HomePage", "Inventory", 0));
        tabWidget->setTabText(tabWidget->indexOf(Reports), QApplication::translate("HomePage", "Reports", 0));
        tabWidget->setTabText(tabWidget->indexOf(Administration), QApplication::translate("HomePage", "Administration", 0));
    } // retranslateUi

};

namespace Ui {
    class HomePage: public Ui_HomePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
