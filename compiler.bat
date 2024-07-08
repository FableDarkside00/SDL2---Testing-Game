@echo off
Rem Alias do compilador para o GLFW
gcc -o %1.exe .\%1.c -I C:\MinGW\include\SDL2 -L C:\MinGW\lib -lSDL2main -lSDL2 -DSDL_MAIN_HANDLED -lopengl32 
Rem C:\GLFW\include\GLFW C:\GLFW\lib\libglfw3.a -lglfw3 -lgdi32 