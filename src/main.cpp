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

#include <cstdlib>
#include <cstring>
#include <cstdio>

#include <diff/display/window.hpp>
#include <diff/util/common.h>

enum ControllerState
{
    DIFF_DEFAULT_STATE = 0u,
    DIFF_VERSION_STATE = 1u,
    DIFF_USAGE_STATE = 2u,
    DIFF_MAX_STATE = 2u
};

static int qt_argc = 0;
static char **qt_argv = nullptr;

typedef int (*diff_top_fp)();

static int default_operation()
{
    return Diff::Display::main_display(qt_argc, qt_argv);
}

static int print_version()
{
    fprintf(stdout, "Diff tool, version %s\n", DIFF_VERSION);
    return 0;
}

static int print_help()
{
    fprintf(stdout, "USAGE: diff_tool [options]\n");
    return 0;
}

static diff_top_fp diff_controllers[] =
{
    default_operation,
    print_version,
    print_help
};

DIFF_EXPORT
int main(int argc, char **argv)
{
    int exit_status = EXIT_SUCCESS;

    unsigned int controller = DIFF_DEFAULT_STATE;

    qt_argc = argc;
    qt_argv = argv;

    if (argc > 1)
    {
        ++argv;
        const char *arg_ptr = *(argv);

        int arg_count = argc;
        while (arg_count > 1)
        {
            if (!strcmp(arg_ptr, "--version") && controller == DIFF_DEFAULT_STATE)
            {
                controller = DIFF_VERSION_STATE;
            }
            else if (!strcmp(arg_ptr, "--help") && controller == DIFF_DEFAULT_STATE)
            {
                controller = DIFF_USAGE_STATE;
            }
            else if (!strcmp(arg_ptr, "-h") && controller == DIFF_DEFAULT_STATE)
            {
                controller = DIFF_USAGE_STATE;
            }

            ++argv;
            arg_ptr = *(argv);
            --arg_count;
        }
    }

    diff_controllers[controller]();

    return exit_status;
}
