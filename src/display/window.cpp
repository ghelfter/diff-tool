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

#include <QAction>
#include <QApplication>
#include <QMenu>
#include <QMenuBar>

#include <memory>
#include <cstdio>

#include <diff/display/window.hpp>
#include <diff/display/menu/edit.hpp>
#include <diff/display/menu/file.hpp>
#include <diff/display/menu/help.hpp>

namespace Diff
{
    namespace Display
    {
        MainWindow::MainWindow(QWidget *parent)
            : QMainWindow(parent)
            , mFileMenu(nullptr)
            , mEditMenu(nullptr)
            , mHelpMenu(nullptr)
        {
            create_menus();
        }

        MainWindow::~MainWindow()
        {
        }

        void MainWindow::create_menus()
        {
            mFileMenu = std::make_unique<FileMenu>();
            menuBar()->addMenu(mFileMenu.get());

            mEditMenu = std::make_unique<EditMenu>();
            menuBar()->addMenu(mEditMenu.get());

            mHelpMenu = std::make_unique<HelpMenu>();
            menuBar()->addMenu(mHelpMenu.get());
        }

        int main_display(int args, char **argv)
        {
            QApplication application(args, argv);

            MainWindow main_window(nullptr);

            main_window.show();

            return application.exec();
        }
    }
}
