#include "networknodeapp.hpp"
#include "ui_networknodeapp.h"

#include "nodefinder.hpp"

NetworkNodeApp::NetworkNodeApp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NetworkNodeApp)
{
    ui->setupUi(this);

    NodeFinder * finder = new NodeFinder(this);
}

NetworkNodeApp::~NetworkNodeApp()
{
    delete ui;
}
