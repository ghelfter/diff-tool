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

#ifndef _DIFF_UTIL_THREAD_H
#define _DIFF_UTIL_THREAD_H

#include <diff/util/common.h>

#if defined(DIFF_POSIX)
typedef void* util_thread_ret_t;
#define UTIL_THREAD_DEFAULT NULL
#elif defined(DIFF_WIN32)
typedef unsigned long util_thread_ret_t;
#define UTIL_THREAD_DEFAULT 0u
#endif

/* Forward declaration of threading types */
typedef util_thread_ret_t (*util_thread_fp)(void*);
typedef struct _util_mutex util_mutex_t;
typedef struct _util_cond util_cond_t;

/* It is the caller's responsibility to ensure that all pointers passed are
 * valid for the threading functions. */

/* Initializes the given mutex lock. Mutex locks do not need to be explicitly
 * destroyed. */
void util_mutex_initialize(util_mutex_t *lock);

/* Given an initialized mutex, performs a lock on the mutex. It will block
 * until the lock becomes free. */
void util_mutex_lock(util_mutex_t *lock);

/* Given an initialized mutex, unlocks the mutex. The current thread must
 * have previously acquired the lock. */
void util_mutex_unlock(util_mutex_t *lock);

/* Initialize the given condition variable. The util_cond_destroy function
 * must be used to clean up the condition variable, when there are no
 * threads waiting on the condition. */
void util_cond_initialize(util_cond_t *cond);

/* Destroys the given condition variable. No thread must be waiting on the
 * condition variable. */
void util_cond_destroy(util_cond_t *cond);

/* Given a mutex lock and a condition variable, will sleep the thread until
 * another thread signals the condition. */
void util_cond_sleep(util_cond_t *cond, util_mutex_t *lock);

/* Signals a thread waiting on the condition variable. The lock associated
 * with this condition variable should be acquired by the signaling thread
 * before signaling it and released afterwards. */
void util_cond_signal(util_cond_t *cond);

/* Signals all threads waiting on the condition variable. The lock associated
 * with this condition variable should be acquired prior to signaling the
 * thread before broadcasting and released afterwards. */
void util_cond_broadcast(util_cond_t *cond);

#endif /* _DIFF_UTIL_THREAD_H */
