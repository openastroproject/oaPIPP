/*****************************************************************************
 *
 * mainWindow.cc -- mainWindow code
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

#include <QtWidgets>

#include <source_location>

#include "ui_pipp.h"
#include "mainWindow.h"
#include "sourceFiles.h"
#include "configuration.h"

static const char* styleGroupBoxBorders =
  "QGroupBox { "
    "margin-top: 1ex;"
    "border: 2px groove grey;"
//  "border-radius: 5px;"
  "} "
  "QGroupBox::title { "
    "subcontrol-origin: margin;"
    "subcontrol-position: left top;"
    "left: 1em;"
  "}";

MainWindow::MainWindow ( void ) :
  ui ( new Ui::MainWindow )
{
	ui->setupUi ( this );

	setWindowTitle ( APPLICATION_NAME + " " + VERSION_STR );

  // The gtk+ style doesn't enable group box borders by default, which makes
  // the display look confusing.
  //
  // Same thing with Qt5, so work out the version and add them if required

	bool ok;
	int i;
	unsigned int qtMajorVersion;

  QString qtVer = qVersion();
  if (( i = qtVer.indexOf ( '.' )) >= 0 ) {
    qtVer.truncate ( i );
  }
  qtMajorVersion = qtVer.toInt( &ok );

	QString currentStyle = QApplication::style()->objectName();
  if ( currentStyle.toLower() == "gtk+" || ( ok && qtMajorVersion > 4 )) {
    this->setStyleSheet ( styleGroupBoxBorders );
  }

	config = new Configuration;
}


void
MainWindow::initialise ( void )
{
	config->initConfig();
	config->loadConfig();

	// Initialise the various widgets for each tab in the main window
	// Need to do this after calling setupUi and once this object has been
	// instantiated

	sourceFiles = new SourceFiles ( this, config );
	ui->sourceFilesLayout->addWidget ( sourceFiles );

	inputOptions = new InputOptions ( this, config );
	ui->outerTabWidget->addTab ( inputOptions, tr ( "Input Options" ));

	processingOptions = new ProcessingOptions;
	ui->outerTabWidget->addTab ( processingOptions, tr ( "Processing Options" ));

	qualityOptions = new QualityOptions;
	ui->outerTabWidget->addTab ( qualityOptions, tr ( "Quality Options" ));

	animationOptions = new AnimationOptions;
	ui->outerTabWidget->addTab ( animationOptions, tr ( "Animation Options" ));

	outputOptions = new OutputOptions;
	ui->outerTabWidget->addTab ( outputOptions, tr ( "Output Options" ));

	doProcessing = new DoProcessing;
	ui->outerTabWidget->addTab ( doProcessing, tr ( "Do Processing" ));

	// Set up slots for the various menu actions

	connect ( ui->actionAddSourceFiles, &QAction::triggered, sourceFiles,
			&SourceFiles::loadImageFiles );
	connect ( ui->actionRemoveAllFiles, &QAction::triggered, sourceFiles,
			&SourceFiles::unloadAllFiles );
	connect ( ui->actionQuit, &QAction::triggered, this,
			&MainWindow::quit );

	connect ( ui->actionResetOptions, &QAction::triggered, this,
			&MainWindow::unimplemented );
	connect ( ui->actionUndoResetOptions, &QAction::triggered, this,
			&MainWindow::unimplemented );
	connect ( ui->actionSaveOptions, &QAction::triggered, this,
			&MainWindow::unimplemented );
	connect ( ui->actionLoadOptions, &QAction::triggered, this,
			&MainWindow::unimplemented );
	connect ( ui->actionSaveRejectedFrames, &QAction::triggered, this,
			&MainWindow::unimplemented );
	connect ( ui->actionUseRAMBuffers, &QAction::triggered, this,
			&MainWindow::unimplemented );

	connect ( ui->actionTestOptions, &QAction::triggered, this,
			&MainWindow::unimplemented );
	connect ( ui->actionStartProcessing, &QAction::triggered, this,
			&MainWindow::unimplemented );
	connect ( ui->actionCancelProcessing, &QAction::triggered, this,
			&MainWindow::unimplemented );

	connect ( ui->actionAbout, &QAction::triggered, this,
			&MainWindow::about );

	// This one is for handling the buttons in the source files tab to set
	// the preset options for a particular image type

	connect ( sourceFiles, &SourceFiles::setPresetOptions, this,
			&MainWindow::updatePresetOptions );
}


MainWindow::~MainWindow ( void )
{
	delete doProcessing;
	delete outputOptions;
	delete animationOptions;
	delete qualityOptions;
	delete processingOptions;
	delete inputOptions;
	delete sourceFiles;
	delete ui;

	delete config;
}


void
MainWindow::quit ( void )
{
	qDebug() << "Write settings on exit?";
	qApp->quit();
}


void
MainWindow::about ( void )
{
	QMessageBox about;
	QString aboutText = tr ( "Planetary Imaging Preprocessor\n"
		"Copyright Open Astro Project\n\n"
		"Open source release based on PIPP v2.5.9\n"
		"Copyright 2012-2017 Chris Garry\n" );

  about.setText ( APPLICATION_NAME + " " + VERSION_STR );
  about.setInformativeText ( aboutText );
	// about.setIconPixmap ( ":/icons/pipp.png" );
  about.exec();
}


void
MainWindow::unimplemented ( void )
{
	qDebug() << "action unimplemented";
}


void
MainWindow::updatePresetOptions ( int option )
{
	inputOptions->updatePresets ( option );
	processingOptions->updatePresets ( option );
	qualityOptions->updatePresets ( option );
	animationOptions->updatePresets ( option );
	outputOptions->updatePresets ( option );
}
