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
 * @brief Test cases for a simple calculator
 */

#include "misc/calculator.h"
#include "gtest/gtest.h"


unsigned int marker_calculator_test = 1;


TEST(CalculatorTest, Addition) {  
  EXPECT_EQ(4, add(2, 2));
  EXPECT_EQ(0, add(2, -2));
  EXPECT_EQ(0, add(-2, 2));
  EXPECT_EQ(-4, add(-2, -2));
  EXPECT_EQ(0, add(0, 0));
}

TEST(CalculatorTest, Multiplication) {  
  EXPECT_EQ(4, multiply(2,2));
  EXPECT_EQ(-4, multiply(2,-2));
  EXPECT_EQ(-4, multiply(-2,2));
  EXPECT_EQ(4, multiply(-2,-2));  
}


