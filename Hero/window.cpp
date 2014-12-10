#include "window.hpp"
#include "exceptions.hpp"

Window::Window(const char *name, int width, int height) :
    m_wnd(nullptr),
    m_renderer(nullptr),
    m_screenSurface(nullptr)
{
    m_wnd = SDL_CreateWindow(
        name,
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        width, height,
        SDL_WINDOW_SHOWN
    );
    if (!m_wnd)
        throw SdlException();

    m_renderer = SDL_CreateRenderer(m_wnd, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!m_renderer)
        throw SdlException();

    SDL_SetRenderDrawColor(m_renderer, 0x33, 0x33, 0x33, 0xFF);

    m_screenSurface = SDL_GetWindowSurface(m_wnd);
    SDL_FillRect(m_screenSurface, nullptr, SDL_MapRGB(m_screenSurface->format, 0x33, 0x33, 0x33));
}

Window::~Window()
{
    if (m_renderer)
        SDL_DestroyRenderer(m_renderer);
    if (m_wnd)
        SDL_DestroyWindow(m_wnd);
}

Sprite * Window::CreateSprite(const std::string &file)
{
    SDL_Surface *tmpSurface = IMG_Load(file.c_str());
    if (!tmpSurface)
        throw SdlImgException();
    int width = tmpSurface->w, height = tmpSurface->h;

    SDL_Texture *tex = SDL_CreateTextureFromSurface(m_renderer, tmpSurface);
    if (!tex)
        throw SdlException();

    SDL_FreeSurface(tmpSurface);

    return new Sprite(width, height, tex);
}

void Window::DrawGfx(Gfx *gfx, int x, int y)
{
    gfx->Draw(m_renderer, x, y);
}