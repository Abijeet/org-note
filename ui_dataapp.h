/********************************************************************************
** Form generated from reading UI file 'dataapp.ui'
**
** Created: Sat May 12 16:38:49 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAAPP_H
#define UI_DATAAPP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dataApp
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QGridLayout *centralGridLayout;
    QSpacerItem *secondVerticalSpacer;
    QHBoxLayout *secondHorizontalLayout;
    QLabel *noteLabel;
    QTextEdit *noteEdit;
    QSpacerItem *firstVerticalSpacer;
    QFrame *buttonFrame;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *hSpacer1;
    QPushButton *saveButton;
    QSpacerItem *hSpacer3;
    QPushButton *searchButton;
    QSpacerItem *hSpacer2;
    QPushButton *deleteButton;
    QSpacerItem *hSpacer4;
    QPushButton *exitButton;
    QSpacerItem *hSpacer5;
    QHBoxLayout *firstHorizontalLayout;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QPushButton *clearButton;
    QSpacerItem *firstHorizontalSpacer;
    QLabel *tagLabel;
    QComboBox *tagComboBox;
    QPushButton *googleButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *dataApp)
    {
        if (dataApp->objectName().isEmpty())
            dataApp->setObjectName(QString::fromUtf8("dataApp"));
        dataApp->resize(646, 563);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dataApp->sizePolicy().hasHeightForWidth());
        dataApp->setSizePolicy(sizePolicy);
        dataApp->setMinimumSize(QSize(646, 563));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/main-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        dataApp->setWindowIcon(icon);
        dataApp->setAutoFillBackground(false);
        centralWidget = new QWidget(dataApp);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 626, 497));
        centralGridLayout = new QGridLayout(verticalLayoutWidget);
        centralGridLayout->setSpacing(6);
        centralGridLayout->setContentsMargins(11, 11, 11, 11);
        centralGridLayout->setObjectName(QString::fromUtf8("centralGridLayout"));
        centralGridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        centralGridLayout->setContentsMargins(0, 0, 0, 0);
        secondVerticalSpacer = new QSpacerItem(20, 35, QSizePolicy::Minimum, QSizePolicy::Expanding);

        centralGridLayout->addItem(secondVerticalSpacer, 3, 1, 1, 1);

        secondHorizontalLayout = new QHBoxLayout();
        secondHorizontalLayout->setSpacing(6);
        secondHorizontalLayout->setObjectName(QString::fromUtf8("secondHorizontalLayout"));
        noteLabel = new QLabel(verticalLayoutWidget);
        noteLabel->setObjectName(QString::fromUtf8("noteLabel"));

        secondHorizontalLayout->addWidget(noteLabel);

        noteEdit = new QTextEdit(verticalLayoutWidget);
        noteEdit->setObjectName(QString::fromUtf8("noteEdit"));
        noteEdit->setMinimumSize(QSize(500, 330));
        noteEdit->setFrameShape(QFrame::VLine);
        noteEdit->setFrameShadow(QFrame::Sunken);
        noteEdit->setAutoFormatting(QTextEdit::AutoBulletList);

        secondHorizontalLayout->addWidget(noteEdit);


        centralGridLayout->addLayout(secondHorizontalLayout, 2, 1, 1, 1);

        firstVerticalSpacer = new QSpacerItem(17, 24, QSizePolicy::Minimum, QSizePolicy::Expanding);

        centralGridLayout->addItem(firstVerticalSpacer, 1, 1, 1, 1);

        buttonFrame = new QFrame(verticalLayoutWidget);
        buttonFrame->setObjectName(QString::fromUtf8("buttonFrame"));
        buttonFrame->setMinimumSize(QSize(521, 50));
        buttonFrame->setFrameShape(QFrame::StyledPanel);
        buttonFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(buttonFrame);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        hSpacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(hSpacer1);

        saveButton = new QPushButton(buttonFrame);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setEnabled(false);
        saveButton->setMinimumSize(QSize(90, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon1);
        saveButton->setIconSize(QSize(21, 21));
        saveButton->setCheckable(false);
        saveButton->setAutoDefault(false);
        saveButton->setDefault(true);

        horizontalLayout->addWidget(saveButton);

        hSpacer3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(hSpacer3);

        searchButton = new QPushButton(buttonFrame);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setEnabled(false);
        searchButton->setMinimumSize(QSize(90, 30));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/search-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchButton->setIcon(icon2);
        searchButton->setIconSize(QSize(21, 21));

        horizontalLayout->addWidget(searchButton);

        hSpacer2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(hSpacer2);

        deleteButton = new QPushButton(buttonFrame);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setEnabled(false);
        deleteButton->setMinimumSize(QSize(90, 30));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/Delete-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon3);
        deleteButton->setIconSize(QSize(21, 21));

        horizontalLayout->addWidget(deleteButton);

        hSpacer4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(hSpacer4);

        exitButton = new QPushButton(buttonFrame);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setMinimumSize(QSize(90, 30));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/log_out.png"), QSize(), QIcon::Normal, QIcon::Off);
        exitButton->setIcon(icon4);
        exitButton->setIconSize(QSize(21, 21));

        horizontalLayout->addWidget(exitButton);

        hSpacer5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(hSpacer5);


        horizontalLayout_2->addLayout(horizontalLayout);


        centralGridLayout->addWidget(buttonFrame, 4, 1, 1, 1);

        firstHorizontalLayout = new QHBoxLayout();
        firstHorizontalLayout->setSpacing(6);
        firstHorizontalLayout->setObjectName(QString::fromUtf8("firstHorizontalLayout"));
        nameLabel = new QLabel(verticalLayoutWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        firstHorizontalLayout->addWidget(nameLabel);

        nameEdit = new QLineEdit(verticalLayoutWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setMinimumSize(QSize(240, 24));

        firstHorizontalLayout->addWidget(nameEdit);

        clearButton = new QPushButton(verticalLayoutWidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/images/gnome_edit_clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearButton->setIcon(icon5);
        clearButton->setIconSize(QSize(19, 19));
        clearButton->setFlat(true);

        firstHorizontalLayout->addWidget(clearButton);

        firstHorizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        firstHorizontalLayout->addItem(firstHorizontalSpacer);

        tagLabel = new QLabel(verticalLayoutWidget);
        tagLabel->setObjectName(QString::fromUtf8("tagLabel"));

        firstHorizontalLayout->addWidget(tagLabel);

        tagComboBox = new QComboBox(verticalLayoutWidget);
        tagComboBox->setObjectName(QString::fromUtf8("tagComboBox"));
        tagComboBox->setMinimumSize(QSize(135, 24));
        tagComboBox->setEditable(true);
        tagComboBox->setMaxVisibleItems(6);
        tagComboBox->setFrame(true);

        firstHorizontalLayout->addWidget(tagComboBox);

        googleButton = new QPushButton(verticalLayoutWidget);
        googleButton->setObjectName(QString::fromUtf8("googleButton"));
        googleButton->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/images/icon-google.png"), QSize(), QIcon::Normal, QIcon::Off);
        googleButton->setIcon(icon6);
        googleButton->setIconSize(QSize(19, 19));
        googleButton->setFlat(true);

        firstHorizontalLayout->addWidget(googleButton);


        centralGridLayout->addLayout(firstHorizontalLayout, 0, 1, 1, 1);

        dataApp->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(dataApp);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setCursor(QCursor(Qt::ArrowCursor));
        dataApp->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        noteLabel->setBuddy(noteEdit);
        nameLabel->setBuddy(nameEdit);
        tagLabel->setBuddy(tagComboBox);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(nameEdit, noteEdit);
        QWidget::setTabOrder(noteEdit, saveButton);
        QWidget::setTabOrder(saveButton, searchButton);

        retranslateUi(dataApp);

        QMetaObject::connectSlotsByName(dataApp);
    } // setupUi

    void retranslateUi(QMainWindow *dataApp)
    {
        dataApp->setWindowTitle(QApplication::translate("dataApp", "Data Manager", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        dataApp->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        noteLabel->setText(QApplication::translate("dataApp", "N&ote", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        noteEdit->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_STATUSTIP
        saveButton->setStatusTip(QApplication::translate("dataApp", "Save the entry with the current information.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        saveButton->setText(QApplication::translate("dataApp", " &Save", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        searchButton->setStatusTip(QApplication::translate("dataApp", "Search for an entry by the name entered OR|AND the tag.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        searchButton->setText(QApplication::translate("dataApp", " Se&arch", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        deleteButton->setStatusTip(QApplication::translate("dataApp", "Delete the specified entry.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        deleteButton->setText(QApplication::translate("dataApp", " &Delete", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        exitButton->setStatusTip(QApplication::translate("dataApp", "Exit App.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        exitButton->setText(QApplication::translate("dataApp", " E&xit", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("dataApp", "&Name", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        nameEdit->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_STATUSTIP
        clearButton->setStatusTip(QApplication::translate("dataApp", "Clear all textboxes. (Ctrl + F.)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        clearButton->setText(QString());
        clearButton->setShortcut(QApplication::translate("dataApp", "Ctrl+F", 0, QApplication::UnicodeUTF8));
        tagLabel->setText(QApplication::translate("dataApp", "Ca&tegory", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        googleButton->setStatusTip(QApplication::translate("dataApp", "Google entry name with/or tag. (Ctrl + G)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        googleButton->setText(QString());
        googleButton->setShortcut(QApplication::translate("dataApp", "Ctrl+G", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        statusBar->setStatusTip(QApplication::translate("dataApp", "Check this space for useful info.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
    } // retranslateUi

};

namespace Ui {
    class dataApp: public Ui_dataApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAAPP_H
