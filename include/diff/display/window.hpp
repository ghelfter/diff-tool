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

#include <memory>

class QTextEdit;

namespace Diff
{
    namespace Display
    {
        /* Forward declare UI types */
        class FileOpenDialog;
        class AboutDialog;
        class EditMenu;
        class FileMenu;
        class HelpMenu;
        class ViewMenu;
        class TextPane;
        class SidePane;

        class MainWindow : public QMainWindow
        {
            Q_OBJECT

            public:
                explicit MainWindow(QWidget *parent = nullptr);
                ~MainWindow() override;

            private:
                /* Main menu bar */
                std::unique_ptr<QMenuBar> mMenuBar;

                /* File menu */
                std::unique_ptr<FileMenu> mFileMenu;

                /* Edit menu */
                std::unique_ptr<EditMenu> mEditMenu;

                /* View menu */
                std::unique_ptr<ViewMenu> mViewMenu;

                /* Help menu */
                std::unique_ptr<HelpMenu> mHelpMenu;

                /* Central text display */
                std::unique_ptr<TextPane> mTextPane;

                /* Side pane */
                std::unique_ptr<SidePane> mSidePane;

                /* File open dialog */
                std::unique_ptr<FileOpenDialog> mFileDialog;

                /* About dialog */
                std::unique_ptr<AboutDialog> mAboutDialog;

            private:
                void create_menus();
                void create_ui_panes();

            signals:
            public slots:
                void about_dialog();
                void open_dialog();
                void close_about_dialog(int result);
                void close_file_dialog(int result);
        };
        
        int main_display(int args, char **argv);
    } // namespace Display
} // namespace Diff

#endif /* _DIFF_DISPLAY_WINDOW_HPP */
