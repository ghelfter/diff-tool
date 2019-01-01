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

#include <diff/display/strings.h>
#include <diff/display/dialog/about.hpp>
#include <diff/util/about.h>

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

namespace Diff
{
    namespace Display
    {
        std::atomic<uint32_t> AboutDialog::sVisible;

        AboutDialog::AboutDialog(QWidget *parent)
            : QDialog(parent)
        {
            create_widgets();

            /* Set the title to the program title */
            setWindowTitle("About " + tr(util_about_title));
        }

        AboutDialog::~AboutDialog()
        {
        }

        void AboutDialog::create_widgets()
        {
            /* Create labels */
            QLabel *version_label = new QLabel(tr(util_about_title)
                                               + tr(" - Version ")
                                               + tr(util_about_version));

            QLabel *copyright_label = new QLabel(tr(util_about_copyright));

            /* Add close button */
            QPushButton *close_button = new QPushButton(display_cancel_button);

            /* Create layout and add UI elements to it. Ownership of the
             * widgets shall be transferred to the layout, whose parent
             * is set to this dialog. */
            mLayout = std::make_unique<QVBoxLayout>();

            mLayout->addWidget(version_label);
            mLayout->addWidget(copyright_label);
            mLayout->addWidget(close_button);

            /* Connect close button with done event */
            connect(close_button, SIGNAL(clicked()), this, SLOT(accept()));

            setLayout(mLayout.get());
        }

        void AboutDialog::done(int r)
        {
            /* Clear atomic state - About should only be opened with an action
             * that acquires the atomic state and fails. */
            uint32_t expected = 1u;
            AboutDialog::sVisible.compare_exchange_strong(expected, 0u);

            /* Call superclass done signal */
            QDialog::done(r);
        }
    } // namespace Display
} // namespace Diff
