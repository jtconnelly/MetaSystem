#pragma once

#include <metasystemlib_export.h>
#include <string_view>
#include <unordered_map>
#include <cassert>


struct MetaInfo final
{
    std::string_view _name{};
    uint32_t _sz{};
    uint32_t _align{};

    template <typename T>
    static constexpr MetaInfo Create();
};

class MetaTypeID final
{
public:
    constexpr MetaTypeID(uint64_t id) : _id{ id } {};

    template <typename T>
    static constexpr MetaTypeID Create();

    static const MetaInfo& getMetaInfo(MetaTypeID id)
    {
        assert(getStatics()._infos.contains(id.getID()));
        return getStatics()._infos[id.getID()];
    }

    constexpr void setTypeID(uint64_t id) { _id = id; }
    constexpr uint64_t getID() const { return _id; }
    const MetaInfo& getMetaInfo() const { return getMetaInfo(*this); }

    static const std::unordered_map<uint64_t, MetaInfo>& getAllMetaInfo()
    {
        return getStatics()._infos;
    }
    template <typename T>
    static void registerType()
    {
        const uint64_t id = Create<T>().getID();
        assert(!_infos.contains(id));


        _infos.emplace(id, MetaInfo::Create<T>());
    }

private:
    uint64_t _id{};

    struct StaticData
    {
        std::unordered_map<uint64_t, MetaInfo> _infos;
    };

    static StaticData& getStatics()
    {
        static StaticData data{};
        return data;
    }


};

template <typename T>
class MetaRegister
{
private:
    class IDRegister
    {
    public:
        IDRegister()
        {
            MetaTypeID::registerType<T>();
        }
    };
    inline static IDRegister r{};
};

#define _INTERNAL_META_DECLARE(TYPE, VARNAME) MetaRegister<TYPE> VARNAME##TYPE {};
#define META_DECLARE(TYPE) _INTERNAL_META_DECLARE(TYPE, MetaRegister_)