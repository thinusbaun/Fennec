
find_package(Qt5Core 5.9 REQUIRED)
find_package(Qt5Test 5.9 REQUIRED)
set(CMAKE_AUTOMOC ON)

add_executable(IdentifiableObjectSerializationTest IdentifiableObjectSerializationTest.cpp)
target_link_libraries(IdentifiableObjectSerializationTest core Qt5::Core Qt5::Test)

IF(WIN32)
	add_custom_command(TARGET IdentifiableObjectSerializationTest POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Core> $<TARGET_FILE_DIR:IdentifiableObjectSerializationTest>
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Test> $<TARGET_FILE_DIR:IdentifiableObjectSerializationTest>
	)
ENDIF()
if(WIN32)
	add_test(IdentifiableObjectSerializationTest ${CTEST_CONFIGURATION_TYPE}/${CMAKE_BINARY_DIR}/IdentifiableObjectSerializationTest.exe)
ELSE()
	add_test(IdentifiableObjectSerializationTest ${CTEST_CONFIGURATION_TYPE}/${CMAKE_BINARY_DIR}/IdentifiableObjectSerializationTest)
ENDIF()
