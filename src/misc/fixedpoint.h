/**
 * Copyright 2014, Rishin Goswami
 *
 * This file is part of myJunk.
 * 
 * myJunk is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * myJunk is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with myJunk.  If not, see <http://www.gnu.org/licenses/>.
 */


/**
 * @brief A set of functions to do simple fixed point calculations
 */


#ifndef MYJUNK_MISC_FIXEDPOINT_H_
#define MYJUNK_MISC_FIXEDPOINT_H_

#include <stdint.h>

#ifdef  __cplusplus
extern "C" {
#endif

typedef int32_t fixed32_t;

typedef uint32_t ufixed32_t;

extern int fixedpoint_parse(const char * number, fixed32_t * fixed);

#ifdef __cplusplus
}
#endif

#endif  // MYJUNK_MISC_CALCULATOR_H_
