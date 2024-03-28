/*****************************************************************************
 *
 * processingOptions.cc -- manage the processing options tab
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

#include "processingOptions.h"
#include "ui_processingOptions.h"

ProcessingOptions::ProcessingOptions ( QWidget* parent ) :
	QWidget ( parent ),
	ui ( new Ui::ProcessingOptions )
{
	ui->setupUi ( this );

	setUpConnections();

	QString err = std::source_location::current().function_name();
  err += " not fully implemented";

  qDebug() << err;
}


ProcessingOptions::~ProcessingOptions ( void )
{
	delete ui;
}


void
ProcessingOptions::setUpConnections ( void )
{
  connect ( ui->processingGain, &QDoubleSpinBox::textChanged, this,
			&ProcessingOptions::unimplemented2 );
  connect ( ui->processingGamma, &QDoubleSpinBox::textChanged, this,
			&ProcessingOptions::unimplemented2 );

  connect ( ui->noiseFilter, &QCheckBox::clicked, this,
			&ProcessingOptions::unimplemented1 );

  connect ( ui->colour2mono, &QCheckBox::clicked, this,
			&ProcessingOptions::unimplemented1 );
  connect ( ui->monochromeSource, &QComboBox::currentTextChanged, this,
			&ProcessingOptions::unimplemented2 );

  connect ( ui->whitePointBox, &QCheckBox::clicked, this,
			&ProcessingOptions::unimplemented1 );
  connect ( ui->whitePointVal, &QSpinBox::textChanged, this,
			&ProcessingOptions::unimplemented2 );
  connect ( ui->blackPointBox, &QCheckBox::clicked, this,
			&ProcessingOptions::unimplemented1 );

  connect ( ui->equaliseIndividually, &QCheckBox::clicked, this,
			&ProcessingOptions::unimplemented1 );

  connect ( ui->numOverexposed, &QSpinBox::textChanged, this,
			&ProcessingOptions::unimplemented2 );
  connect ( ui->rejectOverexposed, &QCheckBox::clicked, this,
			&ProcessingOptions::unimplemented1 );


  connect ( ui->horizontalFlip, &QCheckBox::clicked, this,
			&ProcessingOptions::unimplemented1 );
  connect ( ui->verticalFlip, &QCheckBox::clicked, this,
			&ProcessingOptions::unimplemented1 );

  connect ( ui->rotation, &QComboBox::currentTextChanged, this,
			&ProcessingOptions::unimplemented2 );

  connect ( ui->noStabilisation, &QRadioButton::clicked, this,
			&ProcessingOptions::unimplemented1 );
  connect ( ui->objectStabilisation, &QRadioButton::clicked, this,
			&ProcessingOptions::unimplemented1 );
  connect ( ui->featureStabilisation, &QRadioButton::clicked, this,
			&ProcessingOptions::unimplemented1 );

  connect ( ui->enableObjectDetection, &QCheckBox::clicked, this,
			&ProcessingOptions::unimplemented1 );
  connect ( ui->minObjectSize, &QSpinBox::textChanged, this,
			&ProcessingOptions::unimplemented2 );
  connect ( ui->autoObjectDetection, &QCheckBox::clicked, this,
			&ProcessingOptions::unimplemented1 );
  connect ( ui->detectionThreshold, &QSpinBox::textChanged, this,
			&ProcessingOptions::unimplemented2 );

  connect ( ui->surfaceFeatureTracking, &QCheckBox::clicked, this,
			&ProcessingOptions::unimplemented1 );
  connect ( ui->surfaceStabilisation, &QCheckBox::clicked, this,
			&ProcessingOptions::unimplemented1 );
  connect ( ui->anchorX, &QSpinBox::textChanged, this,
			&ProcessingOptions::unimplemented2 );
  connect ( ui->anchorY, &QSpinBox::textChanged, this,
			&ProcessingOptions::unimplemented2 );
  connect ( ui->anchorWidth, &QSpinBox::textChanged, this,
			&ProcessingOptions::unimplemented2 );
  connect ( ui->anchorHeight, &QSpinBox::textChanged, this,
			&ProcessingOptions::unimplemented2 );
  connect ( ui->rejectNoAnchor, &QCheckBox::clicked, this,
			&ProcessingOptions::unimplemented1 );

  connect ( ui->enableAOI, &QCheckBox::clicked, this,
			&ProcessingOptions::unimplemented1 );
  connect ( ui->aoiX, &QSpinBox::textChanged, this,
			&ProcessingOptions::unimplemented2 );
  connect ( ui->aoiY, &QSpinBox::textChanged, this,
			&ProcessingOptions::unimplemented2 );
  connect ( ui->aoiWidth, &QSpinBox::textChanged, this,
			&ProcessingOptions::unimplemented2 );
  connect ( ui->aoiHeight, &QSpinBox::textChanged, this,
			&ProcessingOptions::unimplemented2 );
  connect ( ui->rejectIncompleteAOI, &QCheckBox::clicked, this,
			&ProcessingOptions::unimplemented1 );
  connect ( ui->aoiCrop, &QCheckBox::clicked, this,
			&ProcessingOptions::unimplemented1 );

  connect ( ui->enableCropping, &QCheckBox::clicked, this,
			&ProcessingOptions::unimplemented1 );
  connect ( ui->cropX, &QSpinBox::textChanged, this,
			&ProcessingOptions::unimplemented2 );
  connect ( ui->cropY, &QSpinBox::textChanged, this,
			&ProcessingOptions::unimplemented2 );
  connect ( ui->cropWidth, &QSpinBox::textChanged, this,
			&ProcessingOptions::unimplemented2 );
  connect ( ui->cropHeight, &QSpinBox::textChanged, this,
			&ProcessingOptions::unimplemented2 );

  connect ( ui->resizeFrames, &QCheckBox::clicked, this,
			&ProcessingOptions::unimplemented1 );
  connect ( ui->keepAspectRatio, &QCheckBox::clicked, this,
			&ProcessingOptions::unimplemented1 );
  connect ( ui->resizeWidth, &QSpinBox::textChanged, this,
			&ProcessingOptions::unimplemented2 );
  connect ( ui->resizeHeight, &QSpinBox::textChanged, this,
			&ProcessingOptions::unimplemented2 );
}


void
ProcessingOptions::unimplemented1 ( void )
{
	qDebug() << "slot not yet implemented";
}


void
ProcessingOptions::unimplemented2 ( const QString& text )
{
	Q_UNUSED ( text )

	qDebug() << "slot not yet implemented";
}


void
ProcessingOptions::updatePresets ( int option )
{
  QString err = std::source_location::current().function_name();
  err += " not fully implemented";

  qDebug() << err;
}

