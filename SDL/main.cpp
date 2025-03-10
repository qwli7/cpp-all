#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#undef main


int main() {
  SDL_INIT(SDL_INIT_EVERYTHING); // 初始化所有的子系统
  return 0;
}
