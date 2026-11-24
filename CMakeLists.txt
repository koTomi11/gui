cmake_minimum_required(VERSION 3.14)
project(gui VERSION 1.0 LANGUAGES CXX)

include(cmake/Functions.cmake)

add_library(Gui STATIC
    src/Gui.cpp
	src/Gui.h
)

add_executable(Test tests/main.cpp)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

load_external_lib(
    NAME      glfw3
    TARGET    Test
    LINK_NAME glfw
    GIT_REPO  https://github.com/glfw/glfw.git
    GIT_TAG   3.5.1
)

# 2. GLAD 2 letöltése (a linkelést még nem itt csináljuk, mert előbb generálni kell)
load_external_lib(
    NAME      glad
    TARGET    Test
    LINK_NAME glad
    GIT_REPO https://github.com/dav1dde/glad.git
    GIT_TAG   master
)

# GLAD C könyvtár legenerálása a kívánt OpenGL verzióhoz (pl. 4.6 Core vagy 3.3 Core)


# GLAD és a rendszer OpenGL könyvtárának linkelése
find_package(OpenGL REQUIRED)
target_link_libraries(Test PRIVATE glad )