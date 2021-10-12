/********************************************************************************
** Form generated from reading UI file 'mode_select.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODE_SELECT_H
#define UI_MODE_SELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mode_select
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *run;
    QPushButton *stop;

    void setupUi(QWidget *mode_select)
    {
        if (mode_select->objectName().isEmpty())
            mode_select->setObjectName(QStringLiteral("mode_select"));
        mode_select->resize(240, 153);
        verticalLayoutWidget = new QWidget(mode_select);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 10, 160, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        run = new QPushButton(verticalLayoutWidget);
        run->setObjectName(QStringLiteral("run"));

        verticalLayout->addWidget(run);

        stop = new QPushButton(verticalLayoutWidget);
        stop->setObjectName(QStringLiteral("stop"));

        verticalLayout->addWidget(stop);


        retranslateUi(mode_select);

        QMetaObject::connectSlotsByName(mode_select);
    } // setupUi

    void retranslateUi(QWidget *mode_select)
    {
        mode_select->setWindowTitle(QApplication::translate("mode_select", "mode_select", Q_NULLPTR));
        run->setText(QApplication::translate("mode_select", "run", Q_NULLPTR));
        stop->setText(QApplication::translate("mode_select", "stop", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mode_select: public Ui_mode_select {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODE_SELECT_H
