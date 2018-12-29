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

#include <diff/util/error.h>

static const char* error_string_table[DIFF_ERROR_MAX] =
{
    "Success - no error was encountered.",
    "Error - an unspecified error condition was encountered",
    "Error - memory allocation has failed"
};

static const char* unknown_error = "Unknown error condition.";

const char* util_get_error_string(unsigned int errorcode)
{
    const char *result = unknown_error;

    if (errorcode < DIFF_ERROR_MAX)
    {
        result = error_string_table[errorcode];
    }

    return result;
}
