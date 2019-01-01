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
#include <diff/display/dialog/about.hpp>
#include <diff/display/menu/edit.hpp>
#include <diff/display/menu/file.hpp>
#include <diff/display/menu/help.hpp>
#include <diff/display/pane/text.hpp>
#include <diff/util/about.h>

namespace Diff
{
    namespace Display
    {
        MainWindow::MainWindow(QWidget *parent)
            : QMainWindow(parent)
            , mMenuBar(nullptr)
            , mFileMenu(nullptr)
            , mEditMenu(nullptr)
            , mHelpMenu(nullptr)
        {
            create_menus();

            /* Create widgets */
            create_ui_panes();

            /* Set main window widget */
            setCentralWidget(mTextPane.get());

            /* Set the title to the program title */
            setWindowTitle(tr(util_about_title));

            setUnifiedTitleAndToolBarOnMac(true);
        }

        MainWindow::~MainWindow()
        {
        }

        void MainWindow::create_menus()
        {
            mMenuBar = std::make_unique<QMenuBar>(nullptr);

            setMenuBar(mMenuBar.get());

            mFileMenu = std::make_unique<FileMenu>();
            mMenuBar->addMenu(mFileMenu.get());

            mEditMenu = std::make_unique<EditMenu>();
            mMenuBar->addMenu(mEditMenu.get());

            mHelpMenu = std::make_unique<HelpMenu>();
            mMenuBar->addMenu(mHelpMenu.get());

            /* Connect dialog slots */
            connect(mHelpMenu.get(), SIGNAL(about_signal()),
                    this, SLOT(about_dialog()));
        }

        void MainWindow::create_ui_panes()
        {
            mTextPane = std::make_unique<TextPane>(this);
        }

        /* Slots */
        void MainWindow::about_dialog()
        {
            /* Set dialog state */
            uint32_t expected = 0u;
            bool set = AboutDialog::mVisible.compare_exchange_strong(expected, 1u);

            if (set)
            {
                /* Create about dialog */
                AboutDialog *dialog = new AboutDialog(this);

                dialog->show();
            }
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
