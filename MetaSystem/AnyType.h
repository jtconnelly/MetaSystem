#pragma once

#include <metasystemlib_export.h>
#include <MetaInfo.h>
#include <string>

class METASYSTEMLIB_EXPORT Any
{
public:
    Any();
    Any(const Any&);
    Any(Any&&);

    explicit Any(const MetaInfo&);
    explicit Any(const MetaInfo*);

    Any& operator=(const Any&);
    Any& operator=(Any&&);

    template<typename T>
    Any& operator=(T&&);

    bool operator==(const Any&) const;

    template<typename T>
    bool operator==(const T&) const;

    template<typename T>
    bool can_convert() const;

    template<typename T>
    bool convert() const;

    std::string pretty();
    const MetaInfo& meta() const;
    ~Any();
private:
    MetaInfo _meta;
    void* _ptr;
};