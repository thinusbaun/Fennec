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

install (TARGETS FennecApp DESTINATION bin)
