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
 * @brief Test cases for a new synchronisation idiom.
 */

#include "misc/sync.h"
#include "gtest/gtest.h"

/**
 * Force the test runner to be dependent on this variable so that this library
 * is linked in.
 */
unsigned int marker_sync_test = 1;

namespace {


class SyncTest : public ::testing::Test {
 protected:
  
  SyncTest() {
    incdec_ = NULL;
  }

  virtual void SetUp() {
    incdec_ = (int*)malloc(sizeof(int));
    ASSERT_TRUE(incdec_ != NULL);
  }

  virtual void TearDown() {
    free(incdec_);
  }
  
  int * incdec_;
};


TEST_F(SyncTest, IncrementDecrement) {
  *incdec_ = 100;
  ASSERT_EQ(0, sync_incdec(incdec_, 10000, 5000));
  EXPECT_EQ(5100, *incdec_);
}

}  // namespace


