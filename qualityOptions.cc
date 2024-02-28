/*****************************************************************************
 *
 * qualityOptions.cc -- manage the quality options tab
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

#include "qualityOptions.h"
#include "ui_qualityOptions.h"

QualityOptions::QualityOptions ( QWidget* parent ) :
	QWidget ( parent ),
	ui ( new Ui::QualityOptions )
{
	ui->setupUi ( this );

	QString err = std::source_location::current().function_name();
  err += " not fully implemented";

  qDebug() << err;
}


QualityOptions::~QualityOptions ( void )
{
	delete ui;
}
