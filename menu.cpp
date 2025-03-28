#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include "gamewindow.h"

#include "menu.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent), gameWindow(nullptr) {
    setWindowTitle("Game Menu");
    setFixedSize(1024, 512);
    //Button

    QVBoxLayout *layout = new QVBoxLayout(this);

    QPushButton *startGameButton = new QPushButton("Start Game", this);
    QPushButton *highscoreButton = new QPushButton("Highscore", this);

    startGameButton->setFixedSize(400,100);
    highscoreButton->setFixedSize(400,100);

    layout->addWidget(startGameButton,0, Qt::AlignHCenter);
    layout->addWidget(highscoreButton,0, Qt::AlignHCenter);

    connect(startGameButton, &QPushButton::clicked, this, &MainWindow::startGame);
    connect(highscoreButton, &QPushButton::clicked, this, &MainWindow::showHighscore);
}

MainWindow::~MainWindow() {
    delete gameWindow;
}

void MainWindow::startGame() {
    if (!gameWindow) {
        gameWindow = new GameWindow();
    }
    gameWindow->show();
}

void MainWindow::showHighscore() {
    QMessageBox::information(this, "Highscore", "Displaying high scores...");
}
