# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

# This is a reminder that you are using a generated .pro file.
# Remove it when you are finished editing this file.
message("You are running qmake on a generated .pro file. This may not work!")

QT += webkitwidgets webkit core gui script widgets sql xml
TEMPLATE = app
TARGET = QSW
DESTDIR = ../Debug
CONFIG += debug
INCLUDEPATH += ./GeneratedFiles \
    ./GeneratedFiles/Debug \
    ./Includes \
    .
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/debug
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles

OTHER_FILES += \
    Icon.rc

HEADERS += \
    Alphanum.h \
    SWSearch.h \
    SWObject.h \
    SWMainForm.h \
    SWEvent.h \
    SWDefines.h \
    SWAboutForm.h \
    SWModels.h \
    SWEnums.h \
    DBC/DBCStructure.h \
    DBC/DBCStores.h \
    DBC/DBCStore.h \
    DBC/DBCfmt.h \
    DBC/DBCFileLoader.h \
    Includes/Define.h \
    Includes/CompilerDefs.h \
    Includes/ByteConverter.h \
    SimpleHistory.h

SOURCES += \
    Main.cpp \
    Alphanum.cpp \
    SWSearch.cpp \
    SWObject.cpp \
    SWMainForm.cpp \
    SWDefines.cpp \
    SWAboutForm.cpp \
    SWModels.cpp \
    SWEnums.cpp \
    DBC/DBCStores.cpp \
    DBC/DBCFileLoader.cpp \
    DBC/DBCStructure.cpp \
    SimpleHistory.cpp

FORMS += \
    SWMainUI.ui \
    SWAboutUI.ui

RESOURCES += \
    SpellWork.qrc

DEFINES += _BUILD=17538

