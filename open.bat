@echo off
@g++ main.cpp -mwindows -IC:\SDL\SDL2-2.0.4\i686-w64-mingw32\include\SDL2 -LC:\SDL\SDL2-2.0.4\i686-w64-mingw32\lib -lSDL2 -o test.exe
pause