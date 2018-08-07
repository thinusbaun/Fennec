
find_package(Qt5Core REQUIRED)
find_package(Qt5Test REQUIRED)
set(CMAKE_AUTOMOC ON)

add_executable(SettingsProviderTest SettingsProviderTest.cpp)
target_link_libraries(SettingsProviderTest core Qt5::Core Qt5::Test)

IF(WIN32)
	add_custom_command(TARGET SettingsProviderTest POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Core> $<TARGET_FILE_DIR:SettingsProviderTest>
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Test> $<TARGET_FILE_DIR:SettingsProviderTest>
	)
ENDIF()

IF(WIN32)
	add_test(SettingsProviderTest ${CTEST_CONFIGURATION_TYPE}/${CMAKE_BINARY_DIR}/SettingsProviderTest.exe)
ELSE()
	add_test(SettingsProviderTest ${CTEST_CONFIGURATION_TYPE}/${CMAKE_BINARY_DIR}/SettingsProviderTest)
ENDIF()
