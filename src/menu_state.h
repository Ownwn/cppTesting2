#pragma once

#include <memory>
#include <sstream>
#include <format>
#include <ranges>
#include <vector>
#include <string>
#include <iostream>

#include "../imgui/imgui.h"
#include "../imgui/backends/imgui_impl_glfw.h"
#include "../imgui/backends/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

#include "data_manager.h"

// #include "data_manager.h"

class InfoMenu;
class MainMenu;
class LogInMenu;
class ProfileMenu;

class MenuState{
    public:
        virtual void draw() = 0;
        bool logged_in = false;
        ~MenuState(){
           // delete menu_state;
           // delete next_state;
        }
        template<typename T>
        static void change_state() {
            static_assert(std::is_base_of_v<MenuState, T>);
            current_state = std::move(std::make_unique<T>());
        }
        static void create_spaces(int numspaces){
            for (int i = 0; i < numspaces; ++i) {
                ImGui::Spacing();
            }
        }

    friend class Menu;
private:
    static std::unique_ptr<MenuState> menu_state;
    static std::unique_ptr<MenuState> next_state;
    static std::shared_ptr<MenuState> current_state;

};

class InfoMenu : public MenuState{

    public:
        void draw() override{
            ImGui::Begin("Info");
            ImGui::Text("User info");
            create_spaces(4);

            ImGui::Text(std::format("There are {} users", DataManager::users.size()).c_str());

            for (User u : DataManager::users) {
                std::ostringstream formatted;
                formatted << "Average rating of " << u.get_name() << ": " << u.average_rating();
                ImGui::Text(formatted.str().c_str());
            }

            create_spaces(3);

            if(ImGui::Button("and back again")){
                change_state<MainMenu>();
            }

            ImGui::End();
        }


};

class MainMenu : public MenuState{

    public:
        void draw() override{
            ImGui::Begin("Info");
            ImGui::SetCursorPos(ImVec2(0,0));
            create_spaces(7);
            ImGui::BeginChild("Inside da box", ImVec2(200,200),1,1);
            if(ImGui::Button("View user summary")){
                change_state<InfoMenu>();
            }
            create_spaces(8);
            if (ImGui::Button("Second button")) {
                std::cout << "Second button pressed\n";
            }

            if(ImGui::Button("View User Database")){
                if(!logged_in){change_state<LogInMenu>();}
                else {change_state<ProfileMenu>();}
            }
            ImGui::EndChild();
            ImGui::End();

        }


};

class LogInMenu : public MenuState{
    public:
        void draw() override{
            if(ImGui::InputText("Input Username",username_input_buffer,IM_ARRAYSIZE(username_input_buffer))){
                
            }
            create_spaces(10);
            if(ImGui::InputText("Input Password",password_input_buffer,IM_ARRAYSIZE(password_input_buffer),true)){
                for(User user : DataManager::users){
                    if(username_input_buffer == user.get_name() && password_input_buffer == user.get_password()){
                        change_state<ProfileMenu>();
                        logged_in = true;
                    }
                }
            }
        }
    private:
        char username_input_buffer[28] = "";
        char password_input_buffer[28] = "";
};  

class ProfileMenu : public MenuState{
    public:
        void draw() override{

        }
};

