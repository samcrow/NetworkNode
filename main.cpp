#include <QtGui/QApplication>
#include "networknodeapp.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NetworkNodeApp w;
    w.show();
    
    return a.exec();
}
