project (FennecApp)

add_executable(FennecApp main.cpp)
target_link_libraries(FennecApp core)

install (TARGETS FennecApp DESTINATION bin)
