cmake_minimum_required(VERSION 3.2)

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)
add_executable(test_print_ip test_print_ip.cpp)

# включаем 14 стандарт для наших целей
set_target_properties(test_print_ip PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

# подключим инклуды из основного каталога проекта
target_include_directories(test_print_ip
    PRIVATE "${PROJECT_SOURCE_DIR}/src"
)

target_include_directories(test_print_ip
    PRIVATE ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(test_print_ip
    CONAN_PKG::gtest
    Threads::Threads
)

# максимально строгие настройки компилятора
if (MSVC)
    target_compile_options(test_print_ip PRIVATE
        /W4
    )
else ()
    target_compile_options(test_print_ip PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

add_test(test_print_ip test_print_ip)
