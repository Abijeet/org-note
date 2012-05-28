/********************************************************************************
** Form generated from reading UI file 'exporttohtml.ui'
**
** Created: Sat May 12 19:32:32 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTTOHTML_H
#define UI_EXPORTTOHTML_H

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

class Ui_exportToHTML
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *listWidget;
    QLabel *descriptorLabel;

    void setupUi(QDialog *exportToHTML)
    {
        if (exportToHTML->objectName().isEmpty())
            exportToHTML->setObjectName(QString::fromUtf8("exportToHTML"));
        exportToHTML->resize(388, 374);
        buttonBox = new QDialogButtonBox(exportToHTML);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(20, 320, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        listWidget = new QListWidget(exportToHTML);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 40, 371, 271));
        descriptorLabel = new QLabel(exportToHTML);
        descriptorLabel->setObjectName(QString::fromUtf8("descriptorLabel"));
        descriptorLabel->setGeometry(QRect(20, 10, 351, 16));

        retranslateUi(exportToHTML);
        QObject::connect(buttonBox, SIGNAL(accepted()), exportToHTML, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), exportToHTML, SLOT(reject()));

        QMetaObject::connectSlotsByName(exportToHTML);
    } // setupUi

    void retranslateUi(QDialog *exportToHTML)
    {
        exportToHTML->setWindowTitle(QApplication::translate("exportToHTML", "Dialog", 0, QApplication::UnicodeUTF8));
        descriptorLabel->setText(QApplication::translate("exportToHTML", "Please choose the category to export to HTML :-", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class exportToHTML: public Ui_exportToHTML {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTTOHTML_H
