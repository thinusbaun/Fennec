cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(Fennec VERSION 0.1 LANGUAGES C CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/clang-cxx-dev-tools.cmake)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(app)
add_subdirectory(core)
enable_testing()
add_subdirectory(test/LogEntryTest)
add_subdirectory(test/LogModelTest)
add_subdirectory(test/RegexLogParserTest)

add_subdirectory(test/LogRowColorizerConfigSerializationTest)
add_subdirectory(test/RegexLogParserConfigSerializationTest)
add_subdirectory(test/TailFileWatchConfigSerializationTest)
