QT       += core gui
QT       += xml


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/cpp/adding.cpp \
    src/cpp/jsonparser.cpp \
    src/cpp/main.cpp \
    src/cpp/mainwindow.cpp \
    src/cpp/parser.cpp \
    src/cpp/xmlparser.cpp

HEADERS += \
    src/header/adding.h \
    src/header/jsonparser.h \
    src/header/mainwindow.h \
    src/header/parser.h \
    src/header/xmlparser.h

FORMS += \
    src/ui/adding.ui \
    src/ui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    .gitignore
