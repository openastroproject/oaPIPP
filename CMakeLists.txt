#[[
  
   CMakeLists.txt -- top level

   Copyright 2024
  		James Fidell (james@openastroproject.org)
  
   License:
  
   This file is part of the Open Astro Project.
  
   The Open Astro Project is free software: you can redistribute it and/or
   modify it under the terms of the GNU General Public License as published
   by the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
  
   The Open Astro Project is distributed in the hope that it will be
   useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
  
   You should have received a copy of the GNU General Public License
   along with the Open Astro Project.  If not, see
   <http://www.gnu.org/licenses/>.
  
]]

cmake_minimum_required(VERSION 3.10)
project ( oapipp VERSION 0.0.1 )

set ( CMAKE_CXX_STANDARD 20 )

include ( FindPkgConfig )

if ( PKG_CONFIG_FOUND )
  pkg_search_module ( LIBTIFF4 libtiff-4 )
  pkg_search_module ( LIBRAW libraw )
  pkg_search_module ( LIBCFITSIO cfitsio )
else()
  message ( FATAL_ERROR "pkg-config not found" )
endif()

if ( NOT LIBTIFF4_FOUND )
  message ( FATAL_ERROR "libtiff required for build" )
endif()
if ( NOT LIBRAW_FOUND )
  message ( FATAL_ERROR "libraw required for build" )
endif()
if ( NOT LIBCFITSIO_FOUND )
  message ( FATAL_ERROR "libcfitsio required for build" )
endif()

set( top ${CMAKE_SOURCE_DIR} )
set( cwd ${CMAKE_CURRENT_SOURCE_DIR} )

find_package(Qt5 REQUIRED COMPONENTS
		Core
		Widgets
		Gui
		LinguistTools
		Help
)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${cwd}/ui)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable ( oapipp
	oapipp.cc
	mainWindow.cc
  animationOptions.cc
  doProcessing.cc
  inputOptions.cc
  outputOptions.cc
  processingOptions.cc
  qualityOptions.cc
  sourceFiles.cc
)

target_include_directories ( oapipp
		PRIVATE
		${Qt5Gui_INCLUDE_DIRS}
		${Qt5Widgets_INCLUDE_DIRS}
		${Qt5Core_INCLUDE_DIRS}
		${Qt5Help_INCLUDE_DIRS}
)

target_compile_options( oapipp PRIVATE -fPIC)

target_link_libraries( oapipp
  Qt::Gui
  Qt::Help
  Qt::Widgets
  Qt::Core
  cfitsio
  tiff
	raw
  pthread
)
