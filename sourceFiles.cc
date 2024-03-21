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
#include <QtWidgets>
#include <source_location>
#include <filesystem>
#include <algorithm>
#include <chrono>
#include <cmath>
// Supposed to be in C++20, but not for GNU CC :(
#ifndef __cpp_lib_format
// std::format polyfill using fmtlib
#include <fmt/core.h>
namespace std {
  using fmt::format;
}
extern "C" {
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
}
#else
  #include <format>
#endif


#include "configuration.h"
#include "sourceFiles.h"
#include "ui_sourceFiles.h"

namespace fs = std::filesystem;
using namespace std::chrono_literals;
using file_time_type = std::chrono::time_point<std::chrono::file_clock>;

SourceFiles::SourceFiles ( QWidget* parent, Configuration* conf ) :
	QTabWidget ( parent ),
	ui ( new Ui::SourceFiles )
{
	config = conf;

	ui->setupUi ( this );

	numLights = numDarks = numFlats = numFlatDarks = 0;

	updateImagesLabel();
	updateDarksLabel();
	updateFlatsLabel();
	updateFlatDarksLabel();

	ui->removeImagesButton->setEnabled ( false );
	ui->removeAllImagesButton->setEnabled ( false );
	ui->removeDarksButton->setEnabled ( false );
	ui->removeAllDarksButton->setEnabled ( false );
	ui->removeFlatsButton->setEnabled ( false );
	ui->removeAllFlatsButton->setEnabled ( false );
	ui->removeFlatDarksButton->setEnabled ( false );
	ui->removeAllFlatDarksButton->setEnabled ( false );

	ui->enableDarkFrameSubtraction->setEnabled ( false );
	ui->enableFlatFrameCorrection->setEnabled ( false );
	ui->enableFlatDarkFrameSubtraction->setEnabled ( false );

	ui->imagesUpButton->setEnabled ( false );
	ui->imagesDownButton->setEnabled ( false );

	setUpTables();
	setUpConnections();

	QString err = std::source_location::current().function_name();
  err += " not fully implemented";

  qDebug() << err;
}


SourceFiles::~SourceFiles ( void )
{
	delete ui;
}


void
SourceFiles::updateImagesLabel ( void )
{
	QString label = QObject::tr ( "Image Files (%1 frames)" );
	setTabText ( 0, label.arg ( numLights ));
}


void
SourceFiles::updateDarksLabel ( void )
{
	QString label = QObject::tr ( "Dark Files (%1 frames)" );
	setTabText ( 1, label.arg ( numDarks ));
}


void
SourceFiles::updateFlatsLabel ( void )
{
	QString label = QObject::tr ( "Flat Files (%1 frames)" );
	setTabText ( 2, label.arg ( numFlats ));
}


void
SourceFiles::updateFlatDarksLabel ( void )
{
	QString label = QObject::tr ( "Flat Dark Files (%1 frames)" );
	setTabText ( 3, label.arg ( numFlatDarks ));
}


void
SourceFiles::setUpConnections ( void )
{
  connect ( ui->addImagesButton, &QPushButton::clicked, this,
			&SourceFiles::loadImageFiles );
  connect ( ui->removeImagesButton, &QPushButton::clicked, this,
			&SourceFiles::removeImageFiles );
  connect ( ui->removeAllImagesButton, &QPushButton::clicked, this,
			&SourceFiles::removeAllImageFiles );

  connect ( ui->imagesUpButton, &QPushButton::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->imagesDownButton, &QPushButton::clicked, this,
			&SourceFiles::unimplemented1 );

  connect ( ui->batchMode, &QRadioButton::clicked, this,
			&SourceFiles::setBatchMode );
  connect ( ui->joinMode, &QRadioButton::clicked, this,
			&SourceFiles::setJoinMode );

  connect ( ui->closeUpButton, &QRadioButton::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->aviButton, &QRadioButton::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->fullDiscButton, &QRadioButton::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->gifButton, &QRadioButton::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->planetaryButton, &QRadioButton::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->issButton, &QRadioButton::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->archiveButton, &QRadioButton::clicked, this,
			&SourceFiles::unimplemented1 );

  connect ( ui->addDarksButton, &QPushButton::clicked, this,
			&SourceFiles::loadDarkFiles );
  connect ( ui->removeDarksButton, &QPushButton::clicked, this,
			&SourceFiles::removeDarkFiles );
  connect ( ui->removeAllDarksButton, &QPushButton::clicked, this,
			&SourceFiles::removeAllDarkFiles );

  connect ( ui->enableDarkFrameSubtraction, &QCheckBox::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->saveMasterDark, &QCheckBox::clicked, this,
			&SourceFiles::unimplemented1 );

  connect ( ui->thresholdVal, &QSpinBox::textChanged, this,
			&SourceFiles::unimplemented2 );
  connect ( ui->enableHotPixel, &QCheckBox::clicked, this,
			&SourceFiles::unimplemented1 );

  connect ( ui->addFlatsButton, &QPushButton::clicked, this,
			&SourceFiles::loadFlatFiles );
  connect ( ui->removeFlatsButton, &QPushButton::clicked, this,
			&SourceFiles::removeFlatFiles );
  connect ( ui->removeAllFlatsButton, &QPushButton::clicked, this,
			&SourceFiles::removeAllFlatFiles );

  connect ( ui->enableFlatFrameCorrection, &QCheckBox::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->flatsMonoWithBayer, &QCheckBox::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->saveMasterFlat, &QCheckBox::clicked, this,
			&SourceFiles::unimplemented1 );

  connect ( ui->addFlatDarksButton, &QPushButton::clicked, this,
			&SourceFiles::loadFlatDarkFiles );
  connect ( ui->removeFlatDarksButton, &QPushButton::clicked, this,
			&SourceFiles::removeFlatDarkFiles );
  connect ( ui->removeAllFlatDarksButton, &QPushButton::clicked, this,
			&SourceFiles::removeAllFlatDarkFiles );

  connect ( ui->enableFlatDarkFrameSubtraction, &QCheckBox::clicked, this,
			&SourceFiles::unimplemented1 );
  connect ( ui->saveMasterFlatDark, &QCheckBox::clicked, this,
			&SourceFiles::unimplemented1 );

	qDebug() << "Need to add connector for moving images up/down";
}


void
SourceFiles::unimplemented1 ( void )
{
	qDebug() << "slot not yet implemented";
}


void
SourceFiles::unimplemented2 ( const QString& text )
{
	Q_UNUSED ( text )

	qDebug() << "slot not yet implemented";
}


void
SourceFiles::loadImageFiles ( void )
{
	QString title = tr ( "Select image files" );

	bool single = loadFiles ( title, ui->imageFileList, numLights );
	updateImagesLabel();

	if ( numLights ) {
		ui->removeImagesButton->setEnabled ( true );
		ui->removeAllImagesButton->setEnabled ( true );
	}

	if ( single ) {
		ui->joinMode->click();
		QMessageBox::information ( this, APPLICATION_NAME,
				tr ( "Selecting join mode because one or "
				"more source files are individual image files" ));
	}

	ui->imagesUpButton->setEnabled ( true );
	ui->imagesDownButton->setEnabled ( true );
}


void
SourceFiles::loadDarkFiles ( void )
{
	QString title = tr ( "Select dark files" );

	std::ignore = loadFiles ( title, ui->darksFileList, numDarks );
	updateDarksLabel();

	if ( numDarks ) {
		ui->removeDarksButton->setEnabled ( true );
		ui->removeAllDarksButton->setEnabled ( true );
		ui->enableDarkFrameSubtraction->setEnabled ( true );
		qDebug() << "check darks subtraction bubbles down";
	}
}


void
SourceFiles::loadFlatFiles ( void )
{
	QString title = tr ( "Select flat files" );

	std::ignore = loadFiles ( title, ui->flatsFileList, numFlats );
	updateFlatsLabel();

	if ( numFlats ) {
		ui->removeFlatsButton->setEnabled ( true );
		ui->removeAllFlatsButton->setEnabled ( true );
		ui->enableFlatFrameCorrection->setEnabled ( true );
		qDebug() << "check flat frame correction bubbles down";
	}

}


void
SourceFiles::loadFlatDarkFiles ( void )
{
	QString title = tr ( "Select flat dark files" );

	std::ignore = loadFiles ( title, ui->flatDarksFileList, numFlatDarks );
	updateFlatDarksLabel();

	if ( numFlatDarks ) {
		ui->removeFlatDarksButton->setEnabled ( true );
		ui->removeAllFlatDarksButton->setEnabled ( true );
		ui->enableFlatDarkFrameSubtraction->setEnabled ( true );
		qDebug() << "check flat dark subtraction bubbles down";
	}
}


bool
SourceFiles::loadFiles ( const QString& title, QTableWidget* table,
		int& fileCount )
{
	QString filters = tr (
		"All supported types (*.png *.jpg *.tiff *.tif *.avi *.ser *.CR2 *.CR3);;"
		"Video files (*.avi);;"
		"LuCam Recorder SER (*.ser);;"
		"Image files (*.png *.jpg *.tiff *.tif);;"
		"Raw image files (*.CR2 *.CR3)");

	QStringList singleImageExtns = { "png", "jpg", "tif", "cr2", "cr3" };
	QFileDialog dialog ( this, title, "", filters );
	bool				haveSingleFrameFile = false;

	dialog.setFileMode ( QFileDialog::ExistingFiles );
	dialog.setViewMode ( QFileDialog::Detail );
	dialog.setAcceptMode ( QFileDialog::AcceptOpen );
	if ( dialog.exec()) {
		QStringList filenames = dialog.selectedFiles();
		for ( auto &file : filenames ) {

			// this is a bit messy

			fs::path p = file.toStdString();
			fs::path parent = p.root_name() / p.parent_path();
			fs::path f = p.filename();
			QString dir = QString::fromStdString ( parent.string());
			QString fname = QString::fromStdString ( f.string());
			// possibly iffy calling toLower() here, but it _is_ an extension
			QString extn = QString::fromStdString ( f.extension().string()).
				remove ( 0, 1 ).toLower();

			// now we have:
			// fname: just the filename
			// dir: full path of the directory containing the file
			// extn: file name extension

			int tableRows = table->rowCount();
			if ( tableRows == fileCount ) {
				table->insertRow ( tableRows );
			}
			QTableWidgetItem* newItem;
			newItem = new QTableWidgetItem ( fname );
			// FIX ME -- might be neater to do this with an enum value for column
			table->setItem ( fileCount, 0, newItem );

			int numFrames = 1;  // default value
			QString type = extn;
			QString fps = "-";
			QString frameSize = "-";
			if ( singleImageExtns.contains ( extn )) {
				haveSingleFrameFile = true;
				qDebug() << "calculate frame size for file";
			} else {
				qDebug() << "calculate frame count, video codec etc. for file";
				numFrames = -1;
			}
			newItem = new QTableWidgetItem ( type );
			newItem->setTextAlignment ( Qt::AlignCenter );
			table->setItem ( fileCount, 1, newItem );
			newItem = new QTableWidgetItem ( QString ( "%1" ).arg ( numFrames ));
			newItem->setTextAlignment ( Qt::AlignRight );
			table->setItem ( fileCount, 2, newItem );
			newItem = new QTableWidgetItem ( fps );
			newItem->setTextAlignment ( Qt::AlignRight );
			table->setItem ( fileCount, 3, newItem );
			newItem = new QTableWidgetItem ( frameSize );
			newItem->setTextAlignment ( Qt::AlignRight );
			table->setItem ( fileCount, 4, newItem );


			// FIX ME -- should check error codes in case the file is missing

#ifdef __cpp_lib_format
			fs::file_time_type ftime = fs::last_write_time ( p );
			newItem = new QTableWidgetItem ( QString::fromStdString (
						std::format ( "%F %R", ftime )));
#else
			// An ugly workaround for the code above if we don't have std::format
			// Really needs some error checking.

			struct stat buf;
			struct tm* ti;
			char filedate_c[64];

			stat ( p.c_str(), &buf );
			ti = localtime ( &buf.st_mtime );
			strftime ( filedate_c, 63, "%F %R", ti );
			QString filedate = filedate_c;
			newItem = new QTableWidgetItem ( filedate );
#endif
			table->setItem ( fileCount, 5, newItem );

			newItem = new QTableWidgetItem ( humanReadable ( fs::file_size ( p )));
			newItem->setTextAlignment ( Qt::AlignRight );
			table->setItem ( fileCount, 6, newItem );

			newItem = new QTableWidgetItem ( dir );
			table->setItem ( fileCount, 7, newItem );

			fileCount++;
		}
	}

	return haveSingleFrameFile;
}


void
SourceFiles::setUpTables ( void )
{
	const QStringList headers = {
		tr ( "Filename" ),
		tr ( "Type" ),
		tr ( "Frames" ),
		tr ( "FPS" ),
		tr ( "Frame size" ),
		tr ( "Date" ),
		tr ( "Filesize" ),
		tr ( "Directory" )
	};

	QList<QTableWidget*> tables = { ui->imageFileList, ui->darksFileList,
		ui->flatsFileList, ui->flatDarksFileList };

	for ( auto table : tables ) {
		table->setColumnCount ( 8 );
    table->setRowCount( 0 );
		table->setHorizontalHeaderLabels ( headers );
		table->verticalHeader()->setVisible ( false );
		table->setSelectionMode ( QTableWidget::ExtendedSelection );
		table->setSelectionBehavior ( QTableWidget::SelectRows );
		table->setAlternatingRowColors ( true );
	}
}


QString
SourceFiles::humanReadable ( std::uintmax_t bytes )
{
	int idx = 0;
	double mantissa = bytes;
	QString ret;

	for ( ; mantissa >= 1024. ; mantissa /= 1024. , idx++ );
	ret = QString ( "%1%2B" ).arg ( std::ceil ( mantissa * 100. ) / 100. ).arg
			( "BKMGTPE"[idx] );
	return ret;
}


void
SourceFiles::removeAllImageFiles ( void )
{
	removeAllFiles ( ui->imageFileList, numLights );
	updateImagesLabel();

	ui->removeImagesButton->setEnabled ( false );
	ui->removeAllImagesButton->setEnabled ( false );
	ui->imagesUpButton->setEnabled ( false );
	ui->imagesDownButton->setEnabled ( false );
}


void
SourceFiles::removeAllDarkFiles ( void )
{
	removeAllFiles ( ui->darksFileList, numDarks );
	updateDarksLabel();

	ui->removeDarksButton->setEnabled ( false );
	ui->removeAllDarksButton->setEnabled ( false );
	ui->enableDarkFrameSubtraction->setEnabled ( false );
  qDebug() << "check darks subtraction bubbles down";
}


void
SourceFiles::removeAllFlatFiles ( void )
{
	removeAllFiles ( ui->flatsFileList, numFlats );
	updateFlatsLabel();

	ui->removeFlatsButton->setEnabled ( false );
	ui->removeAllFlatsButton->setEnabled ( false );
	ui->enableFlatFrameCorrection->setEnabled ( false );
	qDebug() << "disable flat frame correction";
}


void
SourceFiles::removeAllFlatDarkFiles ( void )
{
	removeAllFiles ( ui->flatDarksFileList, numFlatDarks );
	updateFlatDarksLabel();

	ui->removeFlatDarksButton->setEnabled ( false );
	ui->removeAllFlatDarksButton->setEnabled ( false );
	ui->enableFlatDarkFrameSubtraction->setEnabled ( false );
	qDebug() << "Disable flat dark frame subtraction";
}


void
SourceFiles::removeAllFiles ( QTableWidget* table, int& fileCount )
{
	fileCount = 0;
	table->clearContents();
	table->setRowCount ( 0 );
}


void
SourceFiles::removeImageFiles ( void )
{
	removeFiles ( ui->imageFileList, numLights );
	updateImagesLabel();

	if ( !numLights ) {
		ui->removeImagesButton->setEnabled ( false );
		ui->removeImagesButton->setEnabled ( false );
	}
}


void
SourceFiles::removeDarkFiles ( void )
{
	removeFiles ( ui->darksFileList, numDarks );
	updateDarksLabel();

	if ( !numDarks ) {
		ui->removeDarksButton->setEnabled ( false );
		ui->removeDarksButton->setEnabled ( false );
		ui->enableDarkFrameSubtraction->setEnabled ( false );
		qDebug() << "disable darks subtraction option";
	}
}


void
SourceFiles::removeFlatFiles ( void )
{
	removeFiles ( ui->flatsFileList, numFlats );
	updateFlatsLabel();

	if ( !numFlats ) {
		ui->removeFlatsButton->setEnabled ( false );
		ui->removeFlatsButton->setEnabled ( false );
		ui->enableFlatFrameCorrection->setEnabled ( false );
		qDebug() << "disable flat frame correction";
	}
}


void
SourceFiles::removeFlatDarkFiles ( void )
{
	removeFiles ( ui->flatDarksFileList, numFlatDarks );
	updateFlatDarksLabel();

	if ( !numFlatDarks ) {
		ui->removeFlatDarksButton->setEnabled ( false );
		ui->removeFlatDarksButton->setEnabled ( false );
		ui->enableFlatDarkFrameSubtraction->setEnabled ( false );
		qDebug() << "Disable flat dark frame subtraction";
	}
}


void
SourceFiles::removeFiles ( QTableWidget* table, int& fileCount )
{
	QList<QTableWidgetSelectionRange> ranges = table->selectedRanges();

	// deal with everything backwards, so the row numbers don't change
	// as we remove rows
	std::reverse ( ranges.begin(), ranges.end());
	for ( auto range : ranges ) {
		int last = range.bottomRow();
		int first = range.topRow();
		for ( int i = last; i >= first; i-- ) {
			table->removeRow ( i );
			fileCount--;
		}
	}
}


void
SourceFiles::unloadAllFiles ( void )
{
	removeAllImageFiles();
	removeAllDarkFiles();
	removeAllFlatFiles();
	removeAllFlatDarkFiles();
}


void
SourceFiles::setBatchMode ( void )
{
	config->setConfig ( Configuration::sourceMode, Configuration::batchMode );
}


void
SourceFiles::setJoinMode ( void )
{
	config->setConfig ( Configuration::sourceMode, Configuration::joinMode );
}
