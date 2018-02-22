
find_package(Qt5Core REQUIRED)
find_package(Qt5Test REQUIRED)
set(CMAKE_AUTOMOC ON)

add_executable(LogModelTest LogModelTest.cpp)
target_link_libraries(LogModelTest core Qt5::Core Qt5::Test)

IF(WIN32)
	add_custom_command(TARGET LogModelTest POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Core> $<TARGET_FILE_DIR:LogModelTest>
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Test> $<TARGET_FILE_DIR:LogModelTest>
	)
ENDIF()

add_test(LogModelTest ${CTEST_CONFIGURATION_TYPE}/${CMAKE_BINARY_DIR}/LogModelTest.exe)