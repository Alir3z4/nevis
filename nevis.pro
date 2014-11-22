#-------------------------------------------------
#
# Project created by QtCreator 2014-11-22T09:14:50
#
#-------------------------------------------------

QT       += core gui

message(Compiling against Qt version: $$QT_MAJOR_VERSION)

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = nevis
TEMPLATE = app


unix{
    DEFINES += PREFIX=$${PREFIX}
    isEmpty(PREFIX){
        message(The PREFIX is empty. The default value will be used.)
        PREFIX=/usr
        message(PREFIX defined as $$PREFIX)
    }

    target.path = $$PREFIX/bin
    translations.path = $$PREFIX/share/nevis/translations/
    images.path = $$PREFIX/share/pixmaps
    desktop.path = $$PREFIX/share/applications
    doc.path = $$PREFIX/share/doc/nevis
    license.path = $$PREFIX/share/licenses/nevis/

    message(Target: $$target.path)
    message(Translations: $$translations.path)
    message(Images: $$images.path)
    message(Desktop: $$desktop.path)
    message(Documents: $$doc.path)
    message(License: $$license.path)
}

images.files = resource/images/*
desktop.files = installers/nevis.desktop
doc.files = doc/C*
license.files = doc/LICENSE
translations.files = translations/*.qm

DEFINES += TRANSLATION_PATH=$$translations.path
DEFINES += DOC_PATH=$$doc.path


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    README.md \
    LICENSE
