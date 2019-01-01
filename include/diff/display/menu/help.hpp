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

#ifndef _DIFF_DISPLAY_MENU_HELP_HPP
#define _DIFF_DISPLAY_MENU_HELP_HPP

#include <QMenu>

#include <memory>

class QAction;

namespace Diff
{
    namespace Display
    {
        class HelpMenu : public QMenu
        {
            Q_OBJECT

            public:
                explicit HelpMenu(QWidget *parent = nullptr);
                ~HelpMenu() override;

            private:
                /* Help menu actions */
                std::unique_ptr<QAction> mHelpAbout;

            private:
                void create_actions();

            public slots:
                /* Help menu slots */
                void about_action();

            signals:
                void about_signal();
        };
    } // namespace Display
} // namespace Diff

#endif /* _DIFF_DISPLAY_MENU_HELP_HPP */
