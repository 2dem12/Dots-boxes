#pragma once
#include <QWidget>
#include <QGridLayout>
#include <QLabel>

class GameWindow : public QWidget {
    Q_OBJECT
public:
    GameWindow(int n, int m, QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("Game Field");
        setFixedSize(n * 50, m * 50);  // Увеличиваем окно в зависимости от размера поля

        QGridLayout *gridLayout = new QGridLayout(this);
        gridLayout->setSpacing(2);  // Расстояние между клетками
        gridLayout->setContentsMargins(10, 10, 10, 10);

        // Создаём поле n x m
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                QLabel *cell = new QLabel(this);
                cell->setFixedSize(50, 50);  // Размер клетки
                cell->setStyleSheet("border: 1px solid black; background-color: white;");
                cell->setAlignment(Qt::AlignCenter);
                gridLayout->addWidget(cell, i, j);
            }
        }
    }
};
