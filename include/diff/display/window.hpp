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

#ifndef _DIFF_DISPLAY_WINDOW_HPP
#define _DIFF_DISPLAY_WINDOW_HPP

#include <QMainWindow>

namespace Diff
{
    namespace Display
    {
        class MainWindow : public QMainWindow
        {
            Q_OBJECT

            public:
                explicit MainWindow(QWidget *parent = nullptr);
                ~MainWindow() override;

            private:
                /* Main menu bar */
                std::unique_ptr<QMenuBar> mMenuBar;

                /* File menu and its actions */
                std::unique_ptr<QMenu> mFileMenu;

                /* Edit menu and its actions */
                std::unique_ptr<QMenu> mEditMenu;

                /* Help menu and its actions */
                std::unique_ptr<QMenu> mHelpMenu;

            private:
                void create_menus();
                void create_help_menu();

            signals:
            public slots:
        };
        
        int main_display(int args, char **argv);
    } // namespace Display
} // namespace Diff

#endif /* _DIFF_DISPLAY_WINDOW_HPP */
