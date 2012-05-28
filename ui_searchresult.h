/********************************************************************************
** Form generated from reading UI file 'searchresult.ui'
**
** Created: Sun May 13 10:48:32 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHRESULT_H
#define UI_SEARCHRESULT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_searchResult
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *resultList;
    QLabel *descriptorLabel;

    void setupUi(QDialog *searchResult)
    {
        if (searchResult->objectName().isEmpty())
            searchResult->setObjectName(QString::fromUtf8("searchResult"));
        searchResult->resize(388, 374);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/main-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchResult->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(searchResult);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(20, 320, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        resultList = new QListWidget(searchResult);
        resultList->setObjectName(QString::fromUtf8("resultList"));
        resultList->setGeometry(QRect(10, 40, 371, 271));
        descriptorLabel = new QLabel(searchResult);
        descriptorLabel->setObjectName(QString::fromUtf8("descriptorLabel"));
        descriptorLabel->setGeometry(QRect(10, 10, 351, 16));

        retranslateUi(searchResult);
        QObject::connect(buttonBox, SIGNAL(accepted()), searchResult, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), searchResult, SLOT(reject()));

        QMetaObject::connectSlotsByName(searchResult);
    } // setupUi

    void retranslateUi(QDialog *searchResult)
    {
        searchResult->setWindowTitle(QApplication::translate("searchResult", "Dialog", 0, QApplication::UnicodeUTF8));
        descriptorLabel->setText(QApplication::translate("searchResult", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class searchResult: public Ui_searchResult {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHRESULT_H
