cmake_minimum_required(VERSION 3.22.1)

project(imguimenu)


add_executable(imguimenu
        # Add ImGui
        imgui/imgui_demo.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_tables.cpp
        imgui/imgui_widgets.cpp
        imgui/imgui.cpp
        #Add ImGui Backends (GLFW3 + OpenGL 3)
        imgui/backends/imgui_impl_glfw.cpp
        imgui/backends/imgui_impl_opengl3.cpp
        #MAIN FILE
        main.cpp
    )

find_package(OpenGL REQUIRED) # Find OpenGL
find_package(glfw3 REQUIRED) # Find GLFW3

target_link_libraries(imguimenu OpenGL::GL glfw)