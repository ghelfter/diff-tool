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

#ifndef _DIFF_DISPLAY_DIALOG_ABOUT_HPP
#define _DIFF_DISPLAY_DIALOG_ABOUT_HPP

#include <QDialog>
#include <QLayout>

#include <atomic>
#include <memory>

namespace Diff
{
    namespace Display
    {
        class AboutDialog : public QDialog
        {
            Q_OBJECT

            public:
                explicit AboutDialog(QWidget *parent = nullptr);
                ~AboutDialog() override;

            public:
                /* Visibility flag - use an atomic operation in case of
                 * multithreaded operations. */
                static std::atomic<uint32_t> mVisible;

            private:
                std::unique_ptr<QLayout> mLayout;

            private:
                void create_widgets();

            signals:
            public slots:
                /* Note - this will get called for any reason that the dialog
                 * will close, which is good to clear the open state. */
                void done(int r) override;
        };
    } // namespace Display
} // namespace Diff

#endif /* _DIFF_DISPLAY_DIALOG_ABOUT_HPP */
