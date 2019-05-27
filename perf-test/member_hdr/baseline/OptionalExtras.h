/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _BASELINE_OPTIONALEXTRAS_H_
#define _BASELINE_OPTIONALEXTRAS_H_

#if defined(SBE_HAVE_CMATH)
/* cmath needed for std::numeric_limits<double>::quiet_NaN() */
#  include <cmath>
#  define SBE_FLOAT_NAN std::numeric_limits<float>::quiet_NaN()
#  define SBE_DOUBLE_NAN std::numeric_limits<double>::quiet_NaN()
#else
/* math.h needed for NAN */
#  include <math.h>
#  define SBE_FLOAT_NAN NAN
#  define SBE_DOUBLE_NAN NAN
#endif

#if __cplusplus >= 201103L
#  include <cstdint>
#  include <string>
#  include <cstring>
#endif

#if __cplusplus >= 201103L
#  define SBE_CONSTEXPR constexpr
#  define SBE_NOEXCEPT noexcept
#else
#  define SBE_CONSTEXPR
#  define SBE_NOEXCEPT
#endif

#if !defined(__STDC_LIMIT_MACROS)
#  define __STDC_LIMIT_MACROS 1
#endif
#include <cstdint>
#include <cstring>
#include <limits>
#include <stdexcept>

#include <sstream>

#if defined(WIN32) || defined(_WIN32)
#  define SBE_BIG_ENDIAN_ENCODE_16(v) _byteswap_ushort(v)
#  define SBE_BIG_ENDIAN_ENCODE_32(v) _byteswap_ulong(v)
#  define SBE_BIG_ENDIAN_ENCODE_64(v) _byteswap_uint64(v)
#  define SBE_LITTLE_ENDIAN_ENCODE_16(v) (v)
#  define SBE_LITTLE_ENDIAN_ENCODE_32(v) (v)
#  define SBE_LITTLE_ENDIAN_ENCODE_64(v) (v)
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#  define SBE_BIG_ENDIAN_ENCODE_16(v) __builtin_bswap16(v)
#  define SBE_BIG_ENDIAN_ENCODE_32(v) __builtin_bswap32(v)
#  define SBE_BIG_ENDIAN_ENCODE_64(v) __builtin_bswap64(v)
#  define SBE_LITTLE_ENDIAN_ENCODE_16(v) (v)
#  define SBE_LITTLE_ENDIAN_ENCODE_32(v) (v)
#  define SBE_LITTLE_ENDIAN_ENCODE_64(v) (v)
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#  define SBE_LITTLE_ENDIAN_ENCODE_16(v) __builtin_bswap16(v)
#  define SBE_LITTLE_ENDIAN_ENCODE_32(v) __builtin_bswap32(v)
#  define SBE_LITTLE_ENDIAN_ENCODE_64(v) __builtin_bswap64(v)
#  define SBE_BIG_ENDIAN_ENCODE_16(v) (v)
#  define SBE_BIG_ENDIAN_ENCODE_32(v) (v)
#  define SBE_BIG_ENDIAN_ENCODE_64(v) (v)
#else
#  error "Byte Ordering of platform not determined. Set __BYTE_ORDER__ manually before including this file."
#endif

#if defined(SBE_NO_BOUNDS_CHECK)
#  define SBE_BOUNDS_CHECK_EXPECT(exp,c) (false)
#elif defined(_MSC_VER)
#  define SBE_BOUNDS_CHECK_EXPECT(exp,c) (exp)
#else
#  define SBE_BOUNDS_CHECK_EXPECT(exp,c) (__builtin_expect(exp,c))
#endif

#define SBE_NULLVALUE_INT8 (std::numeric_limits<std::int8_t>::min)()
#define SBE_NULLVALUE_INT16 (std::numeric_limits<std::int16_t>::min)()
#define SBE_NULLVALUE_INT32 (std::numeric_limits<std::int32_t>::min)()
#define SBE_NULLVALUE_INT64 (std::numeric_limits<std::int64_t>::min)()
#define SBE_NULLVALUE_UINT8 (std::numeric_limits<std::uint8_t>::max)()
#define SBE_NULLVALUE_UINT16 (std::numeric_limits<std::uint16_t>::max)()
#define SBE_NULLVALUE_UINT32 (std::numeric_limits<std::uint32_t>::max)()
#define SBE_NULLVALUE_UINT64 (std::numeric_limits<std::uint64_t>::max)()

namespace baseline {

class OptionalExtras
{
private:
    char *m_buffer = nullptr;
    std::uint64_t m_bufferLength;
    std::uint64_t m_offset = 0;
    std::uint64_t m_actingVersion;

public:
    enum MetaAttribute
    {
        EPOCH, TIME_UNIT, SEMANTIC_TYPE, PRESENCE
    };

    union sbe_float_as_uint_u
    {
        float fp_value;
        std::uint32_t uint_value;
    };

    union sbe_double_as_uint_u
    {
        double fp_value;
        std::uint64_t uint_value;
    };

    OptionalExtras() = default;

    OptionalExtras(
        char *buffer,
        const std::uint64_t offset,
        const std::uint64_t bufferLength,
        const std::uint64_t actingVersion) :
        m_buffer(buffer),
        m_bufferLength(bufferLength),
        m_offset(offset),
        m_actingVersion(actingVersion)
    {
        if (SBE_BOUNDS_CHECK_EXPECT(((m_offset + 1) > m_bufferLength), false))
        {
            throw std::runtime_error("buffer too short for flyweight [E107]");
        }
    }

    OptionalExtras(
        char *buffer,
        const std::uint64_t bufferLength,
        const std::uint64_t actingVersion) :
        OptionalExtras(buffer, 0, bufferLength, actingVersion)
    {
    }

    OptionalExtras(
        char *buffer,
        const std::uint64_t bufferLength) :
        OptionalExtras(buffer, 0, bufferLength, sbeSchemaVersion())
    {
    }

    OptionalExtras &wrap(char *buffer, const std::uint64_t offset, const std::uint64_t actingVersion, const std::uint64_t bufferLength)
    {
        return *this = OptionalExtras(buffer, offset, bufferLength, actingVersion);
    }

    static SBE_CONSTEXPR std::uint64_t encodedLength() SBE_NOEXCEPT
    {
        return 1;
    }

    std::uint64_t offset() const SBE_NOEXCEPT
    {
        return m_offset;
    }

    const char * buffer() const SBE_NOEXCEPT
    {
        return m_buffer;
    }

    char * buffer() SBE_NOEXCEPT
    {
        return m_buffer;
    }

    std::uint64_t bufferLength() const SBE_NOEXCEPT
    {
        return m_bufferLength;
    }

    std::uint64_t actingVersion() const SBE_NOEXCEPT
    {
        return m_actingVersion;
    }

    static SBE_CONSTEXPR std::uint16_t sbeSchemaId() SBE_NOEXCEPT
    {
        return (std::uint16_t)1;
    }

    static SBE_CONSTEXPR std::uint16_t sbeSchemaVersion() SBE_NOEXCEPT
    {
        return (std::uint16_t)0;
    }

    OptionalExtras &clear()
    {
        std::uint8_t zero = 0;
        std::memcpy(m_buffer + m_offset, &zero, sizeof(std::uint8_t));
        return *this;
    }

    bool isEmpty() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint8_t));
        return 0 == val;
    }

    static bool sunRoof(const std::uint8_t bits)
    {
        return (bits & (static_cast<std::uint8_t>(1) << 0)) != 0;
    }

    static std::uint8_t sunRoof(const std::uint8_t bits, const bool value)
    {
        return value ? (bits | (static_cast<std::uint8_t>(1) << 0)) : (bits & ~(static_cast<std::uint8_t>(1) << 0));
    }

    bool sunRoof() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint8_t));
        return ((val) & (static_cast<std::uint8_t>(1) << 0)) != 0;
    }

    OptionalExtras &sunRoof(const bool value)
    {
        std::uint8_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint8_t));
        bits = (value ? ((bits) | (static_cast<std::uint8_t>(1) << 0)) : ((bits) & ~(static_cast<std::uint8_t>(1) << 0)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint8_t));
        return *this;
    }

    static bool sportsPack(const std::uint8_t bits)
    {
        return (bits & (static_cast<std::uint8_t>(1) << 1)) != 0;
    }

    static std::uint8_t sportsPack(const std::uint8_t bits, const bool value)
    {
        return value ? (bits | (static_cast<std::uint8_t>(1) << 1)) : (bits & ~(static_cast<std::uint8_t>(1) << 1));
    }

    bool sportsPack() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint8_t));
        return ((val) & (static_cast<std::uint8_t>(1) << 1)) != 0;
    }

    OptionalExtras &sportsPack(const bool value)
    {
        std::uint8_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint8_t));
        bits = (value ? ((bits) | (static_cast<std::uint8_t>(1) << 1)) : ((bits) & ~(static_cast<std::uint8_t>(1) << 1)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint8_t));
        return *this;
    }

    static bool cruiseControl(const std::uint8_t bits)
    {
        return (bits & (static_cast<std::uint8_t>(1) << 2)) != 0;
    }

    static std::uint8_t cruiseControl(const std::uint8_t bits, const bool value)
    {
        return value ? (bits | (static_cast<std::uint8_t>(1) << 2)) : (bits & ~(static_cast<std::uint8_t>(1) << 2));
    }

    bool cruiseControl() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint8_t));
        return ((val) & (static_cast<std::uint8_t>(1) << 2)) != 0;
    }

    OptionalExtras &cruiseControl(const bool value)
    {
        std::uint8_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint8_t));
        bits = (value ? ((bits) | (static_cast<std::uint8_t>(1) << 2)) : ((bits) & ~(static_cast<std::uint8_t>(1) << 2)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint8_t));
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& builder, OptionalExtras writer)
    {
        builder << '[';
        bool atLeastOne = false;
        //Token{signal=CHOICE, name='sunRoof', referencedName='null', description='null', id=-1, version=0, deprecated=0, encodedLength=0, offset=0, componentTokenCount=1, encoding=Encoding{presence=REQUIRED, primitiveType=UINT8, byteOrder=LITTLE_ENDIAN, minValue=null, maxValue=null, nullValue=null, constValue=0, characterEncoding='null', epoch='null', timeUnit=null, semanticType='null'}}
        if (writer.sunRoof())
        {
            builder << "\"sunRoof\"";
            atLeastOne = true;
        }
        //Token{signal=CHOICE, name='sportsPack', referencedName='null', description='null', id=-1, version=0, deprecated=0, encodedLength=0, offset=0, componentTokenCount=1, encoding=Encoding{presence=REQUIRED, primitiveType=UINT8, byteOrder=LITTLE_ENDIAN, minValue=null, maxValue=null, nullValue=null, constValue=1, characterEncoding='null', epoch='null', timeUnit=null, semanticType='null'}}
        if (writer.sportsPack())
        {
            if (atLeastOne)
            {
                builder << ", ";
            }
            builder << "\"sportsPack\"";
            atLeastOne = true;
        }
        //Token{signal=CHOICE, name='cruiseControl', referencedName='null', description='null', id=-1, version=0, deprecated=0, encodedLength=0, offset=0, componentTokenCount=1, encoding=Encoding{presence=REQUIRED, primitiveType=UINT8, byteOrder=LITTLE_ENDIAN, minValue=null, maxValue=null, nullValue=null, constValue=2, characterEncoding='null', epoch='null', timeUnit=null, semanticType='null'}}
        if (writer.cruiseControl())
        {
            if (atLeastOne)
            {
                builder << ", ";
            }
            builder << "\"cruiseControl\"";
        }
        builder << ']';
        return builder;
    }
};
}
#endif
