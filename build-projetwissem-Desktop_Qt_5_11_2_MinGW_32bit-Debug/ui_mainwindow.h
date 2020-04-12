/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *acceuil;
    QWidget *categorie;
    QTabWidget *tabWidget_2;
    QWidget *tab;
    QLineEdit *lineEdit_idv;
    QLineEdit *lineEdit_marque;
    QLineEdit *lineEdit_matricule;
    QLineEdit *lineEdit_idcategorie;
    QLineEdit *lineEdit_nbplaces;
    QLineEdit *lineEdit_anciennete;
    QLineEdit *lineEdit_couleur;
    QLineEdit *lineEdit_kilometrage;
    QLineEdit *lineEdit_carburant;
    QLineEdit *lineEdit_prixparjour;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *ajouter;
    QPushButton *supprimer;
    QPushButton *pushButton_2;
    QTableView *tableView2;
    QPushButton *trie;
    QLineEdit *lineEdit_16;
    QPushButton *recherche;
    QPushButton *modifier;
    QComboBox *combo;
    QWidget *tab_3;
    QLineEdit *lineEdit_idc;
    QLineEdit *lineEdit_type;
    QLineEdit *lineEdit_nbvoitures;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QPushButton *ajouter_categorie;
    QTableView *tableView;
    QPushButton *supprimer_categorie;
    QPushButton *trie_categorie;
    QPushButton *pushButton_4;
    QPushButton *modifier_categorie;
    QWidget *clients;
    QGroupBox *verticalGroupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_11;
    QPushButton *pushButton_10;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label_7;
    QCommandLinkButton *commandLinkButton_3;
    QComboBox *comboBox;
    QCommandLinkButton *commandLinkButton_2;
    QLabel *label_6;
    QLineEdit *lineEditrecherche;
    QLineEdit *lineEditcins;
    QCommandLinkButton *commandLinkButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QVBoxLayout *verticalLayout_9;
    QLineEdit *lineEditcin;
    QLineEdit *lineEditnom;
    QLineEdit *lineEditprenom;
    QLineEdit *lineEdittel;
    QLineEdit *lineEditage;
    QTableView *tabclient;
    QLabel *label_23;
    QWidget *page_2;
    QWidget *employes;
    QWidget *assurance;
    QWidget *location;
    QWidget *marketing;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1242, 653);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1441, 781));
        tabWidget->setCursor(QCursor(Qt::PointingHandCursor));
        tabWidget->setStyleSheet(QStringLiteral("font: 75 10pt \"MS Shell Dlg 2\";"));
        acceuil = new QWidget();
        acceuil->setObjectName(QStringLiteral("acceuil"));
        tabWidget->addTab(acceuil, QString());
        categorie = new QWidget();
        categorie->setObjectName(QStringLiteral("categorie"));
        tabWidget_2 = new QTabWidget(categorie);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(20, 10, 1021, 511));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        lineEdit_idv = new QLineEdit(tab);
        lineEdit_idv->setObjectName(QStringLiteral("lineEdit_idv"));
        lineEdit_idv->setGeometry(QRect(100, 60, 113, 22));
        lineEdit_marque = new QLineEdit(tab);
        lineEdit_marque->setObjectName(QStringLiteral("lineEdit_marque"));
        lineEdit_marque->setGeometry(QRect(100, 90, 113, 22));
        lineEdit_matricule = new QLineEdit(tab);
        lineEdit_matricule->setObjectName(QStringLiteral("lineEdit_matricule"));
        lineEdit_matricule->setGeometry(QRect(100, 120, 113, 22));
        lineEdit_idcategorie = new QLineEdit(tab);
        lineEdit_idcategorie->setObjectName(QStringLiteral("lineEdit_idcategorie"));
        lineEdit_idcategorie->setGeometry(QRect(100, 150, 113, 22));
        lineEdit_nbplaces = new QLineEdit(tab);
        lineEdit_nbplaces->setObjectName(QStringLiteral("lineEdit_nbplaces"));
        lineEdit_nbplaces->setGeometry(QRect(370, 60, 113, 22));
        lineEdit_anciennete = new QLineEdit(tab);
        lineEdit_anciennete->setObjectName(QStringLiteral("lineEdit_anciennete"));
        lineEdit_anciennete->setGeometry(QRect(370, 90, 113, 22));
        lineEdit_couleur = new QLineEdit(tab);
        lineEdit_couleur->setObjectName(QStringLiteral("lineEdit_couleur"));
        lineEdit_couleur->setGeometry(QRect(370, 120, 113, 22));
        lineEdit_kilometrage = new QLineEdit(tab);
        lineEdit_kilometrage->setObjectName(QStringLiteral("lineEdit_kilometrage"));
        lineEdit_kilometrage->setGeometry(QRect(370, 150, 113, 22));
        lineEdit_carburant = new QLineEdit(tab);
        lineEdit_carburant->setObjectName(QStringLiteral("lineEdit_carburant"));
        lineEdit_carburant->setGeometry(QRect(610, 80, 113, 22));
        lineEdit_prixparjour = new QLineEdit(tab);
        lineEdit_prixparjour->setObjectName(QStringLiteral("lineEdit_prixparjour"));
        lineEdit_prixparjour->setGeometry(QRect(610, 110, 113, 22));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 60, 71, 21));
        label->setStyleSheet(QStringLiteral(""));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 90, 61, 20));
        label_2->setStyleSheet(QStringLiteral(""));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 120, 55, 16));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 150, 71, 16));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(250, 60, 111, 20));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(300, 90, 55, 16));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(310, 120, 55, 16));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(290, 150, 81, 20));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(540, 80, 55, 16));
        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(524, 110, 71, 20));
        label_13 = new QLabel(tab);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(540, 140, 55, 16));
        ajouter = new QPushButton(tab);
        ajouter->setObjectName(QStringLiteral("ajouter"));
        ajouter->setGeometry(QRect(750, 100, 93, 28));
        supprimer = new QPushButton(tab);
        supprimer->setObjectName(QStringLiteral("supprimer"));
        supprimer->setGeometry(QRect(10, 440, 93, 28));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(750, 440, 93, 28));
        tableView2 = new QTableView(tab);
        tableView2->setObjectName(QStringLiteral("tableView2"));
        tableView2->setGeometry(QRect(10, 180, 831, 221));
        trie = new QPushButton(tab);
        trie->setObjectName(QStringLiteral("trie"));
        trie->setGeometry(QRect(380, 440, 93, 28));
        lineEdit_16 = new QLineEdit(tab);
        lineEdit_16->setObjectName(QStringLiteral("lineEdit_16"));
        lineEdit_16->setGeometry(QRect(590, 30, 113, 22));
        recherche = new QPushButton(tab);
        recherche->setObjectName(QStringLiteral("recherche"));
        recherche->setGeometry(QRect(750, 30, 93, 28));
        modifier = new QPushButton(tab);
        modifier->setObjectName(QStringLiteral("modifier"));
        modifier->setGeometry(QRect(170, 440, 93, 28));
        combo = new QComboBox(tab);
        combo->addItem(QString());
        combo->addItem(QString());
        combo->setObjectName(QStringLiteral("combo"));
        combo->setGeometry(QRect(610, 140, 121, 22));
        tabWidget_2->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        lineEdit_idc = new QLineEdit(tab_3);
        lineEdit_idc->setObjectName(QStringLiteral("lineEdit_idc"));
        lineEdit_idc->setGeometry(QRect(140, 100, 113, 22));
        lineEdit_type = new QLineEdit(tab_3);
        lineEdit_type->setObjectName(QStringLiteral("lineEdit_type"));
        lineEdit_type->setGeometry(QRect(440, 100, 113, 22));
        lineEdit_nbvoitures = new QLineEdit(tab_3);
        lineEdit_nbvoitures->setObjectName(QStringLiteral("lineEdit_nbvoitures"));
        lineEdit_nbvoitures->setGeometry(QRect(760, 100, 113, 22));
        label_24 = new QLabel(tab_3);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(30, 90, 111, 41));
        label_24->setStyleSheet(QLatin1String("\n"
"font: 10pt \"MS Shell Dlg 2\";"));
        label_25 = new QLabel(tab_3);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(370, 100, 71, 20));
        label_25->setStyleSheet(QStringLiteral("font: 10pt \"MS Shell Dlg 2\";"));
        label_26 = new QLabel(tab_3);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(590, 100, 151, 16));
        label_26->setStyleSheet(QStringLiteral("font: 10pt \"MS Shell Dlg 2\";"));
        ajouter_categorie = new QPushButton(tab_3);
        ajouter_categorie->setObjectName(QStringLiteral("ajouter_categorie"));
        ajouter_categorie->setGeometry(QRect(960, 100, 93, 28));
        tableView = new QTableView(tab_3);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(320, 160, 371, 221));
        supprimer_categorie = new QPushButton(tab_3);
        supprimer_categorie->setObjectName(QStringLiteral("supprimer_categorie"));
        supprimer_categorie->setGeometry(QRect(60, 440, 91, 31));
        trie_categorie = new QPushButton(tab_3);
        trie_categorie->setObjectName(QStringLiteral("trie_categorie"));
        trie_categorie->setGeometry(QRect(410, 440, 201, 41));
        pushButton_4 = new QPushButton(tab_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(930, 500, 93, 28));
        modifier_categorie = new QPushButton(tab_3);
        modifier_categorie->setObjectName(QStringLiteral("modifier_categorie"));
        modifier_categorie->setGeometry(QRect(200, 440, 91, 31));
        tabWidget_2->addTab(tab_3, QString());
        tabWidget->addTab(categorie, QString());
        clients = new QWidget();
        clients->setObjectName(QStringLiteral("clients"));
        verticalGroupBox = new QGroupBox(clients);
        verticalGroupBox->setObjectName(QStringLiteral("verticalGroupBox"));
        verticalGroupBox->setGeometry(QRect(0, 80, 161, 171));
        verticalGroupBox->setStyleSheet(QLatin1String("background-color:rgb(255, 255, 255,1);\n"
"border:none;\n"
"heigth:60%;"));
        verticalLayout = new QVBoxLayout(verticalGroupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_11 = new QPushButton(verticalGroupBox);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setStyleSheet(QLatin1String(".QPushButton {\n"
"\n"
"  border-radius: 25%;\n"
"  background-color: #f4511e;\n"
"\n"
"  color: #FFFFFF;\n"
"  text-align: center;\n"
"  font-size: 15px;\n"
"  padding: 20px;\n"
"\n"
"\n"
"  cursor: pointer;\n"
"  margin: 5px;\n"
"}\n"
"\n"
".QPushButton:hover  {\n"
" padding-right: 25px;\n"
"font-size: 22px;\n"
"background-color:black;\n"
"}\n"
"\n"
""));
        pushButton_11->setIconSize(QSize(10, 10));

        verticalLayout->addWidget(pushButton_11);

        pushButton_10 = new QPushButton(verticalGroupBox);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setStyleSheet(QLatin1String(".QPushButton {\n"
"\n"
"  border-radius: 25%;\n"
"  background-color: #f4511e;\n"
"\n"
"  color: #FFFFFF;\n"
"  text-align: center;\n"
"  font-size: 15px;\n"
"  padding: 20px;\n"
"\n"
"\n"
"  cursor: pointer;\n"
"  margin: 5px;\n"
"}\n"
"\n"
".QPushButton:hover  {\n"
"  padding-right: 25px;\n"
"font-size: 22px;\n"
" background-color:black;\n"
"}\n"
"\n"
""));
        pushButton_10->setIconSize(QSize(10, 10));

        verticalLayout->addWidget(pushButton_10);

        stackedWidget = new QStackedWidget(clients);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(150, 0, 1081, 541));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        label_7 = new QLabel(page);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(390, 30, 71, 48));
        commandLinkButton_3 = new QCommandLinkButton(page);
        commandLinkButton_3->setObjectName(QStringLiteral("commandLinkButton_3"));
        commandLinkButton_3->setGeometry(QRect(900, 390, 141, 41));
        commandLinkButton_3->setStyleSheet(QLatin1String("selection-color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 255, 255);"));
        comboBox = new QComboBox(page);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(170, 40, 73, 27));
        commandLinkButton_2 = new QCommandLinkButton(page);
        commandLinkButton_2->setObjectName(QStringLiteral("commandLinkButton_2"));
        commandLinkButton_2->setGeometry(QRect(750, 490, 187, 41));
        label_6 = new QLabel(page);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(520, 490, 56, 48));
        lineEditrecherche = new QLineEdit(page);
        lineEditrecherche->setObjectName(QStringLiteral("lineEditrecherche"));
        lineEditrecherche->setGeometry(QRect(470, 40, 252, 27));
        lineEditrecherche->setStyleSheet(QStringLiteral(""));
        lineEditcins = new QLineEdit(page);
        lineEditcins->setObjectName(QStringLiteral("lineEditcins"));
        lineEditcins->setEnabled(false);
        lineEditcins->setGeometry(QRect(560, 500, 181, 27));
        commandLinkButton = new QCommandLinkButton(page);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(760, 390, 141, 41));
        commandLinkButton->setStyleSheet(QLatin1String("selection-color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 255, 255);"));
        horizontalLayoutWidget = new QWidget(page);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(760, 100, 321, 271));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_18 = new QLabel(horizontalLayoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        verticalLayout_8->addWidget(label_18);

        label_19 = new QLabel(horizontalLayoutWidget);
        label_19->setObjectName(QStringLiteral("label_19"));

        verticalLayout_8->addWidget(label_19);

        label_20 = new QLabel(horizontalLayoutWidget);
        label_20->setObjectName(QStringLiteral("label_20"));

        verticalLayout_8->addWidget(label_20);

        label_21 = new QLabel(horizontalLayoutWidget);
        label_21->setObjectName(QStringLiteral("label_21"));

        verticalLayout_8->addWidget(label_21);

        label_22 = new QLabel(horizontalLayoutWidget);
        label_22->setObjectName(QStringLiteral("label_22"));

        verticalLayout_8->addWidget(label_22);


        horizontalLayout_4->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        lineEditcin = new QLineEdit(horizontalLayoutWidget);
        lineEditcin->setObjectName(QStringLiteral("lineEditcin"));

        verticalLayout_9->addWidget(lineEditcin);

        lineEditnom = new QLineEdit(horizontalLayoutWidget);
        lineEditnom->setObjectName(QStringLiteral("lineEditnom"));
        lineEditnom->setEnabled(true);

        verticalLayout_9->addWidget(lineEditnom);

        lineEditprenom = new QLineEdit(horizontalLayoutWidget);
        lineEditprenom->setObjectName(QStringLiteral("lineEditprenom"));

        verticalLayout_9->addWidget(lineEditprenom);

        lineEdittel = new QLineEdit(horizontalLayoutWidget);
        lineEdittel->setObjectName(QStringLiteral("lineEdittel"));

        verticalLayout_9->addWidget(lineEdittel);

        lineEditage = new QLineEdit(horizontalLayoutWidget);
        lineEditage->setObjectName(QStringLiteral("lineEditage"));

        verticalLayout_9->addWidget(lineEditage);


        horizontalLayout_4->addLayout(verticalLayout_9);

        tabclient = new QTableView(page);
        tabclient->setObjectName(QStringLiteral("tabclient"));
        tabclient->setGeometry(QRect(70, 90, 671, 391));
        label_23 = new QLabel(page);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(90, 30, 71, 48));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        tabWidget->addTab(clients, QString());
        employes = new QWidget();
        employes->setObjectName(QStringLiteral("employes"));
        tabWidget->addTab(employes, QString());
        assurance = new QWidget();
        assurance->setObjectName(QStringLiteral("assurance"));
        tabWidget->addTab(assurance, QString());
        location = new QWidget();
        location->setObjectName(QStringLiteral("location"));
        tabWidget->addTab(location, QString());
        marketing = new QWidget();
        marketing->setObjectName(QStringLiteral("marketing"));
        tabWidget->addTab(marketing, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1242, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        tabWidget->setTabText(tabWidget->indexOf(acceuil), QApplication::translate("MainWindow", "acceuil", nullptr));
        label->setText(QApplication::translate("MainWindow", "id voiture", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Marque", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "matricule", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "idcategorie", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "nombre de places", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "anciennet\303\251", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "couleur", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "kilom\303\251trage", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "carburant", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "prix par jour", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "etat", nullptr));
        ajouter->setText(QApplication::translate("MainWindow", "ajouter", nullptr));
        supprimer->setText(QApplication::translate("MainWindow", "supprimer", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "log out", nullptr));
        trie->setText(QApplication::translate("MainWindow", "trie selon prix", nullptr));
        lineEdit_16->setText(QApplication::translate("MainWindow", "recherche", nullptr));
        recherche->setText(QApplication::translate("MainWindow", "recherche", nullptr));
        modifier->setText(QApplication::translate("MainWindow", "modifier", nullptr));
        combo->setItemText(0, QApplication::translate("MainWindow", "disponible", nullptr));
        combo->setItemText(1, QApplication::translate("MainWindow", "indisponible", nullptr));

        tabWidget_2->setTabText(tabWidget_2->indexOf(tab), QApplication::translate("MainWindow", "voiture", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "id categorie", nullptr));
        label_25->setText(QApplication::translate("MainWindow", "type", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "nombre de voitures", nullptr));
        ajouter_categorie->setText(QApplication::translate("MainWindow", "Ajouter", nullptr));
        supprimer_categorie->setText(QApplication::translate("MainWindow", "Supprimer", nullptr));
        trie_categorie->setText(QApplication::translate("MainWindow", "trie selon nombres de voitures", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "log out", nullptr));
        modifier_categorie->setText(QApplication::translate("MainWindow", "Modifier", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "categorie", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(categorie), QApplication::translate("MainWindow", "categorie", nullptr));
        pushButton_11->setText(QApplication::translate("MainWindow", "client", nullptr));
        pushButton_10->setText(QApplication::translate("MainWindow", "fid\303\251lit\303\251", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "chercher", nullptr));
        commandLinkButton_3->setText(QApplication::translate("MainWindow", "modifier client", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "--", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "cin", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "age", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "nom", nullptr));
        comboBox->setItemText(4, QApplication::translate("MainWindow", "prenom", nullptr));
        comboBox->setItemText(5, QApplication::translate("MainWindow", "tel", nullptr));

        commandLinkButton_2->setText(QApplication::translate("MainWindow", "supprimer client", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "cin", nullptr));
        lineEditrecherche->setText(QString());
        lineEditcins->setText(QString());
        commandLinkButton->setText(QApplication::translate("MainWindow", "Ajouter client", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "cin", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "prenom", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "nom", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "tel", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "age", nullptr));
        lineEditcin->setText(QString());
        label_23->setText(QApplication::translate("MainWindow", "trier par", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(clients), QApplication::translate("MainWindow", "client", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(employes), QApplication::translate("MainWindow", "employe", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(assurance), QApplication::translate("MainWindow", "assurance", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(location), QApplication::translate("MainWindow", "location", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(marketing), QApplication::translate("MainWindow", "marketing", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
