cmake_minimum_required(VERSION 3.10)
project(s21_containers CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Заголовочные файлы
set(LIB_HEADERS 
    include/s21_queue.h
    include/s21_set.h
)

# Библиотека контейнеров (header-only)
add_library(s21_containers INTERFACE)
target_include_directories(s21_containers INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Тесты
find_package(GTest REQUIRED)

set(TEST_SOURCES tests/s21_conteiners_tests.cpp)

add_executable(test_app ${TEST_SOURCES})
target_link_libraries(test_app PRIVATE 
    s21_containers 
    GTest::GTest 
    GTest::Main
)

enable_testing()
add_test(NAME containers_tests COMMAND test_app)