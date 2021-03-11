#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Magick++.h>
#include <franutils.h>

using namespace std;
using namespace franticUtils;

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

	void on_quality_Cbox_stateChanged(int arg1);

	void on_flip_Chbox_stateChanged(int arg1);

	void on_rotation_Chbox_stateChanged(int arg1);

	void on_negate_Chbox_stateChanged(int arg1);

	private:
    Ui::MainWindow *ui;

	void AddFilesIntoTheList();

	convFlags CheckFlags();

	QString filedir;



};
#endif // MAINWINDOW_H
