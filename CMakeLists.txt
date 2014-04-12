##
## This file is part of the QtDMM project.
##
## Copyright (C) 2014 Joel Holdsworth <joel@airwebreathe.org.uk>
##
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 2 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <http://www.gnu.org/licenses/>.
##

cmake_minimum_required(VERSION 2.8.6)

include(FindPkgConfig)
include(GNUInstallDirs)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")

project(qtdmm)

#===============================================================================
#= Dependencies
#-------------------------------------------------------------------------------

find_program(QT_QMAKE_EXECUTABLE NAMES qmake4 qmake-qt4 qmake-mac)
find_package(Qt4 REQUIRED)

#===============================================================================
#= Config Header
#-------------------------------------------------------------------------------

set(QTDMM_TITLE PulseView)
set(QTDMM_DESCRIPTION "A GUI for DMMs")

set(QTDMM_VERSION_MAJOR 0)
set(QTDMM_VERSION_MINOR 8)
set(QTDMM_VERSION_MICRO 14)
set(QTDMM_VERSION_STRING
	${QTDMM_VERSION_MAJOR}.${QTDMM_VERSION_MINOR}.${QTDMM_VERSION_MICRO}
)

configure_file (
	${PROJECT_SOURCE_DIR}/config.h.in
	${PROJECT_BINARY_DIR}/config.h
)

#===============================================================================
#= Sources
#-------------------------------------------------------------------------------

set(qtdmm_SOURCES
	src/colorbutton.cpp
	src/configdlg.cpp
	src/configitem.cpp
	src/displayprefs.cpp
	src/displaywid.cpp
	src/dmm.cpp
	src/dmmbar.cpp
	src/dmmgraph.cpp
	src/dmmprefs.cpp
	src/engnumbervalidator.cpp
	src/executeprefs.cpp
	src/graphprefs.cpp
	src/guiprefs.cpp
	src/integrationprefs.cpp
	src/main.cpp
	src/mainwid.cpp
	src/mainwin.cpp
	src/prefwidget.cpp
	src/printdlg.cpp
	src/readerthread.cpp
	src/readevent.cpp
	src/recorderprefs.cpp
	src/scaleprefs.cpp
	src/simplecfg.cpp
	src/tipdlg.cpp
)

# This list includes only QObject derived class headers.
set(qtdmm_HEADERS
	src/colorbutton.h
	src/configdlg.h
	src/displayprefs.h
	src/displaywid.h
	src/dmm.h
	src/dmmbar.h
	src/dmmgraph.h
	src/dmmprefs.h
	src/executeprefs.h
	src/graphprefs.h
	src/guiprefs.h
	src/integrationprefs.h
	src/mainwid.h
	src/mainwin.h
	src/prefwidget.h
	src/printdlg.h
	src/readerthread.h
	src/recorderprefs.h
	src/scaleprefs.h
	src/tipdlg.h
)

set(qtdmm_FORMS
	src/uiconfigdlg.ui
	src/uidisplayprefs.ui
	src/uidmmprefs.ui
	src/uiexecuteprefs.ui
	src/uigraphprefs.ui
	src/uiguiprefs.ui
	src/uiintegrationprefs.ui
	src/uimainwid.ui
	src/uiprintdlg.ui
	src/uirecorderprefs.ui
	src/uiscaleprefs.ui
	src/uitest.ui
	src/uitipdlg.ui
)

if(WIN32)
	# Use the sigrok icon for the pulseview.exe executable.
	set(CMAKE_RC_COMPILE_OBJECT "${CMAKE_RC_COMPILER} -O coff -I${CMAKE_CURRENT_SOURCE_DIR} <SOURCE> <OBJECT>")
	enable_language(RC)
	list(APPEND pulseview_SOURCES pulseviewico.rc)
endif()

qt4_wrap_cpp(qtdmm_HEADERS_MOC ${qtdmm_HEADERS})
qt4_wrap_ui(qtdmm_FORMS_HEADERS ${qtdmm_FORMS})

include(${QT_USE_FILE})

#===============================================================================
#= Global Definitions
#-------------------------------------------------------------------------------

add_definitions(${QT_DEFINITIONS})
add_definitions(-DQT3_SUPPORT)
add_definitions(-D__STDC_LIMIT_MACROS)

#===============================================================================
#= Global Include Directories
#-------------------------------------------------------------------------------

include_directories(
	${CMAKE_CURRENT_BINARY_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/src/
	${CMAKE_CURRENT_SOURCE_DIR}/src/xpm/
	${QT_QT3SUPPORT_INCLUDE_DIR}
)

if(STATIC_PKGDEPS_LIBS)
	include_directories(${PKGDEPS_STATIC_INCLUDE_DIRS})
else()
	include_directories(${PKGDEPS_INCLUDE_DIRS})
endif()

#===============================================================================
#= Linker Configuration
#-------------------------------------------------------------------------------

set(QTDMM_LINK_LIBS
	${QT_LIBRARIES}
	${QT_QT3SUPPORT_LIBRARY}
)

if(STATIC_PKGDEPS_LIBS)
	link_directories(${PKGDEPS_STATIC_LIBRARY_DIRS})
	list(APPEND QTDMM_LINK_LIBS ${PKGDEPS_STATIC_LIBRARIES})
if(WIN32)
	# Workaround for a MinGW linking issue.
	list(APPEND QTDMM_LINK_LIBS "-llzma -llcms2")
endif()
else()
	link_directories(${PKGDEPS_LIBRARY_DIRS})
	list(APPEND QTDMM_LINK_LIBS ${PKGDEPS_LIBRARIES})
endif()

if(WIN32)
	# On Windows we need to statically link the libqsvg imageformat
	# plugin (and the QtSvg component) for SVG graphics/icons to work.
	add_definitions(-DQT_STATICPLUGIN)
	link_directories("${QT_PLUGINS_DIR}/imageformats")
	list(APPEND QTDMM_LINK_LIBS ${QT_QTSVG_LIBRARY})
	list(APPEND QTDMM_LINK_LIBS "-lqsvg")
endif()

add_executable(${PROJECT_NAME}
	${qtdmm_SOURCES}
	${qtdmm_HEADERS_MOC}
	${qtdmm_FORMS_HEADERS}
	${qtdmm_RESOURCES_RCC}
)

target_link_libraries(${PROJECT_NAME} ${QTDMM_LINK_LIBS})

if(WIN32)
	# Pass -mwindows so that no "DOS box" opens when PulseView is started.
	set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-mwindows")
endif()

if(ENABLE_COTIRE)
	include(cotire)
	cotire(${PROJECT_NAME})
endif()

#===============================================================================
#= Installation
#-------------------------------------------------------------------------------

# Install the executable.
install(TARGETS ${PROJECT_NAME} DESTINATION bin/)

# Install the manpage.
install(FILES doc/qtdmm.1 DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 COMPONENT doc)

#===============================================================================
#= Packaging (handled by CPack)
#-------------------------------------------------------------------------------

set(CPACK_PACKAGE_VERSION_MAJOR ${QTDMM_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${QTDMM_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${QTDMM_VERSION_MICRO})
set(CPACK_PACKAGE_DESCRIPTION_FILE ${CMAKE_CURRENT_SOURCE_DIR}/README)
set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_CURRENT_SOURCE_DIR}/COPYING)
set(CPACK_SOURCE_IGNORE_FILES ${CMAKE_CURRENT_BINARY_DIR} ".gitignore" ".git")
set(CPACK_SOURCE_PACKAGE_FILE_NAME
	"${CMAKE_PROJECT_NAME}-${QTDMM_VERSION_MAJOR}.${QTDMM_VERSION_MINOR}.${QTDMM_VERSION_MICRO}")
set(CPACK_SOURCE_GENERATOR "TGZ")

include(CPack)
