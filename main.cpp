#include "run.hpp"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MenuWidget window;
    window.show();
    return app.exec();
}
