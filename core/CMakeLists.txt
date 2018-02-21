project (libCore_project)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
find_package(Qt5Widgets)
find_package(Qt5Svg)

file (GLOB_RECURSE source *.cpp)
file (GLOB_RECURSE include_files *.h)

add_library(core SHARED ${source})
include(GenerateExportHeader)
generate_export_header(core)

target_include_directories(
    core PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)

target_link_libraries(core Qt5::Widgets)

add_custom_command(TARGET core POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Core> $<TARGET_FILE_DIR:core>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Gui> $<TARGET_FILE_DIR:core>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Widgets> $<TARGET_FILE_DIR:core>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Svg> $<TARGET_FILE_DIR:core>
    )

install(TARGETS core DESTINATION lib)
install(FILES ${include_files} DESTINATION include)
