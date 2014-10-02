/**
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
 * @brief A set of functions to do simple calcuations
 *
 * This file contains functions to do addition, subtraction, multiplication
 * and division over `int` type.
 */


#ifndef MYJUNK_SIMPLE_CALCULATOR_H
#define MYJUNK_SIMPLE_CALCULATOR_H

#ifdef  __cplusplus
extern "C" {
#endif

/**
 * Add two numbers and return the value.
 *
 * @warning overflow caused by addition is ignored
 *
 * @param[in] num1 First number
 * @param[in] num2 Second number
 *
 * @return The sum of the two numbers
 */
extern int add(const int num1, const int num2);

/**
 * Subtract one number from another and return the value.
 *
 * @param[in] num1 Number to be subtracted from
 * @param[in] num2 Number to be subtracted
 *
 * @return The difference of the two numbers
 */
extern int subtract(const int num1, const int num2);

/**
 * Multiply two numbers and return the value.
 *
 * @warning overflow caused by multiplication is ignored
 *
 * @param[in] num1 First number
 * @param[in] num2 Second number
 *
 * @return The difference of the two numbers
 */
extern int multiply(const int num1, const int num2);

/**
 * Divide one number by another and return the value.
 *
 * @warning Only quotient is returned for integers divisions which involves
 * remainders.
 *
 * @param[in] num1 The dividend
 * @param[in] num2 The divisor
 *
 * @return The quotient from the division
 */
extern int divide(const int num1, const int num2);

#ifdef  __cplusplus
}
#endif

#endif