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

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <diff/core/settings.h>
#include <diff/util/error.h>
#include <diff/util/file_utils.h>

typedef struct _diff_settings
{
    char *diff_program_path;
} diff_settings_t;

static diff_settings_t settings = { NULL };

unsigned int core_load_settings_file(const char *filepath)
{
    unsigned int retcode = DIFF_ERROR;
    unsigned int local_ret = DIFF_ERROR;

    uint8_t *buffer = NULL;
    size_t length = 0u;

    local_ret = util_load_file(filepath, &buffer, &length);

    if (local_ret == DIFF_SUCCESS)
    {
        retcode = core_load_settings_buffer(buffer);

        free(buffer);
    }

    return retcode;
}

unsigned int core_load_settings_buffer(uint8_t *buffer)
{
    unsigned int retcode = DIFF_ERROR;

    if (buffer != NULL)
    {
        retcode = DIFF_SUCCESS;
    }

    return retcode;
}

void core_set_diff_program(const char *path)
{
    if (settings.diff_program_path != NULL)
    {
        free(settings.diff_program_path);
    }

    settings.diff_program_path = strdup(path);
}

char* core_get_diff_program()
{
    return strdup(settings.diff_program_path);
}
