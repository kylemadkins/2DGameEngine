#include <SDL.h>
#include <glm/glm.hpp>
#include <sol/sol.hpp>
#include <imgui.h>

int main(int argc, char* argv[]) {
	sol::state lua;
	lua.open_libraries(sol::lib::base);

	glm::vec2 vel = glm::vec2(2.0, -1.0);

	SDL_Init(SDL_INIT_EVERYTHING);

	std::cout << "Hooray! Dependencies are linked correctly!\n";

	return 0;
}
