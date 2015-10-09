cmake_minimum_required(VERSION 2.8.4)
project(Assassin-sGreedV)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -O3 -Wno-deprecated-declarations")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g3 -ggdb -O0")

option(test "Build all tests." OFF)

IF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
            "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")        
    SET(warnings "-Wall -Wextra -Werror")
ENDIF ()

IF(NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE DEBUG)
ENDIF(NOT CMAKE_BUILD_TYPE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin/")


ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(test)

if (test)
  # This adds another subdirectory, which has 'project(gtest)'.
  add_subdirectory(test/gtest-1.7.0)

  enable_testing()

  # Include the gtest library. gtest_SOURCE_DIR is available due to
  # 'project(gtest)' above.
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

  ##############
  # Unit Tests
  ##############

  file(GLOB test_SRC
          "test/*.h"
          "test/*.cc"
  )
  add_executable(unitTests ${test_SRC})

  # Standard linking to gtest stuff.
  target_link_libraries(unitTests gtest gtest_main index common gumbo)

  # Extra linking for the project.
  # target_link_libraries(test)

  # This is so you can do 'make test' to see all your tests run, instead of
  # manually running the executable runUnitTests to see those specific tests.

  # You can also omit NAME and COMMAND. The second argument could be some other
  # test executable.
  add_test(GraphTest unitTests)
endif()


