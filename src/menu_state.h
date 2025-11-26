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

inline std::optional<User> current_user = std::nullopt;

class MenuState{
    public:
        virtual void draw() = 0;
        ~MenuState(){
           // delete menu_state;
           // delete next_state;
        }
        template<typename T>
        static void change_state() {
            static_assert(std::is_base_of_v<MenuState, T>);
            current_state = std::move(std::make_unique<T>());
        }
        static void create_spaces(const int &numspaces = 1){
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

            ImGui::Text("There are %lu users", DataManager::users.size());

            for (User& u : DataManager::users) {
                ImGui::Text("Average rating of %s: %2.1f", u.get_name().data(), u.average_rating());
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

            if(ImGui::Button("View profile")){
                if (current_user.has_value()) {
                    change_state<ProfileMenu>();
                } else {
                    change_state<LogInMenu>();
                }
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
            if(ImGui::InputText("Input Password",password_input_buffer,IM_ARRAYSIZE(password_input_buffer))){
                for(User &user : DataManager::users){
                    if(username_input_buffer == user.get_name() && password_input_buffer == user.get_password()){
                        change_state<ProfileMenu>();
                        current_user = user;
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
            const auto current_user_description = current_user.transform([](const User &u) {
                return u.get_name();
            }).value_or("");

            if (!current_user.has_value()) {
                return;
            }

            ImGui::Text("Logged in as %s", current_user_description.data());

            create_spaces(3);

            const auto& ratings = current_user->get_ratings();

            ImGui::Text("You have rated %lu media pieces", ratings.size());
            create_spaces();

            for (auto& r : ratings) {
                create_spaces();
                auto media_name = r.getMedia()->getName();
                ImGui::Text("Name: %s. Your rating: %d", media_name.data(), r.getValue());
            }

        }
};

