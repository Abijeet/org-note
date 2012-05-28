#include "dataapp.h"
#include "ui_dataapp.h"
#include <QtGui>
#include "searchresult.h"
#include "exporttohtml.h"

dataApp::dataApp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dataApp)
{

    ui->setupUi(this);
    path = dir.homePath().append("/OrgNote");
    userData = path + "/UserData";

    dir.setPath(userData);
    bool check = checkUserData();
    if(!check)
    {
        ui->centralWidget->setDisabled(true);
        QMessageBox::critical(this,tr("Error"),tr("Could not create user data folder.\nCheck if you have write permissions."),QMessageBox::Ok);
    }

    createActions();
    createMenus();

    connect(ui->exitButton,SIGNAL(clicked()),this,SLOT(close()));           // Exit button.
    connect(ui->saveButton,SIGNAL(clicked()),this,SLOT(saveData()));        // Save Button
    connect(ui->searchButton,SIGNAL(clicked()),this,SLOT(search()));        // Search Button
    connect(ui->clearButton,SIGNAL(clicked()),this,SLOT(clearAll()));       // Clear Icon
    connect(ui->googleButton,SIGNAL(clicked()),this,SLOT(google()));        // Google Icon.
    connect(ui->deleteButton,SIGNAL(clicked()),this,SLOT(deleteEntry()));   // Delete Button


    connect(ui->nameEdit,SIGNAL(textChanged(QString)),this,SLOT(enableButtons()));       // Button Enabling
    connect(ui->tagComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(enableButtons()));
    connect(ui->tagComboBox,SIGNAL(editTextChanged(QString)),this,SLOT(enableButtons()));
    connect(ui->noteEdit,SIGNAL(textChanged()),this,SLOT(enableButtons()));

    ui->tagComboBox->insertItem(0,"None");
    QStringList list = dir.entryList(QDir::NoDotAndDotDot|QDir::Dirs,QDir::Time);
    ui->tagComboBox->insertItems(1,list);
    setWindowTitle("OrgNote");
}

dataApp::~dataApp()
{
    delete ui;
}
void dataApp::enableButtons()
{
    ui->saveButton->setEnabled(false);
    ui->searchButton->setEnabled(false);
    ui->clearButton->setEnabled(false);
    ui->googleButton->setEnabled(false);
    ui->deleteButton->setEnabled(false);
    //ui->tagComboBox->setEnabled(false);

    bool nameHasValue=!((ui->nameEdit->text()).isEmpty());
    bool tagHasValue=(!(ui->tagComboBox->currentIndex()==0)||(!(ui->tagComboBox->currentText()=="None") && !(ui->tagComboBox->currentText().isEmpty())));
    bool noteHasValue= !((ui->noteEdit->toPlainText()).isEmpty());


    if(nameHasValue && tagHasValue && noteHasValue)
        ui->saveButton->setEnabled(true);

    if(nameHasValue || tagHasValue)
        ui->searchButton->setEnabled(true);

    if(nameHasValue || tagHasValue || noteHasValue)
        ui->clearButton->setEnabled(true);

    if(nameHasValue || tagHasValue)
        ui->googleButton->setEnabled(true);

    if(nameHasValue && tagHasValue)
        ui->deleteButton->setEnabled(true);

}
bool dataApp::checkUserData()
{
    bool exists = dir.exists();         //Check if directory exists.
    if(exists)
        return true;

    bool mkdirSuccess = dir.mkpath(userData);     //Create if it doesn't.
    if(mkdirSuccess)
        return true;

    return false;           // Doesn't exist and could not create.
}
void dataApp::saveData()
{
    QString name = ui->nameEdit->text();
    QString tag = ui->tagComboBox->currentText();
    QString note = ui->noteEdit->toPlainText();
    QString newPath = userData + "/" + tag;
    bool fileExists = dir.exists(newPath);

    if(!fileExists)
        dir.mkdir(newPath);

    newPath = newPath + "/" + name + ".txt";

    fileExists = dir.exists(newPath);
    if(fileExists)
    {
        QMessageBox msg;

        msg.setWindowTitle("Entry exists");
        msg.setIcon(QMessageBox::Warning);
        msg.setText("Entry already exists.                     ");  //Spaces for sizing the message box, Qt doesn't handle that well.
        msg.setInformativeText("Do you want to edit the entry with the entered information?\n");
        msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msg.setDefaultButton(QMessageBox::Ok);

        int ret = msg.exec();
        if(ret == QMessageBox::Ok)
        {
            QFile file(newPath);
            if(file.open(QIODevice::WriteOnly))
            {
                QTextStream out(&file);
                out<<note;
             }

        }

    }
    QFile file(newPath);
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this,tr("Could not create/open file."),tr("Could not create or open file.\n Check if you have write permissions to the folder."),QMessageBox::Ok);
        return;
    }
    QTextStream out(&file);
    out<<note;
    dir.setPath(userData);          //Resetting the path at the end.
    ui->statusBar->showMessage("Entry Saved.",3000);
    clearAll();
    if(ui->tagComboBox->findText(tag) == -1)
    {
        ui->tagComboBox->addItem(tag);
    }
}
void dataApp::search()
{
    QString nameText = ui->nameEdit->text();
    QString tagText = ui->tagComboBox->currentText();

    if(nameText.isEmpty())
        searchData(tagText);

    else if(tagText == "None")
        searchData(nameText);

    else
        searchData(nameText, tagText);       // Both cannot be empty since then the search button would not be enabled.
}
void dataApp::searchData(QString &name, QString &tag)
{
    ui->statusBar->showMessage("Searching...");

    QString newPath = userData + "/" + tag + "/" + name + ".txt";       // Path to the file to be searched.
    bool fileExists = dir.exists(newPath);                          // Check to see if file exists.
    if(!fileExists)
    {
        QMessageBox::warning(this,"File not found","The file you are searching for was not found.",QMessageBox::Ok);    // File does not exist.
        return;
    }
    QFile file(newPath);
    file.open(QIODevice::ReadOnly);

    QString data;

    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        data.append(line);
        data.append("\n");
    }
    ui->noteEdit->setText(data);
    ui->nameEdit->setText(name);
    ui->tagComboBox->setEditText(tag);


    ui->statusBar->showMessage("Search successful.",3000);
    dir.setPath(userData);
}
void dataApp::searchData(QString &nameTag)
{
    QString newPath;

    if((ui->nameEdit->text()).isEmpty())            // Search with tag only. Display all the files in the folder with the tag.
    {
        newPath = userData + "/" + nameTag;
        bool exists = dir.exists(newPath);
        if(!exists)
        {
            QMessageBox::warning(this, "Tag not found","No files were tagged with the tag that you are searching for.",QMessageBox::Ok);  //Tag does not exists.
            return;
        }
        dir.setPath(newPath);
        QStringList fileList = dir.entryList(QDir::NoDotAndDotDot|QDir::Files,QDir::NoSort);
        QMap<int, QString> fileMap;
        int i = 1;    //  Integer used as key in map.
        for(QStringList::iterator iter = fileList.begin(); iter!= fileList.end(); ++iter)
        {
            iter->remove(iter->size()-4,4); // Removing the .txt part.
            fileMap.insert(i,*iter);
            ++i;
        }
        searchResult obj(fileMap,this);
        QString title = "Names - Choose One";
        QString label = "List of names categorized as " + nameTag + " :-";
        obj.setLabel(title,label);
        if(obj.exec())
        {
            int id = obj.selectedID();    // Retreiving the item selected in ListItemWidget in searchresult class.
            if(id == -1)
                return;

            searchData(fileMap[id],nameTag);
        }

    }
    if((ui->tagComboBox->currentIndex()) == 0)             // Search with name only. Display all the entries with the same name but different tags.
    {
        QStringList fileList = dir.entryList(QDir::NoDotAndDotDot|QDir::AllDirs,QDir::NoSort);
        QMap<int,QString> fileMap;
        int i = 1;

        for(QStringList::const_iterator iter = fileList.begin(); iter!= fileList.end();++iter)    //iter here represents the folder/tag name.
        {
            newPath = userData + "/" + *iter + "/" + nameTag + ".txt";
            if(dir.exists(newPath))
            {
                fileMap.insert(i,*iter);
                ++i;
            }
        }
        if(fileMap.empty())
        {
            QMessageBox::warning(this, "Entry not found","No entries were found with the given name.",QMessageBox::Ok);  // Name/Entry does not exists.
            return;
        }
        searchResult obj(fileMap,this);
        QString title = "Categories - Choose one";
        QString label = "List of categories with " + nameTag + " as entries :-";
        obj.setLabel(title,label);
        if(obj.exec())
        {
              int id = obj.selectedID();    // Retreiving the item selected in ListItemWidget in searchresult class.
              if(id == -1)
                  return;

              searchData(nameTag,fileMap[id]);
        }
    }
}
void dataApp::clearAll()
{
    ui->nameEdit->clear();
    ui->tagComboBox->setCurrentIndex(0);
    ui->noteEdit->clear();
}
void dataApp::google()
{
    QString textToSearch;
    QString tagHasValue = ui->tagComboBox->currentText();
    QString nameHasValue = ui->nameEdit->text();

    if(tagHasValue.isEmpty())
        textToSearch = "https://www.google.com/search?q=" + nameHasValue;

    else if(nameHasValue.isEmpty())
        textToSearch = "https://www.google.com/search?q=" + tagHasValue;

    else
        textToSearch = "https://www.google.com/search?q=" + nameHasValue + " " + tagHasValue;


     QDesktopServices::openUrl(QUrl(textToSearch));
}
/*
  Slot for the delete button. Only deletes when the tag and the name are
  specified. Does not delete to trash or Recycle Bin.
*/
void dataApp::deleteEntry()
{
    QMessageBox msg;
    msg.setWindowTitle("Delete confirmation.");
    msg.setIcon(QMessageBox::Warning);
    msg.setText("Delete file?                   ");
    msg.setInformativeText("Are you sure you want to delete the file?\n");
    msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msg.setDefaultButton(QMessageBox::Ok);

    int ret = msg.exec();
    if(ret == QMessageBox::Cancel)
        return;

    QString name = ui->nameEdit->text();
    QString tag = ui->tagComboBox->currentText();

    QString newPath = userData + "/" + tag + "/" + name + ".txt";
    if(!dir.exists(newPath))
    {
        QMessageBox::warning(this,"Error","File does not exist.",QMessageBox::Ok);
        return;
    }
    bool success = dir.remove(newPath);
    if(!success)
    {
        QMessageBox::warning(this,"Error","Unable to delete file, Check permissions",QMessageBox::Ok);
        return;
    }

    ui->statusBar->showMessage("Entry deleted.",3000);

    clearAll();
}
void dataApp::createActions()
{
    exportAction = new QAction(tr("&Export to HTML..."),this);
    exportAction->setShortcut(tr("Ctrl+E"));
    exportAction->setStatusTip("Create a new spreadsheet file.");
    connect(exportAction,SIGNAL(triggered()),this,SLOT(exportFile()));

    aboutAction = new QAction(tr("About"),this);
    aboutAction->setStatusTip("About OrgNote");
    connect(aboutAction,SIGNAL(triggered()),this,SLOT(about()));

    aboutQtAction = new QAction(tr("About Qt"),this);
    aboutQtAction->setStatusTip("Show the Qt Library's about box.");
    connect(aboutQtAction,SIGNAL(triggered()),qApp,SLOT(aboutQt()));

}
void dataApp::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(exportAction);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutQtAction);
    helpMenu->addAction(aboutAction);

}
void dataApp::exportFile()
{
    QStringList list = dir.entryList(QDir::NoDotAndDotDot|QDir::AllDirs,QDir::NoSort);
    int i=1;
    QMap<int, QString> fileMap;

    for(QStringList::const_iterator iter = list.begin(); iter!= list.end(); ++iter)
    {
        fileMap.insert(i,*iter);
        ++i;
    }
    searchResult obj(fileMap,this);
    obj.setLabel("Category - Choose","Choose a category to export to HTML :-");
    if(obj.exec())
    {
        int id = obj.selectedID();
        if(id== -1)
            return;

        exportToHTML object(this);
        object.toHTML(fileMap[id],path);

    }
}
void dataApp::about()
{
    QMessageBox::about(this, tr("About OrgNote"),tr("<h2>OrgNote 1.0 </h2>"
                                                    "<p>Author : Abijeet Patro</p>"
                                                    "<p>Thank you for using OrgNote.</p>"
                                                    "<p>Please provide your feedback to <a href=\"abijeetpatro@gmail.com\">abijeetpatro@gmail.com</a>.<br/><br/> If you wish to contribute to the project let me know</p>"));
}
