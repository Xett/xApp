# CMakeList.txt : CMake project for xApp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("xApp")

find_package( OpenGL REQUIRED )

set( GLEW_DIR ${PROJECT_SOURCE_DIR}/GLEW/build/cmake )
set( GLEW_INCLUDE ${PROJECT_SOURCE_DIR}/GLEW/include )
set( GLFW_DIR ${PROJECT_SOURCE_DIR}/GLFW )
set( XEVENTSYSTEM_DIR ${PROJECT_SOURCE_DIR}/xEventSystem )

set( GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE )
set( GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE )
set( GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE )
set( GLFW_BUILD_INSTALL OFF CACHE BOOL "" FORCE )

add_subdirectory( ${GLEW_DIR} )
add_subdirectory( ${GLFW_DIR} )
add_subdirectory( ${XEVENTSYSTEM_DIR} )

# Add source to this project's executable.
add_library (xApp STATIC "Application.h" "Application.cpp"  "Window.h" "Window.cpp" "WindowResizeEvent.h" "WindowResizeEventDispatcher.h" "WindowResizeEventDispatcher.cpp" )
add_executable ( xApp_demo "xApp_demo.cpp" )
target_include_directories(xApp PRIVATE ${GLEW_INCLUDE} ${GLFW_DIR}/include )
target_include_directories(xApp_demo PRIVATE ${GLEW_INCLUDE} ${GLFW_DIR}/include )
target_link_libraries( xApp xEventSystem glew_s glfw ${GLFW_LIBRARIES} )
target_link_libraries( xApp_demo xApp glew_s glfw ${GLFW_LIBRARIES} )

# TODO: Add tests and install targets if needed.
