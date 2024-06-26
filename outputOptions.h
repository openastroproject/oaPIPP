/*****************************************************************************
 *
 * outputOptions.h -- header for outputOptions.cc
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

#include <QWidget>

namespace Ui {
  class OutputOptions;
}

class OutputOptions : public QWidget
{
  Q_OBJECT

  public:
    explicit OutputOptions ( QWidget* parent = nullptr );
    virtual ~OutputOptions();

  private:
    void                  setUpConnections ( void );

  private:
    Ui::OutputOptions*    ui;

  private slots:
    void                unimplemented1 ( void );
    void                unimplemented2 ( const QString& text );

  public:
    void                updatePresets ( int );
};
