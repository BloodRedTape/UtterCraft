cmake_minimum_required(VERSION 3.10)

project(UtterCraft)

add_subdirectory(StraitXPackages/Base)
add_subdirectory(StraitXPackages/ImGui)

set(UTTERCRAFT_SOURCES
    sources/main.cpp
    sources/foundation/application.cpp
)

set(UTTERCRAFT_INCLUDE
    sources/
)

add_executable(UtterCraft ${UTTERCRAFT_SOURCES})
target_link_libraries(UtterCraft StraitXBase StraitXImGui)
target_include_directories(UtterCraft 
    PUBLIC ${UTTERCRAFT_INCLUDE}
)