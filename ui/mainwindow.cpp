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
#include <QSettings>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initializeTextEditor();
    loadSettings();
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

void MainWindow::onTextChanged()
{
    QFontMetrics fontMetrics = ui->textEditor->fontMetrics();
    ui->textEditor->setMarginWidth(0, fontMetrics.width(QString::number(ui->textEditor->lines())) + 6);
}

void MainWindow::saveSettings()
{
    QSettings settings;
    settings.beginGroup("MainWindow");

    settings.setValue("pos", pos());
    settings.setValue("size", size());
    settings.setValue("geometry", geometry());
    settings.setValue("fullScreen", isFullScreen());
    settings.setValue("state", saveState());

    settings.beginGroup("menuBar");
    settings.setValue("isHidden", ui->menuBar->isHidden());
    settings.endGroup();


    settings.beginGroup("statusBar");
    settings.setValue("isHidden", ui->statusBar->isHidden());
    settings.endGroup();

    settings.beginGroup("toolBar");
    settings.setValue("isHidden", ui->toolBar->isHidden());
    settings.setValue("geometry", ui->toolBar->geometry());
    settings.endGroup();

    settings.beginGroup("actionShowMenubar");
    settings.setValue("isChecked", ui->actionShowMenubar->isChecked());
    settings.setValue("shortcut", ui->actionShowMenubar->shortcut());
    settings.endGroup();

    settings.beginGroup("actionShowToolbar");
    settings.setValue("isChecked", ui->actionShowToolbar->isChecked());
    settings.setValue("shortcut", ui->actionShowToolbar->shortcut());
    settings.endGroup();

    settings.beginGroup("actionShowStatusbar");
    settings.setValue("isChecked", ui->actionShowStatusbar->isChecked());
    settings.setValue("shortcut", ui->actionShowStatusbar->shortcut());
    settings.endGroup();

    settings.endGroup();
}

void MainWindow::loadSettings()
{
    QSettings settings;
    settings.beginGroup("MainWindow");
    move(settings.value("pos", QPoint(200, 200)).toPoint());
    resize(settings.value("size", QSize(400, 400)).toSize());
    setGeometry(settings.value("geometry", QRect(49, 331, 670, 445)).toRect());
    if (settings.value("fullscreen").toBool()) {
        showFullScreen();
    }
    restoreState(settings.value("state", QByteArray()).toByteArray());

    settings.beginGroup("menuBar");
    ui->menuBar->setHidden(settings.value("isHidden", false).toBool());
    settings.endGroup();

    settings.beginGroup("statusBar");
    ui->statusBar->setHidden(settings.value("isHidden", false).toBool());
    settings.endGroup();

    settings.beginGroup("toolBar");
    ui->toolBar->setHidden(settings.value("isHidden", false).toBool());
    ui->toolBar->setGeometry(settings.value("geometry").toRect());
    settings.endGroup();

    settings.beginGroup("actionShowMenubar");
    ui->actionShowMenubar->setChecked(settings.value("isChecked", true).toBool());
    ui->actionShowMenubar->setShortcut(
                QKeySequence(settings.value("shortcut", ui->actionShowMenubar->shortcut().toString()).toString()));
    settings.endGroup();

    settings.beginGroup("actionShowToolbar");
    ui->actionShowToolbar->setChecked(settings.value("isChecked", true).toBool());
    ui->actionShowToolbar->setShortcut(
                QKeySequence(settings.value("shortcut", ui->actionShowToolbar->shortcut().toString()).toString()));
    settings.endGroup();

    settings.beginGroup("actionShowStatusbar");
    ui->actionShowStatusbar->setChecked(settings.value("isChecked", true).toBool());
    ui->actionShowStatusbar->setShortcut(
                QKeySequence(settings.value("shortcut", ui->actionShowStatusbar->shortcut().toString()).toString()));
    settings.endGroup();

    settings.endGroup();
}

void MainWindow::initializeTextEditor()
{
    initializeMargin();
    initializeCaretLine();
    initializeFolding();
}

void MainWindow::initializeFolding()
{
    QsciScintilla::FoldStyle state = static_cast<QsciScintilla::FoldStyle>((ui->textEditor->folding()) * 5);

    if (state) {
        ui->textEditor->foldAll(false);
    }

    ui->textEditor->setFolding(state);
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

void MainWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event)

    saveSettings();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEditor->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEditor->redo();
}
