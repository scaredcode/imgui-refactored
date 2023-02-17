#include "imgui/imgui.h"
#include "includes.h"
#include <cstdio>
#define GL_SILENCE_DEPRECATION


void CText(std::string text) {
    auto windowWidth = ImGui::GetWindowSize().x;
    auto textWidth   = ImGui::CalcTextSize(text.c_str()).x;

    ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
    ImGui::Text("%s", text.c_str());
}

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

int main(int, char**)
{
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    const char* glsl_version = "#version 130";
    printf("[imguimenu] launch glsl version: %s", glsl_version);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    GLFWwindow* window = glfwCreateWindow(1280, 720, "telegram: https://t.me/scaredmeee | Escape Please", NULL, NULL);
    if (window == NULL)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.Fonts->AddFontFromFileTTF("/home/q/projects/imguimenu/Montserrat-Regular.ttf", 18.0f);
    //ImGui::StyleColorsDark();
    
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    
    ImVec4 clear_color = ImVec4(0.50f, 0.50f, 0.50f, 0.50f);


    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        
        {
            static float f = 0.0f;
            static int counter = 0;
            //ImGui::ShowStyleEditor();
            ImVec2 windowsize = ImVec2(650, 400);
            ImGui::SetNextWindowSize(windowsize);
            ImGui::Begin("menu", nullptr, ImGuiWindowFlags_NoTitleBar || ImGuiWindowFlags_NoResize);
            //Another needs
            ImDrawList *drawlist = ImGui::GetWindowDrawList();
            ImStyle();
            ImColors();

            CText("Escape Please");
            ImGui::Separator();

            // Categories
            ImGui::PushStyleColor(ImGuiCol_ChildBg, ImColor(39, 39, 39, 225).Value);
            ImGui::BeginChild("##Right | Category", ImVec2(150, ImGui::GetWindowSize().y - 43), true);
            {
                if (ImGui::Button("Visuals", ImVec2(136, 50))) {
                    categories::cat1 = true;
                    categories::cat2 = false;
                    categories::cat3 = false;
                    categories::cat0 = false;
                }   

                if (ImGui::Button("Aimbot", ImVec2(136, 50))) {
                    categories::cat1 = false;
                    categories::cat2 = true;
                    categories::cat3 = false;
                    categories::cat0 = false;
                } 

                if (ImGui::Button("Configs", ImVec2(136, 50))) {
                    categories::cat1 = false;
                    categories::cat2 = false;
                    categories::cat3 = true;
                    categories::cat0 = false;
                } 
            }
            ImGui::EndChild();
            ImGui::PopStyleColor();
            //Same Line
            ImGui::SameLine();
            // Functions
            ImGui::BeginChild("## Left | Functions", ImVec2(478, ImGui::GetWindowSize().y - 43), true);
            {
                // Dev Category (default)
                if (categories::cat0) {
                    ImGui::Text("Thanks for use my menu!");
                    ImGui::Text("Telegram: https://t.me/scaredmeee");
                }

                if (categories::cat1) {
                    ImGui::Text("This is Visual Category");
                }

                if (categories::cat2) {
                    ImGui::Text("This is Aimbot Category");
                }

                if (categories::cat3) {
                    ImGui::Text("This is category in dev mode!!!");
                }
            }
            ImGui::EndChild();

            ImGui::End();
        }

        

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
