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

#include "ui_pipp.h"
#include "mainWindow.h"

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
}


void
MainWindow::initialise ( void )
{
	// Initialise the various widgets for each tab in the main window
	// Need to do this after calling setupUi and once this object has been
	// instantiated

	sourceFiles = new SourceFiles;
	ui->sourceFilesLayout->addWidget ( sourceFiles );

	inputOptions = new InputOptions;
	ui->outerTabWidget->addTab ( inputOptions, tr ( "Input Options" ));

	processingOptions = new ProcessingOptions;
	ui->outerTabWidget->addTab ( processingOptions, tr ( "Processing Options" ));

	qualityOptions = new QualityOptions;
	ui->outerTabWidget->addTab ( qualityOptions, tr ( "Quality Options" ));

	animationOptions = new AnimationOptions;
	ui->outerTabWidget->addTab ( animationOptions, tr ( "Animation Options" ));

	outputOptions = new OutputOptions;
	outputOptions->initialise();

	doProcessing = new DoProcessing;
	doProcessing->initialise();
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
}


void
MainWindow::unimplemented ( void )
{
	qDebug() << "action unimplemented";
}
