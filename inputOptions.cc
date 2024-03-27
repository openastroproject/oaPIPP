/*****************************************************************************
 *
 * inputOptions.cc -- manage the input options tab
 *
 * Copyright 2024
 *    James Fidell (james@openastroproject.org)
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

#include "configuration.h"
#include "inputOptions.h"
#include "ui_inputOptions.h"

InputOptions::InputOptions ( QWidget* parent, Configuration* conf ) :
  QWidget ( parent ),
  ui ( new Ui::InputOptions )
{
  config = conf;

  ui->setupUi ( this );

	ui->debayerRaw->setChecked ( true );
	setDebayerRaw ( 1 );

	ui->highlightRecoveryMethod->setCurrentIndex ( 1 );
  config->setConfig ( Configuration::highlightRecovery,
          Configuration::highlightUnclipped );

	ui->dateFromFilename->setChecked ( false );
	setDateFromFilename ( 0 );

  setUpConnections();

  QString err = std::source_location::current().function_name();
  err += " not fully implemented";

  qDebug() << err;
}


InputOptions::~InputOptions ( void )
{
  delete ui;
}


void
InputOptions::setUpConnections ( void )
{
  connect ( ui->binningSelector,
      QOverload<int>::of ( &QComboBox::currentIndexChanged ), this,
      &InputOptions::setBinMode );
  connect ( ui->binningMethod,
      QOverload<int>::of ( &QComboBox::currentIndexChanged ), this,
      &InputOptions::setBinMethod );

  connect ( ui->rawHotPixelFilter, &QCheckBox::clicked, this,
      &InputOptions::setHotPixelFilter );
  connect ( ui->debayerRaw, &QCheckBox::clicked, this,
      &InputOptions::setDebayerRaw );
  connect ( ui->debayerRawMethod,
      QOverload<int>::of ( &QComboBox::currentIndexChanged ), this,
      &InputOptions::setDebayerMethod );
  connect ( ui->colourSpace,
      QOverload<int>::of ( &QComboBox::currentIndexChanged ), this,
      &InputOptions::setColourSpace );
  connect ( ui->highlightRecoveryMethod,
      QOverload<int>::of ( &QComboBox::currentIndexChanged ), this,
      &InputOptions::setHighlightRecoveryType );

  connect ( ui->dateFromFilename, &QCheckBox::clicked, this,
      &InputOptions::setDateFromFilename );
  connect ( ui->convertToUTC, &QCheckBox::clicked, this,
      &InputOptions::unimplemented1 );
  connect ( ui->filenameFormat, &QComboBox::currentTextChanged, this,
      &InputOptions::unimplemented2 );
  connect ( ui->rememberFormat, &QCheckBox::clicked, this,
      &InputOptions::unimplemented1 );
  connect ( ui->serFrameRate, &QSpinBox::textChanged, this,
      &InputOptions::unimplemented2 );

  connect ( ui->strictY800, &QCheckBox::clicked, this,
      &InputOptions::setStrictY800Decoding );

  connect ( ui->serOptions,
      QOverload<int>::of ( &QComboBox::currentIndexChanged ), this,
      &InputOptions::setSERPixelDepth );

  connect ( ui->whichFrames, &QComboBox::currentTextChanged, this,
      &InputOptions::unimplemented2 );
  connect ( ui->frameStart, &QSpinBox::textChanged, this,
      &InputOptions::unimplemented2 );
  connect ( ui->frameEnd, &QSpinBox::textChanged, this,
      &InputOptions::unimplemented2 );
  connect ( ui->noOfFramesBox, &QSpinBox::textChanged, this,
      &InputOptions::unimplemented2 );
  connect ( ui->whichFrames, &QComboBox::currentTextChanged, this,
      &InputOptions::unimplemented2 );
  connect ( ui->limitFrameRange, &QCheckBox::clicked, this,
      &InputOptions::unimplemented1 );

  connect ( ui->droppedFrames, &QSpinBox::textChanged, this,
      &InputOptions::unimplemented2 );

  connect ( ui->inputColourType, &QComboBox::currentTextChanged, this,
      &InputOptions::unimplemented2 );

  connect ( ui->debayerMono, &QCheckBox::clicked, this,
      &InputOptions::unimplemented1 );
  connect ( ui->protectBayer, &QCheckBox::clicked, this,
      &InputOptions::unimplemented1 );

  connect ( ui->debayerAlgorithm, &QComboBox::currentTextChanged, this,
      &InputOptions::unimplemented2 );
  connect ( ui->bayerPattern, &QComboBox::currentTextChanged, this,
      &InputOptions::unimplemented2 );

}


void
InputOptions::unimplemented1 ( void )
{
  qDebug() << "slot not yet implemented";
}


void
InputOptions::unimplemented2 ( const QString& text )
{
  Q_UNUSED ( text )

  qDebug() << "slot not yet implemented";
}


void
InputOptions::setBinMode ( int index )
{
  switch ( index ) {
    case 0:
      config->setConfig ( Configuration::binning,
          Configuration::BinMode::noBinning );
      break;
    case 1:
      config->setConfig ( Configuration::binning,
          Configuration::BinMode::bin2 );
      break;
    case 2:
      config->setConfig ( Configuration::binning,
          Configuration::BinMode::bin3 );
      break;
    case 3:
      config->setConfig ( Configuration::binning,
          Configuration::BinMode::bin4 );
      break;
    case 4:
      config->setConfig ( Configuration::binning,
          Configuration::BinMode::bin5 );
      break;
    default:
			QString err = std::source_location::current().function_name();
			err += " unrecognised binning mode";
			qDebug() << err;
      break;
  }
}


void
InputOptions::setBinMethod ( int index )
{
  switch ( index ) {
    case 0:
      config->setConfig ( Configuration::binMethod,
          Configuration::binAverage );
      break;
    case 1:
      config->setConfig ( Configuration::binMethod,
          Configuration::binSum );
      break;
    default:
			QString err = std::source_location::current().function_name();
			err += " unrecognised binning method";
			qDebug() << err;
      break;
  }
}


void
InputOptions::setHotPixelFilter ( int enabled )
{
	config->setConfig ( Configuration::rawHotPixelFilter,
			enabled ? Configuration::enabled : Configuration::disabled );
}


void
InputOptions::setDebayerRaw ( int enabled )
{
	config->setConfig ( Configuration::debayerRawFiles,
			enabled ? Configuration::enabled : Configuration::disabled );
	bool state = enabled ? true : false;
	ui->debayerRawMethod->setEnabled ( state );
	ui->algorithmLabel->setEnabled ( state );
	ui->colourSpace->setEnabled ( state );
	ui->colourSpaceLabel->setEnabled ( state );
}


void
InputOptions::setDebayerMethod ( int index )
{
  switch ( index ) {
    case 0:
      config->setConfig ( Configuration::debayerAlgorithm,
          Configuration::debayerBilinear );
      break;
    case 1:
      config->setConfig ( Configuration::debayerAlgorithm,
          Configuration::debayerVNG );
      break;
    case 2:
      config->setConfig ( Configuration::debayerAlgorithm,
          Configuration::debayerPPG );
      break;
    case 3:
      config->setConfig ( Configuration::debayerAlgorithm,
          Configuration::debayerAHD );
      break;
    default:
			QString err = std::source_location::current().function_name();
			err += " unrecognised debayer algorithm";
			qDebug() << err;
      break;
  }
}


void
InputOptions::setColourSpace ( int index )
{
  switch ( index ) {
    case 0:
      config->setConfig ( Configuration::colourSpace,
          Configuration::spaceRawCamera );
      break;
    case 1:
      config->setConfig ( Configuration::colourSpace,
          Configuration::spacesRGB );
      break;
    case 2:
      config->setConfig ( Configuration::colourSpace,
          Configuration::spaceAdobe );
      break;
    case 3:
      config->setConfig ( Configuration::colourSpace,
          Configuration::spaceWideGamut );
      break;
    case 4:
      config->setConfig ( Configuration::colourSpace,
          Configuration::spaceKodak );
      break;
    case 5:
      config->setConfig ( Configuration::colourSpace,
          Configuration::spaceXYZ );
      break;
    case 6:
      config->setConfig ( Configuration::colourSpace,
          Configuration::spaceACES );
      break;
    default:
			QString err = std::source_location::current().function_name();
			err += " unrecognised debayer algorithm";
			qDebug() << err;
      break;
  }
}


void
InputOptions::setHighlightRecoveryType ( int index )
{
  switch ( index ) {
    case 0:
      config->setConfig ( Configuration::highlightRecovery,
          Configuration::highlightSolidWhite );
      break;
    case 1:
      config->setConfig ( Configuration::highlightRecovery,
          Configuration::highlightUnclipped );
      break;
    case 2:
      config->setConfig ( Configuration::highlightRecovery,
          Configuration::highlightBlend );
      break;
    case 3:
      config->setConfig ( Configuration::highlightRecovery,
          Configuration::highlight_H3 );
      break;
    case 4:
      config->setConfig ( Configuration::highlightRecovery,
          Configuration::highlight_H4 );
      break;
    case 5:
      config->setConfig ( Configuration::highlightRecovery,
          Configuration::highlight_H5 );
      break;
    case 6:
      config->setConfig ( Configuration::highlightRecovery,
          Configuration::highlight_H6 );
      break;
    case 7:
      config->setConfig ( Configuration::highlightRecovery,
          Configuration::highlight_H7 );
      break;
    case 8:
      config->setConfig ( Configuration::highlightRecovery,
          Configuration::highlight_H8 );
      break;
    case 9:
      config->setConfig ( Configuration::highlightRecovery,
          Configuration::highlight_H9 );
      break;
    default:
			QString err = std::source_location::current().function_name();
			err += " unrecognised highlight recovery type";
			qDebug() << err;
      break;
  }
}


void
InputOptions::setDateFromFilename ( int enabled )
{
	config->setConfig ( Configuration::dateFromFilename,
			enabled ? Configuration::enabled : Configuration::disabled );
	bool state = enabled ? true : false;
	ui->convertToUTC->setEnabled ( state );
	ui->timeFormatLayout->setEnabled ( state );
	ui->filenameFormat->setEnabled ( state );
	ui->filenameTemplate->setEnabled ( state );
	ui->rememberFormat->setEnabled ( state );
	ui->serFrameRate->setEnabled ( state );
	ui->frameRateLabel->setEnabled ( state );
}


void
InputOptions::setStrictY800Decoding ( int enabled )
{
	config->setConfig ( Configuration::strictY800Decoding,
			enabled ? Configuration::enabled : Configuration::disabled );
}


void
InputOptions::setSERPixelDepth ( int index )
{
  switch ( index ) {
    case 0:
      config->setConfig ( Configuration::SERPixelDepth,
          Configuration::asHeader );
      break;
    case 1:
      config->setConfig ( Configuration::SERPixelDepth,
          Configuration::bpp16 );
      break;
    case 2:
      config->setConfig ( Configuration::SERPixelDepth,
          Configuration::bpp15 );
      break;
    case 3:
      config->setConfig ( Configuration::SERPixelDepth,
          Configuration::bpp14 );
      break;
    case 4:
      config->setConfig ( Configuration::SERPixelDepth,
          Configuration::bpp13 );
      break;
    case 5:
      config->setConfig ( Configuration::SERPixelDepth,
          Configuration::bpp12 );
      break;
    case 6:
      config->setConfig ( Configuration::SERPixelDepth,
          Configuration::bpp11 );
      break;
    case 7:
      config->setConfig ( Configuration::SERPixelDepth,
          Configuration::bpp10 );
      break;
    case 8:
      config->setConfig ( Configuration::SERPixelDepth,
          Configuration::bpp9 );
      break;
    case 9:
      config->setConfig ( Configuration::SERPixelDepth,
          Configuration::bpp8 );
      break;
    default:
			QString err = std::source_location::current().function_name();
			err += " unrecognised pixel depth";
			qDebug() << err;
      break;
  }
}


void
InputOptions::updateDefaults ( int option )
{
  QString err = std::source_location::current().function_name();
  err += " not fully implemented";

  qDebug() << err;
}
