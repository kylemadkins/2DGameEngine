# CMakeList.txt : CMake project for 2DGameEngine, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if(POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("2DGameEngine")

# Add source to this project's executable.
add_executable(2DGameEngine "src/Main.cpp" "src/Game.h" "src/Game.cpp")

if(CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 2DGameEngine PROPERTY CXX_STANDARD 20)
endif()

# SDL
add_subdirectory("thirdparty/SDL-2.30.7")

# SDL_image
add_subdirectory("thirdparty/SDL_image-2.8.2")

# SDL_ttf
add_subdirectory("thirdparty/SDL_ttf-2.22.0")

# SDL_mixer
option(SDL2MIXER_VENDORED "Use vendored third-party libraries" ON)
add_subdirectory("thirdparty/SDL_mixer-2.8.0")

target_link_libraries(2DGameEngine SDL2::SDL2 SDL2_image::SDL2_image SDL2_ttf::SDL2_ttf SDL2_mixer::SDL2_mixer)

# glm
add_subdirectory("thirdparty/glm-1.0.1-light/glm")
include_directories("thirdparty/glm-1.0.1-light")

# sol2
include_directories("thirdparty/sol2-3.3.0")

# imgui
include_directories("thirdparty/imgui-1.91.0")

# Lua
set(LUA_DIR "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/lua-5.4.7")

add_library(
    lua STATIC
    ${LUA_DIR}/lapi.c
    ${LUA_DIR}/lauxlib.c
    ${LUA_DIR}/lbaselib.c
    ${LUA_DIR}/lcode.c
    ${LUA_DIR}/lcorolib.c
    ${LUA_DIR}/lctype.c
    ${LUA_DIR}/ldblib.c
    ${LUA_DIR}/ldebug.c
    ${LUA_DIR}/ldo.c
    ${LUA_DIR}/ldump.c
    ${LUA_DIR}/lfunc.c
    ${LUA_DIR}/lgc.c
    ${LUA_DIR}/linit.c
    ${LUA_DIR}/liolib.c
    ${LUA_DIR}/llex.c
    ${LUA_DIR}/lmathlib.c
    ${LUA_DIR}/lmem.c
    ${LUA_DIR}/loadlib.c
    ${LUA_DIR}/lobject.c
    ${LUA_DIR}/lopcodes.c
    ${LUA_DIR}/loslib.c
    ${LUA_DIR}/lparser.c
    ${LUA_DIR}/lstate.c
    ${LUA_DIR}/lstring.c
    ${LUA_DIR}/lstrlib.c
    ${LUA_DIR}/ltable.c
    ${LUA_DIR}/ltablib.c
    ${LUA_DIR}/ltm.c
    ${LUA_DIR}/lundump.c
    ${LUA_DIR}/lutf8lib.c
    ${LUA_DIR}/lvm.c
    ${LUA_DIR}/lzio.c
)

target_link_libraries(2DGameEngine lua)

include_directories(${LUA_DIR})

# Copy assets
add_custom_command(TARGET 2DGameEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/assets
    $<TARGET_FILE_DIR:2DGameEngine>/assets
)
