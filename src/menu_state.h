#pragma once

#include <memory>
#include <sstream>
#include <format>

#include "../imgui/imgui.h"
#include "../imgui/backends/imgui_impl_glfw.h"
#include "../imgui/backends/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

#include "data_manager.h"

// #include "data_manager.h"

class InfoMenu;
class MainMenu;

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
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();

            ImGui::Text(std::format("There are {} users", DataManager::users.size()).c_str());

            for (User u : DataManager::users) {
                std::ostringstream formatted;
                formatted << "Average rating of " << u.get_name() << ": " << u.average_rating();
                ImGui::Text(formatted.str().c_str());
            }

            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();

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
            for (int i = 0; i < 7; ++i) {
                ImGui::Spacing();
            }
            ImGui::BeginChild("Inside da box", ImVec2(200,200),1,1);
            if(ImGui::Button("View user summary")){
                change_state<InfoMenu>();
            }
            for (int i = 0; i < 8; ++i) {
                ImGui::Spacing();
            }
            if (ImGui::Button("Second button")) {
                std::cout << "Second button pressed\n";
            }
            ImGui::EndChild();
            ImGui::End();

        }


};

