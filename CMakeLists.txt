cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(gui)

include(cmake/Functions.cmake)

add_library(Gui STATIC
    src/Gui.cpp
	src/Gui.h
)

add_executable(Test tests/main.cpp tests/Render.h tests/Render.cpp)

set(STB_IMAGE_DIR "${CMAKE_BINARY_DIR}/external/stb")

# Ha még nem létezik a fájl, a CMake letölti közvetlenül a GitHubról
if(NOT EXISTS "${STB_IMAGE_DIR}/stb_image.h")
    message(STATUS "stb_image.h letöltése a GitHubról...")
    file(DOWNLOAD 
        "raw.githubusercontent.com/nothings/stb/refs/heads/master/stb_image.h"
        "${STB_IMAGE_DIR}/stb_image.h"
        SHOW_PROGRESS
    )
endif()

if(NOT EXISTS "${STB_IMAGE_DIR}/stb_truetype.h")
    message(STATUS "stb_truetype.h letöltése a GitHubról...")
    file(DOWNLOAD 
        "https://raw.githubusercontent.com/nothings/stb/refs/heads/master/stb_truetype.h"
        "${STB_IMAGE_DIR}/stb_truetype.h"
        SHOW_PROGRESS
    )
endif()

 target_include_directories(Test PRIVATE ${STB_IMAGE_DIR})
 target_include_directories(Test PRIVATE includes)
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


load_external_lib(
    NAME      glm
    TARGET    Test
    LINK_NAME glm
    GIT_REPO https://github.com/g-truc/glm.git
    GIT_TAG   master
)




# GLAD C könyvtár legenerálása a kívánt OpenGL verzióhoz (pl. 4.6 Core vagy 3.3 Core)


# GLAD és a rendszer OpenGL könyvtárának linkelése
find_package(OpenGL REQUIRED)
target_link_libraries(Test PRIVATE glad )