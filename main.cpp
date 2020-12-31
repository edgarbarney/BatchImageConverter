#include "mainwindow.h"
#include <Magick++.h>
#include <QApplication>

using namespace Magick;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
	InitializeMagick(*argv);
    return a.exec();
}
