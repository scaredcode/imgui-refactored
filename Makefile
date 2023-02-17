IMGUI= imgui-glfw-opengl3/imgui_demo.cpp imgui-glfw-opengl3/imgui_draw.cpp imgui-glfw-opengl3/imgui_tables.cpp imgui-glfw-opengl3/imgui_widgets.cpp imgui-glfw-opengl3/imgui.cpp imgui-glfw-opengl3/backends/imgui_impl_glfw.cpp imgui-glfw-opengl3/backends/imgui_impl_opengl3.cpp
SRC= main.cpp
CXX=clang++
CXX_FLAGS= -lGL -lglfw -o build/imguimenu

all:
	$(CXX) $(IMGUI) $(SRC) $(CXX_FLAGS)

run:
	build/imguimenu