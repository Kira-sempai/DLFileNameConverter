/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_folderPath;
    QPushButton *pushButton_folderPath;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_copy;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_doIt;
    QTableView *tableView;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(837, 576);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit_folderPath = new QLineEdit(Widget);
        lineEdit_folderPath->setObjectName(QString::fromUtf8("lineEdit_folderPath"));

        horizontalLayout_2->addWidget(lineEdit_folderPath);

        pushButton_folderPath = new QPushButton(Widget);
        pushButton_folderPath->setObjectName(QString::fromUtf8("pushButton_folderPath"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_folderPath->sizePolicy().hasHeightForWidth());
        pushButton_folderPath->setSizePolicy(sizePolicy);
        pushButton_folderPath->setMaximumSize(QSize(28, 16777215));

        horizontalLayout_2->addWidget(pushButton_folderPath);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_copy = new QPushButton(Widget);
        pushButton_copy->setObjectName(QString::fromUtf8("pushButton_copy"));

        horizontalLayout->addWidget(pushButton_copy);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_doIt = new QPushButton(Widget);
        pushButton_doIt->setObjectName(QString::fromUtf8("pushButton_doIt"));

        horizontalLayout->addWidget(pushButton_doIt);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(Widget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setShowGrid(false);
        tableView->horizontalHeader()->setVisible(true);
        tableView->horizontalHeader()->setStretchLastSection(false);
        tableView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableView);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "hashren", 0, QApplication::UnicodeUTF8));
        lineEdit_folderPath->setText(QApplication::translate("Widget", "C:\\teplomon\\wc44\\hashren\\kutak", 0, QApplication::UnicodeUTF8));
        pushButton_folderPath->setText(QApplication::translate("Widget", "...", 0, QApplication::UnicodeUTF8));
        pushButton_copy->setText(QApplication::translate("Widget", "copy", 0, QApplication::UnicodeUTF8));
        pushButton_doIt->setText(QApplication::translate("Widget", "do it", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
