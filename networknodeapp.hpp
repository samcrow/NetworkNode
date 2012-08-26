#ifndef NETWORKNODEAPP_HPP
#define NETWORKNODEAPP_HPP

#include <QMainWindow>

namespace Ui {
class NetworkNodeApp;
}

class NetworkNodeApp : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit NetworkNodeApp(QWidget *parent = 0);
    ~NetworkNodeApp();
    
private:
    Ui::NetworkNodeApp *ui;
};

#endif // NETWORKNODEAPP_HPP
