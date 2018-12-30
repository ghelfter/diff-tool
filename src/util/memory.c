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

#include <stdlib.h>

static void* (*util_alloc_func)(size_t) = malloc;
static void (*util_free_func)(void*) = free;

void* util_alloc(size_t size)
{
    return util_alloc_func(size);
}

void util_free(void *mem)
{
    util_free_func(mem);
}

void util_set_allocators(void* (*alloc_func)(size_t), void (*free_func)(void*))
{
    if (alloc_func != NULL && free_func != NULL)
    {
        util_alloc_func = alloc_func;
        util_free_func = free_func;
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
