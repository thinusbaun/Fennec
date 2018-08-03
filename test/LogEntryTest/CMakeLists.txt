
find_package(Qt5Core REQUIRED)
find_package(Qt5Test REQUIRED)
set(CMAKE_AUTOMOC ON)

add_executable(LogEntryTest LogEntryTest.cpp)
target_link_libraries(LogEntryTest core Qt5::Core Qt5::Test)

IF(WIN32)
	add_custom_command(TARGET LogEntryTest POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Core> $<TARGET_FILE_DIR:LogEntryTest>
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Test> $<TARGET_FILE_DIR:LogEntryTest>
	)
ENDIF()
if(WIN32)
	add_test(LogEntryTest ${CTEST_CONFIGURATION_TYPE}/${CMAKE_BINARY_DIR}/LogEntryTest.exe)
ELSE()
	add_test(LogEntryTest ${CTEST_CONFIGURATION_TYPE}/${CMAKE_BINARY_DIR}/LogEntryTest)
ENDIF()
