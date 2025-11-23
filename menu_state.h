#pragma once

#include <memory>

#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_glfw.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

class TestMenu;
class MainMenu;

class MenuState{
    public:
        virtual void draw() = 0;
        static std::unique_ptr<MenuState> menu_state;
        static std::unique_ptr<MenuState> next_state;
        ~MenuState(){
           // delete menu_state;
           // delete next_state;
        }

};

class TestMenu : public MenuState{

    public:
        void draw(){
            ImGui::Begin("yeah");
            ImGui::Text("Hopefully");
            ImGui::End();
        }


};

class MainMenu : public MenuState{

    public:
        void draw(){
            ImGui::Begin("HELLO");
            ImGui::Text("please work");
            ImGui::SetCursorPos(ImVec2(0,0));
            for (int i = 0; i < 7; ++i) {
                ImGui::Spacing();
            }
            ImGui::BeginChild("Inside da box", ImVec2(200,200),1,1);
            if(ImGui::Button("please")){
                MenuState::next_state = std::make_unique<TestMenu>();
            }
            for (int i = 0; i < 8; ++i) {
                ImGui::Spacing();
            }
            if (ImGui::Button("Second button")) {
                std::cout << "Second button pressed\n";
            }
            ImGui::EndChild();
            ImGui::Text("HELLO");
            ImGui::End();
        
        }


};

