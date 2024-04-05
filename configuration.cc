/*****************************************************************************
 *
 * sourceFiles.cc -- manage the source files tab
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

#include "oapipp_common.h"

#include <QtCore>

#include <source_location>
#include <filesystem>
namespace fs = std::filesystem;

#include "configuration.h"

const QString Configuration::sourceMode = "sourceMode";
const QString Configuration::batchMode = "batch";
const QString Configuration::joinMode = "join";

const QString Configuration::binning = "binning";

const QString Configuration::binMethod = "binMethod";
const QString Configuration::binAverage = "average";
const QString Configuration::binSum = "sum";

const QString Configuration::rawHotPixelFilter = "rawHotPixelFilter";

const QString Configuration::debayerRawFiles = "debayerRawFiles";

const QString Configuration::debayerAlgorithm = "debayerAlgorithm";
const QString Configuration::debayerBilinear = "bilinear";
const QString Configuration::debayerVNG = "VNG";
const QString Configuration::debayerPPG = "PPG";
const QString Configuration::debayerAHD = "AHD";

const QString Configuration::colourSpace = "colourSpace";
const QString Configuration::spaceRawCamera = "raw camera";
const QString Configuration::spacesRGB = "sRGB";
const QString Configuration::spaceAdobe = "adobe";
const QString Configuration::spaceWideGamut = "wide gamut";
const QString Configuration::spaceKodak = "kodak";
const QString Configuration::spaceXYZ = "XYZ";
const QString Configuration::spaceACES = "ACES";

const QString Configuration::highlightRecovery = "highlightRecovery";
const QString Configuration::highlightSolidWhite = "white";
const QString Configuration::highlightUnclipped = "unclipped";
const QString Configuration::highlightBlend = "blend";
const QString Configuration::highlight_H3 = "-H=3";
const QString Configuration::highlight_H4 = "-H=4";
const QString Configuration::highlight_H5 = "-H=5";
const QString Configuration::highlight_H6 = "-H=6";
const QString Configuration::highlight_H7 = "-H=7";
const QString Configuration::highlight_H8 = "-H=8";
const QString Configuration::highlight_H9 = "-H=9";

const QString Configuration::dateFromFilename = "extractDateFromFilename";

const QString Configuration::strictY800Decoding = "strictY800Decoding";

const QString Configuration::SERPixelDepth = "SERPixelDepth";
const QString Configuration::asHeader = "asHeader";
const QString Configuration::bpp16 = "16bpp";
const QString Configuration::bpp15 = "15bpp";
const QString Configuration::bpp14 = "14bpp";
const QString Configuration::bpp13 = "13bpp";
const QString Configuration::bpp12 = "12bpp";
const QString Configuration::bpp11 = "11bpp";
const QString Configuration::bpp10 = "10bpp";
const QString Configuration::bpp9 = "9bpp";
const QString Configuration::bpp8 = "8bpp";


Configuration::Configuration ( void )
{
  settingsLoaded = false;
}


Configuration::~Configuration()
{
  if ( settingsLoaded ) {
    delete settings;
  }
}


void
Configuration::initConfig ( void )
{
  QString err = std::source_location::current().function_name();
  err += " not fully implemented";

  qDebug() << err;
}


void
Configuration::loadConfig ( void )
{
  settings = new QSettings ( ORGANISATION_NAME_SETTINGS, APPLICATION_NAME );
  settingsLoaded = true;
}


void
Configuration::saveConfig ( void )
{
  QString err = std::source_location::current().function_name();
  err += " not fully implemented";

  qDebug() << err;
}


void
Configuration::setConfig ( const QString&, const QVariant& )
{
  QString err = std::source_location::current().function_name();
  err += " not fully implemented";

  qDebug() << err;
}


QVariant
Configuration::getConfig ( const QString& )
{
  QVariant  val;

  QString err = std::source_location::current().function_name();
  err += " not fully implemented";

  qDebug() << err;

  return val;
}
