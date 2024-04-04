/*****************************************************************************
 *
 * outputOptions.cc -- manage the output options tab
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

#include "outputOptions.h"
#include "sourceFiles.h"
#include "ui_outputOptions.h"

OutputOptions::OutputOptions ( QWidget* parent ) :
	QWidget ( parent ),
	ui ( new Ui::OutputOptions )
{
	ui->setupUi ( this );

	setUpConnections();

  QString err = std::source_location::current().function_name();
  err += " not fully implemented";

  qDebug() << err;
}


OutputOptions::~OutputOptions ( void )
{
	delete ui;
}


void
OutputOptions::setUpConnections ( void )
{
  connect ( ui->outputAVI, &QRadioButton::clicked, this,
			&OutputOptions::unimplemented1 );
  connect ( ui->outputSER, &QRadioButton::clicked, this,
			&OutputOptions::unimplemented1 );
  connect ( ui->outputBMP, &QRadioButton::clicked, this,
			&OutputOptions::unimplemented1 );
  connect ( ui->outputTIFF, &QRadioButton::clicked, this,
			&OutputOptions::unimplemented1 );
  connect ( ui->outputFITS, &QRadioButton::clicked, this,
			&OutputOptions::unimplemented1 );
  connect ( ui->outputPNG, &QRadioButton::clicked, this,
			&OutputOptions::unimplemented1 );
  connect ( ui->outputAnimGIF, &QRadioButton::clicked, this,
			&OutputOptions::unimplemented1 );

  connect ( ui->useDefaultOutputDir, &QPushButton::clicked, this,
			&OutputOptions::unimplemented1 );
  connect ( ui->selectOutputDir, &QPushButton::clicked, this,
			&OutputOptions::unimplemented1 );

  connect ( ui->createOutputSubdir, &QCheckBox::clicked, this,
			&OutputOptions::unimplemented1 );
  connect ( ui->outputSubdirName, &QLineEdit::editingFinished, this,
			&OutputOptions::unimplemented1 );
  connect ( ui->appendDateTime, &QCheckBox::clicked, this,
			&OutputOptions::unimplemented1 );
  connect ( ui->outputFilePrefix, &QLineEdit::editingFinished, this,
			&OutputOptions::unimplemented1 );
  connect ( ui->outputFileSuffix, &QLineEdit::editingFinished, this,
			&OutputOptions::unimplemented1 );

  connect ( ui->splitRGB, &QCheckBox::clicked, this,
			&OutputOptions::unimplemented1 );

  connect ( ui->framesToDrop, &QSpinBox::textChanged, this,
			&OutputOptions::unimplemented2 );

  connect ( ui->outputCodec, &QComboBox::currentTextChanged, this,
			&OutputOptions::unimplemented2 );
  connect ( ui->outputQuality, &QSpinBox::textChanged, this,
			&OutputOptions::unimplemented2 );
  connect ( ui->oldFormatAVI, &QCheckBox::clicked, this,
			&OutputOptions::unimplemented1 );
  connect ( ui->maxAVISize, &QComboBox::currentTextChanged, this,
			&OutputOptions::unimplemented2 );
  connect ( ui->safeSize, &QCheckBox::clicked, this,
			&OutputOptions::unimplemented1 );
  connect ( ui->matchInputFrameRate, &QCheckBox::clicked, this,
			&OutputOptions::unimplemented1 );
  connect ( ui->defaultFrameRate, &QSpinBox::textChanged, this,
			&OutputOptions::unimplemented2 );

  connect ( ui->winjuposNames, &QCheckBox::clicked, this,
			&OutputOptions::unimplemented1 );
  connect ( ui->filenameTime, &QComboBox::currentTextChanged, this,
			&OutputOptions::unimplemented2 );
}


void
OutputOptions::unimplemented1 ( void )
{
	qDebug() << "slot not yet implemented";
}


void
OutputOptions::unimplemented2 ( const QString& text )
{
	Q_UNUSED ( text )

	qDebug() << "slot not yet implemented";
}


void
OutputOptions::updatePresets ( int option )
{
	// Disable everything that might have been enabled in a previous call
	ui->outputAVI->setChecked ( false );
	ui->matchInputFrameRate->setChecked ( false );
  ui->createOutputSubdir->setChecked ( false );

	// Turn all the options back to the default colour
	ui->outputAVI->setStyleSheet ( presetOffStyle );
	ui->outputCodec->setStyleSheet ( presetOffStyle );
	ui->matchInputFrameRate->setStyleSheet ( presetOffStyle );
	ui->defaultFrameRate->setStyleSheet ( presetOffStyle );
  ui->createOutputSubdir->setStyleSheet ( presetOffStyle );
  ui->outputFileSuffix->setStyleSheet ( presetOffStyle );

	switch ( option ) {
		case SourceFiles::presetPlanet:
		case SourceFiles::presetCloseUp:
			// no changes required
			break;

		case SourceFiles::presetPlanetaryAVI:
			ui->outputAVI->click();
			ui->outputCodec->setCurrentIndex ( 2 );
			ui->matchInputFrameRate->setChecked ( false );
      ui->defaultFrameRate->setValue ( 10 );
			ui->outputAVI->setStyleSheet ( presetOnStyle );
			ui->outputCodec->setStyleSheet ( presetOnStyle );
			ui->matchInputFrameRate->setStyleSheet ( presetOnStyle );
			ui->defaultFrameRate->setStyleSheet ( presetOnStyle );

		case SourceFiles::presetISS:
			// todo
			break;

		case SourceFiles::presetFullDisc:
			// todo
			break;

		case SourceFiles::presetGIF:
			// todo
			break;

		case SourceFiles::presetAVIArchive:
			ui->outputAVI->click();
			ui->outputCodec->setCurrentIndex ( 2 );
      ui->createOutputSubdir->setChecked ( false );
      ui->outputFileSuffix->setText ( "_ulrg" );
			ui->outputAVI->setStyleSheet ( presetOnStyle );
			ui->outputCodec->setStyleSheet ( presetOnStyle );
      ui->createOutputSubdir->setStyleSheet ( presetOnStyle );
      ui->outputFileSuffix->setStyleSheet ( presetOnStyle );
			break;

		default:
			QString err = std::source_location::current().function_name();
			err += " unexpected preset type";

			qDebug() << err;
			break;
	}
}

