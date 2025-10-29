cmake_minimum_required(VERSION 3.15)
project(csi2372_week6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

# --- Task 1: stats ---
add_library(stats src/stats.cpp)
target_include_directories(stats PUBLIC include)

add_executable(stats_tests tests/test_stats.cpp)
target_link_libraries(stats_tests PRIVATE stats)
add_test(NAME stats_tests COMMAND $<TARGET_FILE:stats_tests>)

# --- Task 2: Result ---
add_library(Result src/Result.cpp)
target_include_directories(Result PUBLIC include)

add_executable(Result_tests tests/test_Result.cpp)
target_link_libraries(Result_tests PRIVATE Result)
add_test(NAME Result_tests COMMAND $<TARGET_FILE:Result_tests>)

# --- Task 3: text_utils ---
add_library(text_utils src/text_utils.cpp)
target_include_directories(text_utils PUBLIC include)

add_executable(text_utils_tests tests/test_text_utils.cpp)
target_link_libraries(text_utils_tests PRIVATE text_utils)
add_test(NAME text_utils_tests COMMAND $<TARGET_FILE:text_utils_tests>)

# --- Task 4: Evaluator_Library ---
add_library(Evaluator_Library src/Evaluator_Library.cpp)
target_include_directories(Evaluator_Library PUBLIC include)

add_executable(Evaluator_Library_tests tests/test_Evaluator_Library.cpp)
target_link_libraries(Evaluator_Library_tests PRIVATE Evaluator_Library)
add_test(NAME Evaluator_Library_tests COMMAND $<TARGET_FILE:Evaluator_Library_tests>)
