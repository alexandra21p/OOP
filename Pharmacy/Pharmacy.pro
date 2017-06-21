#-------------------------------------------------
#
# Project created by QtCreator 2015-05-15T15:01:53
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pharmacy
TEMPLATE = app


SOURCES += main.cpp\
        pharmacywindow.cpp \
    FileRepo.cpp \
    InMemoryPharmacyRepo.cpp \
    Medicine.cpp \
    MedicineValidator.cpp \
    PharmacyController.cpp

HEADERS  += pharmacywindow.h \
    FileRepo.h \
    InMemoryPharmacyRepo.h \
    Medicine.h \
    MedicineValidator.h \
    PharmacyController.h \
    PharmacyRepo.h

FORMS    += pharmacywindow.ui

DISTFILES += \
    ../build-Pharmacy-Desktop_Qt_5_4_1_MinGW_32bit-Debug/data.txt
