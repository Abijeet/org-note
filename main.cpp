#include <QtGui/QApplication>
#include "dataapp.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    dataApp w;
    w.show();
    
    return a.exec();
}
