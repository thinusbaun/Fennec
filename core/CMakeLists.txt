project (libCore_project)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
find_package(Qt5Widgets)
find_package(Qt5Svg)
find_package(Git)

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


if (GIT_FOUND)
	execute_process(
		COMMAND git rev-parse --abbrev-ref HEAD
		WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
		OUTPUT_VARIABLE GIT_BRANCH
		OUTPUT_STRIP_TRAILING_WHITESPACE
	)
	execute_process (
		COMMAND git rev-list --count remotes/origin/master..
		WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
		OUTPUT_VARIABLE GIT_COMMIT_NUMBER
		OUTPUT_STRIP_TRAILING_WHITESPACE
	)
	else()
		set(GIT_BRANCH "UNKNOWN")
		set(GIT_COMMIT_NUMBER "UNKNOWN")
	endif()

configure_file(version.h.in "${PROJECT_BINARY_DIR}/version.h" @ONLY)

install(TARGETS core DESTINATION lib)
install(FILES ${include_files} DESTINATION include)
