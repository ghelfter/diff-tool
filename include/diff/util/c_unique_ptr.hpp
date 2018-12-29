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

#ifndef _DIFF_UTIL_C_UNIQUE_PTR_HPP
#define _DIFF_UTIL_C_UNIQUE_PTR_HPP

#include <memory>
#include <cstdlib>

namespace Diff
{
    namespace Util
    {
        template <typename T>
        using c_unique_ptr = std::unique_ptr<T, decltype(&std::free)>;

        template <typename T>
        c_unique_ptr<T> c_make_unique(size_t size)
        {
            return c_unique_ptr<T>((T*) std::malloc(size), &std::free);
        }
    }
}

#endif /* _DIFF_UTIL_C_UNIQUE_PTR_HPP */
