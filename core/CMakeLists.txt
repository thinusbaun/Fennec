project (libCore_project)

set(CMAKE_AUTOMOC ON)
find_package(Qt5Widgets)

file (GLOB_RECURSE source *.cpp)
file (GLOB_RECURSE include_files *.h)

add_library(core SHARED ${source})

target_include_directories(core INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(core Qt5::Widgets)

install(TARGETS core DESTINATION lib)
install(FILES ${include_files} DESTINATION include)
