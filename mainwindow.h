#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "AbstractCardContainer.h"
#include "AbstractCardGame.h"
#include "DrawingWidget.h"

class DrawingWidget;
class QMenu;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
   void newBlackjackGameSlot();
   void newPokerGameSlot();

protected:
   void initMenus();
   void initWidgets();

   DrawingWidget* drawingWidget;

   QMenu* fileMenu;
       QAction* newPokerAction;
       QAction* newBlackjackAction;
       QAction* quitAction;
   QMenu* helpMenu;
       QAction* whatsThisAction;
       QAction* aboutAction;
    
public:
    MainWindow(QWidget* parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
