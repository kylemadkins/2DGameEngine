#define SDL_MAIN_HANDLED

#include <iostream>
#include <SDL.h>
#include <glm/glm.hpp>
#include <sol/sol.hpp>
#include <imgui.h>


int main() {
    sol::state lua;
    lua.open_libraries(sol::lib::base);
    SDL_Init(SDL_INIT_EVERYTHING);
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
