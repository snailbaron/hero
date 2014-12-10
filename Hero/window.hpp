#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

#include <string>
#include <SDL.h>
#include "gfx.hpp"
#include "sprite.hpp"

class Window
{
    public:
        Window(const char *name, int width, int height);
        ~Window();

        SDL_Renderer * GetRenderer() const { return m_renderer; }

        void Clear() const { SDL_RenderClear(m_renderer); }
        Sprite * CreateSprite(const std::string &file);
        void DrawGfx(Gfx *gfx, int x, int y);
        void Update() const { SDL_RenderPresent(m_renderer); }

    private:
        SDL_Window *m_wnd;
        SDL_Renderer *m_renderer;
        SDL_Surface *m_screenSurface;
};

#endif