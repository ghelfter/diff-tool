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

#include <diff/display/strings.h>
#include <diff/display/menu/file.hpp>

#include <memory>
#include <cstdio>

namespace Diff
{
    namespace Display
    {
        FileMenu::FileMenu(QWidget *parent)
            : QMenu(tr("&File"), parent)
            , mFileOpen(nullptr)
            , mFileClose(nullptr)
        {
            create_actions();
        }

        FileMenu::~FileMenu()
        {
        }

        void FileMenu::create_actions()
        {
            mFileOpen = std::make_unique<QAction>(tr(display_open_button), this);
            mFileOpen->setShortcuts(QKeySequence::Open);
            mFileOpen->setStatusTip(tr("Open selected files"));
            connect(mFileOpen.get(), &QAction::triggered,
                    this, &FileMenu::open_action);

            mFileClose = std::make_unique<QAction>(tr(display_close_button), this);
            mFileClose->setShortcuts(QKeySequence::Cut);
            mFileClose->setStatusTip(tr("Close files"));
            connect(mFileClose.get(), &QAction::triggered,
                    this, &FileMenu::close_action);

            addAction(mFileOpen.get());
            addAction(mFileClose.get());
        }

        void FileMenu::open_action()
        {
            emit open_signal();
        }

        void FileMenu::close_action()
        {
        }
    } // namespace Display
} // namespace Diff
