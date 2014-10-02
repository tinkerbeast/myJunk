cmake_minimum_required (VERSION 2.6)
project (myJunk)

# == Test dependencies =======================================================

# Dependency on TEST library - pthread
find_package (Threads)

# Dependency on TEST library - GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# == Source modules  =========================================================

include_directories ("${PROJECT_SOURCE_DIR}/src")

add_subdirectory ("${PROJECT_SOURCE_DIR}/src/misc")

# == Testing modules  ========================================================

add_subdirectory ("${PROJECT_SOURCE_DIR}/test/misc")

# == Executable targets ======================================================

add_executable(run_tests tests.cpp)
target_link_libraries(run_tests ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} misc misc_test)
