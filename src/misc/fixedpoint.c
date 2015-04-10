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
 * @brief ???????????????????????????????????????/
 */

#include "misc/fixedpoint.h"




/**
 * @brief Parse a character string representing a decimal number and get it's
 * corresponding 32-bit fixed-point representation.
 */
extern int fixedpoint_parseFixed32(const char * number, fixed32_t * fixed) {
    int pos = 0;
    uint16_t integer = 0;
    uint16_t fraction = 0;
    int sign = 1;

    // Check for sign
    if (number[pos] == '-') {
        sign = -1;
        pos++;
    }

    // Parse the integer portion
    while (number[pos] != '.' && number[pos] != '\0') {
        if (number[pos] <= '9' && number[pos] >= '0') {
            integer = integer * 10 + (number[pos] - '0');
        } else {
            return -1;
        }
        pos++;
    }

    // Is there a fraction portion?
    if (number[pos] == '\0') {
        *fixed = ((integer << 16) | fraction) * sign;
        return 0;
    } else {
        pos++;
    }

    // Parse the fraction portion
    uint32_t numerator = 0;
    uint32_t denominator = 1;
    while (number[pos] != '\0') {
        if (number[pos] <= '9' && number[pos] >= '0') {
            numerator = numerator * 10 + (number[pos] - '0');
            denominator = denominator * 10;
        } else {
            return -1;
        }
        pos++;
    }

    // Get the fractional part
    for (int i = 0; i < 16; i++) {
        numerator = numerator * 2;
        fraction = fraction << 1;
        if (numerator/denominator == 1) {
            fraction = (fraction | 1);
            numerator = numerator - denominator;
        } else {
            fraction = (fraction | 0);
        }
    }

    *fixed = ((integer << 16) | fraction) * sign;
    return 0;
}
