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

namespace Ui {
	class SourceFiles;
}

class SourceFiles : public QTabWidget
{
	Q_OBJECT

  public:
    explicit SourceFiles ( QWidget* parent = nullptr );
    virtual ~SourceFiles();

	private:
		void							setUpConnections ( void );
		void							setUpTables ( void );
		void							loadImageFiles ( void );
		void							loadDarkFiles ( void );
		void							loadFlatFiles ( void );
		void							loadFlatDarkFiles ( void );
		void							loadFiles ( const QString&, QTableWidget*, int& ); 
		void							removeImageFiles ( void );
		void							removeDarkFiles ( void );
		void							removeFlatFiles ( void );
		void							removeFlatDarkFiles ( void );
		void							removeFiles ( QTableWidget*, int& ); 
		void							removeAllImageFiles ( void );
		void							removeAllDarkFiles ( void );
		void							removeAllFlatFiles ( void );
		void							removeAllFlatDarkFiles ( void );
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

	private slots:
		void							unimplemented1 ( void );
		void							unimplemented2 ( const QString& text );
};
