#include "homepage.h"
#include "ui_homepage.h"

extern bool is_linux;
extern bool is_windows;

HomePage::HomePage(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);

    QStringList data;
    data << "Massimo" << "Jimmy" << "Mike Tyson";

    stringCompleter = new QCompleter(data, this);
    stringCompleter->setCaseSensitivity(Qt::CaseInsensitive);

    ui->parts->setCompleter(stringCompleter);
}

HomePage::~HomePage()
{
    delete ui;
}
