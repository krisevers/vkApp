cmake_minimum_required(VERSION 3.10)

# Project name
project(vkApp)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Compiler flags
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG")

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/core)
include_directories(${CMAKE_SOURCE_DIR}/src/core/vulkan)
include_directories(${CMAKE_SOURCE_DIR}/src/core/renderer)
include_directories(/usr/include/stb)
include_directories(/usr/include)

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

# Source files
file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp 
                            ${CMAKE_SOURCE_DIR}/src/core/*.cpp 
                            ${CMAKE_SOURCE_DIR}/src/core/vulkan/*.cpp 
                            ${CMAKE_SOURCE_DIR}/src/core/renderer/*.cpp)

# Executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Libraries
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan glfw dl pthread) 

# Build types
set(CMAKE_BUILD_TYPE Release)

# # Custom targets
# add_custom_target(test
#     COMMAND ${PROJECT_NAME}
#     DEPENDS ${PROJECT_NAME}
#     WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
# )

# add_custom_target(clean
#     COMMAND ${CMAKE_COMMAND} -E remove ${PROJECT_NAME}
# )