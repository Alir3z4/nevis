/****************************************************************************************
** mainwindow.h is part of Nevis
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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "utils/qscilexer_finder.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpenFile_triggered();
    void on_actionSave_triggered();
    void on_actionAboutQt_triggered();
    void on_actionAboutNevis_triggered();
    void on_actionReportBug_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void onTextChanged();


    void saveSettings();
    void loadSettings();


private:
    Ui::MainWindow *ui;
    QscilexerFinder *lexerFinder;

    void initializeTextEditor();
    void initializeFolding();
    void initializeCaretLine();
    void initializeMargin();

    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
