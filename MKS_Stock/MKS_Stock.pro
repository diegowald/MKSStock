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
    models/modelbase.cpp \
    models/modelusuarios.cpp \
    views/windowusuarios.cpp \
    models/response.cpp \
    models/modelcontainer.cpp \
    views/dlgusuario.cpp \
    views/dlgproducto.cpp \
    views/dlgubicacion.cpp \
    views/dialogmovimientostock.cpp \
    models/modelubicaciones.cpp \
    models/modelproductos.cpp \
    models/modelmovimientosstock.cpp \
    controllers/controllerbase.cpp \
    views/controlledview.cpp \
    views/tablecontrolledwindow.cpp \
    controllers/controllerubicaciones.cpp \
    controllers/controllerusuarios.cpp \
    controllers/controllerproductos.cpp \
    controllers/controllermovimientosstock.cpp \
    views/stockcontrolledwindow.cpp \
    queryBuilder/querycondition.cpp

HEADERS  += mainwindow.h \
    entities/usuario.h \
    entities/producto.h \
    entities/ubicacion.h \
    entities/movimientostock.h \
    entities/entidadbase.h \
    models/modelbase.h \
    models/modelusuarios.h \
    views/windowusuarios.h \
    models/response.h \
    models/modelcontainer.h \
    views/dlgusuario.h \
    views/dlgproducto.h \
    views/dlgubicacion.h \
    views/dialogmovimientostock.h \
    models/modelubicaciones.h \
    models/modelproductos.h \
    models/modelmovimientosstock.h \
    controllers/controllerbase.h \
    views/controlledview.h \
    views/tablecontrolledwindow.h \
    controllers/controllerubicaciones.h \
    controllers/controllerusuarios.h \
    controllers/controllerproductos.h \
    controllers/controllermovimientosstock.h \
    views/stockcontrolledwindow.h \
    queryBuilder/querycondition.h

FORMS    += mainwindow.ui \
    views/windowusuarios.ui \
    views/dlgusuario.ui \
    views/dlgproducto.ui \
    views/dlgubicacion.ui \
    views/dialogmovimientostock.ui \
    views/tablecontrolledwindow.ui \
    views/stockcontrolledwindow.ui

CONFIG += mobility
MOBILITY =

RESOURCES += \
    dbresources.qrc

