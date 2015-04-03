cmake_minimum_required (VERSION 2.6)
project (myJunk)

# Warning: TODO make it GCC unspecific, and file specific
set(CMAKE_C_FLAGS "-std=c99")
#SET(CMAKE_EXE_LINKER_FLAGS "-Wl,--whole-archive")

# == Source dependencies =====================================================

# Library pthread
find_package (Threads)

# == Test dependencies =======================================================

#  Library GTest
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})
add_subdirectory("${PROJECT_SOURCE_DIR}/lib/com.googlecode.googletest" EXCLUDE_FROM_ALL)

include_directories ("${PROJECT_SOURCE_DIR}/lib/com.googlecode.googletest/include")

# == Source modules  =========================================================

include_directories ("${PROJECT_SOURCE_DIR}/src")

add_subdirectory ("${PROJECT_SOURCE_DIR}/src/misc") # misc
add_subdirectory ("${PROJECT_SOURCE_DIR}/src/cppds") # cppds

# == Testing modules  ========================================================

add_custom_target(alltest)

macro(add_gtest test_target test_runner src_targets)
  add_custom_target(${test_target}_runtest
      COMMAND ${test_target}_run #cmake 2.6 required
      DEPENDS ${test_target} ${test_runner} ${src_targets}
      WORKING_DIRECTORY "${CMAKE_BINARY_DIR}")

  add_executable(${test_target}_run  EXCLUDE_FROM_ALL ${test_runner})
  target_link_libraries(${test_target}_run gtest gtest_main ${CMAKE_THREAD_LIBS_INIT} ${test_target} ${src_targets})

  add_dependencies(alltest ${test_target}_runtest)
endmacro()



add_subdirectory ("${PROJECT_SOURCE_DIR}/test/misc" EXCLUDE_FROM_ALL) # misc_test
add_gtest(misc_test "${PROJECT_SOURCE_DIR}/test/misc/main.cpp" misc)

add_subdirectory ("${PROJECT_SOURCE_DIR}/test/cppds" EXCLUDE_FROM_ALL) # cppds_test
add_gtest(cppds_test "${PROJECT_SOURCE_DIR}/test/cppds/main.cpp" cppds)

