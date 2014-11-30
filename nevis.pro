#-------------------------------------------------
#
# Project created by QtCreator 2014-11-22T09:14:50
#
#-------------------------------------------------

QT += core gui
LIBS += -lqt5scintilla2

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

INSTALLS += target\
    images \
    desktop \
    doc \
    license \
    translations


SOURCES += main.cpp\
        ui/mainwindow.cpp \
    ui/dialog/about_dialog.cpp \
    utils/paths.cpp \
    ui/dialog/report_bug_dialog.cpp

HEADERS  += ui/mainwindow.h \
    ui/dialog/about_dialog.h \
    utils/paths.h \
    ui/dialog/report_bug_dialog.h

FORMS   += ui/mainwindow.ui \
    ui/dialog/about_dialog.ui \
    ui/dialog/report_bug_dialog.ui

OTHER_FILES += \
    README.md \
    LICENSE \
    docs/LicenseTemplate
