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

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <diff/core/settings.h>
#include <diff/util/atomic.h>
#include <diff/util/error.h>
#include <diff/util/file_utils.h>
#include <diff/util/memory.h>
#include <diff/util/string_utils.h>

typedef struct _diff_settings
{
    char *diff_program_path;
} diff_settings_t;

static diff_settings_t settings = { NULL };

/* Atomic state to make settings loading fail on repeated attempts */
static uint32_t settings_state = 0u;

/* Atomic states for the settings to ensure that any */
enum DiffSettingsState
{
    DIFF_SETTINGS_UNINITIALIZED = 0u,
    DIFF_SETTINGS_INIT_STARTED  = 1u,
    DIFF_SETTINGS_INITIALIZED   = 2u
};

unsigned int core_load_settings_file(const char *filepath)
{
    unsigned int retcode = DIFF_ERROR;
    unsigned int local_ret = DIFF_ERROR;

    uint8_t *buffer = NULL;
    size_t length = 0u;

    uint32_t state_result = 0u;
    uint32_t state_desired = DIFF_SETTINGS_INIT_STARTED;

    UTIL_ATOMIC_COMPARE_EXCHANGE(settings_state, DIFF_SETTINGS_UNINITIALIZED,
                                 state_desired, state_result);

    if (state_result == DIFF_SETTINGS_UNINITIALIZED)
    {
        local_ret = util_load_file(filepath, &buffer, &length);

        if (local_ret == DIFF_SUCCESS)
        {
            retcode = core_load_settings_buffer(buffer);

            free(buffer);

            state_desired = DIFF_SETTINGS_INITIALIZED;
        }
        else
        {
            /* Clear state on failure */
            state_desired = DIFF_SETTINGS_UNINITIALIZED;
        }

        UTIL_ATOMIC_COMPARE_EXCHANGE(settings_state, DIFF_SETTINGS_INIT_STARTED,
                                     state_desired, state_result);
    }

    return retcode;
}

unsigned int core_load_settings_buffer(uint8_t *buffer)
{
    unsigned int retcode = DIFF_ERROR;

    if (buffer != NULL)
    {
        /* Find the first newline character */

        retcode = DIFF_SUCCESS;
    }

    return retcode;
}

void core_set_diff_program(const char *path)
{
    if (settings.diff_program_path != NULL)
    {
        util_free(settings.diff_program_path);
    }

    settings.diff_program_path = strdup(path);
}

char* core_get_diff_program()
{
    return util_strdup(settings.diff_program_path);
}
