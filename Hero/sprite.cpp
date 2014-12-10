#include "sprite.hpp"
#include "exceptions.hpp"

void Sprite::Draw(SDL_Renderer *renderer, int x, int y)
{
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = m_width;
    dst.h = m_height;
    
    SDL_RenderCopy(renderer, m_tex, nullptr, &dst);
}