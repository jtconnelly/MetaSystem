#pragma once

#include <metasystemlib_export.h>

class METASYSTEMLIB_EXPORT Any
{
public:
    Any();
private:
    void* Pointer;
};