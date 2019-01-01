#   Diff Tool - Tool for graphically running a formatter
#   Copyright (C) 2019 Galen Helfter
#
#   This program is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program.  If not, see <https://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 90)

set(DIFF_PROJECT_NAME "FormatDiff")

project("${DIFF_PROJECT_NAME}")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(MAJOR_VERSION 0)
set(MINOR_VERSION 0)
set(PATCH_VERSION 2)

set(BUILD_VERSION "${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION}")

add_definitions(
    -DDIFF_VERSION="${BUILD_VERSION}"
)

set(PROJECT_NAME ${DIFF_PROJECT_NAME})
set(PROJECT_DESCRIPTION "")

#########################################################
#                       Building                        #
#########################################################

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(DIFF_UNIX_FLAGS "-Wall -Wextra -pedantic -fvisibility=hidden")

if (APPLE)
    set(CMAKE_C_FLAGS "${DIFF_UNIX_FLAGS} -O3 -mmacosx-version-min=10.11")
    set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS}")
elseif (UNIX)
    set(CMAKE_C_FLAGS "${DIFF_UNIX_FLAGS} -O3")
    set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS}")
endif()

set(DIFF_SOURCES
    src/main.cpp

    # Core files
    src/core/document.c
    src/core/log.c
    src/core/settings.c
    src/core/state.c

    # Display and UI files
    src/display/window.cpp
    src/display/strings.c
    src/display/dialog/about.cpp
    src/display/menu/edit.cpp
    src/display/menu/file.cpp
    src/display/menu/help.cpp
    src/display/pane/side.cpp
    src/display/pane/text.cpp

    # Process running files
    src/proc/run_diff.c

    # Utility files
    src/util/about.c
    src/util/error.c
    src/util/file_utils.c
    src/util/memory.c
)

# Note that headers requiring Qt components must be explicitly listed
# for the automoc to run properly with it.
set(DIFF_HEADERS
    include/diff/core/document.h
    include/diff/core/log.h
    include/diff/core/settings.h
    include/diff/core/state.h

    include/diff/display/window.hpp
    include/diff/display/strings.h
    include/diff/display/dialog/about.hpp
    include/diff/display/menu/edit.hpp
    include/diff/display/menu/file.hpp
    include/diff/display/menu/help.hpp
    include/diff/display/pane/side.hpp
    include/diff/display/pane/text.hpp

    include/diff/proc/run_diff.h

    include/diff/util/about.h
    include/diff/util/atomic.h
    include/diff/util/common.h
    include/diff/util/error.h
    include/diff/util/c_unique_ptr.hpp
    include/diff/util/file_utils.h
    include/diff/util/memory.h
)

# Platform specific source files
if (UNIX)
    set(DIFF_SOURCES

        ${DIFF_SOURCES}
        src/util/thread_unix.c
    )
elseif (WIN32)
    set(DIFF_SOURCES

        ${DIFF_SOURCES}
        src/util/thread_windows.c
    )
endif ()

find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)

add_executable(diff_tool ${DIFF_SOURCES} ${DIFF_HEADERS})

target_include_directories(
    diff_tool PUBLIC

    "include"
    "${Qt5Widgets_INCLUDE_DIRS}"
    "${Qt5Core_INCLUDE_DIRS}"
)

target_link_libraries(
    diff_tool

    Qt5::Widgets
    Qt5::Core
)

#########################################################
#                          Qt                           #
#########################################################

qt5_use_modules(diff_tool Widgets Core)

#########################################################
#                     Installation                      #
#########################################################

install(
    TARGETS diff_tool
    LIBRARY DESTINATION "."
    RUNTIME DESTINATION "."
)
