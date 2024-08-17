# 2D Game Engine

## Building

To build and run this project, make sure you have these dependencies installed on your machine:
* SDL2 (2.30.6)
* SDL2_image (2.8.2)
* SDL2_ttf (2.22.0)
* SDL2_mixer (2.8.0)

The project was developed with Visual Studio 2022. It should detect the CMakeLists.txt automatically.

If you're using macOS or Linux, you can run these commands from the root directory:
```
cmake -B build -S .
cd build
cmake --build .
```
