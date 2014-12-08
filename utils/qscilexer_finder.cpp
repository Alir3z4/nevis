/****************************************************************************************
** qscilexer_finder.cpp is part of Nevis
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

#include "qscilexer_finder.h"
#include "Qsci/qscilexerbash.h"
#include "Qsci/qscilexercpp.h"
#include "Qsci/qscilexerpython.h"


QscilexerFinder::QscilexerFinder(QObject *parent) :
    QObject(parent)
{
    this->lexers = new QHash<const QString, QsciLexer*>;

    this->lexers->insert(QString("sh|"), new QsciLexerBash());
    this->lexers->insert(QString("c|cpp|h|hpp|"), new QsciLexerCPP());
    this->lexers->insert(QString("py|pxx|"), new QsciLexerPython());

}
}
