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
 * All unit tests are invoked from here
 */
#include <iostream>
#include "gtest/gtest.h"


/**
 * Force dependencies to include the test libraries. GoogleTest will pass
 * unconditionally unless libraries are not linked to.
 */
extern unsigned int marker_singly_linked_list;


GTEST_API_ int main(int argc, char **argv) {
  std::cout << "Following submdules are linked for testing:" << std::endl;
  std::cout << "===========================================" << std::endl;
  std::cout << "marker_singly_linked_list:"
    << marker_singly_linked_list << std::endl;


  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
