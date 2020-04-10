/********************************************************************************
** Form generated from reading UI file 'dialog_reclamation.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_RECLAMATION_H
#define UI_DIALOG_RECLAMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Reclamation
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *DESC;
    QLabel *label_2;
    QLabel *label_5;
    QPushButton *ajouter;
    QLineEdit *IDV;
    QLabel *label_6;
    QLineEdit *CINC;
    QPushButton *supprimer;
    QLineEdit *search;
    QLineEdit *CINE;
    QLabel *label_4;
    QLabel *label;
    QTableView *data;
    QLineEdit *ID;
    QPushButton *modifier;
    QWidget *tab_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QLineEdit *DESC_2;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *ajouter_2;
    QLineEdit *IDV_2;
    QLabel *label_14;
    QLineEdit *CINC_2;
    QPushButton *supprimer_2;
    QLineEdit *search_2;
    QLineEdit *CINE_2;
    QLabel *label_15;
    QLabel *label_16;
    QTableView *data_2;
    QLineEdit *ID_2;
    QPushButton *modifier_2;
    QWidget *tab_4;
    QLineEdit *CINC_3;
    QLineEdit *IDC;
    QLineEdit *MONTANT;
    QLineEdit *QUOTIENT;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *IDV_3;
    QLabel *label_23;
    QLineEdit *NUM;
    QLabel *label_24;
    QPushButton *AJOUTERC;
    QPushButton *Supprimerc;
    QPushButton *modifierc;
    QTableView *data2;
    QDateEdit *DATEDEBUT;
    QDateEdit *DATEFIN;
    QLineEdit *searchc;

    void setupUi(QDialog *Dialog_Reclamation)
    {
        if (Dialog_Reclamation->objectName().isEmpty())
            Dialog_Reclamation->setObjectName(QStringLiteral("Dialog_Reclamation"));
        Dialog_Reclamation->resize(1018, 655);
        tabWidget = new QTabWidget(Dialog_Reclamation);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(130, 20, 841, 611));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        DESC = new QLineEdit(tab);
        DESC->setObjectName(QStringLiteral("DESC"));
        DESC->setGeometry(QRect(450, 130, 171, 61));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(360, 130, 47, 13));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(360, 260, 47, 13));
        ajouter = new QPushButton(tab);
        ajouter->setObjectName(QStringLiteral("ajouter"));
        ajouter->setGeometry(QRect(380, 310, 75, 23));
        IDV = new QLineEdit(tab);
        IDV->setObjectName(QStringLiteral("IDV"));
        IDV->setGeometry(QRect(450, 230, 181, 20));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(360, 230, 47, 13));
        CINC = new QLineEdit(tab);
        CINC->setObjectName(QStringLiteral("CINC"));
        CINC->setGeometry(QRect(450, 200, 181, 20));
        supprimer = new QPushButton(tab);
        supprimer->setObjectName(QStringLiteral("supprimer"));
        supprimer->setGeometry(QRect(560, 310, 75, 23));
        search = new QLineEdit(tab);
        search->setObjectName(QStringLiteral("search"));
        search->setGeometry(QRect(20, 30, 113, 20));
        CINE = new QLineEdit(tab);
        CINE->setObjectName(QStringLiteral("CINE"));
        CINE->setGeometry(QRect(450, 260, 181, 20));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(360, 200, 47, 13));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(360, 70, 47, 13));
        data = new QTableView(tab);
        data->setObjectName(QStringLiteral("data"));
        data->setGeometry(QRect(20, 60, 321, 281));
        ID = new QLineEdit(tab);
        ID->setObjectName(QStringLiteral("ID"));
        ID->setGeometry(QRect(450, 70, 181, 20));
        modifier = new QPushButton(tab);
        modifier->setObjectName(QStringLiteral("modifier"));
        modifier->setGeometry(QRect(470, 310, 75, 23));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(260, 50, 113, 22));
        lineEdit_2 = new QLineEdit(tab_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(260, 100, 113, 22));
        lineEdit_3 = new QLineEdit(tab_2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(260, 140, 113, 22));
        lineEdit_4 = new QLineEdit(tab_2);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(260, 180, 113, 22));
        lineEdit_5 = new QLineEdit(tab_2);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(260, 210, 113, 22));
        lineEdit_6 = new QLineEdit(tab_2);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(260, 250, 113, 22));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(170, 50, 55, 16));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(190, 100, 55, 16));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(180, 140, 55, 16));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(170, 180, 55, 16));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(170, 220, 55, 16));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(180, 250, 55, 16));
        tabWidget_2 = new QTabWidget(tab_2);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(-40, -30, 861, 591));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        DESC_2 = new QLineEdit(tab_3);
        DESC_2->setObjectName(QStringLiteral("DESC_2"));
        DESC_2->setGeometry(QRect(450, 130, 171, 61));
        label_12 = new QLabel(tab_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(360, 130, 47, 13));
        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(360, 260, 47, 13));
        ajouter_2 = new QPushButton(tab_3);
        ajouter_2->setObjectName(QStringLiteral("ajouter_2"));
        ajouter_2->setGeometry(QRect(380, 310, 75, 23));
        IDV_2 = new QLineEdit(tab_3);
        IDV_2->setObjectName(QStringLiteral("IDV_2"));
        IDV_2->setGeometry(QRect(450, 230, 181, 20));
        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(360, 230, 47, 13));
        CINC_2 = new QLineEdit(tab_3);
        CINC_2->setObjectName(QStringLiteral("CINC_2"));
        CINC_2->setGeometry(QRect(450, 200, 181, 20));
        supprimer_2 = new QPushButton(tab_3);
        supprimer_2->setObjectName(QStringLiteral("supprimer_2"));
        supprimer_2->setGeometry(QRect(560, 310, 75, 23));
        search_2 = new QLineEdit(tab_3);
        search_2->setObjectName(QStringLiteral("search_2"));
        search_2->setGeometry(QRect(20, 30, 113, 20));
        CINE_2 = new QLineEdit(tab_3);
        CINE_2->setObjectName(QStringLiteral("CINE_2"));
        CINE_2->setGeometry(QRect(450, 260, 181, 20));
        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(360, 200, 47, 13));
        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(360, 70, 47, 13));
        data_2 = new QTableView(tab_3);
        data_2->setObjectName(QStringLiteral("data_2"));
        data_2->setGeometry(QRect(20, 60, 321, 281));
        ID_2 = new QLineEdit(tab_3);
        ID_2->setObjectName(QStringLiteral("ID_2"));
        ID_2->setGeometry(QRect(450, 70, 181, 20));
        modifier_2 = new QPushButton(tab_3);
        modifier_2->setObjectName(QStringLiteral("modifier_2"));
        modifier_2->setGeometry(QRect(470, 310, 75, 23));
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        CINC_3 = new QLineEdit(tab_4);
        CINC_3->setObjectName(QStringLiteral("CINC_3"));
        CINC_3->setGeometry(QRect(260, 50, 113, 22));
        IDC = new QLineEdit(tab_4);
        IDC->setObjectName(QStringLiteral("IDC"));
        IDC->setGeometry(QRect(260, 180, 113, 22));
        MONTANT = new QLineEdit(tab_4);
        MONTANT->setObjectName(QStringLiteral("MONTANT"));
        MONTANT->setGeometry(QRect(260, 210, 113, 22));
        QUOTIENT = new QLineEdit(tab_4);
        QUOTIENT->setObjectName(QStringLiteral("QUOTIENT"));
        QUOTIENT->setGeometry(QRect(260, 250, 113, 22));
        label_17 = new QLabel(tab_4);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(170, 50, 71, 16));
        label_18 = new QLabel(tab_4);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(144, 100, 101, 20));
        label_19 = new QLabel(tab_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(180, 140, 55, 16));
        label_20 = new QLabel(tab_4);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(170, 180, 55, 16));
        label_21 = new QLabel(tab_4);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(170, 220, 55, 16));
        label_22 = new QLabel(tab_4);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(180, 250, 55, 16));
        IDV_3 = new QLineEdit(tab_4);
        IDV_3->setObjectName(QStringLiteral("IDV_3"));
        IDV_3->setGeometry(QRect(260, 290, 113, 22));
        label_23 = new QLabel(tab_4);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(190, 290, 55, 16));
        NUM = new QLineEdit(tab_4);
        NUM->setObjectName(QStringLiteral("NUM"));
        NUM->setGeometry(QRect(260, 330, 113, 22));
        label_24 = new QLabel(tab_4);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(180, 330, 55, 16));
        AJOUTERC = new QPushButton(tab_4);
        AJOUTERC->setObjectName(QStringLiteral("AJOUTERC"));
        AJOUTERC->setGeometry(QRect(210, 410, 93, 28));
        Supprimerc = new QPushButton(tab_4);
        Supprimerc->setObjectName(QStringLiteral("Supprimerc"));
        Supprimerc->setGeometry(QRect(330, 410, 93, 28));
        modifierc = new QPushButton(tab_4);
        modifierc->setObjectName(QStringLiteral("modifierc"));
        modifierc->setGeometry(QRect(90, 410, 93, 28));
        data2 = new QTableView(tab_4);
        data2->setObjectName(QStringLiteral("data2"));
        data2->setGeometry(QRect(400, 80, 451, 261));
        DATEDEBUT = new QDateEdit(tab_4);
        DATEDEBUT->setObjectName(QStringLiteral("DATEDEBUT"));
        DATEDEBUT->setGeometry(QRect(260, 100, 110, 22));
        DATEFIN = new QDateEdit(tab_4);
        DATEFIN->setObjectName(QStringLiteral("DATEFIN"));
        DATEFIN->setGeometry(QRect(260, 140, 110, 22));
        searchc = new QLineEdit(tab_4);
        searchc->setObjectName(QStringLiteral("searchc"));
        searchc->setGeometry(QRect(460, 40, 113, 22));
        tabWidget_2->addTab(tab_4, QString());
        tabWidget->addTab(tab_2, QString());

        retranslateUi(Dialog_Reclamation);

        tabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Dialog_Reclamation);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Reclamation)
    {
        Dialog_Reclamation->setWindowTitle(QApplication::translate("Dialog_Reclamation", "Dialog", nullptr));
        DESC->setText(QString());
        label_2->setText(QApplication::translate("Dialog_Reclamation", "Desc", nullptr));
        label_5->setText(QApplication::translate("Dialog_Reclamation", "CIN E", nullptr));
        ajouter->setText(QApplication::translate("Dialog_Reclamation", "ajouter", nullptr));
        label_6->setText(QApplication::translate("Dialog_Reclamation", "ID V", nullptr));
        supprimer->setText(QApplication::translate("Dialog_Reclamation", "supprimer", nullptr));
        label_4->setText(QApplication::translate("Dialog_Reclamation", "CIN C", nullptr));
        label->setText(QApplication::translate("Dialog_Reclamation", "ID", nullptr));
        modifier->setText(QApplication::translate("Dialog_Reclamation", "modifier", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Dialog_Reclamation", "Tab 1", nullptr));
        label_3->setText(QApplication::translate("Dialog_Reclamation", "TextLabel", nullptr));
        label_7->setText(QApplication::translate("Dialog_Reclamation", "TextLabel", nullptr));
        label_8->setText(QApplication::translate("Dialog_Reclamation", "TextLabel", nullptr));
        label_9->setText(QApplication::translate("Dialog_Reclamation", "TextLabel", nullptr));
        label_10->setText(QApplication::translate("Dialog_Reclamation", "TextLabel", nullptr));
        label_11->setText(QApplication::translate("Dialog_Reclamation", "TextLabel", nullptr));
        DESC_2->setText(QString());
        label_12->setText(QApplication::translate("Dialog_Reclamation", "Desc", nullptr));
        label_13->setText(QApplication::translate("Dialog_Reclamation", "CIN E", nullptr));
        ajouter_2->setText(QApplication::translate("Dialog_Reclamation", "ajouter", nullptr));
        label_14->setText(QApplication::translate("Dialog_Reclamation", "ID V", nullptr));
        supprimer_2->setText(QApplication::translate("Dialog_Reclamation", "supprimer", nullptr));
        label_15->setText(QApplication::translate("Dialog_Reclamation", "CIN C", nullptr));
        label_16->setText(QApplication::translate("Dialog_Reclamation", "ID", nullptr));
        modifier_2->setText(QApplication::translate("Dialog_Reclamation", "modifier", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("Dialog_Reclamation", "Tab 1", nullptr));
        label_17->setText(QApplication::translate("Dialog_Reclamation", "numero CIN", nullptr));
        label_18->setText(QApplication::translate("Dialog_Reclamation", "Date debut", nullptr));
        label_19->setText(QApplication::translate("Dialog_Reclamation", "Date fin", nullptr));
        label_20->setText(QApplication::translate("Dialog_Reclamation", "ID contrat", nullptr));
        label_21->setText(QApplication::translate("Dialog_Reclamation", "Montant", nullptr));
        label_22->setText(QApplication::translate("Dialog_Reclamation", "Quotient", nullptr));
        label_23->setText(QApplication::translate("Dialog_Reclamation", "IDV", nullptr));
        label_24->setText(QApplication::translate("Dialog_Reclamation", "num", nullptr));
        AJOUTERC->setText(QApplication::translate("Dialog_Reclamation", "ajouter", nullptr));
        Supprimerc->setText(QApplication::translate("Dialog_Reclamation", "supprimer", nullptr));
        modifierc->setText(QApplication::translate("Dialog_Reclamation", "modifier", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("Dialog_Reclamation", "Tab 2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Dialog_Reclamation", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Reclamation: public Ui_Dialog_Reclamation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_RECLAMATION_H
