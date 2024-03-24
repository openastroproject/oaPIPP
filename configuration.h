/*****************************************************************************
 *
 * configuration.h -- handle the application's configuration
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

#pragma once

#include <QSettings>


class Configuration
{
  public:
    explicit Configuration ( void );
    virtual ~Configuration();

  public:
    void              initConfig ( void );
    void              loadConfig ( void );
    void              saveConfig ( void );
    void              setConfig ( const QString&, const QVariant& );
    QVariant          getConfig ( const QString& );
    
  private:
    QSettings*        settings;
    bool              settingsLoaded;

  public:
		static const int	disabled = 0;
		static const int	enabled = 1;

    static const QString  sourceMode;
    static const QString  batchMode;
    static const QString  joinMode;

    static const QString  binning;
    enum BinMode {
      noBinning,
      bin2,
      bin3,
      bin4,
      bin5
    };

		static const QString binMethod;
		static const QString binAverage;
		static const QString binSum;

		static const QString rawHotPixelFilter;

		static const QString debayerRawFiles;

		static const QString debayerAlgorithm;
		static const QString debayerBilinear;
		static const QString debayerVNG;
		static const QString debayerPPG;
		static const QString debayerAHD;

		static const QString colourSpace;
		static const QString spaceRawCamera;
		static const QString spacesRGB;
		static const QString spaceAdobe;
		static const QString spaceWideGamut;
		static const QString spaceKodak;
		static const QString spaceXYZ;
		static const QString spaceACES;
};
