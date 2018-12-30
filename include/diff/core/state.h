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

#ifndef _DIFF_CORE_STATE_H
#define _DIFF_CORE_STATE_H

#if defined(__cplusplus)
extern "C"
{
#endif /* __cplusplus */

#include <stdint.h>

enum DiffCoreState
{
    DIFF_UNINITIALIZED,
    DIFF_INIT_STARTED,
    DIFF_INITIALIZED,
    DIFF_SHUTDOWN_STARTED
};

typedef struct _core_state
{
    uint32_t state;
} core_state_t;

extern core_state_t core_state;

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* _DIFF_CORE_STATE_H */
