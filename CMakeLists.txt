project( Project_05_glfw )

message( "Configuring main application - ${PROJECT_NAME} : " )

# Enable C++11 / C++14 / C++17 / C++20
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_BUILD_TYPE Release )

link_libraries(glfw)

include_directories("${GLFW_SOURCE_DIR}/deps")

if (MATH_LIBRARY)
	message(${MATH_LIBRARY})
    link_libraries("${MATH_LIBRARY}")
endif()

# Workaround for the MS CRT deprecating parts of the standard library
if (MSVC OR CMAKE_C_SIMULATE_ID STREQUAL "MSVC")
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

if (WIN32)
    set(ICON ../glfw.rc)
elseif (APPLE)
    set(ICON ../glfw.icns)
endif()

set(GLAD_GL "${GLFW_SOURCE_DIR}/deps/glad/gl.h")
set(GLAD_GLES2 "${GLFW_SOURCE_DIR}/deps/glad/gles2.h")
set(GETOPT "${GLFW_SOURCE_DIR}/deps/getopt.h"
           "${GLFW_SOURCE_DIR}/deps/getopt.c")
set(TINYCTHREAD "${GLFW_SOURCE_DIR}/deps/tinycthread.h"
                "${GLFW_SOURCE_DIR}/deps/tinycthread.c")

# OpenGL
find_package(OpenGL REQUIRED)


file(GLOB SOURCES "*.cpp" ${DEPENDENCY_DIR}/include/glad/glad/glad.c )
file(GLOB HEADERS "*.h" "*.txt" "*.rst" "*.md" )
file(GLOB SHADERS "*.vert" "*.frag" "*.vs" "*.fs" )

add_executable(
 ${PROJECT_NAME} WIN32 MACOSX_BUNDLE  
 ${HEADERS} ${SOURCES} ${SHADERS}
 ${ICON} ${GLAD_GL}   )

message( "\nBuild mode test is: ${CMAKE_BUILD_TYPE}" )

set(GUI_ONLY_BINARIES  ${PROJECT_NAME})

message( "\nBuild C++ standard is: ${CMAKE_CXX_STANDARD}" ) 

SET(SUBSYSTEM_LINK_FLAGS "-mconsole -mwindows")

target_link_libraries(  ${PROJECT_NAME} 
                        ${SUBSYSTEM_LINK_FLAGS}
                        )

