#pragma once
#include "menu_state.h"
#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_glfw.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

class Menu{
    public:

        void draw_gui(){
            GLFWwindow* window = initializeGUI();
            
            while(!glfwWindowShouldClose(window)){

                glfwPollEvents();

                ImGui_ImplOpenGL3_NewFrame();
                ImGui_ImplGlfw_NewFrame();
                ImGui::NewFrame();

                MenuState::menu_state->draw();

                if(MenuState::next_state){
                    delete MenuState::menu_state;
                    MenuState::menu_state = MenuState::next_state;
                    MenuState::next_state = nullptr;
                }
                ImGui::Render();
                glViewport(0,0,window_size_x,window_size_y);
                glClear(GL_COLOR_BUFFER_BIT);

                ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
                glfwSwapBuffers(window);
            }

        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        glfwDestroyWindow(window);
        glfwTerminate();

        }

    
    private:
        
        int window_size_x = 1920;
        int window_size_y = 1080;
        
        GLFWwindow* initializeGUI(){
            glfwInit();
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
            GLFWwindow* window = glfwCreateWindow(window_size_x, window_size_y, "Owen smells", NULL, NULL);
            glfwMakeContextCurrent(window);

            IMGUI_CHECKVERSION();
            ImGui::CreateContext();
            ImGuiIO& io = ImGui::GetIO();
            io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

            ImGui_ImplGlfw_InitForOpenGL(window, true);
            ImGui_ImplOpenGL3_Init("#version 130");

            return window;
}


};