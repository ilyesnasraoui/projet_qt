#-------------------------------------------------
#
# Project created by QtCreator 2020-03-26T14:08:56
#
#-------------------------------------------------

QT       += core gui sql
QT       += core gui network
QT       += core gui printsupport
QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projetwissem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    client.cpp \
    connexion.cpp \
    voiture.cpp \
    categorie.cpp \
    smtp.cpp \
    fidelite.cpp \
    contrat.cpp \
    reclamation.cpp \
    evenement.cpp \
    promotion.cpp

HEADERS += \
        mainwindow.h \
    connexion.h \
    client.h \
    voiture.h \
    categorie.h \
    smtp.h \
    fidelite.h \
    contrat.h \
    reclamation.h \
    evenement.h \
    promotion.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
