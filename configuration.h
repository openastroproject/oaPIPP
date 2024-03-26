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

		static const QString highlightRecovery;
		static const QString highlightSolidWhite;
		static const QString highlightUnclipped;
		static const QString highlightBlend;
		static const QString highlight_H3;
		static const QString highlight_H4;
		static const QString highlight_H5;
		static const QString highlight_H6;
		static const QString highlight_H7;
		static const QString highlight_H8;
		static const QString highlight_H9;

		static const QString dateFromFilename;

		static const QString strictY800Decoding;

		static const QString SERPixelDepth;
		static const QString asHeader;
		static const QString bpp16;
		static const QString bpp15;
		static const QString bpp14;
		static const QString bpp13;
		static const QString bpp12;
		static const QString bpp11;
		static const QString bpp10;
		static const QString bpp9;
		static const QString bpp8;
};
