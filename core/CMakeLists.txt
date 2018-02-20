project (libCore_project)

set(CMAKE_AUTOMOC ON)
find_package(Qt5Widgets)

file (GLOB_RECURSE source *.cpp)
file (GLOB_RECURSE include_files *.h)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(core SHARED ${source})

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(core Qt5::Widgets)

add_custom_command(TARGET core POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Core> $<TARGET_FILE_DIR:core>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Gui> $<TARGET_FILE_DIR:core>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Widgets> $<TARGET_FILE_DIR:core>
    )

install(TARGETS core DESTINATION lib)
install(FILES ${include_files} DESTINATION include)
