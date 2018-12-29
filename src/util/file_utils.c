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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <diff/util/common.h>
#include <diff/util/error.h>
#include <diff/util/file_utils.h>

unsigned int util_load_file(const char *filepath, uint8_t **buffer,
                            size_t *length)
{
    unsigned int retcode = DIFF_ERROR;
    FILE *fp = NULL;
    uint8_t *local_buffer = NULL;
    long filesize = 0;
    size_t local_length = 0u;

    if (filepath != NULL && buffer != NULL && length != NULL)
    {
        fp = fopen(filepath, "r");

        if (fp != NULL)
        {
            fseek(fp, 0l, SEEK_END);
            filesize = ftell(fp);
            fseek(fp, 0l, SEEK_SET);

            if (filesize > 0l)
            {
                /* File was successfully opened and is not empty */
                local_length = (size_t) filesize + 1u;
                local_buffer = malloc(local_length);

                /* Attempt to read the file into memory */
                fread(local_buffer, sizeof(uint8_t), filesize, fp);
                local_buffer[filesize] = '\0'; /* Null terminate string */

                retcode = DIFF_SUCCESS;
            }

            fclose(fp);
            fp = NULL;
        }
    }

    /* Only commit the output values on success */
    if (retcode == DIFF_SUCCESS)
    {
        *buffer = local_buffer;
        *length = local_length;
    }
    else if(local_buffer != NULL)
    {
        free(local_buffer);
    }

    return retcode;
}
