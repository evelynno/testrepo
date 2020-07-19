cmake_minimum_required(VERSION 3.10)
PROJECT( testing_test
  VERSION "1.0" )

enable_testing()
find_package(GTest REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(rapidcheck REQUIRED)
#find_package(rapidcheck_gtest REQUIRED)

# Add a find_package here for rapid check
pkg_check_modules(gtest REQUIRED gtest>=1.8.1)
pkg_check_modules(gmock REQUIRED gmock>=1.8.1)


# You may need to add include directories for rapid check
include_directories( include
${rapidcheck_INCLUDE_DIRS} )

# message(${rapidcheck_INCLUDE_DIRS})

add_library(testing_test SHARED
  src/main.cpp)

add_executable( tests
  test/gtest.cpp)

# You probably will have to link the their library too.
target_link_libraries(tests
  testing_test
  ${gtest_LIBRARIES}
  ${gmock_LIBRARIES}
  ${rapidcheck_LIBRARIES}
  rapidcheck_gtest
)

# gtest_add_tests(TARGET tests)
add_test(NAME check COMMAND tests)
