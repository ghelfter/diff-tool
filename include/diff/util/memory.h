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

#ifndef _DIFF_UTIL_MEMORY_H
#define _DIFF_UTIL_MEMORY_H

#if defined(__cplusplus)
extern "C"
{
#endif

/* Allocates the given amount of memory using the internally set memory
 * allocator. */
void* util_alloc(size_t size);

/* Frees the memory using the internal free function. This must have been
 * allocated using util_alloc. */
void util_free(void *mem);

/* Sets the internal allocators to the provided functions, matching the
 * signatures of malloc and free respectively. These functions must be
 * the foil of each other. */
void util_set_allocators(void* (*alloc_func)(size_t), void (*free_func)(void*));

/* Duplicates a string, using the internal memory allocator. This can later be
 * freed using util_free. */
char* util_strdup(const char *str);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* _DIFF_UTIL_MEMORY_H */
