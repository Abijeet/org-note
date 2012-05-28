#ifndef EXPORTTOHTML_H
#define EXPORTTOHTML_H

#include <QDialog>

namespace Ui {
class exportToHTML;
}

class exportToHTML : public QDialog
{
    Q_OBJECT
    
public:
    explicit exportToHTML(QWidget *parent = 0);
    ~exportToHTML();
    bool toHTML(const QString &catName, const QString &dataPath);       // Path of directory to be exported
    
private:
    Ui::exportToHTML *ui;
    void fileToHTML(const QString &fileName, const QString &filePath, const QString &pathToExport);      // Name of file to be exported, location to be exported to.
    void createIndexFile(const QString &filePath,const QString &catName);
};

#endif // EXPORTTOHTML_H
