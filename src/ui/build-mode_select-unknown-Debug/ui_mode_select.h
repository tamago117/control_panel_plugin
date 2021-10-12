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

class Ui_mode_selectUI
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *start;
    QPushButton *stop;

    void setupUi(QWidget *mode_selectUI)
    {
        if (mode_selectUI->objectName().isEmpty())
            mode_selectUI->setObjectName(QStringLiteral("mode_selectUI"));
        mode_selectUI->resize(240, 153);
        verticalLayoutWidget = new QWidget(mode_selectUI);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 10, 160, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        start = new QPushButton(verticalLayoutWidget);
        start->setObjectName(QStringLiteral("start"));

        verticalLayout->addWidget(start);

        stop = new QPushButton(verticalLayoutWidget);
        stop->setObjectName(QStringLiteral("stop"));

        verticalLayout->addWidget(stop);


        retranslateUi(mode_selectUI);

        QMetaObject::connectSlotsByName(mode_selectUI);
    } // setupUi

    void retranslateUi(QWidget *mode_selectUI)
    {
        mode_selectUI->setWindowTitle(QApplication::translate("mode_selectUI", "mode_select", Q_NULLPTR));
        start->setText(QApplication::translate("mode_selectUI", "start", Q_NULLPTR));
        stop->setText(QApplication::translate("mode_selectUI", "stop", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mode_selectUI: public Ui_mode_selectUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODE_SELECT_H
