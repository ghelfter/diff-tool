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
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <diff/util/error.h>
#include <diff/util/memory.h>
#include <diff/util/string_utils.h>

static char *log_path = NULL;

static void set_log_path(const char *path)
{
    if (path != NULL)
    {
        if (log_path != NULL)
        {
            util_free(log_path);
        }

        log_path = util_strdup(path);
    }
}

unsigned int core_log_init(const char *path)
{
    unsigned int retcode = DIFF_SUCCESS;

    set_log_path(path);

    return retcode;
}

void core_log_write(const char *message)
{
    FILE *fp = NULL;

    if (message != NULL)
    {
        fp = fopen(log_path, "a");

        if (fp != NULL)
        {
            fputs(message, fp);
            fputc('\n', fp);

            fclose(fp);
        }
    }
}

void core_log_write_timestamped(const char *message)
{
    FILE *fp = NULL;
    time_t current_time;
    char *time_string = NULL;
    struct tm *time_info = NULL;

    if (message != NULL)
    {
        fp = fopen(log_path, "a");

        if (fp != NULL)
        {
            /* Acquire current time */
            time(&current_time);

            time_info = localtime(&current_time);
            time_string = asctime(time_info);
            util_chomp(time_string, '\n');

            fputs(time_string, fp);
            fputs(" -- ", fp);
            fputs(message, fp);
            fputc('\n', fp);
        }
    }
}

void core_log_shutdown()
{
    util_free(log_path);
    log_path = NULL;
}
