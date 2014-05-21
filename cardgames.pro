#-------------------------------------------------
#
# Project created by QtCreator 2014-05-17T18:39:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cardgames
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    AbstractCardContainer.cpp \
    AbstractCardGame.cpp \
    Hand.cpp \
    Deck.cpp \
    Card.cpp \
    DrawingWidget.cpp

HEADERS  += mainwindow.h \
    PokerHandEvaluator.h \
    PokerGame.h \
    Hand.h \
    Deck.h \
    Card.h \
    BlackJackHandEvaluator.h \
    BlackJackGame.h \
    AbstractCardContainer.h \
    AbstractCardGame.h \
    AbstractHandEvaluator.h \
    DrawingWidget.h

RESOURCES += \
    assets.qrc
