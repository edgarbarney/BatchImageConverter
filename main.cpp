#include "mainwindow.h"
#include <Magick++.h>
#include <QApplication>
#include <locale.h>

using namespace Magick;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	InitializeMagick(*argv);
	setlocale(LC_ALL, "");
    MainWindow w;
    w.show();
    return a.exec();
}
