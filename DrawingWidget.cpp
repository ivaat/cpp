#include "DrawingWidget.h"

#include <QPainter>
#include <QPaintEvent>
#include <QStyleOption>
#include <QRectF>
#include <QPixmap>
#include <QPointF>
#include <QSizeF>
#include "mainwindow.h"


/**
  Constructs a drawing widget.
  \param[in] parent parent widget of the drawing widget.
*/
DrawingWidget::DrawingWidget(MainWindow *parent)
    : QWidget(parent), mainWindow(parent)
{

    //TEE SEE LOLLUS ÜMBER
    QPixmap imagecp(":/assets/assets/cards.jpg");
    cardsImage = imagecp;

    QSizeF cardSizeCp(CARD_WIDTH, CARD_HEIGHT);
    cardSize = cardSizeCp;


    /*
     *        QRectF source3(CARDS_STARTING_X + 4 * (CARD_WIDTH + CARDS_DISTANCE_X),
                       CARDS_STARTING_Y + 3 * (CARD_HEIGHT + CARDS_DISTANCE_Y),
                       */

    for (int i = 0; i < 52; i++) {
        int yPos = 0;
        for (int j = 0; j < 13; j++) {
            cardPoints[i] = QPointF(CARDS_STARTING_X + j * (CARD_WIDTH + CARDS_DISTANCE_X),
                                    CARDS_STARTING_Y + yPos * (CARD_HEIGHT + CARDS_DISTANCE_Y));
        }
        yPos++;
    }
    cardPoints[52] = QPointF(1798.0, 418.0);


    drawDeck = false;
    //TODO - kuidas teha nii et ta image failid kaasa võtab?

    setStyleSheet("border-image: url(:/assets/assets/background2.jpeg)");

    //setStyleSheet("background-image: url(:/assets/assets/background2.jpeg); background-position: center; background-repeat: no-repeat; background-size: contain");

}

DrawingWidget::~DrawingWidget() {

}

void DrawingWidget::paintEvent(QPaintEvent *event) {
    QStyleOption opt;
    opt.init(this);

    QPainter painter(this);
    //painter.fillRect(event->rect(), Qt::black);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

    drawDeck = true;

    if (drawDeck) {
        //TODO - defineeri kaartide laius ja pikkus
        QPointF topLeft(10.0, 20.0);

        QRectF target(topLeft, cardSize);

        QRectF source(CARDS_STARTING_X, CARDS_STARTING_Y, CARD_WIDTH, CARD_HEIGHT);

        //QRectF source(1798.0, 418.0, CARD_WIDTH, CARD_HEIGHT);

        painter.drawPixmap(target, cardsImage, source);


        QPointF topLeft2(200.0, 20.0);
        QRectF target2(topLeft2, cardSize);

        QRectF source2(CARDS_STARTING_X + CARD_WIDTH + CARDS_DISTANCE_X,
                       CARDS_STARTING_Y,
                       CARD_WIDTH,
                       CARD_HEIGHT);

        painter.drawPixmap(target2, cardsImage, source2);

        QPointF topLeft3(400.0, 20.0);
        QRectF target3(topLeft3, cardSize);

        QRectF source3(CARDS_STARTING_X + 4 * (CARD_WIDTH + CARDS_DISTANCE_X),
                       CARDS_STARTING_Y + 3 * (CARD_HEIGHT + CARDS_DISTANCE_Y),
                       CARD_WIDTH,
                       CARD_HEIGHT);

        painter.drawPixmap(target3, cardsImage, source3);
    }
}


QPointF* DrawingWidget::getImagePointIndex(Card* card) {
    int index = card->suit * 13 + card->rank;
    return &cardPoints[index];
}

//paremini teha..

void DrawingWidget::newBlackjackGame() {
    newGameGenericSetup();


}

//paremini teha..

void DrawingWidget::newPokerGame() {
    newGameGenericSetup();



}


void DrawingWidget::newGameGenericSetup() {
    setStyleSheet("border-image: url(:/assets/assets/background.jpeg)");
    drawDeck = true;
}



/*
void DrawingWidget::mousePressEvent(QMouseEvent *event) {

    if (event->button() != Qt::LeftButton)
        return;


         Vector2 v {event->x(),event->y()};

    if (m_mainWindow->m_state == ADD_VERTEX)
        handleAddVertex(&v);

    if (m_mainWindow->m_state == MOVE_VERTEX)
        handleTrackingVertex(&v);

    if (m_mainWindow->m_state == ADD_LINE) {
        handleAddLine(&v);
    }

    if (m_mainWindow->m_state == DELETE_VERTEX)
        handleDeleteVertex(&v);

    update();
}
*/

/*
void DrawingWidget::mouseReleaseEvent(QMouseEvent *event) {

    if (event->button() != Qt::LeftButton ||
        m_mainWindow->m_state != MOVE_VERTEX ||
       trackedVertex == 0)
            return;

    setMouseTracking(false);

    trackedVertex->x = event->x();
    trackedVertex->y = event->y();
    adjustVertex(trackedVertex);
    trackedVertex = 0;

    update();
}
*/

/*
void DrawingWidget::mouseMoveEvent(QMouseEvent *event) {
    if (trackedVertex == 0 || m_mainWindow->m_state != MOVE_VERTEX)
            return;

    trackedVertex->x = event->x();
    trackedVertex->y = event->y();
    adjustVertex(trackedVertex);

    update();
}
*/
