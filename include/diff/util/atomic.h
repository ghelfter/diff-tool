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

#ifndef _DIFF_UTIL_ATOMIC_H
#define _DIFF_UTIL_ATOMIC_H

#include <diff/util/common.h>

#if defined(__cplusplus)
extern "C"
{
#endif /* __cplusplus */

/* Forced standard C syntax */
#if defined(DIFF_FORCE_NO_ATOMIC)
#define UTIL_ATOMIC_COMPARE_EXCHANGE(val,oval,nval,res) \
    if((val)==(oval))\
    {\
        (val)=(nval);\
        (res)=(oval);\
    }
#define UTIL_ATOMIC_AND(val,op,res) \
    {\
        (res)=(val);\
        (res)&=(op);\
    }
#define UTIL_ATOMIC_OR(val,op,res) \
    {\
        (res)=(val);\
        (res)|=(op);\
    }
#define UTIL_ATOMIC_XOR(val,op,res) \
    {\
        (res)=(val);\
        (res)^=(op);\
    }
#define UTIL_ATOMIC_INCREMENT(val,res) \
    ((res) = (++(val)))

#define UTIL_ATOMIC_DECREMENT(val,res) \
    ((res) = (--(val)))

#define UTIL_ATOMIC_EXCHANGE(val,op,res) \
    {\
        (res)=(val);\
        (val)=(op);\
    }

/* GCC/Clang atomic definitions */
#elif defined(__GNUC__)
/* Define the default memory order */
#define UTIL_MEMORDER __ATOMIC_RELAXED

#define UTIL_ATOMIC_COMPARE_EXCHANGE(val,oval,nval,res) \
    {\
        (res)=(oval);\
        __atomic_compare_exchange(&(val),&(res),(nval),\
                                  UTIL_MEMORDER,\
                                  UTIL_MEMORDER);\
    }

#define UTIL_ATOMIC_AND(val,op,res) \
    ((res) = __atomic_fetch_and(&(val),op,UTIL_MEMORDER))

#define UTIL_ATOMIC_OR(val,op,res) \
    ((res) = __atomic_fetch_or(&(val),op,UTIL_MEMORDER))

#define UTIL_ATOMIC_XOR(val,op,res) \
    ((res) = __atomic_fetch_xor(&(val),op,UTIL_MEMORDER))

#define UTIL_ATOMIC_INCREMENT(val,res) \
    ((res) = __atomic_add_fetch(&(val),1,UTIL_MEMORDER))

#define UTIL_ATOMIC_DECREMENT(val,res) \
    ((res) = __atomic_sub_fetch(&(val),1,UTIL_MEMORDER))

#define UTIL_ATOMIC_EXCHANGE(val,op,res) \
    __atomic_exchange(&(val),&(op),&(res),UTIL_MEMORDER)

/* MSVC atomic operations */
#elif defined(DIFF_WIN32)
#include <wdm.h> /* Windows header for Interlocked operations */

#define UTIL_ATOMIC_COMPARE_EXCHANGE(val,oval,nval,res) \
    ((res) = InterlockedCompareExchange(&(val),(nval),(oval)))

#define UTIL_ATOMIC_AND(val,op,res) \
    ((res) = InterlockedAnd(&(val),op))

#define UTIL_ATOMIC_OR(val,op,res) \
    ((res) = InterlockedOr(&(val),op))

#define UTIL_ATOMIC_XOR(val,op,res) \
    ((res) = InterlockedXor(&(val),op))

#define UTIL_ATOMIC_INCREMENT(val,res) \
    ((res) = InterlockedIncrement(&(val)))

#define UTIL_ATOMIC_DECREMENT(val,res) \
    ((res) = InterlockedDecrement(&(val)))

#define UTIL_ATOMIC_EXCHANGE(val,op,res) \
    ((res) = InterlockedExchange(&(val),(op)));

/* Error if none are found */
#else
#error "Must have defined atomic operations"
#endif

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* _DIFF_UTIL_ATOMIC_H */
