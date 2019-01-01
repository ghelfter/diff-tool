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

#ifndef _DIFF_DISPLAY_MENU_EDIT_HPP
#define _DIFF_DISPLAY_MENU_EDIT_HPP

#include <QMenu>
#include <QAction>

#include <memory>

namespace Diff
{
    namespace Display
    {
        class EditMenu : public QMenu
        {
            Q_OBJECT

            public:
                explicit EditMenu(QWidget *parent = nullptr);
                ~EditMenu() override;

            private:
                /* Edit menu actions */
                std::unique_ptr<QAction> mEditCopy;
                std::unique_ptr<QAction> mEditCut;

            private:
                void create_actions();

            signals:
            public slots:
                /* Edit menu slots */
                void copy_action();
                void cut_action();
        };
        
        int main_display(int args, char **argv);
    } // namespace Display
} // namespace Diff

#endif /* _DIFF_DISPLAY_MENU_EDIT_HPP */
