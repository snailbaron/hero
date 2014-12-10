#ifndef _GFX_HPP_
#define _GFX_HPP_

#include <SDL.h>

class Gfx
{
    public:
        Gfx(int width, int height) : m_width(width), m_height(height) {}
        virtual ~Gfx() {}

        virtual void Draw(SDL_Renderer *renderer, int x, int y) = 0;

    protected:
        int m_width;
        int m_height;
};

#endif