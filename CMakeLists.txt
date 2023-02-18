cmake_minimum_required(VERSION 3.22.1)
project(imguimenu)


add_executable(imguimenu main.cpp imgui-glfw-opengl3/imgui_demo.cpp imgui-glfw-opengl3/imgui_draw.cpp imgui-glfw-opengl3/imgui_tables.cpp imgui-glfw-opengl3/imgui_widgets.cpp imgui-glfw-opengl3/imgui.cpp imgui-glfw-opengl3/backends/imgui_impl_glfw.cpp imgui-glfw-opengl3/backends/imgui_impl_opengl3.cpp)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(imguimenu ${OPENGL_LIBRARIES} glfw)