#include "searchresult.h"
#include "ui_searchresult.h"
/*
 Constructor. Takes a QMap<int,QString> which it displays in the list widget.
*/
searchResult::searchResult(QMap<int,QString> &mymap,QWidget *parent) :
  QDialog(parent),
  ui(new Ui::searchResult)
{
  ui->setupUi(this);
  ui->descriptorLabel->setHidden(true);

  id = -1;
  for(QMap<int,QString>::const_iterator mapIt = mymap.begin(); mapIt!= mymap.end(); ++mapIt)
  {
      QListWidgetItem * item = new QListWidgetItem(mapIt.value(),ui->resultList);
      item->setData(Qt::UserRole,mapIt.key());

  }
  connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(done()));
  connect(ui->buttonBox,SIGNAL(rejected()),this,SLOT(done()));

}
/*
  Sets the label and the window title for the dialog box.
*/
void searchResult::setLabel(const QString title, const QString label)
{
  ui->descriptorLabel->setHidden(false);
  this->setWindowTitle(title);
  ui->descriptorLabel->setText(label);
}
/*
  Destructor
*/
searchResult::~searchResult()
{
  delete ui;
}
/*
  Slot that handles user input and stores the input that user
  user selected.
*/
void searchResult::done()
{

  if(result() == QDialog::Accepted)
  {
      QListWidgetItem *item = ui->resultList->currentItem();
      if(item)
        id = item->data(Qt::UserRole).toInt();
  }

  QDialog::done(result());
}
