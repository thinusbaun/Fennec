project (FennecApp)

find_package(Qt5Core)
set(CMAKE_AUTORCC ON)

QT5_ADD_RESOURCES(RESOURCES res/app.qrc)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

add_executable(FennecApp
	main.cpp
	${RESOURCES}
	res/app.rc)

target_link_libraries(FennecApp core)

add_custom_command(TARGET FennecApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Core> $<TARGET_FILE_DIR:FennecApp>
    )

install (TARGETS FennecApp DESTINATION bin)
