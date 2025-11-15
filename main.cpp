#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include "user.h"
#include "song.h"
#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_glfw.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

std::vector dummy_names = {"frank ocean", "marco", "the pope", "settlers of catan enjoyer"};

std::vector song_names = {"minions", ""};

User create_dummy_user() {
    int index = rand() % dummy_names.size();
    User user(dummy_names[index]);
    return user;
}

GLFWwindow* initializeGUI(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    GLFWwindow* window = glfwCreateWindow(800, 600, "Owen smells", NULL, NULL);
    glfwMakeContextCurrent(window);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    return window;
}

int main() {
    User magnus("magnu");
    if (magnus.has_ratings()) {
        std::cout << magnus << " has rating " << magnus.get_ratings().at(0) << '\n';
    } else {
        std::cout << magnus << " has no ratings :(\n";
    }

    std::vector<std::string> v;
    Song song("chungus humungus", 600, v);
    std::cout << song.getRating();

    User dummy = create_dummy_user();
    std::cout << dummy << " is dummy\n";
    
    GLFWwindow* window = initializeGUI();

    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("HELLO");
        ImGui::Text("please work");
        ImGui::Button("please");
        ImGui::End();

        ImGui::Render();
        glViewport(0,0,800,600);
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