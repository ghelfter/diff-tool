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

#include <diff/display/menu/help.hpp>
#include <diff/display/strings.h>

#include <QAction>

namespace Diff
{
    namespace Display
    {
        HelpMenu::HelpMenu(QWidget *parent)
            : QMenu(tr(display_help_button), parent)
            , mHelpAbout(nullptr)
        {
            create_actions();
        }

        HelpMenu::~HelpMenu()
        {
        }

        void HelpMenu::create_actions()
        {
            mHelpAbout = std::make_unique<QAction>(tr(display_about_button), this);
            mHelpAbout->setStatusTip(tr("About this program"));
            connect(mHelpAbout.get(), &QAction::triggered,
                    this, &HelpMenu::about_action);

            addAction(mHelpAbout.get());
        }

        void HelpMenu::about_action()
        {
            /* Forward event signal from the menu to any others awaiting */
            emit about_signal();
        }
    } // namespace Display
} // namespace Diff
