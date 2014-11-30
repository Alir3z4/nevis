/****************************************************************************************
** about_dialog.cpp is part of Nevis
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

#include "about_dialog.h"
#include "ui_about_dialog.h"
#include "utils/paths.h"
#include <QFile>
#include <QTextStream>

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

    QFile licenseFile(Paths::docsPath() + "/LICENSE");
    QTextStream in(&licenseFile);

    ui->licenseTextEdit->setPlainText(in.readAll());
    ui->descriptionLabel->setText(tr(
                    "<b>Version: %1</b>\n"
                    "Based on Qt %2\n\n\n"
                    "Nevis is only a simple fast text editor.\n"
                    "Nevis uses Qt toolkit for both front-end and back-end implementation!\n\n\n"
                    "Copyright (C) 2014 by Alireza Savand\nhttps://github.com/Alir3z4/nevis/\n")
                                     .arg(qApp->applicationVersion())
                                     .arg(qVersion()));

}

AboutDialog::~AboutDialog()
{
    delete ui;
}
