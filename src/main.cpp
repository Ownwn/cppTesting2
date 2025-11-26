#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include "user.h"
#include "song.h"
#include "../imgui/imgui.h"
#include "../imgui/backends/imgui_impl_glfw.h"
#include "../imgui/backends/imgui_impl_opengl3.h"
#include "menu_state.h"
#include <GLFW/glfw3.h>
#include "menu.h"
#include "data_manager.h"


std::shared_ptr<MenuState> MenuState::current_state = std::make_unique<MainMenu>();
Menu menu;
static DataManager dataManager;

int main() {
    User magnus("magnu");
    if (magnus.has_ratings()) {
        std::cout << magnus << " has rating " << magnus.get_ratings().at(0) << '\n';
    } else {
        std::cout << magnus << " has no ratings :(\n";
    }

    dataManager.setup_random_users();

    menu.draw_gui();

    return 0;
}