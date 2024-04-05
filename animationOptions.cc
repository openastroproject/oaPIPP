/*****************************************************************************
 *
 * animationOptions.cc -- manage the animation options tab
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

#include <QtCore>
#include <QtWidgets>
#include <source_location>

#include "oapipp_common.h"

#include "animationOptions.h"
#include "sourceFiles.h"
#include "ui_animationOptions.h"

AnimationOptions::AnimationOptions ( QWidget* parent ) :
  QWidget ( parent ),
  ui ( new Ui::AnimationOptions )
{
  ui->setupUi ( this );

  setUpConnections();

  QString err = std::source_location::current().function_name();
  err += " not fully implemented";

  qDebug() << err;
}


AnimationOptions::~AnimationOptions ( void )
{
  delete ui;
}


void
AnimationOptions::setUpConnections ( void )
{
  connect ( ui->playForward, &QCheckBox::clicked, this,
      &AnimationOptions::unimplemented1 );
  connect ( ui->pauseFinalForward, &QCheckBox::clicked, this,
      &AnimationOptions::unimplemented1 );
  connect ( ui->forwardPauseFrames, &QSpinBox::textChanged, this,
      &AnimationOptions::unimplemented2 );

  connect ( ui->playReverse, &QCheckBox::clicked, this,
      &AnimationOptions::unimplemented1 );
  connect ( ui->pauseFinalReverse, &QCheckBox::clicked, this,
      &AnimationOptions::unimplemented1 );
  connect ( ui->reversePauseFrames, &QSpinBox::textChanged, this,
      &AnimationOptions::unimplemented2 );

  connect ( ui->repeatFrames, &QCheckBox::clicked, this,
      &AnimationOptions::unimplemented1 );
  connect ( ui->repeatCount, &QSpinBox::textChanged, this,
      &AnimationOptions::unimplemented2 );
  connect ( ui->dontReverseFinal, &QCheckBox::clicked, this,
      &AnimationOptions::unimplemented1 );
}


void
AnimationOptions::unimplemented1 ( void )
{
  qDebug() << "slot not yet implemented";
}


void
AnimationOptions::unimplemented2 ( const QString& text )
{
  Q_UNUSED ( text )

  qDebug() << "slot not yet implemented";
}


void
AnimationOptions::updatePresets ( int option )
{
  // Disable everything that might have been enabled in a previous call
  ui->pauseFinalForward->setChecked ( false );
  ui->repeatFrames->setChecked ( false );

  // Turn all the options back to the default colour
  ui->pauseFinalForward->setStyleSheet ( presetOffStyle );
  ui->forwardPauseFrames->setStyleSheet ( presetOffStyle );
  ui->repeatFrames->setStyleSheet ( presetOffStyle );
  ui->repeatCount->setStyleSheet ( presetOffStyle );

  switch ( option ) {
    case SourceFiles::presetPlanet:
    case SourceFiles::presetCloseUp:
    case SourceFiles::presetISS:
    case SourceFiles::presetFullDisc:
    case SourceFiles::presetAVIArchive:
      // These do nothing
      break;

    case SourceFiles::presetPlanetaryAVI:
      ui->pauseFinalForward->click();
      ui->forwardPauseFrames->setValue ( 20 );
      ui->repeatFrames->click();
      ui->repeatCount->setValue ( 5 );
      ui->pauseFinalForward->setStyleSheet ( presetOnStyle );
      ui->forwardPauseFrames->setStyleSheet ( presetOnStyle );
      ui->repeatFrames->setStyleSheet ( presetOnStyle );
      ui->repeatCount->setStyleSheet ( presetOnStyle );
      break;

    case SourceFiles::presetGIF:
      ui->pauseFinalForward->click();
      ui->forwardPauseFrames->setValue ( 6 );
      ui->pauseFinalForward->setStyleSheet ( presetOnStyle );
      ui->forwardPauseFrames->setStyleSheet ( presetOnStyle );
      break;

    default:
      QString err = std::source_location::current().function_name();
      err += " unexpected preset type";

      qDebug() << err;
      break;
  }
}

