/*****************************************************************************
 *
 * mainWindow.h -- main application window header
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

#include <QtWidgets>

#include "sourceFiles.h"
#include "inputOptions.h"
#include "processingOptions.h"
#include "qualityOptions.h"
#include "animationOptions.h"
#include "outputOptions.h"
#include "doProcessing.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
		MainWindow ( void );
		~MainWindow();

		void		initialise ( void );
		void		unimplemented ( void );

	private:
		Ui::MainWindow*			ui;
		SourceFiles*				sourceFiles;
		InputOptions*				inputOptions;
		ProcessingOptions*	processingOptions;
		QualityOptions*			qualityOptions;
		AnimationOptions*		animationOptions;
		OutputOptions*			outputOptions;
		DoProcessing*				doProcessing;
};
