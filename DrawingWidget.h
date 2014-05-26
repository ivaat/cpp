#ifndef DRAWINGWIDGET_H
#define DRAWINGWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QSizeF>
#include <QPointF>
#include "Card.h"

#define CARD_WIDTH 123 //TODO - adjustida kõiki neid, arvatavasti peab komakohaga olema
#define CARD_HEIGHT 174

#define CARDS_STARTING_X 78
#define CARDS_STARTING_Y 46

#define CARDS_DISTANCE_X 9.5
#define CARDS_DISTANCE_Y 11.5

#define PLAYER_TEXT_X 400
#define PLAYER_TEXT_Y 500

#define DEALER_TEXT_X 400
#define DEALER_TEXT_Y 200

#define GAMEOVER_TEXT_X 300
#define GAMEOVER_TEXT_Y 350

class MainWindow;

class DrawingWidget: public QWidget {
    Q_OBJECT
    public:
        DrawingWidget(MainWindow *parent = 0);
        ~DrawingWidget();

        void newBlackjackGame();
        void newPokerGame();
        void newGameGenericSetup();
        QPointF* getImagePointIndex(Card* card);

    protected:
        //void mousePressEvent(QMouseEvent *event);
        //void mouseReleaseEvent(QMouseEvent *event);
        //void mouseMoveEvent(QMouseEvent *event);
        void paintEvent(QPaintEvent *event);


        MainWindow *mainWindow;
        bool drawDeck;
        QPixmap cardsImage;
        QSizeF cardSize;
        QPointF cardPoints[53];
};

#endif // DRAWINGWIDGET_H
