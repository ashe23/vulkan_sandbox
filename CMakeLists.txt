cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

set(project_name "vulkan_sandbox")

project(${project_name} VERSION 0.1.0 LANGUAGES CXX)

# cpp standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# vulkan
find_package(Vulkan)
if (NOT ${Vulkan_INCLUDE_DIRS} STREQUAL "")
    set(VULKAN_PATH ${Vulkan_INCLUDE_DIRS})
    STRING(REGEX REPLACE "/Include" "" VULKAN_PATH ${VULKAN_PATH})
endif()
        
if(NOT Vulkan_FOUND)
    # CMake may fail to locate the libraries but could be able to 
    # provide some path in Vulkan SDK include directory variable
    # 'Vulkan_INCLUDE_DIRS', try to extract path from this.
    message(STATUS "Failed to locate Vulkan SDK, retrying again...")
    if(EXISTS "${VULKAN_PATH}")
        message(STATUS "Successfully located the Vulkan SDK: ${VULKAN_PATH}")
    else()
        message(STATUS "Failed to locate Vulkan SDK.Aborting")
        return()
    endif()
endif()

set(VULKAN_LIB_LIST "vulkan-1")

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	# Include Vulkan header files from Vulkan SDK
	include_directories(AFTER ${VULKAN_PATH}/Include)

	# Link directory for vulkan-1
	link_directories(${VULKAN_PATH}/Bin;${VULKAN_PATH}/Lib;)
endif()

add_subdirectory(external)

add_executable(${project_name} "src/main.cpp")
target_link_libraries(${project_name} ${VULKAN_LIB_LIST} glfw)