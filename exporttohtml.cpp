#include "exporttohtml.h"
#include "ui_exporttohtml.h"
#include <QDir>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

exportToHTML::exportToHTML(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::exportToHTML)
{
    ui->setupUi(this);

}

exportToHTML::~exportToHTML()
{
    delete ui;
}
bool exportToHTML::toHTML(const QString &catName,const QString &dataPath)
{
    QString path = dataPath + "/UserData/" + catName;      // Path of the category to be exported.
    QString pathToExport = dataPath + "/UserHTML/" + catName;  // Path to store the exported HTML
    QDir dir(path);
    if(!dir.exists(pathToExport))
    {
        if(!dir.mkpath(pathToExport))
        {
             QMessageBox::critical(this,tr("Error"),tr("Could not create user data folder.\nCheck if you have write permissions."),QMessageBox::Ok);
             return false;
        }
    }
    QStringList list= dir.entryList(QDir::NoDotAndDotDot|QDir::Files,QDir::Time|QDir::Reversed);
    for(QStringList::Iterator iter = list.begin(); iter != list.end(); ++iter)
    {
        fileToHTML(*iter,path+"/"+*iter,pathToExport);        // Convert file at "path+..." to file.html at datapath.
    }
    createIndexFile(pathToExport,catName);
    return true;
}
void exportToHTML::fileToHTML(const QString &fileName,const QString &filePath, const QString &pathToExport)
{
    QString data,line;
    QFile file(filePath);
    QString name= fileName;
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            line = in.readLine();
            data.append(line);
            data.append("\n");
        }
    }
    file.close();
    QString outputFile = pathToExport + "/" + name.remove(name.size()-4,4)+".html";     //Removing the .txt part from file name and building the path to store the file.
    QFile outFile(outputFile);
    if(outFile.open(QIODevice::WriteOnly))
    {
        QTextStream out(&outFile);

        /* Generating HTML */

        out<<"<html>";
        out<<"<head>";
        out<<"<title>"<<name<<"</title>";
        out<<"</head>";
        out<<"<body align=\"justify\" >";
        out<<"<h2 style='font-family:monospace'>"<< name<<"</h2>";
        out<<"<pre style='font-family:monospace'>";
        out<<data<<"\n";
        out<<"</pre>";
        out<<"<br/><br/>"<<"<a href=\"./index.html\">index</a>";
        out<<"</body>";
        out<<"</html>";
    }

}
void exportToHTML::createIndexFile(const QString &filePath,const  QString &catName)
{
    QDir dir1(filePath);
    QStringList fileList = dir1.entryList(QDir::NoDotAndDotDot|QDir::Files,QDir::NoSort);
    QString tempFileName;

    QFile indexFile(filePath+"/index.html");
    if(indexFile.open(QIODevice::WriteOnly))
    {
        QTextStream out(&indexFile);
        out<<"<html>";
        out<<"<head><title>"<<catName<<"</title></head>";
        out<<"<body align=\"justify\">";
        out<<"<h2 style='font-family:monospace'> Notes categorized under "<<catName<<"</h2>";
        out<<"<ul>";
        for(QStringList::const_iterator iter = fileList.begin(); iter!= fileList.end(); ++iter)
        {
            if(*iter == "index.html")
                continue;
            tempFileName = *iter;
            tempFileName.remove(tempFileName.size()-5,5);

            out<<"<li><a href=\"./"<<*iter<<"\">"<<tempFileName<<"</a></li>\n";
        }
        out<<"</ul>";
        out<<"</body>";
        out<<"</html>";

    }
}
