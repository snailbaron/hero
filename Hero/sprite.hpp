#ifndef _SPRITE_HPP_
#define _SPRITE_HPP_

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "gfx.hpp"

class Sprite : public Gfx
{
    public:
        Sprite(int width, int height, SDL_Texture *tex) : Gfx(width, height), m_tex(tex) {}
        ~Sprite() { if (m_tex) SDL_DestroyTexture(m_tex); }

        void Draw(SDL_Renderer *renderer, int x, int y);

    private:
        SDL_Texture *m_tex;
};

#endif