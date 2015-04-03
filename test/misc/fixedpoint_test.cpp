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
 * @brief Test cases for a simple calculator
 */

#include "misc/fixedpoint.h"
#include "gtest/gtest.h"

/**
 * Force the test runner to be dependent on this variable so that this library
 * is linked in.
 */
unsigned int marker_fixedpoint_test = 1;


TEST(FixedpointTest, Parse) {
  int status = -1;
  fixed32_t fixed;

  status = fixedpoint_parse("1", &fixed);
  EXPECT_EQ(status, 0);
  EXPECT_EQ(65536, fixed);


  status = fixedpoint_parse("0.5", &fixed);
  EXPECT_EQ(status, 0);
  EXPECT_EQ(32768, fixed);
}
