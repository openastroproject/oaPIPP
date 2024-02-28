/*****************************************************************************
 *
 * sourceFiles.cc -- manage the source files tab
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

#include "sourceFiles.h"
#include "ui_sourceFiles.h"

SourceFiles::SourceFiles ( QWidget* parent ) :
	QTabWidget ( parent ),
	ui ( new Ui::SourceFiles )
{
	ui->setupUi ( this );

	numLights = numDarks = numFlats = numFlatDarks = 0;

	updateImagesLabel();
	updateDarksLabel();
	updateFlatsLabel();
	updateFlatDarksLabel();

	ui->removeImagesButton->setEnabled ( false );
	ui->removeAllImagesButton->setEnabled ( false );
	ui->removeDarksButton->setEnabled ( false );
	ui->removeAllDarksButton->setEnabled ( false );
	ui->removeFlatsButton->setEnabled ( false );
	ui->removeAllFlatsButton->setEnabled ( false );
	ui->removeFlatDarksButton->setEnabled ( false );
	ui->removeAllFlatDarksButton->setEnabled ( false );

	QString err = std::source_location::current().function_name();
  err += " not fully implemented";

  qDebug() << err;
}


SourceFiles::~SourceFiles ( void )
{
	delete ui;
}


void
SourceFiles::updateImagesLabel ( void )
{
	QString label = QObject::tr ( "Image Files (%1 frames)" );
	setTabText ( 0, label.arg ( numLights ));
}


void
SourceFiles::updateDarksLabel ( void )
{
	QString label = QObject::tr ( "Dark Files (%1 frames)" );
	setTabText ( 1, label.arg ( numDarks ));
}


void
SourceFiles::updateFlatsLabel ( void )
{
	QString label = QObject::tr ( "Flat Files (%1 frames)" );
	setTabText ( 2, label.arg ( numFlats ));
}


void
SourceFiles::updateFlatDarksLabel ( void )
{
	QString label = QObject::tr ( "Flat Dark Files (%1 frames)" );
	setTabText ( 3, label.arg ( numFlatDarks ));
}
