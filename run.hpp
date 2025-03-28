#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include "game_window.hpp"

class MenuWidget : public QWidget {
    Q_OBJECT
public:
    MenuWidget(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);
        setFixedSize(1300, 800); // Запрещает изменение размера
        this->setStyleSheet("background-color: #fff3b0;");

        QLabel *titleLabel = new QLabel("Menu", this);
        titleLabel->setAlignment(Qt::AlignCenter);
        titleLabel->setStyleSheet("color: blak; font-size: 80px;");
        layout->addWidget(titleLabel);

        QComboBox *sizeComboBox = new QComboBox(this);
        sizeComboBox->setFixedSize(250, 50);
        sizeComboBox->addItems({"3x2", "5x4", "6x8"});
        sizeComboBox->setStyleSheet("background-color: #e5e5e5; color: black; font-size: 20px;");
        layout->addWidget(sizeComboBox, 0, Qt::AlignCenter);


        QComboBox *difficultyComboBox = new QComboBox(this);
        difficultyComboBox->setFixedSize(250, 50);
        difficultyComboBox->addItems({"Easy", "Normal", "Hard"});
        // layout->setAlignment(difficultyComboBox, Qt::AlignCenter);
        difficultyComboBox->setStyleSheet("background-color: #e5e5e5; color: blak; font-size: 20px;");
        layout->addWidget(difficultyComboBox, 0, Qt::AlignCenter);

        QPushButton *runButton = new QPushButton("Run", this);
        runButton->setFixedSize(250, 100);
        // layout->setAlignment(runButton, Qt::AlignCenter);
        runButton->setStyleSheet("background-color: #a7c957; color: blak; font-size: 40px;");

        connect(runButton, &QPushButton::clicked, this, [this, sizeComboBox]() {
            QString selectedSize = sizeComboBox->currentText();

            int n = 3, m = 2;  // Значения по умолчанию
            if (selectedSize == "5x4") {
                n = 5; m = 4;
            } else if (selectedSize == "6x8") {
                n = 6; m = 8;
            }

            GameWindow *gameWindow = new GameWindow(n, m);
            gameWindow->show();
        });


        QPushButton *exitButton = new QPushButton("Exit", this);
        exitButton->setFixedSize(250, 100);
        // layout->setAlignment(exitButton, Qt::AlignCenter);
        exitButton->setStyleSheet("background-color: #bc4749; color: blak; font-size: 40px;");

        layout->addWidget(runButton, 0, Qt::AlignCenter);
        layout->addWidget(exitButton, 0, Qt::AlignCenter);
        layout->setSpacing(10);  // Установить расстояние между кнопками
        layout->setContentsMargins(0, 0, 0, 0);  // Убирает отступы вокруг layout

        connect(exitButton, &QPushButton::clicked, qApp, &QApplication::quit);
    }
};


