//  -------------------------------------------------------------------------
//  Copyright (C) 2012 BMW Car IT GmbH
//  -------------------------------------------------------------------------
//  This Source Code Form is subject to the terms of the Mozilla Public
//  License, v. 2.0. If a copy of the MPL was not distributed with this
//  file, You can obtain one at https://mozilla.org/MPL/2.0/.
//  -------------------------------------------------------------------------

#ifndef RAMSES_IINPUTSTREAM_H
#define RAMSES_IINPUTSTREAM_H

#include "PlatformAbstraction/PlatformError.h"
#include "PlatformAbstraction/PlatformTypes.h"
#include <type_traits>

namespace ramses_internal
{
    class IInputStream
    {
    public:
        virtual ~IInputStream() = default;

        virtual IInputStream& read(Char* data, UInt32 size) = 0;
        virtual EStatus getState() const = 0;
    };

    inline IInputStream& operator>>(IInputStream& stream, int32_t& value)
    {
        return stream.read(reinterpret_cast<Char*>(&value), sizeof(value));
    }

    inline IInputStream& operator>>(IInputStream& stream, Int64& value)
    {
        return stream.read(reinterpret_cast<Char*>(&value), sizeof(value));
    }

    inline IInputStream& operator>>(IInputStream& stream, UInt32& value)
    {
        return stream.read(reinterpret_cast<Char*>(&value), sizeof(value));
    }

    inline IInputStream& operator>>(IInputStream& stream, UInt64& value)
    {
        return stream.read(reinterpret_cast<Char*>(&value), sizeof(value));
    }

    inline IInputStream& operator>>(IInputStream& stream, Bool&  value)
    {
        return stream.read(reinterpret_cast<Char*>(&value), sizeof(value));
    }

    inline IInputStream& operator>>(IInputStream& stream, Float& value)
    {
        return stream.read(reinterpret_cast<Char*>(&value), sizeof(value));
    }

    inline IInputStream& operator>>(IInputStream& stream, UInt16& value)
    {
        return stream.read(reinterpret_cast<Char*>(&value), sizeof(value));
    }

    template<typename E,
             typename = typename std::enable_if<std::is_enum<E>::value  && !std::is_convertible<E, int>::value>::type>
    IInputStream& operator>>(IInputStream& stream, E& value)
    {
        typename std::underlying_type<E>::type valueInUnderlyingType;
        stream >> valueInUnderlyingType;
        value = static_cast<E>(valueInUnderlyingType);

        return stream;
    }
}

#endif
