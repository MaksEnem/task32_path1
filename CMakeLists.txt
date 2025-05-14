
cmake_minimum_required (VERSION 3.8)

project ("task1")

set(JSON_BuildTests OFF CACHE INTERNAL "")


add_subdirectory(nlohmann_json)
add_executable (task1 "task1.cpp" "task1.h")

target_link_libraries(task1 PRIVATE nlohmann_json::nlohmann_json)

