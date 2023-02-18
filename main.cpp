#include "imgui-special/imgui.h"
#include "includes.h"
#include <cstdio>
#include <type_traits>
#define GL_SILENCE_DEPRECATION


void CText(std::string text) {
    auto windowWidth = ImGui::GetWindowSize().x;
    auto textWidth   = ImGui::CalcTextSize(text.c_str()).x;

    ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
    ImGui::Text("%s", text.c_str());
}



int main(int, char**)
{
    

     // Setup SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0)
    {
        printf("Error: %s\n", SDL_GetError());
        return -1;
    }

    // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
    // GL ES 2.0 + GLSL 100
    const char* glsl_version = "#version 100";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#elif defined(__APPLE__)
    // GL 3.2 Core + GLSL 150
    const char* glsl_version = "#version 150";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG); // Always required on Mac
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#endif

    // From 2.0.18: Enable native IME.
#ifdef SDL_HINT_IME_SHOW_UI
    SDL_SetHint(SDL_HINT_IME_SHOW_UI, "1");
#endif

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Window* window = SDL_CreateWindow("Test SDL2 Render", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags);
    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, gl_context);
    SDL_GL_SetSwapInterval(1); // Enable vsync

    
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.Fonts->AddFontFromFileTTF("/home/q/projects/imguimenu/Montserrat-Regular.ttf", 18.0f);
    //ImGui::StyleColorsDark();
    ImStyle();
    ImColorsDark();
    // If You need dark theme, use ImColorsLight();
    
    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init(glsl_version);

    
    ImVec4 clear_color = ImVec4(0.50f, 0.50f, 0.50f, 0.50f);
    bool done = false;


    while (!done)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                done = true;
            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window))
                done = true;
        }

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        
        {
            
            ImGui::SetNextWindowPos(ImVec2(30, 30));
            ImGui::SetNextWindowSize(ImVec2(70, 70));
            ImGui::Begin("##brain open", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBackground);
            {
                if (ImGui::Button("Open", ImVec2(55, 55))) {
                    if (open::isOpen == 0) {
                        open::isOpen = 1;
                    } else if (open::isOpen == 1) {
                        open::isOpen = 0;
                    }
                }
            }
            ImGui::End();

            static float f = 0.0f;
            static int counter = 0;
            //ImGui::ShowStyleEditor();
            if (open::isOpen == 1) {
                ImVec2 windowsize = ImVec2(650, 400);
                ImGui::SetNextWindowSize(windowsize);
                ImGui::Begin("menu", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoDecoration);
                //Another needs

                CText("Escape Please");
                ImGui::Separator();


                int right_x = 150;
                int left_x = 478;

                // If You Use Light Theme Change r,g,b in color ImGuiCol_ChildBg
                // Categories
                ImGui::PushStyleColor(ImGuiCol_ChildBg, ImColor(39, 39, 39, 225).Value);
                ImGui::BeginChild("##Right | Category", ImVec2(right_x, ImGui::GetWindowSize().y - 43), true);
                {
                    if (ImGui::Button("kall 1", ImVec2(136, 50))) {
                        categories::cat1 = true;
                        categories::cat2 = false;
                        categories::cat3 = false;
                        categories::cat0 = false;
                    }   

                    if (ImGui::Button("kall 2", ImVec2(136, 50))) {
                        categories::cat1 = false;
                        categories::cat2 = true;
                        categories::cat3 = false;
                        categories::cat0 = false;
                    } 

                    if (ImGui::Button("kall 3", ImVec2(136, 50))) {
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
                ImGui::BeginChild("## Left | Functions", ImVec2(left_x, ImGui::GetWindowSize().y - 43), true);
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
        }

        

        // Rendering
        ImGui::Render();
        glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
