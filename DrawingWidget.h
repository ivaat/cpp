#ifndef DRAWINGWIDGET_H
#define DRAWINGWIDGET_H

#include <QWidget>

class MainWindow;

class DrawingWidget: public QWidget {
    Q_OBJECT
    public:
        DrawingWidget(MainWindow *parent = 0);
        ~DrawingWidget();

        void newBlackjackGame();
        void newPokerGame();
        void newGameGenericSetup();

    protected:
        //void mousePressEvent(QMouseEvent *event);
        //void mouseReleaseEvent(QMouseEvent *event);
        //void mouseMoveEvent(QMouseEvent *event);
        void paintEvent(QPaintEvent *event);


        MainWindow *mainWindow;
};

#endif // DRAWINGWIDGET_H
