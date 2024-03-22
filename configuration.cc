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
	QVariant	val;

	QString err = std::source_location::current().function_name();
  err += " not fully implemented";

  qDebug() << err;

	return val;
}
