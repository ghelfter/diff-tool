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

#include <stddef.h>
#include <pthread.h>
#include <diff/util/thread.h>

/* Declare internal representations of the threading structures to use a
 * pthread implementation. */
struct _util_mutex
{
    pthread_mutex_t lock;
};

struct _util_cond
{
    pthread_cond_t cond;
};

void util_mutex_initialize(util_mutex_t *lock)
{
    pthread_mutex_init(&lock->lock, NULL);
}

void util_mutex_lock(util_mutex_t *lock)
{
    pthread_mutex_lock(&lock->lock);
}

void util_mutex_unlock(util_mutex_t *lock)
{
    pthread_mutex_unlock(&lock->lock);
}

void util_cond_initialize(util_cond_t *cond)
{
    pthread_cond_init(&cond->cond, NULL);
}

void util_cond_destroy(util_cond_t *cond)
{
    pthread_cond_destroy(&cond->cond);
}

void util_cond_sleep(util_cond_t *cond, util_mutex_t *lock)
{
    pthread_cond_wait(&cond->cond, &lock->lock);
}

void util_cond_signal(util_cond_t *cond)
{
    pthread_cond_signal(&cond->cond);
}

void util_cond_broadcast(util_cond_t *cond)
{
    pthread_cond_broadcast(&cond->cond);
}
