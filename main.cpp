#include <SDL.h>

int main(int argc, char *argv[])
{
    SDL_Window *window = SDL_CreateWindow("sound-synth", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_OPENGL);
    SDL_DestroyWindow(window);
}
