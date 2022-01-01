#define SDL_MAIN_HANDLED 1
#include <SDL.h>

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
    SDL_Window *window = SDL_CreateWindow("sound-synth", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_OPENGL);
    SDL_DestroyWindow(window);
    return 0;
}
