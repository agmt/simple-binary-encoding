/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _BASELINE_ENGINE_H_
#define _BASELINE_ENGINE_H_

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

#include "BooleanType.h"
#include "Booster.h"
#include "BoostType.h"

namespace baseline {

class Engine
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

    Engine() = default;

    Engine(
        char *buffer,
        const std::uint64_t offset,
        const std::uint64_t bufferLength,
        const std::uint64_t actingVersion) :
        m_buffer(buffer),
        m_bufferLength(bufferLength),
        m_offset(offset),
        m_actingVersion(actingVersion)
    {
        if (SBE_BOUNDS_CHECK_EXPECT(((m_offset + 10) > m_bufferLength), false))
        {
            throw std::runtime_error("buffer too short for flyweight [E107]");
        }
    }

    Engine(
        char *buffer,
        const std::uint64_t bufferLength,
        const std::uint64_t actingVersion) :
        Engine(buffer, 0, bufferLength, actingVersion)
    {
    }

    Engine(
        char *buffer,
        const std::uint64_t bufferLength) :
        Engine(buffer, 0, bufferLength, sbeSchemaVersion())
    {
    }

    Engine &wrap(char *buffer, const std::uint64_t offset, const std::uint64_t actingVersion, const std::uint64_t bufferLength)
    {
        return *this = Engine(buffer, offset, bufferLength, actingVersion);
    }

    static SBE_CONSTEXPR std::uint64_t encodedLength() SBE_NOEXCEPT
    {
        return 10;
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

    static const char * capacityMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "";
            case MetaAttribute::TIME_UNIT: return "";
            case MetaAttribute::SEMANTIC_TYPE: return "";
            case MetaAttribute::PRESENCE: return "required";
        }

        return "";
    }

    static SBE_CONSTEXPR std::uint64_t capacitySinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool capacityInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= capacitySinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    static SBE_CONSTEXPR std::size_t capacityEncodingOffset() SBE_NOEXCEPT
    {
        return 0;
    }

    static SBE_CONSTEXPR std::uint16_t capacityNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_UINT16;
    }

    static SBE_CONSTEXPR std::uint16_t capacityMinValue() SBE_NOEXCEPT
    {
        return (std::uint16_t)0;
    }

    static SBE_CONSTEXPR std::uint16_t capacityMaxValue() SBE_NOEXCEPT
    {
        return (std::uint16_t)65534;
    }

    static SBE_CONSTEXPR std::size_t capacityEncodingLength() SBE_NOEXCEPT
    {
        return 2;
    }

    std::uint16_t capacity() const
    {
        std::uint16_t val;
        std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::uint16_t));
        return SBE_LITTLE_ENDIAN_ENCODE_16(val);
    }

    Engine &capacity(const std::uint16_t value)
    {
        std::uint16_t val = SBE_LITTLE_ENDIAN_ENCODE_16(value);
        std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::uint16_t));
        return *this;
    }

    static const char * numCylindersMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "";
            case MetaAttribute::TIME_UNIT: return "";
            case MetaAttribute::SEMANTIC_TYPE: return "";
            case MetaAttribute::PRESENCE: return "required";
        }

        return "";
    }

    static SBE_CONSTEXPR std::uint64_t numCylindersSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool numCylindersInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= numCylindersSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    static SBE_CONSTEXPR std::size_t numCylindersEncodingOffset() SBE_NOEXCEPT
    {
        return 2;
    }

    static SBE_CONSTEXPR std::uint8_t numCylindersNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_UINT8;
    }

    static SBE_CONSTEXPR std::uint8_t numCylindersMinValue() SBE_NOEXCEPT
    {
        return (std::uint8_t)0;
    }

    static SBE_CONSTEXPR std::uint8_t numCylindersMaxValue() SBE_NOEXCEPT
    {
        return (std::uint8_t)254;
    }

    static SBE_CONSTEXPR std::size_t numCylindersEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    std::uint8_t numCylinders() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 2, sizeof(std::uint8_t));
        return (val);
    }

    Engine &numCylinders(const std::uint8_t value)
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 2, &val, sizeof(std::uint8_t));
        return *this;
    }

    static const char * maxRpmMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "";
            case MetaAttribute::TIME_UNIT: return "";
            case MetaAttribute::SEMANTIC_TYPE: return "";
            case MetaAttribute::PRESENCE: return "constant";
        }

        return "";
    }

    static SBE_CONSTEXPR std::uint64_t maxRpmSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool maxRpmInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= maxRpmSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    static SBE_CONSTEXPR std::size_t maxRpmEncodingOffset() SBE_NOEXCEPT
    {
        return 3;
    }

    static SBE_CONSTEXPR std::uint16_t maxRpmNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_UINT16;
    }

    static SBE_CONSTEXPR std::uint16_t maxRpmMinValue() SBE_NOEXCEPT
    {
        return (std::uint16_t)0;
    }

    static SBE_CONSTEXPR std::uint16_t maxRpmMaxValue() SBE_NOEXCEPT
    {
        return (std::uint16_t)65534;
    }

    static SBE_CONSTEXPR std::size_t maxRpmEncodingLength() SBE_NOEXCEPT
    {
        return 0;
    }

    static SBE_CONSTEXPR std::uint16_t maxRpm() SBE_NOEXCEPT
    {
        return (std::uint16_t)9000;
    }

    static const char * manufacturerCodeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "";
            case MetaAttribute::TIME_UNIT: return "";
            case MetaAttribute::SEMANTIC_TYPE: return "";
            case MetaAttribute::PRESENCE: return "required";
        }

        return "";
    }

    static SBE_CONSTEXPR std::uint64_t manufacturerCodeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool manufacturerCodeInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= manufacturerCodeSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    static SBE_CONSTEXPR std::size_t manufacturerCodeEncodingOffset() SBE_NOEXCEPT
    {
        return 3;
    }

    static SBE_CONSTEXPR char manufacturerCodeNullValue() SBE_NOEXCEPT
    {
        return (char)0;
    }

    static SBE_CONSTEXPR char manufacturerCodeMinValue() SBE_NOEXCEPT
    {
        return (char)32;
    }

    static SBE_CONSTEXPR char manufacturerCodeMaxValue() SBE_NOEXCEPT
    {
        return (char)126;
    }

    static SBE_CONSTEXPR std::size_t manufacturerCodeEncodingLength() SBE_NOEXCEPT
    {
        return 3;
    }

    static SBE_CONSTEXPR std::uint64_t manufacturerCodeLength() SBE_NOEXCEPT
    {
        return 3;
    }

    const char *manufacturerCode() const SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 3;
    }

    char *manufacturerCode() SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 3;
    }

    char manufacturerCode(const std::uint64_t index) const
    {
        if (index >= 3)
        {
            throw std::runtime_error("index out of range for manufacturerCode [E104]");
        }

        char val;
        std::memcpy(&val, m_buffer + m_offset + 3 + (index * 1), sizeof(char));
        return (val);
    }

    Engine &manufacturerCode(const std::uint64_t index, const char value)
    {
        if (index >= 3)
        {
            throw std::runtime_error("index out of range for manufacturerCode [E105]");
        }

        char val = (value);
        std::memcpy(m_buffer + m_offset + 3 + (index * 1), &val, sizeof(char));
        return *this;
    }

    std::uint64_t getManufacturerCode(char *const dst, const std::uint64_t length) const
    {
        if (length > 3)
        {
            throw std::runtime_error("length too large for getManufacturerCode [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 3, sizeof(char) * length);
        return length;
    }

    Engine &putManufacturerCode(const char *const src) SBE_NOEXCEPT
    {
        std::memcpy(m_buffer + m_offset + 3, src, sizeof(char) * 3);
        return *this;
    }

    Engine &putManufacturerCode(
        const char value0,
        const char value1,
        const char value2) SBE_NOEXCEPT
    {
        char val0 = (value0);
        std::memcpy(m_buffer + m_offset + 3, &val0, sizeof(char));
        char val1 = (value1);
        std::memcpy(m_buffer + m_offset + 4, &val1, sizeof(char));
        char val2 = (value2);
        std::memcpy(m_buffer + m_offset + 5, &val2, sizeof(char));

        return *this;
    }

    std::string getManufacturerCodeAsString() const
    {
        const char *buffer = m_buffer + m_offset + 3;
        size_t length = 0;

        for (; length < 3 && *(buffer + length) != '\0'; ++length);
        std::string result(buffer, length);

        return result;
    }

    #if __cplusplus >= 201703L
    std::string_view getManufacturerCodeAsStringView() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 3;
        size_t length = 0;

        for (; length < 3 && *(buffer + length) != '\0'; ++length);
        std::string_view result(buffer, length);

        return result;
    }
    #endif

    #if __cplusplus >= 201703L
    Engine &putManufacturerCode(const std::string_view str)
    {
        const size_t srcLength = str.length();
        if (srcLength > 3)
        {
            throw std::runtime_error("string too large for putManufacturerCode [E106]");
        }

        std::memcpy(m_buffer + m_offset + 3, str.data(), srcLength);
        for (size_t start = srcLength; start < 3; ++start)
        {
            m_buffer[m_offset + 3 + start] = 0;
        }

        return *this;
    }
    #else
    Engine &putManufacturerCode(const std::string& str)
    {
        const size_t srcLength = str.length();
        if (srcLength > 3)
        {
            throw std::runtime_error("string too large for putManufacturerCode [E106]");
        }

        std::memcpy(m_buffer + m_offset + 3, str.c_str(), srcLength);
        for (size_t start = srcLength; start < 3; ++start)
        {
            m_buffer[m_offset + 3 + start] = 0;
        }

        return *this;
    }
    #endif

    static const char * fuelMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "";
            case MetaAttribute::TIME_UNIT: return "";
            case MetaAttribute::SEMANTIC_TYPE: return "";
            case MetaAttribute::PRESENCE: return "constant";
        }

        return "";
    }

    static SBE_CONSTEXPR std::uint64_t fuelSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool fuelInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= fuelSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    static SBE_CONSTEXPR std::size_t fuelEncodingOffset() SBE_NOEXCEPT
    {
        return 6;
    }

    static SBE_CONSTEXPR char fuelNullValue() SBE_NOEXCEPT
    {
        return (char)0;
    }

    static SBE_CONSTEXPR char fuelMinValue() SBE_NOEXCEPT
    {
        return (char)32;
    }

    static SBE_CONSTEXPR char fuelMaxValue() SBE_NOEXCEPT
    {
        return (char)126;
    }

    static SBE_CONSTEXPR std::size_t fuelEncodingLength() SBE_NOEXCEPT
    {
        return 0;
    }

    static SBE_CONSTEXPR std::uint64_t fuelLength() SBE_NOEXCEPT
    {
        return 6;
    }

    const char *fuel() const
    {
        static std::uint8_t fuelValues[] = {80, 101, 116, 114, 111, 108};

        return (const char *)fuelValues;
    }

    char fuel(const std::uint64_t index) const
    {
        static std::uint8_t fuelValues[] = {80, 101, 116, 114, 111, 108};

        return fuelValues[index];
    }

    std::uint64_t getFuel(char *dst, const std::uint64_t length) const
    {
        static std::uint8_t fuelValues[] = {80, 101, 116, 114, 111, 108};
        std::uint64_t bytesToCopy = length < sizeof(fuelValues) ? length : sizeof(fuelValues);

        std::memcpy(dst, fuelValues, bytesToCopy);
        return bytesToCopy;
    }

    static const char * efficiencyMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "";
            case MetaAttribute::TIME_UNIT: return "";
            case MetaAttribute::SEMANTIC_TYPE: return "";
            case MetaAttribute::PRESENCE: return "required";
        }

        return "";
    }

    static SBE_CONSTEXPR std::uint64_t efficiencySinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool efficiencyInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= efficiencySinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    static SBE_CONSTEXPR std::size_t efficiencyEncodingOffset() SBE_NOEXCEPT
    {
        return 6;
    }

    static SBE_CONSTEXPR std::int8_t efficiencyNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT8;
    }

    static SBE_CONSTEXPR std::int8_t efficiencyMinValue() SBE_NOEXCEPT
    {
        return (std::int8_t)0;
    }

    static SBE_CONSTEXPR std::int8_t efficiencyMaxValue() SBE_NOEXCEPT
    {
        return (std::int8_t)100;
    }

    static SBE_CONSTEXPR std::size_t efficiencyEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    std::int8_t efficiency() const
    {
        std::int8_t val;
        std::memcpy(&val, m_buffer + m_offset + 6, sizeof(std::int8_t));
        return (val);
    }

    Engine &efficiency(const std::int8_t value)
    {
        std::int8_t val = (value);
        std::memcpy(m_buffer + m_offset + 6, &val, sizeof(std::int8_t));
        return *this;
    }

    static const char * boosterEnabledMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "";
            case MetaAttribute::TIME_UNIT: return "";
            case MetaAttribute::SEMANTIC_TYPE: return "";
            case MetaAttribute::PRESENCE: return "required";
        }

        return "";
    }

    static SBE_CONSTEXPR std::uint64_t boosterEnabledSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool boosterEnabledInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= boosterEnabledSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    static SBE_CONSTEXPR std::size_t boosterEnabledEncodingOffset() SBE_NOEXCEPT
    {
        return 7;
    }

    static SBE_CONSTEXPR std::size_t boosterEnabledEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    BooleanType::Value boosterEnabled() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 7, sizeof(std::uint8_t));
        return BooleanType::get((val));
    }

    Engine &boosterEnabled(const BooleanType::Value value)
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 7, &val, sizeof(std::uint8_t));
        return *this;
    }

    static const char * boosterMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "";
            case MetaAttribute::TIME_UNIT: return "";
            case MetaAttribute::SEMANTIC_TYPE: return "";
            case MetaAttribute::PRESENCE: return "required";
        }

        return "";
    }

    static SBE_CONSTEXPR std::uint64_t boosterSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool boosterInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= boosterSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    static SBE_CONSTEXPR std::size_t boosterEncodingOffset() SBE_NOEXCEPT
    {
        return 8;
    }

    Booster booster()
    {
        return Booster(m_buffer, m_offset + 8, m_bufferLength, m_actingVersion);
    }
};

}

#endif
