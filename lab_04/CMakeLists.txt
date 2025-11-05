cmake_minimum_required(VERSION 3.10)
project(lab_04)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add_library(${CMAKE_PROJECT_NAME}_1 include/foo.h)


add_executable(${CMAKE_PROJECT_NAME}_exe main.cpp)

# target_link_libraries(${CMAKE_PROJECT_NAME}_exe ${CMAKE_PROJECT_NAME}_1)


# Установка Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.0
  TLS_VERIFY false
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Добавление тестов
enable_testing()

add_executable(tests test/tests04.cpp)
target_link_libraries(tests gtest_main)


# Добавление тестов в тестовый набор
add_test(NAME MyProjectTests COMMAND tests)