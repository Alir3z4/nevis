/****************************************************************************************
** paths.h is part of Nevis
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

#ifndef PATHS_H
#define PATHS_H

#define STRINGIFY2(x) #x
#define STRINGIFY(x) STRINGIFY2(x)

#include <QString>

class Paths
{
public:
    static QString translationsPath();
    static QString docsPath();
};

#endif // PATHS_H
