cmake_minimum_required(VERSION 4.0)
project(LogikaAndAlgoritma)

set(CMAKE_CXX_STANDARD 26)

set(SOURCE_CODE
    src/scripts/main.cpp
    src/scripts/samplelogic.cpp
    src/headers/samplelogic.hpp
    src/scripts/algoritmabensin.cpp
    src/headers/algoritmabensin.hpp
    src/scripts/HandleWindow.cpp
    src/headers/HandleWindow.hpp
)


set(OpenGL_GL_PREFERENCE "GLVND")
find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
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
)

set(Vendor
    vendor/imgui/imgui.cpp
    vendor/imgui/imgui_demo.cpp
    vendor/imgui/imgui_draw.cpp
    vendor/imgui/imgui_tables.cpp
    vendor/imgui/imgui_widgets.cpp
    vendor/imgui/backends/imgui_impl_glfw.cpp
    vendor/imgui/backends/imgui_impl_opengl3.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_CODE} ${Vendor})