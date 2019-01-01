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

#include <diff/display/menu/view.hpp>
#include <diff/display/strings.h>

#include <QAction>

namespace Diff
{
    namespace Display
    {
        ViewMenu::ViewMenu(QWidget *parent)
            : QMenu(tr(display_view_button), parent)
            , mViewSide(nullptr)
        {
            create_actions();
        }

        ViewMenu::~ViewMenu()
        {
        }

        void ViewMenu::create_actions()
        {
            mViewSide = std::make_unique<QAction>(tr("Side"), this);

            mViewSide->setStatusTip(tr("Display sidebar"));

            connect(mViewSide.get(), &QAction::triggered,
                    this, &ViewMenu::side_action);

            addAction(mViewSide.get());
        }

        void ViewMenu::side_action()
        {
            emit side_signal();
        }
    } // namespace Display
} // namespace Diff
