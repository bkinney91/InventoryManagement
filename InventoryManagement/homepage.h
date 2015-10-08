#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QMainWindow>
#include <QSqlDatabase>

namespace Ui
{
    class HomePage;
}

class HomePage : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = 0);
    ~HomePage();
    void setDatabase(QSqlDatabase posDatabase) { database = posDatabase; }

private:
    Ui::HomePage *ui;
    QSqlDatabase database;
};

#endif
