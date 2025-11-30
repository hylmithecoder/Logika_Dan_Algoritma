cmake_minimum_required(VERSION 4.0)
project(LogikaAndAlgoritma)

set(CMAKE_CXX_STANDARD 26)

file(GLOB_RECURSE SOURCE_CODE src/scripts/*.cpp)

set(OpenGL_GL_PREFERENCE "GLVND")
find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(nlohmann_json REQUIRED)
pkg_check_modules(MUPDF REQUIRED mupdf)

include_directories(
    src/headers
    vendor/imgui
    opengl32
    glfw3
    /usr/include/GLFW
)

link_libraries(
    glfw
    OpenGL::GL
    mupdf
    freetype
    harfbuzz
    jpeg
    jbig2dec
    z
    nlohmann_json::nlohmann_json
)

file(GLOB_RECURSE Vendor vendor/imgui/*.cpp vendor/imgui/backends/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_CODE} ${Vendor})