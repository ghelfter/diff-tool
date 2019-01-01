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
#include <diff/display/dialog/open.hpp>
#include <diff/display/menu/edit.hpp>
#include <diff/display/menu/file.hpp>
#include <diff/display/menu/help.hpp>
#include <diff/display/menu/view.hpp>
#include <diff/display/pane/side.hpp>
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
            , mViewMenu(nullptr)
            , mHelpMenu(nullptr)
            , mTextPane(nullptr)
            , mSidePane(nullptr)
            , mFileDialog(nullptr)
            , mAboutDialog(nullptr)
        {
            create_menus();

            /* Create widgets */
            create_ui_panes();

            /* Set main window widget */
            setCentralWidget(mTextPane.get());

            /* Set side pane */
            addDockWidget(Qt::LeftDockWidgetArea, mSidePane.get());

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

            mViewMenu = std::make_unique<ViewMenu>();
            mMenuBar->addMenu(mViewMenu.get());

            mHelpMenu = std::make_unique<HelpMenu>();
            mMenuBar->addMenu(mHelpMenu.get());

            /* Connect dialog slots */
            connect(mHelpMenu.get(), SIGNAL(about_signal()),
                    this, SLOT(about_dialog()));
            connect(mFileMenu.get(), SIGNAL(open_signal()),
                    this, SLOT(open_dialog()));
        }

        void MainWindow::create_ui_panes()
        {
            mTextPane = std::make_unique<TextPane>(this);

            mSidePane = std::make_unique<SidePane>(this);
        }

        /* Slots */
        void MainWindow::about_dialog()
        {
            /* Set dialog state */
            uint32_t expected = 0u;
            bool set = AboutDialog::sVisible.compare_exchange_strong(expected, 1u);

            if (set)
            {
                /* Create about dialog */
                mAboutDialog = std::make_unique<AboutDialog>(this);
                connect(mAboutDialog.get(), SIGNAL(finished(int)),
                        this, SLOT(close_about_dialog(int)));

                mAboutDialog->show();
            }
        }

        void MainWindow::close_about_dialog(int reason)
        {
            mAboutDialog = nullptr;
        }

        void MainWindow::close_file_dialog(int reason)
        {
            if (reason == static_cast<int>(QDialog::Accepted))
            {
                /* Forward selection to core operations */
            }

            mFileDialog = nullptr;
        }

        void MainWindow::open_dialog()
        {
            /* Check dialog state for file->open */
            uint32_t expected = 0u;
            bool set = FileOpenDialog::sVisible.compare_exchange_strong(expected, 1u);

            if (set)
            {
                /* Create about dialog */
                mFileDialog = std::make_unique<FileOpenDialog>(this);
                connect(mFileDialog.get(), SIGNAL(finished(int)),
                        this, SLOT(close_file_dialog(int)));

                mFileDialog->show();
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
