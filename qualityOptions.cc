/*****************************************************************************
 *
 * qualityOptions.cc -- manage the quality options tab
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

#include <QtCore>
#include <QtWidgets>
#include <source_location>

#include "qualityOptions.h"
#include "ui_qualityOptions.h"

QualityOptions::QualityOptions ( QWidget* parent ) :
	QWidget ( parent ),
	ui ( new Ui::QualityOptions )
{
	ui->setupUi ( this );

	setUpConnections();

	QString err = std::source_location::current().function_name();
  err += " not fully implemented";

  qDebug() << err;
}


QualityOptions::~QualityOptions ( void )
{
	delete ui;
}


void
QualityOptions::setUpConnections ( void )
{
  connect ( ui->qualityEstimation, &QCheckBox::clicked, this,
			&QualityOptions::unimplemented1 );
  connect ( ui->reorderByQuality, &QCheckBox::clicked, this,
			&QualityOptions::unimplemented1 );
  connect ( ui->enableQualityLimit, &QCheckBox::clicked, this,
			&QualityOptions::unimplemented1 );
  connect ( ui->keepTypeSelector, &QComboBox::currentTextChanged, this,
			&QualityOptions::unimplemented2 );
  connect ( ui->numberToKeep, &QSpinBox::textChanged, this,
			&QualityOptions::unimplemented2 );

  connect ( ui->pippQuality, &QRadioButton::clicked, this,
			&QualityOptions::unimplemented1 );
  connect ( ui->ninoxQuality, &QRadioButton::clicked, this,
			&QualityOptions::unimplemented1 );
  connect ( ui->peakHistogramQuality, &QRadioButton::clicked, this,
			&QualityOptions::unimplemented1 );
  connect ( ui->brightnessQuality, &QRadioButton::clicked, this,
			&QualityOptions::unimplemented1 );

  connect ( ui->minSubsample, &QSpinBox::textChanged, this,
			&QualityOptions::unimplemented2 );
  connect ( ui->maxSubsample, &QSpinBox::textChanged, this,
			&QualityOptions::unimplemented2 );
  connect ( ui->subsampleIncrement, &QSpinBox::textChanged, this,
			&QualityOptions::unimplemented2 );

  connect ( ui->qualityWeighting, &QCheckBox::clicked, this,
			&QualityOptions::unimplemented1 );
}


void
QualityOptions::unimplemented1 ( void )
{
	qDebug() << "slot not yet implemented";
}


void
QualityOptions::unimplemented2 ( const QString& text )
{
	Q_UNUSED ( text )

	qDebug() << "slot not yet implemented";
}
