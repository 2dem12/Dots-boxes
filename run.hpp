#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>

class MenuWidget : public QWidget {
    Q_OBJECT
public:
    MenuWidget(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);
        setFixedSize(1300, 800); // Запрещает изменение размера

        QLabel *titleLabel = new QLabel("Menu", this);
        titleLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(titleLabel);

        QComboBox *sizeComboBox = new QComboBox(this);
        sizeComboBox->addItems({"3x2", "5x4", "6x8"});
        layout->addWidget(sizeComboBox);

        QComboBox *difficultyComboBox = new QComboBox(this);
        difficultyComboBox->addItems({"Easy", "Normal", "Hard"});
        layout->addWidget(difficultyComboBox);

        QPushButton *runButton = new QPushButton("Run", this);
        QPushButton *exitButton = new QPushButton("Exit", this);

        layout->addWidget(runButton);
        layout->addWidget(exitButton);

        connect(exitButton, &QPushButton::clicked, qApp, &QApplication::quit);
    }
};

int run(int argc, char *argv[]);

