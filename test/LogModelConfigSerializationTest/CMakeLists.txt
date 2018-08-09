
find_package(Qt5Core REQUIRED)
find_package(Qt5Test REQUIRED)
set(CMAKE_AUTOMOC ON)

add_executable(LogModelConfigSerializationTest LogModelConfigSerializationTest.cpp)
target_link_libraries(LogModelConfigSerializationTest core Qt5::Core Qt5::Test)

IF(WIN32)
        add_custom_command(TARGET LogModelConfigSerializationTest POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Core> $<TARGET_FILE_DIR:LogModelConfigSerializationTest>
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Test> $<TARGET_FILE_DIR:LogModelConfigSerializationTest>
	)
ENDIF()
if(WIN32)
        add_test(LogModelConfigSerializationTest ${CTEST_CONFIGURATION_TYPE}/${CMAKE_BINARY_DIR}/LogModelConfigSerializationTest.exe)
ELSE()
        add_test(LogModelConfigSerializationTest ${CTEST_CONFIGURATION_TYPE}/${CMAKE_BINARY_DIR}/LogModelConfigSerializationTest)
ENDIF()
