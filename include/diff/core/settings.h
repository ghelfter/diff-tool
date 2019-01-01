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

#ifndef _DIFF_CORE_SETTINGS_H
#define _DIFF_CORE_SETTINGS_H

#include <stdint.h>

#if defined(__cplusplus)
extern "C"
{
#endif /* __cplusplus */

unsigned int core_load_settings_file(const char *filepath);

unsigned int core_load_settings_buffer(uint8_t *buffer);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* _DIFF_CORE_SETTINGS_H */
