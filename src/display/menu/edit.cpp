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

#include <diff/display/menu/edit.hpp>

#include <memory>
#include <cstdio>

namespace Diff
{
    namespace Display
    {
        EditMenu::EditMenu(QWidget *parent)
            : QMenu(tr("&Edit"), parent)
            , mEditCopy(nullptr)
            , mEditCut(nullptr)
        {
            create_actions();
        }

        EditMenu::~EditMenu()
        {
        }

        void EditMenu::create_actions()
        {
            mEditCopy = std::make_unique<QAction>(tr("&Copy"), this);
            mEditCopy->setShortcuts(QKeySequence::Copy);
            mEditCopy->setStatusTip(tr("Copy selected text"));
            connect(mEditCopy.get(), &QAction::triggered,
                    this, &EditMenu::copy_action);

            mEditCut = std::make_unique<QAction>(tr("&Cut"), this);
            mEditCut->setShortcuts(QKeySequence::Cut);
            mEditCut->setStatusTip(tr("Cut selected text"));
            connect(mEditCut.get(), &QAction::triggered,
                    this, &EditMenu::cut_action);

            addAction(mEditCopy.get());
            addAction(mEditCut.get());
        }

        void EditMenu::copy_action()
        {
            fprintf(stdout, "Edit->Copy\n");
        }

        void EditMenu::cut_action()
        {
            fprintf(stdout, "Edit->Cut\n");
        }
    } // namespace Display
} // namespace Diff
