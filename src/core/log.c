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

static char *log_path = NULL;

static void set_log_path(const char *path)
{
    if (path != NULL)
    {
        if (log_path != NULL)
        {
            free(log_path);
        }

        log_path = strdup(path);
    }
}

unsigned int core_log_init(const char *path)
{
    unsigned int retcode = 0u;

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
