
find_package(Qt5Core 5.9 REQUIRED)
find_package(Qt5Test 5.9 REQUIRED)
set(CMAKE_AUTOMOC ON)

add_executable(LogRowColorizerConfigSerializationTest LogRowColorizerConfigSerializationTest.cpp)
target_link_libraries(LogRowColorizerConfigSerializationTest core Qt5::Core Qt5::Test)

IF(WIN32)
	add_custom_command(TARGET LogRowColorizerConfigSerializationTest POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Core> $<TARGET_FILE_DIR:LogRowColorizerConfigSerializationTest>
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Test> $<TARGET_FILE_DIR:LogRowColorizerConfigSerializationTest>
	)
ENDIF()
if(WIN32)
	add_test(LogRowColorizerConfigSerializationTest ${CTEST_CONFIGURATION_TYPE}/${CMAKE_BINARY_DIR}/LogRowColorizerConfigSerializationTest.exe)
ELSE()
	add_test(LogRowColorizerConfigSerializationTest ${CTEST_CONFIGURATION_TYPE}/${CMAKE_BINARY_DIR}/LogRowColorizerConfigSerializationTest)
ENDIF()
