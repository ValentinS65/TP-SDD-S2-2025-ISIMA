#ifndef sierpinski_sdl_h
#define sierpinski_sdl_h
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "sierpinski.h"

void dessineLigne(int ,int ,int ,int );

void dessineTriangle(triangle );

void dessineListe(list_triangles*l);

void dessineFractale();

void dessinerFenetre() ;

int main_SDL();

#endif