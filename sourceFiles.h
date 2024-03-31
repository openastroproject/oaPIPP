/*****************************************************************************
 *
 * sourceFiles.h -- header for sourceFiles.cc
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

#pragma once

#include <QTabWidget>

#include "configuration.h"


namespace Ui {
	class SourceFiles;
}

class SourceFiles : public QTabWidget
{
	Q_OBJECT

  public:
    explicit SourceFiles ( QWidget* parent, Configuration* conf );
    virtual ~SourceFiles();

	private:
		void							setUpConnections ( void );
		void							setUpTables ( void );
		bool							loadFiles ( const QString&, QTableWidget*, int& ); 
		void							removeFiles ( QTableWidget*, int& ); 
		void							removeAllFiles ( QTableWidget*, int& ); 
		void							updateImagesLabel ( void );
		void							updateDarksLabel ( void );
		void							updateFlatsLabel ( void );
		void							updateFlatDarksLabel ( void );
		QString						humanReadable ( std::uintmax_t );

		Ui::SourceFiles*	ui;
	  int								numLights;
		int								numDarks;
		int								numFlats;
		int								numFlatDarks;
		Configuration*		config;

	public slots:
		void							loadImageFiles ( void );
		void							removeImageFiles ( void );
		void							unloadAllFiles ( void );

	private slots:
		void							unimplemented1 ( void );
		void							unimplemented2 ( const QString& text );
		void							loadDarkFiles ( void );
		void							loadFlatFiles ( void );
		void							loadFlatDarkFiles ( void );
		void							removeDarkFiles ( void );
		void							removeFlatFiles ( void );
		void							removeFlatDarkFiles ( void );
		void							removeAllImageFiles ( void );
		void							removeAllDarkFiles ( void );
		void							removeAllFlatFiles ( void );
		void							removeAllFlatDarkFiles ( void );

		void							setBatchMode ( void );
		void							setJoinMode ( void );
		void							setCloseUpOptions ( int );
		void							setPlanetaryAVIOptions ( int );
		void							setFullDiscOptions ( int );
		void							setGifOptions ( int );
		void							setPlanetaryOptions ( int );
		void							setISSOptions ( int );
		void							setAVIArchiveOptions ( int );

	public:
		static const int	presetPlanet = 1;
		static const int	presetCloseUp = 2;
		static const int	presetPlanetaryAVI = 3;
		static const int	presetISS = 4;
		static const int	presetFullDisc = 5;
		static const int	presetGIF = 6;
		static const int	presetAVIArchive = 7;

	signals:
		void							setPresetOptions ( int );
};
