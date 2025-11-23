cmake_minimum_required(VERSION 3.10)
project(cppTesting2)

set(CMAKE_CXX_STANDARD 23)

file(GLOB IMGUI_SOURCES imgui/*.cpp)
file(GLOB IMGUI_BACKEND_SOURCES imgui/backends/*.cpp)

add_executable(cppTesting2
        main.cpp
        ${IMGUI_SOURCES}
        ${IMGUI_BACKEND_SOURCES}
)

# Include directories
target_include_directories(cppTesting2 PRIVATE
        imgui
        imgui/backends
)

# Link libraries
target_link_libraries(cppTesting2
        glfw
        GL
        dl
        pthread
)