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
#include <QtWidgets/QDateEdit>
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
    QStackedWidget *stackedWidget22;
    QWidget *page_3;
    QLabel *label_34;
    QLineEdit *lineEdit_carburant;
    QLineEdit *lineEdit_matricule;
    QLineEdit *lineEdit_kilometrage;
    QLabel *label_35;
    QLineEdit *lineEdit_idcategorie;
    QPushButton *modifier;
    QLabel *label_36;
    QLineEdit *lineEdit_16;
    QPushButton *ajouter;
    QTableView *tableView2;
    QLabel *label_37;
    QLabel *label_38;
    QLineEdit *lineEdit_couleur;
    QLineEdit *lineEdit_nbplaces;
    QPushButton *imprimerr;
    QPushButton *trie;
    QLineEdit *lineEdit_idv;
    QLineEdit *lineEdit_marque;
    QLabel *label_39;
    QLineEdit *lineEdit_prixparjour;
    QPushButton *stat;
    QLabel *label_40;
    QPushButton *supprimer;
    QLineEdit *lineEdit_anciennete;
    QComboBox *combo;
    QLineEdit *lineEdit;
    QLabel *label_41;
    QLabel *label_42;
    QLabel *label_43;
    QLabel *label_44;
    QPushButton *recherche;
    QLabel *label;
    QWidget *page_6;
    QLineEdit *lineEdit_nbvoitures;
    QPushButton *modifier_categorie;
    QLineEdit *lineEdit_type;
    QLabel *label_45;
    QLabel *label_46;
    QPushButton *supprimer_categorie;
    QLineEdit *lineEdit_idc;
    QPushButton *trie_categorie;
    QLabel *label_47;
    QTableView *tableView;
    QPushButton *pushButton_6;
    QPushButton *voituree;
    QPushButton *categoriee;
    QWidget *clients;
    QGroupBox *verticalGroupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_11;
    QPushButton *pushButton_10;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label_7;
    QComboBox *comboBox;
    QLineEdit *lineEditrecherche;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_27;
    QVBoxLayout *verticalLayout_9;
    QLineEdit *lineEditcin;
    QLineEdit *lineEditnom;
    QLineEdit *lineEditprenom;
    QLineEdit *lineEdittel;
    QLineEdit *lineEditage;
    QLineEdit *lineEditemail;
    QTableView *tabclient;
    QLabel *label_23;
    QPushButton *supprimerclient;
    QPushButton *ajouterclient;
    QPushButton *modifierclient;
    QLabel *label_6;
    QWidget *page_2;
    QTableView *tabfidelite;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_33;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QVBoxLayout *verticalLayout_11;
    QLineEdit *idfid;
    QComboBox *cinf;
    QLineEdit *valeurfid;
    QDateEdit *dated;
    QDateEdit *datef;
    QCommandLinkButton *commandLinkButton_4;
    QLabel *label_32;
    QComboBox *comboBoxf;
    QLabel *label_14;
    QLineEdit *lineEditrecherchef;
    QCommandLinkButton *commandLinkButton_5;
    QLabel *label_15;
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
        tabWidget->setStyleSheet(QLatin1String("QTabBar \n"
"{\n"
"	background-color: transparent;\n"
"}\n"
"\n"
"\n"
"QTabWidget::tab-bar \n"
"{\n"
"	border:none;\n"
"	left: 0px;\n"
"width:1250px;\n"
"\n"
"}\n"
"\n"
"\n"
"QTabBar::tab \n"
"{\n"
"	color: #fff;\n"
"	padding-left: 15px; \n"
"	padding-right: 15px; \n"
"	height: 25px;\n"
"}\n"
"\n"
"\n"
"QTabWidget::pane \n"
"{\n"
"	border: 1px solid #3a546e; \n"
"\n"
"}\n"
"\n"
"\n"
"QTabBar::tab:!selected \n"
"{\n"
"	color: #b1b1b1; \n"
"	border: px solid #000;\n"
"	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(44, 52, 60, 255),stop:1 rgba(15, 20, 26, 255));\n"
"	margin-top: 3px;\n"
"}\n"
"\n"
"\n"
"QTabBar::tab:selected \n"
"{\n"
"	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(67, 79, 91, 255),stop:1 rgba(32, 44, 56, 255));\n"
"	border: 1px solid #414141;\n"
"	color: #fff;\n"
"\n"
"}\n"
"\n"
"\n"
"QTabBar::tab:!selected:hover \n"
"{\n"
"	color: #fff; \n"
"}"));
        acceuil = new QWidget();
        acceuil->setObjectName(QStringLiteral("acceuil"));
        tabWidget->addTab(acceuil, QString());
        categorie = new QWidget();
        categorie->setObjectName(QStringLiteral("categorie"));
        stackedWidget22 = new QStackedWidget(categorie);
        stackedWidget22->setObjectName(QStringLiteral("stackedWidget22"));
        stackedWidget22->setGeometry(QRect(190, 0, 951, 541));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        label_34 = new QLabel(page_3);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(340, 140, 55, 16));
        lineEdit_carburant = new QLineEdit(page_3);
        lineEdit_carburant->setObjectName(QStringLiteral("lineEdit_carburant"));
        lineEdit_carburant->setGeometry(QRect(690, 130, 113, 22));
        lineEdit_carburant->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}"));
        lineEdit_matricule = new QLineEdit(page_3);
        lineEdit_matricule->setObjectName(QStringLiteral("lineEdit_matricule"));
        lineEdit_matricule->setGeometry(QRect(180, 170, 113, 22));
        lineEdit_matricule->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}"));
        lineEdit_kilometrage = new QLineEdit(page_3);
        lineEdit_kilometrage->setObjectName(QStringLiteral("lineEdit_kilometrage"));
        lineEdit_kilometrage->setGeometry(QRect(450, 200, 113, 22));
        lineEdit_kilometrage->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}"));
        label_35 = new QLabel(page_3);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(340, 170, 55, 16));
        lineEdit_idcategorie = new QLineEdit(page_3);
        lineEdit_idcategorie->setObjectName(QStringLiteral("lineEdit_idcategorie"));
        lineEdit_idcategorie->setGeometry(QRect(180, 200, 113, 22));
        lineEdit_idcategorie->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}"));
        modifier = new QPushButton(page_3);
        modifier->setObjectName(QStringLiteral("modifier"));
        modifier->setGeometry(QRect(350, 510, 93, 28));
        label_36 = new QLabel(page_3);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(90, 110, 71, 21));
        label_36->setStyleSheet(QStringLiteral(""));
        lineEdit_16 = new QLineEdit(page_3);
        lineEdit_16->setObjectName(QStringLiteral("lineEdit_16"));
        lineEdit_16->setGeometry(QRect(620, 50, 113, 22));
        lineEdit_16->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}"));
        ajouter = new QPushButton(page_3);
        ajouter->setObjectName(QStringLiteral("ajouter"));
        ajouter->setGeometry(QRect(850, 160, 93, 28));
        tableView2 = new QTableView(page_3);
        tableView2->setObjectName(QStringLiteral("tableView2"));
        tableView2->setGeometry(QRect(80, 230, 861, 271));
        tableView2->setStyleSheet(QLatin1String("QWidget {\n"
"    background-color: #333333;\n"
"    color: #fffff8;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #646464;\n"
"    padding: 4px;\n"
"    border: 1px solid #fffff8;\n"
"    font-size: 14pt;\n"
"}\n"
"\n"
"QTableWidget {\n"
"    gridline-color: #fffff8;\n"
"    font-size: 12pt;\n"
"}\n"
"\n"
"QTableWidget QTableCornerButton::section {\n"
"    background-color: #646464;\n"
"    border: 1px solid #fffff8;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #646464;\n"
"    padding: 4px;\n"
"    font-size: 10pt;\n"
"    border-style: none;\n"
"    border-bottom: 1px solid #fffff8;\n"
"    border-right: 1px solid #fffff8;\n"
"}\n"
"\n"
"QHeaderView::section:horizontal\n"
"{\n"
"    border-top: 1px solid #fffff8;\n"
"}\n"
"\n"
"QHeaderView::section:vertical\n"
"{\n"
"    border-left: 1px solid #fffff8;\n"
"height:100%;\n"
" \n"
"}"));
        label_37 = new QLabel(page_3);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(90, 140, 61, 20));
        label_37->setStyleSheet(QStringLiteral(""));
        label_38 = new QLabel(page_3);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setGeometry(QRect(750, 190, 55, 16));
        lineEdit_couleur = new QLineEdit(page_3);
        lineEdit_couleur->setObjectName(QStringLiteral("lineEdit_couleur"));
        lineEdit_couleur->setGeometry(QRect(450, 170, 113, 22));
        lineEdit_couleur->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}"));
        lineEdit_nbplaces = new QLineEdit(page_3);
        lineEdit_nbplaces->setObjectName(QStringLiteral("lineEdit_nbplaces"));
        lineEdit_nbplaces->setGeometry(QRect(450, 110, 113, 22));
        lineEdit_nbplaces->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}"));
        imprimerr = new QPushButton(page_3);
        imprimerr->setObjectName(QStringLiteral("imprimerr"));
        imprimerr->setGeometry(QRect(360, 40, 121, 28));
        trie = new QPushButton(page_3);
        trie->setObjectName(QStringLiteral("trie"));
        trie->setGeometry(QRect(600, 510, 93, 28));
        lineEdit_idv = new QLineEdit(page_3);
        lineEdit_idv->setObjectName(QStringLiteral("lineEdit_idv"));
        lineEdit_idv->setGeometry(QRect(180, 110, 113, 22));
        lineEdit_idv->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}"));
        lineEdit_marque = new QLineEdit(page_3);
        lineEdit_marque->setObjectName(QStringLiteral("lineEdit_marque"));
        lineEdit_marque->setGeometry(QRect(180, 140, 113, 22));
        lineEdit_marque->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}"));
        label_39 = new QLabel(page_3);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setGeometry(QRect(610, 160, 71, 20));
        lineEdit_prixparjour = new QLineEdit(page_3);
        lineEdit_prixparjour->setObjectName(QStringLiteral("lineEdit_prixparjour"));
        lineEdit_prixparjour->setGeometry(QRect(690, 160, 113, 22));
        lineEdit_prixparjour->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}"));
        stat = new QPushButton(page_3);
        stat->setObjectName(QStringLiteral("stat"));
        stat->setGeometry(QRect(850, 510, 93, 28));
        label_40 = new QLabel(page_3);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setGeometry(QRect(90, 200, 71, 16));
        supprimer = new QPushButton(page_3);
        supprimer->setObjectName(QStringLiteral("supprimer"));
        supprimer->setGeometry(QRect(140, 510, 93, 28));
        lineEdit_anciennete = new QLineEdit(page_3);
        lineEdit_anciennete->setObjectName(QStringLiteral("lineEdit_anciennete"));
        lineEdit_anciennete->setGeometry(QRect(450, 140, 113, 22));
        lineEdit_anciennete->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}"));
        combo = new QComboBox(page_3);
        combo->addItem(QString());
        combo->addItem(QString());
        combo->setObjectName(QStringLiteral("combo"));
        combo->setGeometry(QRect(690, 190, 121, 22));
        combo->setStyleSheet(QLatin1String("QComboBox\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}"));
        lineEdit = new QLineEdit(page_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(190, 40, 113, 22));
        lineEdit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}"));
        label_41 = new QLabel(page_3);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setGeometry(QRect(610, 130, 55, 16));
        label_42 = new QLabel(page_3);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setGeometry(QRect(340, 110, 121, 20));
        label_43 = new QLabel(page_3);
        label_43->setObjectName(QStringLiteral("label_43"));
        label_43->setGeometry(QRect(340, 200, 81, 20));
        label_44 = new QLabel(page_3);
        label_44->setObjectName(QStringLiteral("label_44"));
        label_44->setGeometry(QRect(90, 170, 55, 16));
        recherche = new QPushButton(page_3);
        recherche->setObjectName(QStringLiteral("recherche"));
        recherche->setGeometry(QRect(750, 50, 186, 28));
        recherche->setStyleSheet(QStringLiteral(""));
        label = new QLabel(page_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(610, 190, 55, 16));
        stackedWidget22->addWidget(page_3);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        lineEdit_nbvoitures = new QLineEdit(page_6);
        lineEdit_nbvoitures->setObjectName(QStringLiteral("lineEdit_nbvoitures"));
        lineEdit_nbvoitures->setGeometry(QRect(780, 90, 113, 22));
        lineEdit_nbvoitures->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}\n"
""));
        modifier_categorie = new QPushButton(page_6);
        modifier_categorie->setObjectName(QStringLiteral("modifier_categorie"));
        modifier_categorie->setGeometry(QRect(800, 250, 91, 31));
        lineEdit_type = new QLineEdit(page_6);
        lineEdit_type->setObjectName(QStringLiteral("lineEdit_type"));
        lineEdit_type->setGeometry(QRect(780, 130, 113, 22));
        lineEdit_type->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}\n"
"\n"
""));
        label_45 = new QLabel(page_6);
        label_45->setObjectName(QStringLiteral("label_45"));
        label_45->setGeometry(QRect(610, 90, 151, 16));
        label_45->setStyleSheet(QStringLiteral("font: 10pt \"MS Shell Dlg 2\";"));
        label_46 = new QLabel(page_6);
        label_46->setObjectName(QStringLiteral("label_46"));
        label_46->setGeometry(QRect(610, 170, 111, 41));
        label_46->setStyleSheet(QLatin1String("\n"
"font: 10pt \"MS Shell Dlg 2\";"));
        supprimer_categorie = new QPushButton(page_6);
        supprimer_categorie->setObjectName(QStringLiteral("supprimer_categorie"));
        supprimer_categorie->setGeometry(QRect(600, 250, 91, 31));
        lineEdit_idc = new QLineEdit(page_6);
        lineEdit_idc->setObjectName(QStringLiteral("lineEdit_idc"));
        lineEdit_idc->setGeometry(QRect(780, 180, 113, 22));
        lineEdit_idc->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}\n"
""));
        trie_categorie = new QPushButton(page_6);
        trie_categorie->setObjectName(QStringLiteral("trie_categorie"));
        trie_categorie->setGeometry(QRect(650, 320, 201, 41));
        label_47 = new QLabel(page_6);
        label_47->setObjectName(QStringLiteral("label_47"));
        label_47->setGeometry(QRect(610, 140, 71, 20));
        label_47->setStyleSheet(QStringLiteral("font: 10pt \"MS Shell Dlg 2\";"));
        tableView = new QTableView(page_6);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(180, 80, 411, 351));
        tableView->setStyleSheet(QLatin1String("QWidget {\n"
"    background-color: #333333;\n"
"    color: #fffff8;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #646464;\n"
"    padding: 4px;\n"
"    border: 1px solid #fffff8;\n"
"    font-size: 14pt;\n"
"}\n"
"\n"
"QTableWidget {\n"
"    gridline-color: #fffff8;\n"
"    font-size: 12pt;\n"
"}\n"
"\n"
"QTableWidget QTableCornerButton::section {\n"
"    background-color: #646464;\n"
"    border: 1px solid #fffff8;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #646464;\n"
"    padding: 4px;\n"
"    font-size: 10pt;\n"
"    border-style: none;\n"
"    border-bottom: 1px solid #fffff8;\n"
"    border-right: 1px solid #fffff8;\n"
"}\n"
"\n"
"QHeaderView::section:horizontal\n"
"{\n"
"    border-top: 1px solid #fffff8;\n"
"}\n"
"\n"
"QHeaderView::section:vertical\n"
"{\n"
"    border-left: 1px solid #fffff8;\n"
"height:100%;\n"
" \n"
"}"));
        stackedWidget22->addWidget(page_6);
        pushButton_6 = new QPushButton(categorie);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(60, 460, 93, 28));
        voituree = new QPushButton(categorie);
        voituree->setObjectName(QStringLiteral("voituree"));
        voituree->setGeometry(QRect(20, 30, 139, 68));
        voituree->setStyleSheet(QLatin1String(".QPushButton {\n"
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
        voituree->setIconSize(QSize(10, 10));
        categoriee = new QPushButton(categorie);
        categoriee->setObjectName(QStringLiteral("categoriee"));
        categoriee->setGeometry(QRect(20, 110, 139, 68));
        categoriee->setStyleSheet(QLatin1String(".QPushButton {\n"
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
        categoriee->setIconSize(QSize(10, 10));
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
        stackedWidget->setStyleSheet(QStringLiteral(""));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        label_7 = new QLabel(page);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(390, 30, 71, 48));
        comboBox = new QComboBox(page);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(170, 40, 73, 27));
        comboBox->setStyleSheet(QLatin1String("QComboBox\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}\n"
"QComboBox::drop-down {\n"
"	subcontrol-origin: padding;\n"
"	subcontrol-position: top right;\n"
"	width: 20px;\n"
" \n"
"	border-top-right-radius: 3px;\n"
"	border-bottom-right-radius: 3px;\n"
"}\n"
"QComboBox QAbstractItemView{\n"
"	background-color: #4f4f4f;\n"
"	color: #999999;\n"
" \n"
"	selection-background-color: #999999;\n"
"	selection-color: #4f4f4f;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        lineEditrecherche = new QLineEdit(page);
        lineEditrecherche->setObjectName(QStringLiteral("lineEditrecherche"));
        lineEditrecherche->setGeometry(QRect(470, 40, 252, 27));
        lineEditrecherche->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}"));
        horizontalLayoutWidget = new QWidget(page);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(760, 110, 301, 271));
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

        label_27 = new QLabel(horizontalLayoutWidget);
        label_27->setObjectName(QStringLiteral("label_27"));

        verticalLayout_8->addWidget(label_27);


        horizontalLayout_4->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        lineEditcin = new QLineEdit(horizontalLayoutWidget);
        lineEditcin->setObjectName(QStringLiteral("lineEditcin"));
        lineEditcin->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}\n"
"\n"
"\n"
"QLineEdit::disabled\n"
"{\n"
"	background-color: #404040;\n"
"	color: #656565;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}"));

        verticalLayout_9->addWidget(lineEditcin);

        lineEditnom = new QLineEdit(horizontalLayoutWidget);
        lineEditnom->setObjectName(QStringLiteral("lineEditnom"));
        lineEditnom->setEnabled(true);
        lineEditnom->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}\n"
"\n"
"\n"
"QLineEdit::disabled\n"
"{\n"
"	background-color: #404040;\n"
"	color: #656565;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}\n"
"\n"
"QLineEdit::disabled\n"
"{\n"
"	background-color: #404040;\n"
"	color: #656565;\n"
"	border-width: 1px;\n"
"	border-radius: 3px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}"));

        verticalLayout_9->addWidget(lineEditnom);

        lineEditprenom = new QLineEdit(horizontalLayoutWidget);
        lineEditprenom->setObjectName(QStringLiteral("lineEditprenom"));
        lineEditprenom->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}\n"
"\n"
"\n"
"QLineEdit::disabled\n"
"{\n"
"	background-color: #404040;\n"
"	color: #656565;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}"));

        verticalLayout_9->addWidget(lineEditprenom);

        lineEdittel = new QLineEdit(horizontalLayoutWidget);
        lineEdittel->setObjectName(QStringLiteral("lineEdittel"));
        lineEdittel->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}\n"
"\n"
"\n"
"QLineEdit::disabled\n"
"{\n"
"	background-color: #404040;\n"
"	color: #656565;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}"));

        verticalLayout_9->addWidget(lineEdittel);

        lineEditage = new QLineEdit(horizontalLayoutWidget);
        lineEditage->setObjectName(QStringLiteral("lineEditage"));
        lineEditage->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}\n"
"\n"
"\n"
"QLineEdit::disabled\n"
"{\n"
"	background-color: #404040;\n"
"	color: #656565;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}"));

        verticalLayout_9->addWidget(lineEditage);

        lineEditemail = new QLineEdit(horizontalLayoutWidget);
        lineEditemail->setObjectName(QStringLiteral("lineEditemail"));
        lineEditemail->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}\n"
"\n"
"\n"
"QLineEdit::disabled\n"
"{\n"
"	background-color: #404040;\n"
"	color: #656565;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}"));

        verticalLayout_9->addWidget(lineEditemail);


        horizontalLayout_4->addLayout(verticalLayout_9);

        tabclient = new QTableView(page);
        tabclient->setObjectName(QStringLiteral("tabclient"));
        tabclient->setGeometry(QRect(70, 90, 671, 391));
        tabclient->setStyleSheet(QLatin1String("QWidget {\n"
"    background-color: #333333;\n"
"    color: #fffff8;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #646464;\n"
"    padding: 4px;\n"
"    border: 1px solid #fffff8;\n"
"    font-size: 14pt;\n"
"\n"
"\n"
"\n"
"}\n"
"\n"
"QTableWidget {\n"
"    gridline-color: #fffff8;\n"
"    font-size: 12pt;\n"
"\n"
"\n"
"}\n"
"\n"
"QTableWidget QTableCornerButton::section {\n"
"    background-color: #646464;\n"
"    border: 1px solid #fffff8;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #646464;\n"
"    padding: 4px;\n"
"    font-size: 10pt;\n"
"    border-style: none;\n"
"    border-bottom: 1px solid #fffff8;\n"
"    border-right: 1px solid #fffff8;\n"
"}\n"
"\n"
"QHeaderView::section:horizontal\n"
"{\n"
"    border-top: 1px solid #fffff8;\n"
"\n"
"\n"
"}\n"
"\n"
"QHeaderView::section:vertical\n"
"{\n"
"\n"
"    border-left: 1px solid #fffff8;\n"
"height:100%;\n"
" \n"
"}"));
        label_23 = new QLabel(page);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(90, 30, 71, 48));
        supprimerclient = new QPushButton(page);
        supprimerclient->setObjectName(QStringLiteral("supprimerclient"));
        supprimerclient->setGeometry(QRect(860, 450, 93, 28));
        supprimerclient->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(84, 84, 84, 255),stop:1 rgba(59, 59, 59, 255));\n"
"	color: #ffffff;\n"
"	min-width: 80px;\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	border-radius: 7px;\n"
"	border-color: #051a39;\n"
"	padding: 5px;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::flat\n"
"{\n"
"	background-color: transparent;\n"
"	border: none;\n"
"	color: #fff;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::disabled\n"
"{\n"
"	background-color: #404040;\n"
"	color: #656565;\n"
"	border-color: #051a39;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::hover\n"
"{\n"
"	background-color: rgba(183, 134, 32, 20%);\n"
"	border: 1px solid #b78620;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(74, 74, 74, 255),stop:1 rgba(49, 49, 49, 255));\n"
"	border: 1px solid #b78620;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::checked\n"
"{\n"
"	background-color: qlineargradient(sprea"
                        "d:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(74, 74, 74, 255),stop:1 rgba(49, 49, 49, 255));\n"
"	border: 1px solid #222;\n"
"\n"
"}"));
        ajouterclient = new QPushButton(page);
        ajouterclient->setObjectName(QStringLiteral("ajouterclient"));
        ajouterclient->setGeometry(QRect(780, 400, 93, 28));
        ajouterclient->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(84, 84, 84, 255),stop:1 rgba(59, 59, 59, 255));\n"
"	color: #ffffff;\n"
"	min-width: 80px;\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	border-radius: 7px;\n"
"	border-color: #051a39;\n"
"	padding: 5px;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::flat\n"
"{\n"
"	background-color: transparent;\n"
"	border: none;\n"
"	color: #fff;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::disabled\n"
"{\n"
"	background-color: #404040;\n"
"	color: #656565;\n"
"	border-color: #051a39;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::hover\n"
"{\n"
"	background-color: rgba(183, 134, 32, 20%);\n"
"	border: 1px solid #b78620;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(74, 74, 74, 255),stop:1 rgba(49, 49, 49, 255));\n"
"	border: 1px solid #b78620;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::checked\n"
"{\n"
"	background-color: qlineargradient(sprea"
                        "d:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(74, 74, 74, 255),stop:1 rgba(49, 49, 49, 255));\n"
"	border: 1px solid #222;\n"
"\n"
"}\n"
""));
        modifierclient = new QPushButton(page);
        modifierclient->setObjectName(QStringLiteral("modifierclient"));
        modifierclient->setGeometry(QRect(940, 400, 93, 28));
        modifierclient->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(84, 84, 84, 255),stop:1 rgba(59, 59, 59, 255));\n"
"	color: #ffffff;\n"
"	min-width: 80px;\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	border-radius: 7px;\n"
"	border-color: #051a39;\n"
"	padding: 5px;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::flat\n"
"{\n"
"	background-color: transparent;\n"
"	border: none;\n"
"	color: #fff;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::disabled\n"
"{\n"
"	background-color: #404040;\n"
"	color: #656565;\n"
"	border-color: #051a39;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::hover\n"
"{\n"
"	background-color: rgba(183, 134, 32, 20%);\n"
"	border: 1px solid #b78620;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(74, 74, 74, 255),stop:1 rgba(49, 49, 49, 255));\n"
"	border: 1px solid #b78620;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::checked\n"
"{\n"
"	background-color: qlineargradient(sprea"
                        "d:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(74, 74, 74, 255),stop:1 rgba(49, 49, 49, 255));\n"
"	border: 1px solid #222;\n"
"\n"
"}"));
        label_6 = new QLabel(page);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(750, 90, 331, 411));
        label_6->setStyleSheet(QLatin1String("background-color: transparent;\n"
"border-radius: 12px;\n"
"border-color: rgb(255, 175, 14);\n"
"	padding: 5px;\n"
"border-width: 3px;\n"
"border-style: solid ;"));
        stackedWidget->addWidget(page);
        label_6->raise();
        label_7->raise();
        comboBox->raise();
        lineEditrecherche->raise();
        horizontalLayoutWidget->raise();
        tabclient->raise();
        label_23->raise();
        supprimerclient->raise();
        ajouterclient->raise();
        modifierclient->raise();
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        tabfidelite = new QTableView(page_2);
        tabfidelite->setObjectName(QStringLiteral("tabfidelite"));
        tabfidelite->setGeometry(QRect(70, 90, 661, 391));
        tabfidelite->setStyleSheet(QLatin1String("QWidget {\n"
"    background-color: #333333;\n"
"    color: #fffff8;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #646464;\n"
"    padding: 4px;\n"
"    border: 1px solid #fffff8;\n"
"    font-size: 14pt;\n"
"}\n"
"\n"
"QTableWidget {\n"
"    gridline-color: #fffff8;\n"
"    font-size: 12pt;\n"
"}\n"
"\n"
"QTableWidget QTableCornerButton::section {\n"
"    background-color: #646464;\n"
"    border: 1px solid #fffff8;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #646464;\n"
"    padding: 4px;\n"
"    font-size: 10pt;\n"
"    border-style: none;\n"
"    border-bottom: 1px solid #fffff8;\n"
"    border-right: 1px solid #fffff8;\n"
"}\n"
"\n"
"QHeaderView::section:horizontal\n"
"{\n"
"    border-top: 1px solid #fffff8;\n"
"}\n"
"\n"
"QHeaderView::section:vertical\n"
"{\n"
"    border-left: 1px solid #fffff8;\n"
"height:100%;\n"
" \n"
"}"));
        horizontalLayoutWidget_2 = new QWidget(page_2);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(750, 100, 321, 271));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        label_33 = new QLabel(horizontalLayoutWidget_2);
        label_33->setObjectName(QStringLiteral("label_33"));

        verticalLayout_10->addWidget(label_33);

        label_28 = new QLabel(horizontalLayoutWidget_2);
        label_28->setObjectName(QStringLiteral("label_28"));

        verticalLayout_10->addWidget(label_28);

        label_29 = new QLabel(horizontalLayoutWidget_2);
        label_29->setObjectName(QStringLiteral("label_29"));

        verticalLayout_10->addWidget(label_29);

        label_30 = new QLabel(horizontalLayoutWidget_2);
        label_30->setObjectName(QStringLiteral("label_30"));

        verticalLayout_10->addWidget(label_30);

        label_31 = new QLabel(horizontalLayoutWidget_2);
        label_31->setObjectName(QStringLiteral("label_31"));

        verticalLayout_10->addWidget(label_31);


        horizontalLayout_5->addLayout(verticalLayout_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        idfid = new QLineEdit(horizontalLayoutWidget_2);
        idfid->setObjectName(QStringLiteral("idfid"));
        idfid->setEnabled(false);
        idfid->setStyleSheet(QLatin1String("\n"
"\n"
"\n"
"QLineEdit::disabled\n"
"{\n"
"	background-color: #404040;\n"
"	color: #656565;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}"));

        verticalLayout_11->addWidget(idfid);

        cinf = new QComboBox(horizontalLayoutWidget_2);
        cinf->setObjectName(QStringLiteral("cinf"));
        cinf->setStyleSheet(QLatin1String("QComboBox\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
""));

        verticalLayout_11->addWidget(cinf);

        valeurfid = new QLineEdit(horizontalLayoutWidget_2);
        valeurfid->setObjectName(QStringLiteral("valeurfid"));
        valeurfid->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	background-color: #404040;\n"
"	color: #656565;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}"));

        verticalLayout_11->addWidget(valeurfid);

        dated = new QDateEdit(horizontalLayoutWidget_2);
        dated->setObjectName(QStringLiteral("dated"));
        dated->setStyleSheet(QLatin1String("QDateEdit\n"
"{\n"
"	background-color: #404040;\n"
"	color: #656565;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}"));
        dated->setCalendarPopup(true);

        verticalLayout_11->addWidget(dated);

        datef = new QDateEdit(horizontalLayoutWidget_2);
        datef->setObjectName(QStringLiteral("datef"));
        datef->setStyleSheet(QLatin1String("QDateEdit\n"
"{\n"
"	background-color: #404040;\n"
"	color: #656565;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}"));
        datef->setCalendarPopup(true);

        verticalLayout_11->addWidget(datef);


        horizontalLayout_5->addLayout(verticalLayout_11);

        commandLinkButton_4 = new QCommandLinkButton(page_2);
        commandLinkButton_4->setObjectName(QStringLiteral("commandLinkButton_4"));
        commandLinkButton_4->setGeometry(QRect(750, 390, 141, 41));
        commandLinkButton_4->setStyleSheet(QLatin1String("selection-color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 255, 255);"));
        label_32 = new QLabel(page_2);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(90, 30, 71, 48));
        comboBoxf = new QComboBox(page_2);
        comboBoxf->addItem(QString());
        comboBoxf->addItem(QString());
        comboBoxf->addItem(QString());
        comboBoxf->addItem(QString());
        comboBoxf->addItem(QString());
        comboBoxf->addItem(QString());
        comboBoxf->setObjectName(QStringLiteral("comboBoxf"));
        comboBoxf->setGeometry(QRect(170, 40, 73, 27));
        comboBoxf->setStyleSheet(QLatin1String("QComboBox\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"	subcontrol-origin: padding;\n"
"	subcontrol-position: top right;\n"
"	width: 20px;\n"
" \n"
"	border-top-right-radius: 3px;\n"
"	border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"\n"
"\n"
""));
        label_14 = new QLabel(page_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(390, 30, 71, 48));
        lineEditrecherchef = new QLineEdit(page_2);
        lineEditrecherchef->setObjectName(QStringLiteral("lineEditrecherchef"));
        lineEditrecherchef->setGeometry(QRect(470, 40, 252, 27));
        lineEditrecherchef->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	background-color: #525251;\n"
"	color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}\n"
"\n"
"\n"
"QLineEdit::disabled\n"
"{\n"
"	background-color: #404040;\n"
"	color: #656565;\n"
"	border-width: 1px;\n"
"	border-radius: 9px;\n"
"	border-color: #051a39;\n"
"	padding: 2px;\n"
"\n"
"}"));
        commandLinkButton_5 = new QCommandLinkButton(page_2);
        commandLinkButton_5->setObjectName(QStringLiteral("commandLinkButton_5"));
        commandLinkButton_5->setGeometry(QRect(560, 490, 187, 41));
        label_15 = new QLabel(page_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(750, 80, 331, 411));
        label_15->setStyleSheet(QLatin1String("background-color: transparent;\n"
"border-radius: 12px;\n"
"border-color: rgb(255, 175, 14);\n"
"	padding: 5px;\n"
"border-width: 3px;\n"
"border-style: solid ;"));
        stackedWidget->addWidget(page_2);
        label_15->raise();
        tabfidelite->raise();
        horizontalLayoutWidget_2->raise();
        commandLinkButton_4->raise();
        label_32->raise();
        comboBoxf->raise();
        label_14->raise();
        lineEditrecherchef->raise();
        commandLinkButton_5->raise();
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
        stackedWidget22->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        tabWidget->setTabText(tabWidget->indexOf(acceuil), QApplication::translate("MainWindow", "acceuil", nullptr));
        label_34->setText(QApplication::translate("MainWindow", "anciennet\303\251", nullptr));
        label_35->setText(QApplication::translate("MainWindow", "couleur", nullptr));
        modifier->setText(QApplication::translate("MainWindow", "modifier", nullptr));
        label_36->setText(QApplication::translate("MainWindow", "id voiture", nullptr));
        lineEdit_16->setText(QApplication::translate("MainWindow", "recherche", nullptr));
        ajouter->setText(QApplication::translate("MainWindow", "ajouter", nullptr));
        label_37->setText(QApplication::translate("MainWindow", "Marque", nullptr));
        label_38->setText(QApplication::translate("MainWindow", "etat", nullptr));
        imprimerr->setText(QApplication::translate("MainWindow", "imprimer la fiche", nullptr));
        trie->setText(QApplication::translate("MainWindow", "trie selon prix", nullptr));
        label_39->setText(QApplication::translate("MainWindow", "prix par jour", nullptr));
        stat->setText(QApplication::translate("MainWindow", "statistique", nullptr));
        label_40->setText(QApplication::translate("MainWindow", "idcategorie", nullptr));
        supprimer->setText(QApplication::translate("MainWindow", "supprimer", nullptr));
        combo->setItemText(0, QApplication::translate("MainWindow", "disponible", nullptr));
        combo->setItemText(1, QApplication::translate("MainWindow", "indisponible", nullptr));

        label_41->setText(QApplication::translate("MainWindow", "carburant", nullptr));
        label_42->setText(QApplication::translate("MainWindow", "nombre de places", nullptr));
        label_43->setText(QApplication::translate("MainWindow", "kilom\303\251trage", nullptr));
        label_44->setText(QApplication::translate("MainWindow", "matricule", nullptr));
        recherche->setText(QApplication::translate("MainWindow", "recherche", nullptr));
        label->setText(QApplication::translate("MainWindow", "etat", nullptr));
        modifier_categorie->setText(QApplication::translate("MainWindow", "Modifier", nullptr));
        label_45->setText(QApplication::translate("MainWindow", "nombre de voitures", nullptr));
        label_46->setText(QApplication::translate("MainWindow", "id categorie", nullptr));
        supprimer_categorie->setText(QApplication::translate("MainWindow", "Supprimer", nullptr));
        trie_categorie->setText(QApplication::translate("MainWindow", "trie selon nombres de voitures", nullptr));
        label_47->setText(QApplication::translate("MainWindow", "type", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "log out", nullptr));
        voituree->setText(QApplication::translate("MainWindow", "voiture", nullptr));
        categoriee->setText(QApplication::translate("MainWindow", "categorie", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(categorie), QApplication::translate("MainWindow", "categorie", nullptr));
        pushButton_11->setText(QApplication::translate("MainWindow", "client", nullptr));
        pushButton_10->setText(QApplication::translate("MainWindow", "fid\303\251lit\303\251", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "chercher", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "--", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "cin", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "age", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "nom", nullptr));
        comboBox->setItemText(4, QApplication::translate("MainWindow", "prenom", nullptr));
        comboBox->setItemText(5, QApplication::translate("MainWindow", "tel", nullptr));

        lineEditrecherche->setText(QString());
        label_18->setText(QApplication::translate("MainWindow", "cin", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "prenom", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "nom", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "tel", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "age", nullptr));
        label_27->setText(QApplication::translate("MainWindow", "email", nullptr));
        lineEditcin->setText(QString());
        label_23->setText(QApplication::translate("MainWindow", "trier par", nullptr));
        supprimerclient->setText(QApplication::translate("MainWindow", "supprimer", nullptr));
        ajouterclient->setText(QApplication::translate("MainWindow", "ajouter", nullptr));
        modifierclient->setText(QApplication::translate("MainWindow", "modifier", nullptr));
        label_6->setText(QString());
        label_33->setText(QApplication::translate("MainWindow", "numero de fidelit\303\251", nullptr));
        label_28->setText(QApplication::translate("MainWindow", "cin", nullptr));
        label_29->setText(QApplication::translate("MainWindow", "valeur", nullptr));
        label_30->setText(QApplication::translate("MainWindow", "dated", nullptr));
        label_31->setText(QApplication::translate("MainWindow", "datef", nullptr));
        commandLinkButton_4->setText(QApplication::translate("MainWindow", "Ajouter fid", nullptr));
        label_32->setText(QApplication::translate("MainWindow", "trier par", nullptr));
        comboBoxf->setItemText(0, QApplication::translate("MainWindow", "--", nullptr));
        comboBoxf->setItemText(1, QApplication::translate("MainWindow", "cin", nullptr));
        comboBoxf->setItemText(2, QApplication::translate("MainWindow", "age", nullptr));
        comboBoxf->setItemText(3, QApplication::translate("MainWindow", "nom", nullptr));
        comboBoxf->setItemText(4, QApplication::translate("MainWindow", "prenom", nullptr));
        comboBoxf->setItemText(5, QApplication::translate("MainWindow", "tel", nullptr));

        label_14->setText(QApplication::translate("MainWindow", "chercher", nullptr));
        lineEditrecherchef->setText(QString());
        commandLinkButton_5->setText(QApplication::translate("MainWindow", "supprimer fidelite", nullptr));
        label_15->setText(QString());
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
