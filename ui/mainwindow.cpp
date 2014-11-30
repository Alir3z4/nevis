/****************************************************************************************
** mainwindow.cpp is part of Nevis
**
** Copyright 2014 Alireza Savand <alireza.savand@gmail.com>
**
** Nevis is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 3 of the License, or
** (at your option) any later version.
**
** Nevis is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui/dialog/about_dialog.h"
#include "ui/dialog/report_bug_dialog.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpenFile_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(), tr("Any File (*.*)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        }
        QTextStream in(&file);
        ui->textEditor->setText(in.readAll());
        file.close();
    }
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save file"), QString(), tr("Any File (*.*)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not save file"));
        } else {
            QTextStream stream(&file);
            stream << ui->textEditor->text();
            stream.flush();;
            file.close();
        }
    }
}

void MainWindow::on_actionAboutQt_triggered()
{
    qApp->aboutQt();
}

void MainWindow::on_actionAboutNevis_triggered()
{
    AboutDialog about_dialog(this);
    about_dialog.exec();
}

void MainWindow::on_actionReportBug_triggered()
{
    ReportBugDialog report_bug_dialog;
    report_bug_dialog.exec();
}


void MainWindow::initializeCaretLine()
{
    // Current line visible with special background color
    ui->textEditor->setCaretLineVisible(true);
    ui->textEditor->setCaretLineBackgroundColor(QColor("#ffe4e4"));
}
void MainWindow::initializeMargin()
{
    QFontMetrics fontMetrics = QFontMetrics(ui->textEditor->font());
    ui->textEditor->setMarginsFont(ui->textEditor->font());
    ui->textEditor->setMarginWidth(0, fontMetrics.width(QString::number(ui->textEditor->lines())) + 6);
    ui->textEditor->setMarginLineNumbers(0, true);
    ui->textEditor->setMarginsBackgroundColor(QColor("#cccccc"));

    connect(ui->textEditor, SIGNAL(textChanged()), this, SLOT(onTextChanged()));
}
