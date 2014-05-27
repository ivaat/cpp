#ifndef DRAWINGWIDGET_H
#define DRAWINGWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QSizeF>
#include <QPointF>
#include <QPushButton>
#include "Card.h"

#define CARD_WIDTH 123 //TODO - adjustida kõiki neid, arvatavasti peab komakohaga olema
#define CARD_HEIGHT 174

#define CARDS_STARTING_X 78
#define CARDS_STARTING_Y 46

#define CARDS_DISTANCE_X 9.5
#define CARDS_DISTANCE_Y 11.5

#define PLAYER_TEXT_X 455
#define PLAYER_TEXT_Y 400

#define DEALER_TEXT_X 455
#define DEALER_TEXT_Y 200

#define GAMEOVER_TEXT_X 300
#define GAMEOVER_TEXT_Y 350

#define PLAYER_FIRST_CARD_Y 450
#define DEALER_FIRST_CARD_Y 50


#define BLACKJACK_HIT_BUTTON_X 295
#define BLACKJACK_HIT_BUTTON_Y 400

#define BLACKJACK_STAND_BUTTON_X 595
#define BLACKJACK_STAND_BUTTON_Y 400

class MainWindow;

class DrawingWidget: public QWidget {
    Q_OBJECT

    public slots:
        //blackjack
        void blackjackHitActionSlot();
        void blackjackStandActionSlot();

    public:
        DrawingWidget(MainWindow *parent = 0);
        ~DrawingWidget();

        void newBlackjackGame();
        void newPokerGame();
        void newGameGenericSetup();
        QPointF getImagePointIndex(Card* card);

    protected:
        //void mousePressEvent(QMouseEvent *event);
        //void mouseReleaseEvent(QMouseEvent *event);
        //void mouseMoveEvent(QMouseEvent *event);
        void paintEvent(QPaintEvent *event);
        unsigned short calculateFirstCardStartingX(unsigned short cardsAmount);


        MainWindow *mainWindow;
        bool drawDeck;
        QPixmap cardsImage;
        QSizeF cardSize;
        QPointF cardPoints[52];

        //BLACKJACK
        QPushButton* hit_button;
        QPushButton* stand_button;
};

#endif // DRAWINGWIDGET_H
