cmake_minimum_required(VERSION 3.20)
project(trpo)

# Указываем C++ стандарт
set(CMAKE_CXX_STANDARD 14)

# Добавляем исполняемый файл и файл с тестами
add_executable(trpo main.cpp test.cpp)

# Добавляем папку с исходными файлами Google Test
add_subdirectory(googletest-main)

# Включаем заголовочные файлы Google Test
include_directories(googletest-main/googletest/include)

# Создаем исполняемый файл для тестов
add_executable(ComplexTests test.cpp) # Замените test1.cpp и test2.cpp на ваши файлы с тестами

# Линкуем с Google Test
target_link_libraries(ComplexTests gtest gtest_main)
