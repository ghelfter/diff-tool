/*
    Diff Tool - Tool for graphically running a formatter
    Copyright (C) 2019 Galen Helfter

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <diff/display/dialog/open.hpp>
#include <diff/display/strings.h>

#include <QStringList>

namespace Diff
{
    namespace Display
    {
        std::atomic<uint32_t> FileOpenDialog::sVisible;

        FileOpenDialog::FileOpenDialog(QWidget *parent)
            : QFileDialog(parent)
        {
            /* Set the open title */
            setWindowTitle(tr("Open Files"));

            /* Set up mime filters */
            QStringList filters;

            setup_filter_types(filters);

            setNameFilters(filters);
        }

        FileOpenDialog::~FileOpenDialog()
        {
        }

        void FileOpenDialog::done(int r)
        {
            /* Clear atomic state - About should only be opened with an action
             * that acquires the atomic state and fails if the dialog is
             * open. */
            uint32_t expected = 1u;
            FileOpenDialog::sVisible.compare_exchange_strong(expected, 0u);

            /* Call superclass done method */
            QDialog::done(r);
        }

        void FileOpenDialog::setup_filter_types(QStringList &list)
        {
            list << "C & C++ files (*.c *.h *.cpp *.hpp *.C *.cc)"
                 << "Python files (*.py)"
                 << "Perl files (*.pl *.pm)"
                 << "Haskell files (*.hs)"
                 << "Tcl files (*.tcl)"
                 << "Lisp files (*.lisp)"
                 << "All file types (*)";
        }
    } // namespace Display
} // namespace Diff
