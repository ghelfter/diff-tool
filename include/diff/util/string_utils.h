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


/* Contains string utilities beyond what is in the standard string.h,
 * including reimplementations of functions that allocate memory, as
 * to force usage of the allocator specified in the util/memory.h header. */

#ifndef _DIFF_UTIL_STRING_UTILS_H
#define _DIFF_UTIL_STRING_UTILS_H

#if defined(__cplusplus)
extern "C"
{
#endif /* __cplusplus */

/* Chomps a character off the end of the string, if the string ends with that
 * character. Similar to the 'chomp' command in Perl. */
void util_chomp(char *string, char delim);

/* Duplicates a string, using the internal memory allocator. This can later be
 * freed using util_free - see util/memory.h */
char* util_strdup(const char *str);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* _DIFF_UTIL_STRING_UTILS_H */
