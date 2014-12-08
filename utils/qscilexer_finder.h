/****************************************************************************************
** qscilexer_finder.h is part of Nevis
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

#ifndef QSCILEXER_FINDER_H
#define QSCILEXER_FINDER_H

#include <QObject>

class QscilexerFinder : public QObject
{
    Q_OBJECT
public:
    explicit QscilexerFinder(QObject *parent = 0);

signals:

public slots:

};

#endif // QSCILEXER_FINDER_H
