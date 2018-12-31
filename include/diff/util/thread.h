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
#include <pthread.h>
typedef pthread_mutex_t util_mutex_t;
typedef pthread_cond_t util_cond_t;

#define DIFF_UTIL_COND_INIT PTHREAD_COND_INITIALIZER
#define DIFF_UTIL_THREAD_RETTYPE void*
#elif defined(DIFF_WIN32)
#include <synhapi.h>
typedef SRWLock util_mutex_t;
typedef CONDITION_VARIABLE util_cond_t;

#define DIFF_UTIL_COND_INIT CONDITION_VARIABLE_INIT
#define DIFF_UTIL_THREAD_RETTYPE unsigned long
#endif

/* Given an initialized mutex, performs a lock on the mutex. It will block
 * until the lock becomes free. */
void util_mutex_lock(util_mutex_t *lock);

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
