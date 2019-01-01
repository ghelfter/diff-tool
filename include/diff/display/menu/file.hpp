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

#ifndef _DIFF_DISPLAY_MENU_FILE_HPP
#define _DIFF_DISPLAY_MENU_FILE_HPP

#include <QMenu>
#include <QAction>

#include <memory>

namespace Diff
{
    namespace Display
    {
        class FileMenu : public QMenu
        {
            Q_OBJECT

            public:
                explicit FileMenu(QWidget *parent = nullptr);
                ~FileMenu() override;

            private:
                /* File menu actions */
                std::unique_ptr<QAction> mFileOpen;
                std::unique_ptr<QAction> mFileClose;

            private:
                void create_actions();

            signals:
                void open_signal();

            public slots:
                /* File menu slots */
                void open_action();
                void close_action();
        };
    } // namespace Display
} // namespace Diff

#endif /* _DIFF_DISPLAY_MENU_FILE_HPP */
