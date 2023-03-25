#pragma once

#include <metasystemlib_export.h>

class METASYSTEMLIB_EXPORT MetaInfo
{
public:
    enum class Fundamental
    {
        Null,
        Bool,
        Char,
        UInt8,
        UInt16,
        UInt32,
        UInt64,
        Int8,
        Int16,
        Int32,
        Int64,
        Float,
        Double,
        NonFundamental
    };

    MetaInfo();
private:
    Fundamental _type;
    std::string _className;
    uint32_t _id;
};