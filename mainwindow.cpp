#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <list>
#include <iterator>
#include <QFileDialog>
#include <filesystem>
#include <franutils.h>

using namespace std;
using namespace franticUtils;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	filedir = nullptr;
}


MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_browse_Btn_released()
{
	QString defDir = "";

	if (ui->fileDirectory_Text->text() != nullptr)
	{
		QString defDir = ui->fileDirectory_Text->text();
		filedir = defDir;
	}
	else
	{
		QString defDir = "";
	}
	QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),defDir,QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if (dir != nullptr)
	{
		ui->fileDirectory_Text->setText(dir);
	}
}


void MainWindow::AddFilesIntoTheList()
{
	if (ui->fileDirectory_Text->text() != nullptr)
	{
		QString defDir = ui->fileDirectory_Text->text();
		filedir = defDir;
	}
	filesystem::path pathOfDir = qstToStd(filedir);
	if (filedir != nullptr && filesystem::is_directory(filesystem::path(qstToStd(filedir))))
	{
		if (!ui->isRecursive_Cbox->isChecked())
		{
			for (const auto & item : filesystem::directory_iterator(filesystem::path(qstToStd(filedir))))
			{
				if (ui->convertFrom_Cbox->currentIndex() != ui->convertFrom_Cbox->count())
				{
					string extStr = qstToStd(ui->convertFrom_Cbox->currentText());
					extStr.insert(0,".");
					if (pathOfDir.extension() == extStr){
						ui->filesToConvert_List->addItem(QString::fromStdString(item.path().u8string()));
					}
				}
				else
				{
					for(int i = 0; i < ui->convertFrom_Cbox->count()-1 ; i++)
					{
						string extStr = qstToStd(ui->convertFrom_Cbox->itemText(i));
						extStr.insert(0,".");
						if (pathOfDir.extension() == extStr){
							ui->filesToConvert_List->addItem(QString::fromStdString(item.path().u8string()));
						}
					}
				}
			}
		}
		else
		{
			for (const auto & item : filesystem::recursive_directory_iterator(filesystem::path(qstToStd(filedir))))
			{
				ui->filesToConvert_List->addItem(QString::fromStdString(item.path().u8string()));
			}
		}

	}
}


void MainWindow::on_loadFiles_Btn_released()
{
	AddFilesIntoTheList();
}

void MainWindow::on_clearFiles_Btn_released()
{
	ui->filesToConvert_List->clear();
	ui->filesToExclue_List->clear();
}
