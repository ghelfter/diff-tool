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
#include <diff/util/error.h>
#include <diff/core/document.h>

#include <errno.h>
#include <stdlib.h>

#if defined(DIFF_POSIX)
#include <unistd.h>
#define DIFF_UNLINK unlink
#elif defined(DIFF_WIN32)
#define DIFF_UNLINK _unlink
#endif

void core_document_init(diff_document_t *document)
{
    if (document != NULL)
    {
        document->filepath = NULL;
    }
}

void core_document_clear(diff_document_t *document)
{
    if (document != NULL)
    {
        free(document->filepath);
        document->filepath = NULL;
    }
}

unsigned int core_document_write(diff_document_t *document)
{
    unsigned int retcode = DIFF_ERROR;
    int result = 0;

    if (document != NULL && document->filepath != NULL)
    {
        result = DIFF_UNLINK(document->filepath);

        if (result < 0)
        {
            /* Error unlinking/deleting the file */
            if (errno == ENOENT)
            {
                /* File doesn't exist - this is fine */
            }
            else if (errno == EACCES)
            {
                /* No permission to write to this file */
            }
        }

        /* Open the given file and write to disk */
    }

    return retcode;
}
