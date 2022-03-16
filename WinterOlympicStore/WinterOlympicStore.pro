QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminwindow.cpp \
    banwindow.cpp \
    buyerwindow.cpp \
    buywindow.cpp \
    calculator.cpp \
    calculatorwindow.cpp \
    commodity.cpp \
    commoditydetailwindow.cpp \
    datastructure.cpp \
    invoice.cpp \
    login.cpp \
    main.cpp \
    modifycommoditywindow.cpp \
    modifywindow.cpp \
    personwindow.cpp \
    publishwindow.cpp \
    pullcommodity.cpp \
    searchwindow.cpp \
    sellerwindow.cpp \
    topupwindow.cpp \
    user.cpp \
    userwindow.cpp

HEADERS += \
    adminwindow.h \
    banwindow.h \
    buyerwindow.h \
    buywindow.h \
    calculator.h \
    calculatorwindow.h \
    commodity.h \
    commoditydetailwindow.h \
    datastructure.h \
    invoice.h \
    login.h \
    modifycommoditywindow.h \
    modifywindow.h \
    personwindow.h \
    publishwindow.h \
    pullcommodity.h \
    searchwindow.h \
    sellerwindow.h \
    topupwindow.h \
    user.h \
    userwindow.h

FORMS += \
    adminwindow.ui \
    banwindow.ui \
    buyerwindow.ui \
    buywindow.ui \
    calculatorwindow.ui \
    commoditydetailwindow.ui \
    login.ui \
    modifycommoditywindow.ui \
    modifywindow.ui \
    personwindow.ui \
    publishwindow.ui \
    pullcommodity.ui \
    searchwindow.ui \
    sellerwindow.ui \
    topupwindow.ui \
    userwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
