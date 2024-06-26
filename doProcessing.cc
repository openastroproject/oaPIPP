/*****************************************************************************
 *
 * doProcessing.cc -- manage the processing options tab
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
#include <source_location>

#include "doProcessing.h"
#include "ui_doProcessing.h"

DoProcessing::DoProcessing ( QWidget* parent  ) :
  QWidget ( parent ),
  ui ( new Ui::DoProcessing )
{
  ui->setupUi ( this );

  setUpConnections();

  QString err = std::source_location::current().function_name();
  err += " not fully implemented";

  qDebug() << err;
}


DoProcessing::~DoProcessing ( void )
{
  delete ui;
}


void
DoProcessing::setUpConnections ( void )
{
  connect ( ui->startProcessing, &QPushButton::clicked, this,
      &DoProcessing::unimplemented1 );
  connect ( ui->cancelProcessing, &QPushButton::clicked, this,
      &DoProcessing::unimplemented1 );
  connect ( ui->openOutputDir, &QPushButton::clicked, this,
      &DoProcessing::unimplemented1 );
}


void
DoProcessing::unimplemented1 ( void )
{
  qDebug() << "slot not yet implemented";
}


void
DoProcessing::unimplemented2 ( const QString& text )
{
  Q_UNUSED ( text )

  qDebug() << "slot not yet implemented";
}
