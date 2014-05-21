#include "DrawingWidget.h"

#include <QPainter>
#include <QPaintEvent>
#include <QStyleOption>
#include "mainwindow.h"


/**
  Constructs a drawing widget.
  \param[in] parent parent widget of the drawing widget.
*/
DrawingWidget::DrawingWidget(MainWindow *parent)
    : QWidget(parent), mainWindow(parent)
{

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
    /*
     * QRectF target(10.0, 20.0, 80.0, 60.0);
 QRectF source(0.0, 0.0, 70.0, 40.0);
 QPixmap pixmap(":myPixmap.png");

 QPainter(this);
 painter.drawPixmap(target, image, source);
 */
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
