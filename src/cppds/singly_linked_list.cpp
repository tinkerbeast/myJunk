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
 * @brief Implementations for a set of fuctions to do simple calculations.
 */

#include "misc/calculator.h"


/**
 * Simple addition using the addition operator
 */
extern int add(const int num1, const int num2) {
    return num1 + num2;
}

/**
 * Simple subtraction using the subtraction operator
 */
extern int subtract(const int num1, const int num2) {
    return num1 - num2;
}

/**
 * Simple multiplication using the multiplication operator
 */
extern int multiply(const int num1, const int num2) {
    return num1 * num2;
}

/**
 * Simple division using the division operator
 */
extern int divide(const int num1, const int num2) {
    return num1 / num2;
}
