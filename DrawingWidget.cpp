#include "DrawingWidget.h"

#include <QPainter>
#include <QPaintEvent>
#include <QStyleOption>
#include <QRectF>
#include <QPixmap>
#include <QPointF>
#include <QSizeF>
#include "mainwindow.h"
#include <QDebug>
#include <QPushButton>


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


    int i = 0;
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 13; x++) {
            cardPoints[i++] = QPointF(CARDS_STARTING_X + x * (CARD_WIDTH + CARDS_DISTANCE_X),
                                    CARDS_STARTING_Y + y * (CARD_HEIGHT + CARDS_DISTANCE_Y));
        }
    }

    drawDeck = false;

    setStyleSheet("border-image: url(:/assets/assets/background2.jpeg)");

    //setStyleSheet("background-image: url(:/assets/assets/background2.jpeg); background-position: center; background-repeat: no-repeat; background-size: contain");

}

DrawingWidget::~DrawingWidget() {

}

unsigned short DrawingWidget::calculateFirstCardStartingX(unsigned short cardsAmount) {

    unsigned short ret = 0;

    if (cardsAmount % 2 == 0)    {
        ret = ((cardsAmount / 2) * CARD_WIDTH) + (((cardsAmount / 2) - 1) * CARDS_DISTANCE_X);
    }

    else {
        ret =  ((cardsAmount-1) / 2) * CARD_WIDTH;
        ret += (cardsAmount-1) / 2 * CARDS_DISTANCE_X;
        ret += CARD_WIDTH / 2;
    }

    return (500 - ret);
}

void DrawingWidget::paintEvent(QPaintEvent *event) {
    QStyleOption opt;
    opt.init(this);

    QPainter painter(this);
    //painter.fillRect(event->rect(), Qt::black);



    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);



    if (drawDeck) {

        if (mainWindow->currentGame->state >= WAITING_FOR_DEALER) {
            hit_button->setEnabled(false);
            stand_button->setEnabled(false);
        }

        QFont font=painter.font() ;
        font.setPointSize (18);
        font.setWeight(QFont::DemiBold);
        painter.setFont(font);
        painter.setPen(Qt::white);

        //TODO - saad siiski virtualiks teha selle meetodi
        //mul oli BlackjackGame:: jäänud cpp-s ette panemata
        //mine või lolliks
        //pane ka see playeri tekst paremasse kohta
        if (mainWindow->currentGame->type == BLACKJACK) {
            BlackjackGame* game = (BlackjackGame*) mainWindow->currentGame;
            unsigned short playerStrength = game->getHandStrength(mainWindow->currentGame->playerHand);
            QString value;
            if (playerStrength <= 21) value = QString::number(playerStrength);
            else value = "BUST!";
            painter.drawText(QPoint(PLAYER_TEXT_X,PLAYER_TEXT_Y), "PLAYER: " + value);

            if (mainWindow->currentGame->state >= WAITING_FOR_DEALER) {
                unsigned short dealerStrength = game->getHandStrength(mainWindow->currentGame->dealerHand);
                if (dealerStrength <= 21) value = QString::number(dealerStrength);
                else value = "BUST!";
                painter.drawText(QPoint(DEALER_TEXT_X,DEALER_TEXT_Y), "DEALER: " + value);
            }
        }


        //TODO - defineeri kaartide laius ja pikkus
        int playerSize = mainWindow->currentGame->playerHand->size();
        int playerStartingX = calculateFirstCardStartingX(playerSize);

        for (int i = 0; i < playerSize; i++) {
            int currentX = playerStartingX + i * (CARD_WIDTH + CARDS_DISTANCE_X);
            QPointF topLeft(currentX,
                            PLAYER_FIRST_CARD_Y);
            QRectF target(topLeft, cardSize);
            QPointF src1 = getImagePointIndex(mainWindow->currentGame->playerHand->at(i));
            QRectF source(src1, cardSize);
            painter.drawPixmap(target, cardsImage, source);
        }

        int dealerSize = mainWindow->currentGame->dealerHand->size();
        int dealerStartingX = calculateFirstCardStartingX(dealerSize);

        for (int i = 0; i < dealerSize; i++) {
            int currentX = dealerStartingX + i * (CARD_WIDTH + CARDS_DISTANCE_X);
            QPointF topLeft(currentX,
                            DEALER_FIRST_CARD_Y);
            QRectF target(topLeft, cardSize);
            QPointF src1 = getImagePointIndex(mainWindow->currentGame->dealerHand->at(i));
            QRectF source(src1, cardSize);
            painter.drawPixmap(target, cardsImage, source);
        }
    }
}


QPointF DrawingWidget::getImagePointIndex(Card* card) {
    int index = card->suit * 13 + card->rank;
    qDebug() << "Getting image point index: ";
    qDebug() << "Suit: " << card->suit;
    qDebug() << "Rank: " << card->rank;
    qDebug() << "Index: " << index;
    qDebug() << cardPoints[index].x();
    qDebug() << cardPoints[index].y();
    return cardPoints[index];
}

//paremini teha..

void DrawingWidget::blackjackHitActionSlot() {
    qDebug() << "boo";
    BlackjackGame* game = (BlackjackGame*) mainWindow->currentGame;
    game->playerHit();
    qDebug() << "boo2";
    update();
}


void DrawingWidget::blackjackStandActionSlot() {
    qDebug() << "boo";
    BlackjackGame* game = (BlackjackGame*) mainWindow->currentGame;
    game->playerStand();
    qDebug() << "boo2";
    update();
}


void DrawingWidget::newBlackjackGame() {
    drawDeck = true;
    newGameGenericSetup();



    hit_button = new QPushButton(this);
    hit_button->setText(tr("HIT"));
    hit_button->move(BLACKJACK_HIT_BUTTON_X,
                     BLACKJACK_HIT_BUTTON_Y);
    hit_button->setStyleSheet("color: black; background-color: white; border-image: none; border-style: outset; border-width: 2px; border-radius: 10px; border-color: beige; font: bold 14px; min-width: 5em; padding: 6px;");
    hit_button->setAutoFillBackground(true);
    connect(hit_button, SIGNAL(released()), this, SLOT(blackjackHitActionSlot()));
    hit_button->show();

    stand_button = new QPushButton(this);
    stand_button->setText(tr("STAND"));
    stand_button->move(BLACKJACK_STAND_BUTTON_X,
                       BLACKJACK_STAND_BUTTON_Y);
    stand_button->setStyleSheet("color: red; background-color: white; border-image: none; border-style: outset; border-width: 2px; border-radius: 10px; border-color: beige; font: bold 14px; min-width: 5em; padding: 6px;");
    stand_button->setAutoFillBackground(true);
    connect(stand_button, SIGNAL(released()), this, SLOT(blackjackStandActionSlot()));
    stand_button->show();
}

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




/*

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
*/
