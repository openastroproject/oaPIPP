/*****************************************************************************
 *
 * doProcessing.cc -- manage the processing options tab
 *
 * Copyright 2024
 *		James Fidell (james@openastroproject.org)
 *
 * License:
 *
 * This file is part of the Open Astro Project.
 *
 * The Open Astro Project is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * The Open Astro Project is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the Open Astro Project.  If not, see
 * <http://www.gnu.org/licenses/>.
 *
 *****************************************************************************/

#include <QtCore>
#include <source_location>

#include "doProcessing.h"

DoProcessing::DoProcessing ( void )
{
}


DoProcessing::~DoProcessing ( void )
{
}


void
DoProcessing::initialise ( void )
{
	  QString err = std::source_location::current().function_name();
  err += " not yet implemented";

  qDebug() << err;
}
