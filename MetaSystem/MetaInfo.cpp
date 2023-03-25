#include "MetaInfo.h"
#include <string>

#define CLASS_NAME(className) \
std::string classname()  \
{ \
return #className; \
}

static uint32_t idCount = 1;

MetaInfo::MetaInfo()
{
    _id = idCount++;
}