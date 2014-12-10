#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "window.hpp"
#include "sprite.hpp"

int main(int argc, char *argv[])
{
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    int imgInitFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgInitFlags) & imgInitFlags))
    {
        std::cerr << "Failed to initialize SDL_image: " << IMG_GetError() << std::endl;
        return 1;
    }

    Window *window = new Window("Main window", SCREEN_WIDTH, SCREEN_HEIGHT);

    Sprite *tree = window->CreateSprite("img/tree.bmp");



    int heroX = 0, heroY = 0;
    bool done = false;
    while (!done)
    {
        SDL_Event evt;
        while (SDL_PollEvent(&evt))
        {
            switch (evt.type)
            {
                case SDL_QUIT:
                    done = true;
                    break;

                case SDL_KEYDOWN:
                    switch (evt.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            done = true;
                            break;
                        case SDLK_UP:
                            heroY--;
                            break;
                        case SDLK_DOWN:
                            heroY++;
                            break;
                        case SDLK_LEFT:
                            heroX--;
                            break;
                        case SDLK_RIGHT:
                            heroX++;
                            break;
                    }
                    break;
            }            
        }

        window->Clear();
        window->DrawGfx(tree, heroX, heroY);
        window->Update();
    }
    
        
    delete tree;
    delete window;

    SDL_Quit();

    return 0;
}