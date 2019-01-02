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

#include <diff/util/common.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <diff/proc/run_diff.h>
#include <diff/util/error.h>

#if defined(DIFF_POSIX)
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#elif defined(DIFF_WIN32)
#endif

static int run_process(const char *program, const char *file, uint8_t **buffer);

#if defined(DIFF_POSIX)
static int run_process(const char *program, const char *file, uint8_t **buffer)
{
    int result = 0;
    int process_res = 0;
    pid_t id = 0;
    char *argv[12];

    id = fork();

    if (id == 0)
    {
        /* Execute the formatter */
        argv[0] = file;
        argv[1] = NULL;
        execvp(program, argv);
    }
    else
    {
        /* Wait for the process to finish */
        waitpid(id, &process_res, 0);
        if (WIFEXITED(process_res))
        {
            result = 1;
        }
    }

    return result;
}
#else
static int run_process(const char *program, const char *file, uint8_t **buffer)
{
    return 0;
}
#endif

/* #TODO:: Change this to allow for arguments to be passed in as an array
 * instead of just the file argument. */
unsigned int proc_run_diff(const char *program, const char *file,
                           uint8_t **buffer)
{
    unsigned int retcode = DIFF_ERROR;
    int result = 0;

    if (program != NULL && file != NULL && buffer != NULL)
    {
        result = run_process(program, file, buffer);

        if (result != 0)
        {
            retcode = DIFF_SUCCESS;
        }
    }

    return retcode;
}
