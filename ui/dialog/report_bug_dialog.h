/****************************************************************************************
** report_bug_dialog.h is part of Nevis
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

#ifndef REPORT_BUG_DIALOG_H
#define REPORT_BUG_DIALOG_H

#include <QDialog>
#include <QDesktopServices>
#include <QUrl>

namespace Ui {
class ReportBugDialog;
}

class ReportBugDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReportBugDialog(QWidget *parent = 0);
    ~ReportBugDialog();

private slots:
    void on_submitButton_clicked();

private:
    Ui::ReportBugDialog *ui;
};

#endif // REPORT_BUG_DIALOG_H
