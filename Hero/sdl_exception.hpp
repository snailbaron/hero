#ifndef _SDL_EXCEPTION_HPP_
#define _SDL_EXCEPTION_HPP_

#include <SDL.h>
#include "exception.hpp"

class SdlException : public Exception
{
    public:
        SdlException() : m_msg(SDL_GetError()) {}
        SdlException(const SdlException &ex) : m_msg(ex.m_msg) {}
        ~SdlException() {}

        const char * Msg() const { return m_msg; }

    private:
        const char *m_msg;
};

#endif