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

#if defined(DIFF_FORCE_NO_ATOMIC)
#define UTIL_ATOMIC_EXCHANGE(val,oval,nval,res) \
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
#elif defined(__GNUC__)
#define UTIL_ATOMIC_EXCHANGE(val,oval,nval,res) \
    {\
        (res)=(oval);\
        __atomic_compare_exchange(&(val),&(res),(nval),\
                                  __ATOMIC_RELAXED,\
                                  __ATOMIC_RELAXED);\
    }
#define UTIL_ATOMIC_AND(val,op,res) \
    ((res) = __atomic_fetch_and(&(val),op,__ATOMIC_RELAXED))
#define UTIL_ATOMIC_OR(val,op,res) \
    ((res) = __atomic_fetch_or(&(val),op,__ATOMIC_RELAXED))
#define UTIL_ATOMIC_XOR(val,op,res) \
    ((res) = __atomic_fetch_xor(&(val),op,__ATOMIC_RELAXED))
#elif defined(DIFF_WIN32)
#define UTIL_ATOMIC_EXCHANGE(val,oval,nval,res) \
    ((res) = InterlockedCompareExchange(&(val),(nval),(oval)))
#define UTIL_ATOMIC_AND(val,op,res) \
    ((res) = InterlockedAnd(&(val),op))
#define UTIL_ATOMIC_OR(val,op,res) \
    ((res) = InterlockedOr(&(val),op))
#define UTIL_ATOMIC_XOR(val,op,res) \
    ((res) = InterlockedXor(&(val),op))
#else
#error "Must have defined atomic operations"
#endif

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* _DIFF_UTIL_ATOMIC_H */
