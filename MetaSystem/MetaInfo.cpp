#include "MetaInfo.h"
#include <functional>

#define CLASS_NAME(className) \
#className;

static uint32_t idCount = 1;

template <typename T>
inline constexpr MetaInfo MetaInfo::Create()
{
    MetaInfo info{};
    info._name = CLASS_NAME(T);
    info._sz = sizeof(T);
    info._align = alignof(T);

    return info;
}

//FNV-1A
constexpr uint64_t hash(std::string_view str)
{
    uint64_t hsh = 0xcbf29ce484111215ULL;
    constexpr uint64_t prime = 0x100000001b3ULL; 
    for (char c : str)
    {
        hsh ^= static_cast<uint64_t>(c);
        hsh *= prime;
    }
    return hsh;
}

template<typename T>
inline constexpr MetaTypeID MetaTypeID::Create()
{
    MetaTypeID id;

    id._id = hsh(MetaInfo::Create<T>()._name);

    return id;
}