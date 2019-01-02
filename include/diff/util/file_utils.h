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

#ifndef _DIFF_UTIL_FILE_UTILS_H
#define _DIFF_UTIL_FILE_UTILS_H

#if defined(__cplusplus)
extern "C"
{
#endif /* __cplusplus */

unsigned int util_load_file(const char *filepath, uint8_t **buffer,
                            size_t *length);

enum FileInfo
{
    DIFF_FILE_NONEXISTANT = 0u,  /* Filepath does not exist.         */
    DIFF_FILE_REGULAR     = 1u,  /* Normal file, with proper access  */
    DIFF_FILE_NOACCESS    = 2u,  /* No access to the given file path */
    DIFF_FILE_DIRECTORY   = 3u,  /* Path exists, but is a directory  */
    DIFF_FILE_IRREGULAR   = 4u,  /* Sockets, devices, FIFOs, etc.    */
    DIFF_FILE_SYMBOLIC    = 5u,  /* Symbolic link, could be file.    */
    DIFF_FILE_ERROR       = 6u   /* System level error.              */
};

/* Returns an enum value from the FileInfo enum, accounting for whether the
 * file exists and whether the process has access to it. */
unsigned int util_is_file(const char *filepath);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* _DIFF_UTIL_FILE_UTILS_H */
