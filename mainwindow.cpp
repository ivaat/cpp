#include "mainwindow.h"

#include <QAction>
#include <QApplication>
#include <QEvent>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QWhatsThis>
#include <QLabel>
#include <QString>
//#include "drawingwidget.h"

//alguses joonistab siia mingi tausta vms
//ülevalt saad new game asju valida, selle peale joonistab siis üle
//pokkeri ja blackjacki jaoks erinevad taustad ka?


//TODO - pane siia ka mingi activegame asi..

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    this->setFixedSize(1000, 800); //TODO - mingi õigem state
    this->setWindowTitle("Card Games");

    //m_state = INACTIVE; - TODO - pane mingi õige state

    //TODO - võibolla pead need ümber tõstma!
    initWidgets();
    initMenus();
}

MainWindow::~MainWindow() {
    //jätan tühjaks..? või pead need kaartid ja asjad ära kustutama..?
}

void MainWindow::newBlackjackGameSlot() {
    //TODO

    drawingWidget->newBlackjackGame();
}


void MainWindow::newPokerGameSlot() {
    //TODO
}

void MainWindow::initMenus() {
    fileMenu = new QMenu(this);
    fileMenu->setTitle(QString("&File"));
    menuBar()->addMenu(fileMenu);

    quitAction = new QAction(this);
    quitAction->setMenuRole(QAction::QuitRole);
    quitAction->setText(QString("&Quit"));
    quitAction->setStatusTip(QString("Quits this application"));
    quitAction->setToolTip(QString("Quits this application"));
    quitAction->setWhatsThis(QString("Activate this item to quit this application. You will"
                                  " be asked for confirmation."));
    fileMenu->addAction(quitAction);

    connect(quitAction, SIGNAL(triggered()),
            this, SLOT(close()));

    newPokerAction = new QAction(this);
    newPokerAction->setText(QString("New &Poker Game"));
    newPokerAction->setStatusTip(QString("Starts a new game of poker."));
    newPokerAction->setToolTip(QString("Starts a new game of poker."));
    newPokerAction->setWhatsThis(QString("Click this to start a new game of poker. If you're currently in the middle of a game, you will lose the current game."));
    fileMenu->addAction(newPokerAction);

    connect(newPokerAction, SIGNAL(triggered()),
            this, SLOT(newPokerGameSlot()));

    newBlackjackAction = new QAction(this);
    newBlackjackAction->setText(QString("New &Blackjack Game"));
    newBlackjackAction->setStatusTip(QString("Starts a new game of blackjack."));
    newBlackjackAction->setToolTip(QString("Starts a new game of blackjack."));
    newBlackjackAction->setWhatsThis(QString("Click this to start a new game of blackjack. If you're currently in the middle of a game, you will lose the current game."));
    fileMenu->addAction(newBlackjackAction);

    connect(newBlackjackAction, SIGNAL(triggered()),
            this, SLOT(newBlackjackGameSlot()));
}

void MainWindow::initWidgets() {
    drawingWidget = new DrawingWidget(this);
    setCentralWidget(drawingWidget);
}


//TODO - midagi sarnast on vaja
/*
void MainWindow::updateToolsMenuItems() {

    if (verticesVector.size() == 0) {
        m_deleteVertexAction->setEnabled(false);
        m_moveVertexAction->setEnabled(false);
    }
    else {
        m_deleteVertexAction->setEnabled(true);
        m_moveVertexAction->setEnabled(true);
    }

    if (verticesVector.size() < 2) {
        m_addLineAction->setEnabled(false);
    }
    else {
        m_addLineAction->setEnabled(true);
    }


    if (linesVector.size() == 0)
        m_deleteLineAction->setEnabled(false);
    else
        m_deleteLineAction->setEnabled(true);
}
*/


//TODO - midagi sarnast vaja
/*
void MainWindow::updateStatusBar() {

    //kindlasti saaks kuidagi targemalt switchida
    //mölla nimeruumide ja asjadega hiljem
    if (m_state == INACTIVE)
        modeStatusLabel->setText("INACTIVE");
    else if (m_state == ADD_VERTEX)
        modeStatusLabel->setText("Adding vertices");
    else if (m_state == MOVE_VERTEX)
        modeStatusLabel->setText("Moving vertices");
    else if (m_state == DELETE_VERTEX)
        modeStatusLabel->setText("Deleting vertices");
    else if (m_state == ADD_LINE)
        modeStatusLabel->setText("Adding lines");
    else if (m_state == DELETE_LINE)
        modeStatusLabel->setText("Deleting lines");
    else //error
        modeStatusLabel->setText("ERROR");

    verticesStatusLabel->setText("Vertices: " + QString::number(verticesVector.size()));
    linesStatusLabel->setText("Lines: " + QString::number(linesVector.size()));
}
*/
