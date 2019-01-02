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

/* Contains a dialog, which will show a formatted document/diff after the
 * formatter has been run on the original documents. */

#ifndef _DIFF_DISPLAY_DIALOG_FORMAT_HPP
#define _DIFF_DISPLAY_DIALOG_FORMAT_HPP

#include <QDialog>

namespace Diff
{
    namespace Display
    {
        class FormatDialog : public QDialog
        {
            Q_OBJECT

            public:
                explicit FormatDialog(QWidget *parent = nullptr);
                ~FormatDialog() override;

            private:

            signals:
            public slots:
        };
    } // namespace Display
} // namespace Diff

#endif /* _DIFF_DISPLAY_DIALOG_FORMAT_HPP */
