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

#include "oapipp_common.h"
#include "processingOptions.h"
#include "sourceFiles.h"
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
	// Disable everything that might have been enabled in a previous call
	ui->enableObjectDetection->setChecked ( false );
	ui->centreObject->setChecked ( false );
	ui->enableCropping->setChecked ( false );

	ui->colour2mono->setChecked ( false );
	ui->surfaceFeatureTracking->setChecked ( false );
	ui->surfaceStabilisation->setChecked ( false );

	ui->whitePointBox->setChecked ( false );
	ui->blackPointBox->setChecked ( false );
	ui->equaliseIndividually->setChecked ( false );

	ui->enableObjectDetection->setChecked ( false );
	ui->autoObjectDetection->setChecked ( false );

	// Turn all the options back to the default colour
	ui->objectStabilisation->setStyleSheet ( presetOffStyle );
	ui->enableObjectDetection->setStyleSheet ( presetOffStyle );
	ui->centreObject->setStyleSheet ( presetOffStyle );
	ui->enableCropping->setStyleSheet ( presetOffStyle );
	ui->cropHeight->setStyleSheet ( presetOffStyle );
	ui->cropWidth->setStyleSheet ( presetOffStyle );

	ui->featureStabilisation->setStyleSheet ( presetOffStyle );
	ui->colour2mono->setStyleSheet ( presetOffStyle );
	ui->surfaceFeatureTracking->setStyleSheet ( presetOffStyle );
	ui->surfaceStabilisation->setStyleSheet ( presetOffStyle );

	ui->whitePointBox->setStyleSheet ( presetOffStyle );
	ui->whitePointVal->setStyleSheet ( presetOffStyle );
	ui->blackPointBox->setStyleSheet ( presetOffStyle );
	ui->equaliseIndividually->setStyleSheet ( presetOffStyle );
	ui->detectionThreshold->setStyleSheet ( presetOffStyle );

	ui->equaliseIndividually->setStyleSheet ( presetOffStyle );
	ui->autoObjectDetection->setStyleSheet ( presetOffStyle );
	ui->detectionThreshold->setStyleSheet ( presetOffStyle );

	ui->noStabilisation->setChecked ( false );
	ui->noStabilisation->setStyleSheet ( presetOffStyle );

	switch ( option ) {
		case SourceFiles::presetPlanet:
			ui->objectStabilisation->click();
			ui->enableObjectDetection->click();
			ui->centreObject->click();
			ui->enableCropping->click();
			ui->cropHeight->setValue ( 448 );
			ui->cropWidth->setValue ( 448 );
			ui->objectStabilisation->setStyleSheet ( presetOnStyle );
			ui->enableObjectDetection->setStyleSheet ( presetOnStyle );
			ui->centreObject->setStyleSheet ( presetOnStyle );
			ui->enableCropping->setStyleSheet ( presetOnStyle );
			ui->cropHeight->setStyleSheet ( presetOnStyle );
			ui->cropWidth->setStyleSheet ( presetOnStyle );
			break;

		case SourceFiles::presetCloseUp:
			ui->colour2mono->click();
			ui->featureStabilisation->click();
			ui->surfaceFeatureTracking->click();
			ui->surfaceStabilisation->click();
			ui->colour2mono->setStyleSheet ( presetOnStyle );
			ui->featureStabilisation->setStyleSheet ( presetOnStyle );
			ui->surfaceFeatureTracking->setStyleSheet ( presetOnStyle );
			ui->surfaceStabilisation->setStyleSheet ( presetOnStyle );
			break;

		case SourceFiles::presetPlanetaryAVI:
			ui->whitePointBox->click();
			ui->whitePointVal->setValue ( 95 );
			ui->blackPointBox->click();
			ui->equaliseIndividually->click();
			ui->objectStabilisation->click();
			ui->enableObjectDetection->click();
			ui->detectionThreshold->setValue ( 20 );
			ui->centreObject->click();
			ui->whitePointBox->setStyleSheet ( presetOnStyle );
			ui->whitePointVal->setStyleSheet ( presetOnStyle );
			ui->blackPointBox->setStyleSheet ( presetOnStyle );
			ui->equaliseIndividually->setStyleSheet ( presetOnStyle );
			ui->objectStabilisation->setStyleSheet ( presetOnStyle );
			ui->enableObjectDetection->setStyleSheet ( presetOnStyle );
			ui->detectionThreshold->setStyleSheet ( presetOnStyle );
			ui->centreObject->setStyleSheet ( presetOnStyle );
			break;

		case SourceFiles::presetISS:
			ui->objectStabilisation->click();
			ui->enableObjectDetection->click();
			ui->centreObject->click();
			ui->enableCropping->click();
			ui->cropHeight->setValue ( 300 );
			ui->cropWidth->setValue ( 300 );
			ui->objectStabilisation->setStyleSheet ( presetOnStyle );
			ui->enableObjectDetection->setStyleSheet ( presetOnStyle );
			ui->centreObject->setStyleSheet ( presetOnStyle );
			ui->enableCropping->setStyleSheet ( presetOnStyle );
			ui->cropHeight->setStyleSheet ( presetOnStyle );
			ui->cropWidth->setStyleSheet ( presetOnStyle );
			break;

		case SourceFiles::presetFullDisc:
			ui->colour2mono->click();
			ui->objectStabilisation->click();
			ui->enableObjectDetection->click();
			ui->centreObject->click();
			ui->enableCropping->click();
			ui->cropHeight->setValue ( 1200 );
			ui->cropWidth->setValue ( 1200 );
			ui->colour2mono->setStyleSheet ( presetOnStyle );
			ui->objectStabilisation->setStyleSheet ( presetOnStyle );
			ui->enableObjectDetection->setStyleSheet ( presetOnStyle );
			ui->centreObject->setStyleSheet ( presetOnStyle );
			ui->enableCropping->setStyleSheet ( presetOnStyle );
			ui->cropHeight->setStyleSheet ( presetOnStyle );
			ui->cropWidth->setStyleSheet ( presetOnStyle );
			break;

		case SourceFiles::presetGIF:
			ui->whitePointBox->click();
			ui->whitePointVal->setValue ( 95 );
			ui->blackPointBox->click();
			ui->equaliseIndividually->setChecked ( false );
			ui->objectStabilisation->click();
			ui->enableObjectDetection->click();
			ui->autoObjectDetection->setChecked ( false );
			ui->detectionThreshold->setValue ( 20 );
			ui->centreObject->click();
			ui->whitePointBox->setStyleSheet ( presetOnStyle );
			ui->whitePointVal->setStyleSheet ( presetOnStyle );
			ui->blackPointBox->setStyleSheet ( presetOnStyle );
			ui->equaliseIndividually->setStyleSheet ( presetOnStyle );
			ui->objectStabilisation->setStyleSheet ( presetOnStyle );
			ui->enableObjectDetection->setStyleSheet ( presetOnStyle );
			ui->autoObjectDetection->setStyleSheet ( presetOnStyle );
			ui->detectionThreshold->setStyleSheet ( presetOnStyle );
			ui->centreObject->setStyleSheet ( presetOnStyle );
			break;

		case SourceFiles::presetAVIArchive:
			ui->noStabilisation->click();
			ui->noStabilisation->setStyleSheet ( presetOnStyle );
			break;

		default:
			QString err = std::source_location::current().function_name();
			err += " unexpected preset type";

			qDebug() << err;
			break;
	}
}

