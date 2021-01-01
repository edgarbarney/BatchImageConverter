#include "mainwindow.h"
#include <Magick++.h>
#include <QApplication>

using namespace Magick;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	InitializeMagick(*argv);
    MainWindow w;
    w.show();
    return a.exec();
}
