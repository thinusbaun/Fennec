
find_package(Qt5Core REQUIRED)
find_package(Qt5Test REQUIRED)
set(CMAKE_AUTOMOC ON)

add_executable(TailFileWatchConfigSerializationTest TailFileWatchConfigSerializationTest.cpp)
target_link_libraries(TailFileWatchConfigSerializationTest core Qt5::Core Qt5::Test)

IF(WIN32)
        add_custom_command(TARGET TailFileWatchConfigSerializationTest POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Core> $<TARGET_FILE_DIR:LogRowColorizerConfigSerializationTest>
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Test> $<TARGET_FILE_DIR:LogRowColorizerConfigSerializationTest>
	)
ENDIF()
if(WIN32)
        add_test(TailFileWatchConfigSerializationTest ${CTEST_CONFIGURATION_TYPE}/${CMAKE_BINARY_DIR}/TailFileWatchConfigSerializationTest.exe)
ELSE()
        add_test(TailFileWatchConfigSerializationTest ${CTEST_CONFIGURATION_TYPE}/${CMAKE_BINARY_DIR}/TailFileWatchConfigSerializationTest)
ENDIF()
