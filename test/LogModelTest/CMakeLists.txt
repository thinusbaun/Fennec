
find_package(Qt5Core 5.9 REQUIRED)
find_package(Qt5Test 5.9 REQUIRED)
set(CMAKE_AUTOMOC ON)

add_executable(LogModelTest LogModelTest.cpp)
target_link_libraries(LogModelTest core Qt5::Core Qt5::Test)

IF(WIN32)
	add_custom_command(TARGET LogModelTest POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Core> $<TARGET_FILE_DIR:LogModelTest>
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Test> $<TARGET_FILE_DIR:LogModelTest>
	)
ENDIF()

IF(WIN32)
	add_test(LogModelTest ${CTEST_CONFIGURATION_TYPE}/${CMAKE_BINARY_DIR}/LogModelTest.exe)
ELSE()
	add_test(LogModelTest ${CTEST_CONFIGURATION_TYPE}/${CMAKE_BINARY_DIR}/LogModelTest)
ENDIF()
