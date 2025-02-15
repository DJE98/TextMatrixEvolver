cmake_minimum_required(VERSION 3.10)
project(TEXTMATRIXEVOVER C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

# Enable warnings
add_compile_options(-Wall -Wextra)

include_directories(${CMAKE_SOURCE_DIR}/dep/Unity/src)

# Enable sanitizers
#add_compile_options(-fsanitize=address -fsanitize=undefined)

set(SOURCE_FILES
    population.c
    evaluation.c
    mutation.c
    recombination.c
    selection.c
    main.c
)
set(TEST_SOURCES tests/population.c)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
add_executable(tests ${TEST_SOURCES} ${SOURCE_FILES})
target_link_libraries(tests Unity)
add_test(NAME tests COMMAND tests)