#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Magick++.h>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_browse_Btn_released();

	void on_browseTarget_Btn_released();

    void on_loadFiles_Btn_released();

    void on_clearFiles_Btn_released();

	void on_exclude_Btn_released();

	void on_include_Btn_released();

	void on_start_Btn_released();

	private:
    Ui::MainWindow *ui;
    //std::string filedir = "";
    QString filedir;
    void AddFilesIntoTheList();
};
#endif // MAINWINDOW_H
