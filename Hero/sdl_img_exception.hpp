#ifndef _SDL_IMG_EXCEPTION_HPP_
#define _SDL_IMG_EXCEPTION_HPP_

#include <SDL_image.h>
#include "exception.hpp"

class SdlImgException : public Exception
{
    public:
        SdlImgException() : m_msg(IMG_GetError()) {}
        SdlImgException(const SdlImgException &ex) : m_msg(ex.m_msg) {}
        ~SdlImgException() {}

        const char * Msg() const { return m_msg; }

    private:
        const char *m_msg;
};


#endif