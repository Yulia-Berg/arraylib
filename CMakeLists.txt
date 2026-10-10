cmake_minimum_required(VERSION 3.16)

project(arraylib VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ---- Динамическая библиотека ----

add_library(arraylib SHARED
    src/arraylib.cpp
)

# Все цели, подключённые к arraylib, получают путь к include/.
target_include_directories(arraylib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# ARRAYLIB_BUILD определяется только при сборке библиотеки.
target_compile_definitions(arraylib
    PRIVATE
        ARRAYLIB_BUILD
)

if (MSVC)
    target_compile_options(arraylib
        PRIVATE
            /W4
    )
else()
    target_compile_options(arraylib
        PRIVATE
            -Wall
            -Wextra
            -Wpedantic
    )
endif()

# ---- Демонстрационная программа ----

add_executable(app
    main.cpp
)

target_link_libraries(app
    PRIVATE
        arraylib
)

# В Linux программа ищет libarraylib.so рядом с собой.
set_target_properties(app PROPERTIES
    BUILD_RPATH "$ORIGIN"
)

# Все результаты помещаются в каталог сборки.
set_target_properties(arraylib app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

# ---- Тесты ----

include(CTest)

if (BUILD_TESTING)
    add_executable(test_unit
        tests/test_unit.cpp
    )

    target_link_libraries(test_unit
        PRIVATE
            arraylib
    )

    target_compile_options(test_unit
        PRIVATE
            -UNDEBUG
    )

    add_test(
        NAME unit
        COMMAND test_unit
    )

    add_executable(test_integration
        tests/test_integration.cpp
    )

    target_link_libraries(test_integration
        PRIVATE
            arraylib
    )

    target_compile_options(test_integration
        PRIVATE
            -UNDEBUG
    )

    add_test(
        NAME integration
        COMMAND test_integration
    )
endif()

# ---- Программа по варианту 4 ----

add_executable(variant_04
    examples/variant_04.cpp
)

target_link_libraries(variant_04
    PRIVATE
        arraylib
)

set_target_properties(variant_04 PROPERTIES
    BUILD_RPATH "$ORIGIN"
)