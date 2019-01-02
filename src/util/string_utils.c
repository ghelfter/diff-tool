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

#include <string.h>
#include <diff/util/memory.h>

void util_chomp(char *string, char delim)
{
    size_t length = 0u;

    if (string != NULL)
    {
        length = strlen(string);

        if (length > 0u && string[length - 1u] == delim)
        {
            string[length - 1u] = '\0';
        }
    }
}

char* util_strdup(const char *str)
{
    char *result = NULL;
    size_t string_length = 0u;

    if (str != NULL)
    {
        string_length = strlen(str) + 1;
        result = util_alloc(sizeof(char) * string_length);

        memcpy(result, str, sizeof(char) * string_length);
    }

    return result;
}
