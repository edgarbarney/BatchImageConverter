#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <list>
#include <iterator>
#include <QFileDialog>
#include <filesystem>
#include <franutils.h>
#include <algorithm>

using namespace std;
using namespace franticUtils;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	filedir = nullptr;
	setFixedSize(this->geometry().width(),this->geometry().height());
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

void MainWindow::on_browseTarget_Btn_released()
{
	QString defDir = "";

	if (ui->targetDirectory_Text->text() != nullptr)
	{
		QString defDir = ui->targetDirectory_Text->text();
		filedir = defDir;
	}
	else
	{
		QString defDir = "";
	}
	QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),defDir,QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if (dir != nullptr)
	{
		ui->targetDirectory_Text->setText(dir);
	}
}


void MainWindow::AddFilesIntoTheList()
{
	if (ui->fileDirectory_Text->text() != nullptr)
	{
		QString defDir = ui->fileDirectory_Text->text();
		filedir = defDir;
	}
	filesystem::path pathOfDir = QstToStd(filedir);
	if (filedir != nullptr && filesystem::is_directory(filesystem::path(QstToStd(filedir))))
	{
		if (!ui->isRecursive_Cbox->isChecked())
		{
			for (const auto & item : filesystem::directory_iterator(filesystem::path(QstToStd(filedir))))
			{
				if (ui->convertFrom_Cbox->currentIndex() != ui->convertFrom_Cbox->count()-1)
				{
					string extStr = QstToStd(ui->convertFrom_Cbox->currentText());
					extStr.insert(0,".");
					string extToWorkOn = item.path().extension().u8string();
					transform(extToWorkOn.begin(), extToWorkOn.end(), extToWorkOn.begin(), ::toupper);
					if (extToWorkOn == extStr){
						ui->filesToConvert_List->addItem(QString::fromStdString(item.path().u8string()));
					}
				}
				else
				{
					for(int i = 0; i < ui->convertFrom_Cbox->count() ; i++)
					{
						string extStr = QstToStd(ui->convertFrom_Cbox->itemText(i));
						extStr.insert(0,".");
						string extToWorkOn = item.path().extension().u8string();
						transform(extToWorkOn.begin(), extToWorkOn.end(), extToWorkOn.begin(), ::toupper);
						if (extToWorkOn == extStr){
							ui->filesToConvert_List->addItem(QString::fromStdString(item.path().u8string()));
						}
					}
				}
			}
		}
		else
		{
			for (const auto & item : filesystem::recursive_directory_iterator(filesystem::path(QstToStd(filedir))))
			{
				if (ui->convertFrom_Cbox->currentIndex() != ui->convertFrom_Cbox->count()-1)
				{
					string extStr = QstToStd(ui->convertFrom_Cbox->currentText());
					extStr.insert(0,".");
					string extToWorkOn = item.path().extension().u8string();
					transform(extToWorkOn.begin(), extToWorkOn.end(), extToWorkOn.begin(), ::toupper);
					if (extToWorkOn == extStr){
						ui->filesToConvert_List->addItem(QString::fromStdString(item.path().u8string()));
					}
				}
				else
				{
					for(int i = 0; i < ui->convertFrom_Cbox->count() ; i++)
					{
						string extStr = QstToStd(ui->convertFrom_Cbox->itemText(i));
						extStr.insert(0,".");
						string extToWorkOn = item.path().extension().u8string();
						transform(extToWorkOn.begin(), extToWorkOn.end(), extToWorkOn.begin(), ::toupper);
						if (extToWorkOn == extStr){
							ui->filesToConvert_List->addItem(QString::fromStdString(item.path().u8string()));
						}
					}
				}
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

void MainWindow::on_exclude_Btn_released()
{
	QList<QListWidgetItem*> items = ui->filesToConvert_List->selectedItems();
	foreach(QListWidgetItem * item, items)
	{
		ui->filesToExclue_List->addItem(item->text());
		delete item;
	}
}

void MainWindow::on_include_Btn_released()
{
	QList<QListWidgetItem*> items = ui->filesToExclue_List->selectedItems();
	foreach(QListWidgetItem * item, items)
	{
		ui->filesToConvert_List->addItem(item->text());
		delete item;
	}
}

void MainWindow::on_start_Btn_released()
{
	if (ui->filesToConvert_List->count() != 0)
	{
		for (int i = 0; i < ui->filesToConvert_List->count(); i++)
		{
			string extStr = QstToStd(ui->convertTo_Cbox->currentText());
			//extStr.insert(0,".");
			const filesystem::path path = QstToStd(ui->filesToConvert_List->item(i)->text());
			ConvertImage(QstToStd(ui->filesToConvert_List->item(i)->text()), extStr, ui->targetDirectory_Text->text(),path.filename().u8string());
		}
	}
}
