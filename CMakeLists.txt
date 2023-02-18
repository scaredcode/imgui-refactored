cmake_minimum_required(VERSION 3.22.1)
project(imguimenu)


add_executable(imguimenu main.cpp imgui-special/imgui_demo.cpp imgui-special/imgui_draw.cpp imgui-special/imgui_tables.cpp imgui-special/imgui_widgets.cpp imgui-special/imgui.cpp imgui-special/backends/imgui_impl_sdl2.cpp imgui-special/backends/imgui_impl_opengl3.cpp)

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
include_directories(imguimenu ${SDL2_INCLUDE_DIRS})

target_link_libraries(imguimenu ${OPENGL_LIBRARIES} ${SDL2_LIBRARIES})
