#ifndef DATAAPP_H
#define DATAAPP_H

#include <QMainWindow>
#include <QDir>
#include <QString>

class QAction;
class QMenu;

namespace Ui {
class dataApp;
}

class dataApp : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit dataApp(QWidget *parent = 0);
    ~dataApp();
    
private:
    Ui::dataApp *ui;
    QDir dir;
    bool checkUserData();
    QString path;
    QString userData;
    void searchData(QString &);
    void searchData(QString &,QString &);
    void createActions();
    void createMenus();
    QAction *exportAction;
    QAction *aboutQtAction;
    QAction *aboutAction;
    QMenu *fileMenu;
    QMenu *helpMenu;


private slots:
    void enableButtons();
    void saveData();
    void search();
    void clearAll();
    void google();
    void deleteEntry();
    void exportFile();
    void about();

};

#endif // DATAAPP_H
