#pragma once

#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_glfw.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

class TestMenu;
class MainMenu;

class MenuState{
    public:
        virtual void draw() = 0;
        static MenuState* menu_state;
        static MenuState* next_state;
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
            ImGui::BeginChild("Inside da box", ImVec2(200,200),1,1);
            if(ImGui::Button("please")){
                MenuState::next_state = new TestMenu();
            }
            ImGui::Button("Second button");
            ImGui::EndChild();
            ImGui::Text("HELLO");
            ImGui::End();
        
        }


};

