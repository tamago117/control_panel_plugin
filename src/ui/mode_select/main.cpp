#include "mode_select.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mode_select w;
    w.show();

    return a.exec();
}
