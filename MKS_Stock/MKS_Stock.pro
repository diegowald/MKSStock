#-------------------------------------------------
#
# Project created by QtCreator 2016-07-05T19:36:23
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MKS_Stock
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    entities/usuario.cpp \
    entities/producto.cpp \
    entities/ubicacion.cpp \
    entities/movimientostock.cpp \
    entities/entidadbase.cpp \
    models/modelbase.cpp

HEADERS  += mainwindow.h \
    entities/usuario.h \
    entities/producto.h \
    entities/ubicacion.h \
    entities/movimientostock.h \
    entities/entidadbase.h \
    models/modelbase.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY =

