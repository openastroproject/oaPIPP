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
#include <QtWidgets>
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

	setUpConnections();

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


void
SourceFiles::setUpConnections ( void )
{
  connect ( ui->addImagesButton, &QPushButton::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->removeImagesButton, &QPushButton::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->removeAllImagesButton, &QPushButton::clicked, this,
			&SourceFiles::unimplemented1 );

  connect ( ui->imagesUpButton, &QPushButton::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->imagesDownButton, &QPushButton::clicked, this,
			&SourceFiles::unimplemented1 );

  connect ( ui->batchMode, &QRadioButton::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->joinMode, &QRadioButton::clicked, this,
			&SourceFiles::unimplemented1 );

  connect ( ui->closeUpButton, &QRadioButton::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->aviButton, &QRadioButton::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->fullDiscButton, &QRadioButton::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->gifButton, &QRadioButton::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->planetaryButton, &QRadioButton::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->issButton, &QRadioButton::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->archiveButton, &QRadioButton::clicked, this,
			&SourceFiles::unimplemented1 );

  connect ( ui->addDarksButton, &QPushButton::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->removeDarksButton, &QPushButton::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->removeAllDarksButton, &QPushButton::clicked, this,
			&SourceFiles::unimplemented1 );

  connect ( ui->enableDarkFrameSubtraction, &QCheckBox::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->saveMasterDark, &QCheckBox::clicked, this,
			&SourceFiles::unimplemented1 );


  connect ( ui->thresholdVal, &QSpinBox::textChanged, this,
			&SourceFiles::unimplemented2 );
  connect ( ui->enableHotPixel, &QCheckBox::clicked, this,
			&SourceFiles::unimplemented1 );

  connect ( ui->addFlatsButton, &QPushButton::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->removeFlatsButton, &QPushButton::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->removeAllFlatsButton, &QPushButton::clicked, this,
			&SourceFiles::unimplemented1 );

  connect ( ui->enableFlatFrameCorrection, &QCheckBox::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->flatsMonoWithBayer, &QCheckBox::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->saveMasterFlat, &QCheckBox::clicked, this,
			&SourceFiles::unimplemented1 );

  connect ( ui->addFlatDarksButton, &QPushButton::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->removeFlatDarksButton, &QPushButton::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->removeAllFlatDarksButton, &QPushButton::clicked, this,
			&SourceFiles::unimplemented1 );

  connect ( ui->enableFlatDarkFrameSubtraction, &QCheckBox::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->saveMasterFlatDark, &QCheckBox::clicked, this,
			&SourceFiles::unimplemented1 );
}


void
SourceFiles::unimplemented1 ( void )
{
	qDebug() << "slot not yet implemented";
}


void
SourceFiles::unimplemented2 ( const QString& text )
{
	Q_UNUSED ( text )

	qDebug() << "slot not yet implemented";
}
