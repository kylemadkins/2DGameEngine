# 2D Game Engine

## Dependencies

The engine depends on the following 3rd party libraries, which will be automatically included in the project via Git submodules and CMake.

- SDL (2.30.7)
- SDL_image (2.8.2)
- SDL_ttf (2.22.0)
- SDL_mixer (2.8.0)
- glm (1.0.1)
- sol2 (3.3.0)
- imgui (1.91.2)
- lua (5.4.7)

Be sure to update the Git submodules. This might take a while.

```
git submodule update --init --recursive
```

## Building

The project was developed with Visual Studio 2022. It should detect the CMakeLists.txt automatically.

If you're using macOS or Linux, you can run these commands from the root directory to build the project using CMake.

```
cmake -B build -S .
cd build
cmake --build .
```
