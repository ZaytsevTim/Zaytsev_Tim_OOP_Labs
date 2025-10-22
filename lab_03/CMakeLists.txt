cmake_minimum_required(VERSION 3.10)
project(lab_03)

add_library(${CMAKE_PROJECT_NAME}_1lib src/Figure.cpp)
add_library(${CMAKE_PROJECT_NAME}_2lib src/Rectangle.cpp)
add_library(${CMAKE_PROJECT_NAME}_3lib src/Square.cpp)
add_library(${CMAKE_PROJECT_NAME}_4lib src/Trapezoid.cpp)

add_executable(${CMAKE_PROJECT_NAME}_exe main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME}_exe ${CMAKE_PROJECT_NAME}_1lib)
target_link_libraries(${CMAKE_PROJECT_NAME}_exe ${CMAKE_PROJECT_NAME}_2lib)
target_link_libraries(${CMAKE_PROJECT_NAME}_exe ${CMAKE_PROJECT_NAME}_3lib)
target_link_libraries(${CMAKE_PROJECT_NAME}_exe ${CMAKE_PROJECT_NAME}_4lib)

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

add_executable(tests test/tests03.cpp)
target_link_libraries(tests ${CMAKE_PROJECT_NAME}_1lib gtest_main)
target_link_libraries(tests ${CMAKE_PROJECT_NAME}_2lib gtest_main)
target_link_libraries(tests ${CMAKE_PROJECT_NAME}_3lib gtest_main)
target_link_libraries(tests ${CMAKE_PROJECT_NAME}_4lib gtest_main)

# Добавление тестов в тестовый набор
add_test(NAME MyProjectTests COMMAND tests)