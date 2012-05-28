#ifndef SEARCHRESULT_H
#define SEARCHRESULT_H

#include <QDialog>

namespace Ui {
  class searchResult;
}

class searchResult : public QDialog
{
  Q_OBJECT
  
public:
  explicit searchResult(QMap<int, QString> &mymap, QWidget *parent=0);
  int selectedID(){return id;}
  ~searchResult();
  void setLabel(const QString title, const QString label);
  
private:
  Ui::searchResult *ui;
  int id;



private slots:
  void done();

};

#endif // SEARCHRESULT_H
