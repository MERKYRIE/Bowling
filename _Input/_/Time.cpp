#include"Time.hpp"

namespace NAdvancedEngineArchitecture
{
    void CTime::BUpdate()
    {
        FLast = FAbsolute;
        FAbsolute = SDL_GetTicks();
        FRelative = FAbsolute - FLast;
    }

    std::uint32_t CTime::OAbsolute()
    {
        return(FAbsolute);
    }
    std::uint32_t CTime::ORelative()
    {
        return(FRelative);
    }
}