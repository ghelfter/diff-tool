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

#ifndef _DIFF_CORE_LOG_H
#define _DIFF_CORE_LOG_H

#if defined(__cplusplus)
extern "C"
{
#endif /* __cplusplus */

/* Initializes the logging system to write to the given path. */
unsigned int core_log_init(const char *path);

/* Given the current log, writes the message and a newline character out to
 * the log file. */
void core_log_write(const char *message);

/* Logs the given message, with a timestamp alongside the message. */
void core_log_write_timestamped(const char *message);

void core_log_shutdown();

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* _DIFF_CORE_LOG_H */
