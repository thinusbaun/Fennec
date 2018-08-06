
find_package(Qt5Core REQUIRED)
find_package(Qt5Test REQUIRED)
set(CMAKE_AUTOMOC ON)

add_executable(RegexLogParserConfigSerializationTest RegexLogParserConfigSerializationTest.cpp)
target_link_libraries(RegexLogParserConfigSerializationTest core Qt5::Core Qt5::Test)

IF(WIN32)
        add_custom_command(TARGET RegexLogParserConfigSerializationTest POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Core> $<TARGET_FILE_DIR:LogRowColorizerConfigSerializationTest>
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Test> $<TARGET_FILE_DIR:LogRowColorizerConfigSerializationTest>
	)
ENDIF()
if(WIN32)
        add_test(RegexLogParserConfigSerializationTest ${CTEST_CONFIGURATION_TYPE}/${CMAKE_BINARY_DIR}/RegexLogParserConfigSerializationTest.exe)
ELSE()
        add_test(RegexLogParserConfigSerializationTest ${CTEST_CONFIGURATION_TYPE}/${CMAKE_BINARY_DIR}/RegexLogParserConfigSerializationTest)
ENDIF()
