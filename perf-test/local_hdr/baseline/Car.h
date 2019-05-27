/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _BASELINE_CAR_H_
#define _BASELINE_CAR_H_

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

#include "OptionalExtras.h"
#include "MessageHeader.h"
#include "Booster.h"
#include "BooleanType.h"
#include "Model.h"
#include "GroupSizeEncoding.h"
#include "VarStringEncoding.h"
#include "Engine.h"
#include "BoostType.h"

namespace baseline {

class Car
{
private:
    char *m_buffer = nullptr;
    std::uint64_t m_bufferLength = 0;
    std::uint64_t m_offset = 0;
    std::uint64_t m_position;
    std::uint64_t m_actingVersion;

    inline std::uint64_t *sbePositionPtr() SBE_NOEXCEPT
    {
        return &m_position;
    }

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

    Car() = default;

    Car(
        char *buffer,
        const std::uint64_t offset,
        const std::uint64_t bufferLength,
        const std::uint64_t actingBlockLength,
        const std::uint64_t actingVersion) :
        m_buffer(buffer),
        m_bufferLength(bufferLength),
        m_offset(offset),
        m_position(sbeCheckPosition(offset + actingBlockLength)),
        m_actingVersion(actingVersion)
    {
    }

    Car(char *buffer, const std::uint64_t bufferLength) :
        Car(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion())
    {
    }

    Car(char *buffer, const std::uint64_t bufferLength, const std::uint64_t actingBlockLength, const std::uint64_t actingVersion) :
        Car(buffer, 0, bufferLength, actingBlockLength, actingVersion)
    {
    }

    static SBE_CONSTEXPR std::uint16_t sbeBlockLength() SBE_NOEXCEPT
    {
        return (std::uint16_t)45;
    }

    static SBE_CONSTEXPR std::uint16_t sbeTemplateId() SBE_NOEXCEPT
    {
        return (std::uint16_t)1;
    }

    static SBE_CONSTEXPR std::uint16_t sbeSchemaId() SBE_NOEXCEPT
    {
        return (std::uint16_t)1;
    }

    static SBE_CONSTEXPR std::uint16_t sbeSchemaVersion() SBE_NOEXCEPT
    {
        return (std::uint16_t)0;
    }

    static SBE_CONSTEXPR const char * sbeSemanticType() SBE_NOEXCEPT
    {
        return "";
    }

    std::uint64_t offset() const SBE_NOEXCEPT
    {
        return m_offset;
    }

    Car &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        return *this = Car(buffer, offset, bufferLength, sbeBlockLength(), sbeSchemaVersion());
    }

    Car &wrapAndApplyHeader(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        MessageHeader hdr(buffer, offset, bufferLength, sbeSchemaVersion());

        hdr
            .blockLength(sbeBlockLength())
            .templateId(sbeTemplateId())
            .schemaId(sbeSchemaId())
            .version(sbeSchemaVersion());

        return *this = Car(
            buffer,
            offset + MessageHeader::encodedLength(),
            bufferLength,
            sbeBlockLength(),
            sbeSchemaVersion());
    }

    Car &wrapForDecode(
        char *buffer, const std::uint64_t offset, const std::uint64_t actingBlockLength,
        const std::uint64_t actingVersion, const std::uint64_t bufferLength)
    {
        return *this = Car(buffer, offset, bufferLength, actingBlockLength, actingVersion);
    }

    std::uint64_t sbePosition() const SBE_NOEXCEPT
    {
        return m_position;
    }

    std::uint64_t sbeCheckPosition(const std::uint64_t position)
    {
        if (SBE_BOUNDS_CHECK_EXPECT((position > m_bufferLength), false))
        {
            throw std::runtime_error("buffer too short [E100]");
        }
        return position;
    }

    void sbePosition(const std::uint64_t position)
    {
        m_position = sbeCheckPosition(position);
    }

    std::uint64_t encodedLength() const SBE_NOEXCEPT
    {
        return sbePosition() - m_offset;
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

    static const char * serialNumberMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
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

    static SBE_CONSTEXPR std::uint16_t serialNumberId() SBE_NOEXCEPT
    {
        return 1;
    }

    static SBE_CONSTEXPR std::uint64_t serialNumberSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool serialNumberInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= serialNumberSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    static SBE_CONSTEXPR std::size_t serialNumberEncodingOffset() SBE_NOEXCEPT
    {
        return 0;
    }

    static SBE_CONSTEXPR std::uint64_t serialNumberNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_UINT64;
    }

    static SBE_CONSTEXPR std::uint64_t serialNumberMinValue() SBE_NOEXCEPT
    {
        return 0x0L;
    }

    static SBE_CONSTEXPR std::uint64_t serialNumberMaxValue() SBE_NOEXCEPT
    {
        return 0xfffffffffffffffeL;
    }

    static SBE_CONSTEXPR std::size_t serialNumberEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    std::uint64_t serialNumber() const
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::uint64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    Car &serialNumber(const std::uint64_t value)
    {
        std::uint64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::uint64_t));
        return *this;
    }

    static const char * modelYearMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
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

    static SBE_CONSTEXPR std::uint16_t modelYearId() SBE_NOEXCEPT
    {
        return 2;
    }

    static SBE_CONSTEXPR std::uint64_t modelYearSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool modelYearInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= modelYearSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    static SBE_CONSTEXPR std::size_t modelYearEncodingOffset() SBE_NOEXCEPT
    {
        return 8;
    }

    static SBE_CONSTEXPR std::uint16_t modelYearNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_UINT16;
    }

    static SBE_CONSTEXPR std::uint16_t modelYearMinValue() SBE_NOEXCEPT
    {
        return (std::uint16_t)0;
    }

    static SBE_CONSTEXPR std::uint16_t modelYearMaxValue() SBE_NOEXCEPT
    {
        return (std::uint16_t)65534;
    }

    static SBE_CONSTEXPR std::size_t modelYearEncodingLength() SBE_NOEXCEPT
    {
        return 2;
    }

    std::uint16_t modelYear() const
    {
        std::uint16_t val;
        std::memcpy(&val, m_buffer + m_offset + 8, sizeof(std::uint16_t));
        return SBE_LITTLE_ENDIAN_ENCODE_16(val);
    }

    Car &modelYear(const std::uint16_t value)
    {
        std::uint16_t val = SBE_LITTLE_ENDIAN_ENCODE_16(value);
        std::memcpy(m_buffer + m_offset + 8, &val, sizeof(std::uint16_t));
        return *this;
    }

    static const char * availableMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
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

    static SBE_CONSTEXPR std::uint16_t availableId() SBE_NOEXCEPT
    {
        return 3;
    }

    static SBE_CONSTEXPR std::uint64_t availableSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool availableInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= availableSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    static SBE_CONSTEXPR std::size_t availableEncodingOffset() SBE_NOEXCEPT
    {
        return 10;
    }

    static SBE_CONSTEXPR std::size_t availableEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    BooleanType::Value available() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 10, sizeof(std::uint8_t));
        return BooleanType::get((val));
    }

    Car &available(const BooleanType::Value value)
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 10, &val, sizeof(std::uint8_t));
        return *this;
    }

    static const char * codeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
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

    static SBE_CONSTEXPR std::uint16_t codeId() SBE_NOEXCEPT
    {
        return 4;
    }

    static SBE_CONSTEXPR std::uint64_t codeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool codeInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= codeSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    static SBE_CONSTEXPR std::size_t codeEncodingOffset() SBE_NOEXCEPT
    {
        return 11;
    }

    static SBE_CONSTEXPR std::size_t codeEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    Model::Value code() const
    {
        char val;
        std::memcpy(&val, m_buffer + m_offset + 11, sizeof(char));
        return Model::get((val));
    }

    Car &code(const Model::Value value)
    {
        char val = (value);
        std::memcpy(m_buffer + m_offset + 11, &val, sizeof(char));
        return *this;
    }

    static const char * someNumbersMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
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

    static SBE_CONSTEXPR std::uint16_t someNumbersId() SBE_NOEXCEPT
    {
        return 5;
    }

    static SBE_CONSTEXPR std::uint64_t someNumbersSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool someNumbersInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= someNumbersSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    static SBE_CONSTEXPR std::size_t someNumbersEncodingOffset() SBE_NOEXCEPT
    {
        return 12;
    }

    static SBE_CONSTEXPR std::uint32_t someNumbersNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_UINT32;
    }

    static SBE_CONSTEXPR std::uint32_t someNumbersMinValue() SBE_NOEXCEPT
    {
        return 0;
    }

    static SBE_CONSTEXPR std::uint32_t someNumbersMaxValue() SBE_NOEXCEPT
    {
        return 4294967294;
    }

    static SBE_CONSTEXPR std::size_t someNumbersEncodingLength() SBE_NOEXCEPT
    {
        return 16;
    }

    static SBE_CONSTEXPR std::uint64_t someNumbersLength() SBE_NOEXCEPT
    {
        return 4;
    }

    const char *someNumbers() const SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 12;
    }

    char *someNumbers() SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 12;
    }

    std::uint32_t someNumbers(const std::uint64_t index) const
    {
        if (index >= 4)
        {
            throw std::runtime_error("index out of range for someNumbers [E104]");
        }

        std::uint32_t val;
        std::memcpy(&val, m_buffer + m_offset + 12 + (index * 4), sizeof(std::uint32_t));
        return SBE_LITTLE_ENDIAN_ENCODE_32(val);
    }

    Car &someNumbers(const std::uint64_t index, const std::uint32_t value)
    {
        if (index >= 4)
        {
            throw std::runtime_error("index out of range for someNumbers [E105]");
        }

        std::uint32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        std::memcpy(m_buffer + m_offset + 12 + (index * 4), &val, sizeof(std::uint32_t));
        return *this;
    }

    std::uint64_t getSomeNumbers(char *const dst, const std::uint64_t length) const
    {
        if (length > 4)
        {
            throw std::runtime_error("length too large for getSomeNumbers [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 12, sizeof(std::uint32_t) * length);
        return length;
    }

    Car &putSomeNumbers(const char *const src) SBE_NOEXCEPT
    {
        std::memcpy(m_buffer + m_offset + 12, src, sizeof(std::uint32_t) * 4);
        return *this;
    }

    Car &putSomeNumbers(
        const std::uint32_t value0,
        const std::uint32_t value1,
        const std::uint32_t value2,
        const std::uint32_t value3) SBE_NOEXCEPT
    {
        std::uint32_t val0 = SBE_LITTLE_ENDIAN_ENCODE_32(value0);
        std::memcpy(m_buffer + m_offset + 12, &val0, sizeof(std::uint32_t));
        std::uint32_t val1 = SBE_LITTLE_ENDIAN_ENCODE_32(value1);
        std::memcpy(m_buffer + m_offset + 16, &val1, sizeof(std::uint32_t));
        std::uint32_t val2 = SBE_LITTLE_ENDIAN_ENCODE_32(value2);
        std::memcpy(m_buffer + m_offset + 20, &val2, sizeof(std::uint32_t));
        std::uint32_t val3 = SBE_LITTLE_ENDIAN_ENCODE_32(value3);
        std::memcpy(m_buffer + m_offset + 24, &val3, sizeof(std::uint32_t));

        return *this;
    }

    static const char * vehicleCodeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
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

    static SBE_CONSTEXPR std::uint16_t vehicleCodeId() SBE_NOEXCEPT
    {
        return 6;
    }

    static SBE_CONSTEXPR std::uint64_t vehicleCodeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool vehicleCodeInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= vehicleCodeSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    static SBE_CONSTEXPR std::size_t vehicleCodeEncodingOffset() SBE_NOEXCEPT
    {
        return 28;
    }

    static SBE_CONSTEXPR char vehicleCodeNullValue() SBE_NOEXCEPT
    {
        return (char)0;
    }

    static SBE_CONSTEXPR char vehicleCodeMinValue() SBE_NOEXCEPT
    {
        return (char)32;
    }

    static SBE_CONSTEXPR char vehicleCodeMaxValue() SBE_NOEXCEPT
    {
        return (char)126;
    }

    static SBE_CONSTEXPR std::size_t vehicleCodeEncodingLength() SBE_NOEXCEPT
    {
        return 6;
    }

    static SBE_CONSTEXPR std::uint64_t vehicleCodeLength() SBE_NOEXCEPT
    {
        return 6;
    }

    const char *vehicleCode() const SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 28;
    }

    char *vehicleCode() SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 28;
    }

    char vehicleCode(const std::uint64_t index) const
    {
        if (index >= 6)
        {
            throw std::runtime_error("index out of range for vehicleCode [E104]");
        }

        char val;
        std::memcpy(&val, m_buffer + m_offset + 28 + (index * 1), sizeof(char));
        return (val);
    }

    Car &vehicleCode(const std::uint64_t index, const char value)
    {
        if (index >= 6)
        {
            throw std::runtime_error("index out of range for vehicleCode [E105]");
        }

        char val = (value);
        std::memcpy(m_buffer + m_offset + 28 + (index * 1), &val, sizeof(char));
        return *this;
    }

    std::uint64_t getVehicleCode(char *const dst, const std::uint64_t length) const
    {
        if (length > 6)
        {
            throw std::runtime_error("length too large for getVehicleCode [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 28, sizeof(char) * length);
        return length;
    }

    Car &putVehicleCode(const char *const src) SBE_NOEXCEPT
    {
        std::memcpy(m_buffer + m_offset + 28, src, sizeof(char) * 6);
        return *this;
    }

    std::string getVehicleCodeAsString() const
    {
        const char *buffer = m_buffer + m_offset + 28;
        size_t length = 0;

        for (; length < 6 && *(buffer + length) != '\0'; ++length);
        std::string result(buffer, length);

        return result;
    }

    #if __cplusplus >= 201703L
    std::string_view getVehicleCodeAsStringView() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 28;
        size_t length = 0;

        for (; length < 6 && *(buffer + length) != '\0'; ++length);
        std::string_view result(buffer, length);

        return result;
    }
    #endif

    #if __cplusplus >= 201703L
    Car &putVehicleCode(const std::string_view str)
    {
        const size_t srcLength = str.length();
        if (srcLength > 6)
        {
            throw std::runtime_error("string too large for putVehicleCode [E106]");
        }

        std::memcpy(m_buffer + m_offset + 28, str.data(), srcLength);
        for (size_t start = srcLength; start < 6; ++start)
        {
            m_buffer[m_offset + 28 + start] = 0;
        }

        return *this;
    }
    #else
    Car &putVehicleCode(const std::string& str)
    {
        const size_t srcLength = str.length();
        if (srcLength > 6)
        {
            throw std::runtime_error("string too large for putVehicleCode [E106]");
        }

        std::memcpy(m_buffer + m_offset + 28, str.c_str(), srcLength);
        for (size_t start = srcLength; start < 6; ++start)
        {
            m_buffer[m_offset + 28 + start] = 0;
        }

        return *this;
    }
    #endif

    static const char * extrasMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
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

    static SBE_CONSTEXPR std::uint16_t extrasId() SBE_NOEXCEPT
    {
        return 7;
    }

    static SBE_CONSTEXPR std::uint64_t extrasSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool extrasInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= extrasSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    static SBE_CONSTEXPR std::size_t extrasEncodingOffset() SBE_NOEXCEPT
    {
        return 34;
    }

    OptionalExtras extras()
    {
        return OptionalExtras(m_buffer, m_offset + 34, m_bufferLength, m_actingVersion);
    }

    static SBE_CONSTEXPR std::size_t extrasEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    static const char * discountedModelMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
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

    static SBE_CONSTEXPR std::uint16_t discountedModelId() SBE_NOEXCEPT
    {
        return 8;
    }

    static SBE_CONSTEXPR std::uint64_t discountedModelSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool discountedModelInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= discountedModelSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    static SBE_CONSTEXPR std::size_t discountedModelEncodingOffset() SBE_NOEXCEPT
    {
        return 35;
    }

    static SBE_CONSTEXPR std::size_t discountedModelEncodingLength() SBE_NOEXCEPT
    {
        return 0;
    }

    static SBE_CONSTEXPR Model::Value discountedModelConstValue() SBE_NOEXCEPT
    {
        return Model::Value::C;
    }

    Model::Value discountedModel() const SBE_NOEXCEPT
    {
        return Model::Value::C;
    }

    static const char * engineMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
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

    static SBE_CONSTEXPR std::uint16_t engineId() SBE_NOEXCEPT
    {
        return 9;
    }

    static SBE_CONSTEXPR std::uint64_t engineSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool engineInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= engineSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    static SBE_CONSTEXPR std::size_t engineEncodingOffset() SBE_NOEXCEPT
    {
        return 35;
    }

    Engine engine()
    {
        return Engine(m_buffer, m_offset + 35, m_bufferLength, m_actingVersion);
    }

    class FuelFigures
    {
    private:
        char *m_buffer;
        std::uint64_t m_bufferLength;
        std::uint64_t *m_positionPtr;
        std::uint64_t m_blockLength;
        std::uint64_t m_count;
        std::uint64_t m_index;
        std::uint64_t m_offset;
        std::uint64_t m_actingVersion;

        std::uint64_t *sbePositionPtr() SBE_NOEXCEPT
        {
            return m_positionPtr;
        }

    public:
        inline void wrapForDecode(
            char *buffer,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
            GroupSizeEncoding dimensions(buffer, *pos, bufferLength, actingVersion);
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            m_blockLength = dimensions.blockLength();
            m_count = dimensions.numInGroup();
            m_index = -1;
            m_actingVersion = actingVersion;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 4;
        }

        inline void wrapForEncode(
            char *buffer,
            const std::uint16_t count,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wtype-limits"
    #endif
            if (count > 65534)
            {
                throw std::runtime_error("count outside of allowed range [E110]");
            }
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic pop
    #endif
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            GroupSizeEncoding dimensions(buffer, *pos, bufferLength, actingVersion);
            dimensions.blockLength((std::uint16_t)6);
            dimensions.numInGroup((std::uint16_t)count);
            m_index = -1;
            m_count = count;
            m_blockLength = 6;
            m_actingVersion = actingVersion;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 4;
        }

        static SBE_CONSTEXPR std::uint64_t sbeHeaderSize() SBE_NOEXCEPT
        {
            return 4;
        }

        static SBE_CONSTEXPR std::uint64_t sbeBlockLength() SBE_NOEXCEPT
        {
            return 6;
        }

        std::uint64_t sbePosition() const
        {
            return *m_positionPtr;
        }

        std::uint64_t sbeCheckPosition(const std::uint64_t position)
        {
            if (SBE_BOUNDS_CHECK_EXPECT((position > m_bufferLength), false))
            {
                throw std::runtime_error("buffer too short [E100]");
            }
            return position;
        }

        void sbePosition(const std::uint64_t position)
        {
            *m_positionPtr = sbeCheckPosition(position);
        }

        inline std::uint64_t count() const SBE_NOEXCEPT
        {
            return m_count;
        }

        inline bool hasNext() const SBE_NOEXCEPT
        {
            return m_index + 1 < m_count;
        }

        inline FuelFigures &next()
        {
            m_offset = *m_positionPtr;
            if (SBE_BOUNDS_CHECK_EXPECT(((m_offset + m_blockLength) > m_bufferLength), false))
            {
                throw std::runtime_error("buffer too short to support next group index [E108]");
            }
            *m_positionPtr = m_offset + m_blockLength;
            ++m_index;

            return *this;
        }
    #if __cplusplus < 201103L
        template<class Func> inline void forEach(Func& func)
        {
            while (hasNext())
            {
                next();
                func(*this);
            }
        }

    #else
        template<class Func> inline void forEach(Func&& func)
        {
            while (hasNext())
            {
                next();
                func(*this);
            }
        }

    #endif

        static const char * speedMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
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

        static SBE_CONSTEXPR std::uint16_t speedId() SBE_NOEXCEPT
        {
            return 11;
        }

        static SBE_CONSTEXPR std::uint64_t speedSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        bool speedInActingVersion() SBE_NOEXCEPT
        {
    #if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wtautological-compare"
    #endif
            return m_actingVersion >= speedSinceVersion();
    #if defined(__clang__)
    #pragma clang diagnostic pop
    #endif
        }

        static SBE_CONSTEXPR std::size_t speedEncodingOffset() SBE_NOEXCEPT
        {
            return 0;
        }

        static SBE_CONSTEXPR std::uint16_t speedNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_UINT16;
        }

        static SBE_CONSTEXPR std::uint16_t speedMinValue() SBE_NOEXCEPT
        {
            return (std::uint16_t)0;
        }

        static SBE_CONSTEXPR std::uint16_t speedMaxValue() SBE_NOEXCEPT
        {
            return (std::uint16_t)65534;
        }

        static SBE_CONSTEXPR std::size_t speedEncodingLength() SBE_NOEXCEPT
        {
            return 2;
        }

        std::uint16_t speed() const
        {
            std::uint16_t val;
            std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::uint16_t));
            return SBE_LITTLE_ENDIAN_ENCODE_16(val);
        }

        FuelFigures &speed(const std::uint16_t value)
        {
            std::uint16_t val = SBE_LITTLE_ENDIAN_ENCODE_16(value);
            std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::uint16_t));
            return *this;
        }

        static const char * mpgMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
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

        static SBE_CONSTEXPR std::uint16_t mpgId() SBE_NOEXCEPT
        {
            return 12;
        }

        static SBE_CONSTEXPR std::uint64_t mpgSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        bool mpgInActingVersion() SBE_NOEXCEPT
        {
    #if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wtautological-compare"
    #endif
            return m_actingVersion >= mpgSinceVersion();
    #if defined(__clang__)
    #pragma clang diagnostic pop
    #endif
        }

        static SBE_CONSTEXPR std::size_t mpgEncodingOffset() SBE_NOEXCEPT
        {
            return 2;
        }

        static SBE_CONSTEXPR float mpgNullValue() SBE_NOEXCEPT
        {
            return SBE_FLOAT_NAN;
        }

        static SBE_CONSTEXPR float mpgMinValue() SBE_NOEXCEPT
        {
            return 1.401298464324817E-45f;
        }

        static SBE_CONSTEXPR float mpgMaxValue() SBE_NOEXCEPT
        {
            return 3.4028234663852886E38f;
        }

        static SBE_CONSTEXPR std::size_t mpgEncodingLength() SBE_NOEXCEPT
        {
            return 4;
        }

        float mpg() const
        {
            union sbe_float_as_uint_u val;
            std::memcpy(&val, m_buffer + m_offset + 2, sizeof(float));
            val.uint_value = SBE_LITTLE_ENDIAN_ENCODE_32(val.uint_value);
            return val.fp_value;
        }

        FuelFigures &mpg(const float value)
        {
            union sbe_float_as_uint_u val;
            val.fp_value = value;
            val.uint_value = SBE_LITTLE_ENDIAN_ENCODE_32(val.uint_value);
            std::memcpy(m_buffer + m_offset + 2, &val, sizeof(float));
            return *this;
        }

        static const char * usageDescriptionMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "";
                case MetaAttribute::PRESENCE: return "required";
            }

            return "";
        }

        static const char *usageDescriptionCharacterEncoding() SBE_NOEXCEPT
        {
            return "UTF-8";
        }

        static SBE_CONSTEXPR std::uint64_t usageDescriptionSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        bool usageDescriptionInActingVersion() SBE_NOEXCEPT
        {
    #if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wtautological-compare"
    #endif
            return m_actingVersion >= usageDescriptionSinceVersion();
    #if defined(__clang__)
    #pragma clang diagnostic pop
    #endif
        }

        static SBE_CONSTEXPR std::uint16_t usageDescriptionId() SBE_NOEXCEPT
        {
            return 200;
        }

        static SBE_CONSTEXPR std::uint64_t usageDescriptionHeaderLength() SBE_NOEXCEPT
        {
            return 4;
        }

        std::uint32_t usageDescriptionLength() const
        {
            std::uint32_t length;
            std::memcpy(&length, m_buffer + sbePosition(), sizeof(std::uint32_t));
            return SBE_LITTLE_ENDIAN_ENCODE_32(length);
        }

        const char *usageDescription()
        {
            std::uint32_t lengthFieldValue;
            std::memcpy(&lengthFieldValue, m_buffer + sbePosition(), sizeof(std::uint32_t));
            const char *fieldPtr = m_buffer + sbePosition() + 4;
            sbePosition(sbePosition() + 4 + SBE_LITTLE_ENDIAN_ENCODE_32(lengthFieldValue));
            return fieldPtr;
        }

        std::uint64_t getUsageDescription(char *dst, const std::uint64_t length)
        {
            std::uint64_t lengthOfLengthField = 4;
            std::uint64_t lengthPosition = sbePosition();
            sbePosition(lengthPosition + lengthOfLengthField);
            std::uint32_t lengthFieldValue;
            std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint32_t));
            std::uint64_t dataLength = SBE_LITTLE_ENDIAN_ENCODE_32(lengthFieldValue);
            std::uint64_t bytesToCopy = length < dataLength ? length : dataLength;
            std::uint64_t pos = sbePosition();
            sbePosition(pos + dataLength);
            std::memcpy(dst, m_buffer + pos, bytesToCopy);
            return bytesToCopy;
        }

        FuelFigures &putUsageDescription(const char *src, const std::uint32_t length)
        {
            std::uint64_t lengthOfLengthField = 4;
            std::uint64_t lengthPosition = sbePosition();
            std::uint32_t lengthFieldValue = SBE_LITTLE_ENDIAN_ENCODE_32(length);
            sbePosition(lengthPosition + lengthOfLengthField);
            std::memcpy(m_buffer + lengthPosition, &lengthFieldValue, sizeof(std::uint32_t));
            std::uint64_t pos = sbePosition();
            sbePosition(pos + length);
            std::memcpy(m_buffer + pos, src, length);
            return *this;
        }

        std::string getUsageDescriptionAsString()
        {
            std::uint64_t lengthOfLengthField = 4;
            std::uint64_t lengthPosition = sbePosition();
            sbePosition(lengthPosition + lengthOfLengthField);
            std::uint32_t lengthFieldValue;
            std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint32_t));
            std::uint64_t dataLength = SBE_LITTLE_ENDIAN_ENCODE_32(lengthFieldValue);
            std::uint64_t pos = sbePosition();
            const std::string result(m_buffer + pos, dataLength);
            sbePosition(pos + dataLength);
            return result;
        }

        #if __cplusplus >= 201703L
        std::string_view getUsageDescriptionAsStringView()
        {
            std::uint64_t lengthOfLengthField = 4;
            std::uint64_t lengthPosition = sbePosition();
            sbePosition(lengthPosition + lengthOfLengthField);
            std::uint32_t lengthFieldValue;
            std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint32_t));
            std::uint64_t dataLength = SBE_LITTLE_ENDIAN_ENCODE_32(lengthFieldValue);
            std::uint64_t pos = sbePosition();
            const std::string_view result(m_buffer + pos, dataLength);
            sbePosition(pos + dataLength);
            return result;
        }
        #endif

        FuelFigures &putUsageDescription(const std::string& str)
        {
            if (str.length() > 1073741824)
            {
                throw std::runtime_error("std::string too long for length type [E109]");
            }
            std::uint64_t lengthOfLengthField = 4;
            std::uint64_t lengthPosition = sbePosition();
            std::uint32_t lengthFieldValue = SBE_LITTLE_ENDIAN_ENCODE_32(static_cast<std::uint32_t>(str.length()));
            sbePosition(lengthPosition + lengthOfLengthField);
            std::memcpy(m_buffer + lengthPosition, &lengthFieldValue, sizeof(std::uint32_t));
            std::uint64_t pos = sbePosition();
            sbePosition(pos + str.length());
            std::memcpy(m_buffer + pos, str.c_str(), str.length());
            return *this;
        }
    };

private:
    FuelFigures m_fuelFigures;

public:
    static SBE_CONSTEXPR std::uint16_t fuelFiguresId() SBE_NOEXCEPT
    {
        return 10;
    }

    inline FuelFigures &fuelFigures()
    {
        m_fuelFigures.wrapForDecode(m_buffer, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_fuelFigures;
    }

    FuelFigures &fuelFiguresCount(const std::uint16_t count)
    {
        m_fuelFigures.wrapForEncode(m_buffer, count, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_fuelFigures;
    }

    static SBE_CONSTEXPR std::uint64_t fuelFiguresSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool fuelFiguresInActingVersion() const SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= fuelFiguresSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    class PerformanceFigures
    {
    private:
        char *m_buffer;
        std::uint64_t m_bufferLength;
        std::uint64_t *m_positionPtr;
        std::uint64_t m_blockLength;
        std::uint64_t m_count;
        std::uint64_t m_index;
        std::uint64_t m_offset;
        std::uint64_t m_actingVersion;

        std::uint64_t *sbePositionPtr() SBE_NOEXCEPT
        {
            return m_positionPtr;
        }

    public:
        inline void wrapForDecode(
            char *buffer,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
            GroupSizeEncoding dimensions(buffer, *pos, bufferLength, actingVersion);
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            m_blockLength = dimensions.blockLength();
            m_count = dimensions.numInGroup();
            m_index = -1;
            m_actingVersion = actingVersion;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 4;
        }

        inline void wrapForEncode(
            char *buffer,
            const std::uint16_t count,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wtype-limits"
    #endif
            if (count > 65534)
            {
                throw std::runtime_error("count outside of allowed range [E110]");
            }
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic pop
    #endif
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            GroupSizeEncoding dimensions(buffer, *pos, bufferLength, actingVersion);
            dimensions.blockLength((std::uint16_t)1);
            dimensions.numInGroup((std::uint16_t)count);
            m_index = -1;
            m_count = count;
            m_blockLength = 1;
            m_actingVersion = actingVersion;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 4;
        }

        static SBE_CONSTEXPR std::uint64_t sbeHeaderSize() SBE_NOEXCEPT
        {
            return 4;
        }

        static SBE_CONSTEXPR std::uint64_t sbeBlockLength() SBE_NOEXCEPT
        {
            return 1;
        }

        std::uint64_t sbePosition() const
        {
            return *m_positionPtr;
        }

        std::uint64_t sbeCheckPosition(const std::uint64_t position)
        {
            if (SBE_BOUNDS_CHECK_EXPECT((position > m_bufferLength), false))
            {
                throw std::runtime_error("buffer too short [E100]");
            }
            return position;
        }

        void sbePosition(const std::uint64_t position)
        {
            *m_positionPtr = sbeCheckPosition(position);
        }

        inline std::uint64_t count() const SBE_NOEXCEPT
        {
            return m_count;
        }

        inline bool hasNext() const SBE_NOEXCEPT
        {
            return m_index + 1 < m_count;
        }

        inline PerformanceFigures &next()
        {
            m_offset = *m_positionPtr;
            if (SBE_BOUNDS_CHECK_EXPECT(((m_offset + m_blockLength) > m_bufferLength), false))
            {
                throw std::runtime_error("buffer too short to support next group index [E108]");
            }
            *m_positionPtr = m_offset + m_blockLength;
            ++m_index;

            return *this;
        }
    #if __cplusplus < 201103L
        template<class Func> inline void forEach(Func& func)
        {
            while (hasNext())
            {
                next();
                func(*this);
            }
        }

    #else
        template<class Func> inline void forEach(Func&& func)
        {
            while (hasNext())
            {
                next();
                func(*this);
            }
        }

    #endif

        static const char * octaneRatingMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
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

        static SBE_CONSTEXPR std::uint16_t octaneRatingId() SBE_NOEXCEPT
        {
            return 14;
        }

        static SBE_CONSTEXPR std::uint64_t octaneRatingSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        bool octaneRatingInActingVersion() SBE_NOEXCEPT
        {
    #if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wtautological-compare"
    #endif
            return m_actingVersion >= octaneRatingSinceVersion();
    #if defined(__clang__)
    #pragma clang diagnostic pop
    #endif
        }

        static SBE_CONSTEXPR std::size_t octaneRatingEncodingOffset() SBE_NOEXCEPT
        {
            return 0;
        }

        static SBE_CONSTEXPR std::uint8_t octaneRatingNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_UINT8;
        }

        static SBE_CONSTEXPR std::uint8_t octaneRatingMinValue() SBE_NOEXCEPT
        {
            return (std::uint8_t)90;
        }

        static SBE_CONSTEXPR std::uint8_t octaneRatingMaxValue() SBE_NOEXCEPT
        {
            return (std::uint8_t)110;
        }

        static SBE_CONSTEXPR std::size_t octaneRatingEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        std::uint8_t octaneRating() const
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::uint8_t));
            return (val);
        }

        PerformanceFigures &octaneRating(const std::uint8_t value)
        {
            std::uint8_t val = (value);
            std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::uint8_t));
            return *this;
        }

        class Acceleration
        {
        private:
            char *m_buffer;
            std::uint64_t m_bufferLength;
            std::uint64_t *m_positionPtr;
            std::uint64_t m_blockLength;
            std::uint64_t m_count;
            std::uint64_t m_index;
            std::uint64_t m_offset;
            std::uint64_t m_actingVersion;

            std::uint64_t *sbePositionPtr() SBE_NOEXCEPT
            {
                return m_positionPtr;
            }

        public:
            inline void wrapForDecode(
                char *buffer,
                std::uint64_t *pos,
                const std::uint64_t actingVersion,
                const std::uint64_t bufferLength)
            {
                GroupSizeEncoding dimensions(buffer, *pos, bufferLength, actingVersion);
                m_buffer = buffer;
                m_bufferLength = bufferLength;
                m_blockLength = dimensions.blockLength();
                m_count = dimensions.numInGroup();
                m_index = -1;
                m_actingVersion = actingVersion;
                m_positionPtr = pos;
                *m_positionPtr = *m_positionPtr + 4;
            }

            inline void wrapForEncode(
                char *buffer,
                const std::uint16_t count,
                std::uint64_t *pos,
                const std::uint64_t actingVersion,
                const std::uint64_t bufferLength)
            {
        #if defined(__GNUG__) && !defined(__clang__)
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wtype-limits"
        #endif
                if (count > 65534)
                {
                    throw std::runtime_error("count outside of allowed range [E110]");
                }
        #if defined(__GNUG__) && !defined(__clang__)
        #pragma GCC diagnostic pop
        #endif
                m_buffer = buffer;
                m_bufferLength = bufferLength;
                GroupSizeEncoding dimensions(buffer, *pos, bufferLength, actingVersion);
                dimensions.blockLength((std::uint16_t)6);
                dimensions.numInGroup((std::uint16_t)count);
                m_index = -1;
                m_count = count;
                m_blockLength = 6;
                m_actingVersion = actingVersion;
                m_positionPtr = pos;
                *m_positionPtr = *m_positionPtr + 4;
            }

            static SBE_CONSTEXPR std::uint64_t sbeHeaderSize() SBE_NOEXCEPT
            {
                return 4;
            }

            static SBE_CONSTEXPR std::uint64_t sbeBlockLength() SBE_NOEXCEPT
            {
                return 6;
            }

            std::uint64_t sbePosition() const
            {
                return *m_positionPtr;
            }

            std::uint64_t sbeCheckPosition(const std::uint64_t position)
            {
                if (SBE_BOUNDS_CHECK_EXPECT((position > m_bufferLength), false))
                {
                    throw std::runtime_error("buffer too short [E100]");
                }
                return position;
            }

            void sbePosition(const std::uint64_t position)
            {
                *m_positionPtr = sbeCheckPosition(position);
            }

            inline std::uint64_t count() const SBE_NOEXCEPT
            {
                return m_count;
            }

            inline bool hasNext() const SBE_NOEXCEPT
            {
                return m_index + 1 < m_count;
            }

            inline Acceleration &next()
            {
                m_offset = *m_positionPtr;
                if (SBE_BOUNDS_CHECK_EXPECT(((m_offset + m_blockLength) > m_bufferLength), false))
                {
                    throw std::runtime_error("buffer too short to support next group index [E108]");
                }
                *m_positionPtr = m_offset + m_blockLength;
                ++m_index;

                return *this;
            }
        #if __cplusplus < 201103L
            template<class Func> inline void forEach(Func& func)
            {
                while (hasNext())
                {
                    next();
                    func(*this);
                }
            }

        #else
            template<class Func> inline void forEach(Func&& func)
            {
                while (hasNext())
                {
                    next();
                    func(*this);
                }
            }

        #endif

            static const char * mphMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
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

            static SBE_CONSTEXPR std::uint16_t mphId() SBE_NOEXCEPT
            {
                return 16;
            }

            static SBE_CONSTEXPR std::uint64_t mphSinceVersion() SBE_NOEXCEPT
            {
                return 0;
            }

            bool mphInActingVersion() SBE_NOEXCEPT
            {
        #if defined(__clang__)
        #pragma clang diagnostic push
        #pragma clang diagnostic ignored "-Wtautological-compare"
        #endif
                return m_actingVersion >= mphSinceVersion();
        #if defined(__clang__)
        #pragma clang diagnostic pop
        #endif
            }

            static SBE_CONSTEXPR std::size_t mphEncodingOffset() SBE_NOEXCEPT
            {
                return 0;
            }

            static SBE_CONSTEXPR std::uint16_t mphNullValue() SBE_NOEXCEPT
            {
                return SBE_NULLVALUE_UINT16;
            }

            static SBE_CONSTEXPR std::uint16_t mphMinValue() SBE_NOEXCEPT
            {
                return (std::uint16_t)0;
            }

            static SBE_CONSTEXPR std::uint16_t mphMaxValue() SBE_NOEXCEPT
            {
                return (std::uint16_t)65534;
            }

            static SBE_CONSTEXPR std::size_t mphEncodingLength() SBE_NOEXCEPT
            {
                return 2;
            }

            std::uint16_t mph() const
            {
                std::uint16_t val;
                std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::uint16_t));
                return SBE_LITTLE_ENDIAN_ENCODE_16(val);
            }

            Acceleration &mph(const std::uint16_t value)
            {
                std::uint16_t val = SBE_LITTLE_ENDIAN_ENCODE_16(value);
                std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::uint16_t));
                return *this;
            }

            static const char * secondsMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
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

            static SBE_CONSTEXPR std::uint16_t secondsId() SBE_NOEXCEPT
            {
                return 17;
            }

            static SBE_CONSTEXPR std::uint64_t secondsSinceVersion() SBE_NOEXCEPT
            {
                return 0;
            }

            bool secondsInActingVersion() SBE_NOEXCEPT
            {
        #if defined(__clang__)
        #pragma clang diagnostic push
        #pragma clang diagnostic ignored "-Wtautological-compare"
        #endif
                return m_actingVersion >= secondsSinceVersion();
        #if defined(__clang__)
        #pragma clang diagnostic pop
        #endif
            }

            static SBE_CONSTEXPR std::size_t secondsEncodingOffset() SBE_NOEXCEPT
            {
                return 2;
            }

            static SBE_CONSTEXPR float secondsNullValue() SBE_NOEXCEPT
            {
                return SBE_FLOAT_NAN;
            }

            static SBE_CONSTEXPR float secondsMinValue() SBE_NOEXCEPT
            {
                return 1.401298464324817E-45f;
            }

            static SBE_CONSTEXPR float secondsMaxValue() SBE_NOEXCEPT
            {
                return 3.4028234663852886E38f;
            }

            static SBE_CONSTEXPR std::size_t secondsEncodingLength() SBE_NOEXCEPT
            {
                return 4;
            }

            float seconds() const
            {
                union sbe_float_as_uint_u val;
                std::memcpy(&val, m_buffer + m_offset + 2, sizeof(float));
                val.uint_value = SBE_LITTLE_ENDIAN_ENCODE_32(val.uint_value);
                return val.fp_value;
            }

            Acceleration &seconds(const float value)
            {
                union sbe_float_as_uint_u val;
                val.fp_value = value;
                val.uint_value = SBE_LITTLE_ENDIAN_ENCODE_32(val.uint_value);
                std::memcpy(m_buffer + m_offset + 2, &val, sizeof(float));
                return *this;
            }
        };

private:
        Acceleration m_acceleration;

public:
        static SBE_CONSTEXPR std::uint16_t accelerationId() SBE_NOEXCEPT
        {
            return 15;
        }

        inline Acceleration &acceleration()
        {
            m_acceleration.wrapForDecode(m_buffer, sbePositionPtr(), m_actingVersion, m_bufferLength);
            return m_acceleration;
        }

        Acceleration &accelerationCount(const std::uint16_t count)
        {
            m_acceleration.wrapForEncode(m_buffer, count, sbePositionPtr(), m_actingVersion, m_bufferLength);
            return m_acceleration;
        }

        static SBE_CONSTEXPR std::uint64_t accelerationSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        bool accelerationInActingVersion() const SBE_NOEXCEPT
        {
    #if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wtautological-compare"
    #endif
            return m_actingVersion >= accelerationSinceVersion();
    #if defined(__clang__)
    #pragma clang diagnostic pop
    #endif
        }
    };

private:
    PerformanceFigures m_performanceFigures;

public:
    static SBE_CONSTEXPR std::uint16_t performanceFiguresId() SBE_NOEXCEPT
    {
        return 13;
    }

    inline PerformanceFigures &performanceFigures()
    {
        m_performanceFigures.wrapForDecode(m_buffer, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_performanceFigures;
    }

    PerformanceFigures &performanceFiguresCount(const std::uint16_t count)
    {
        m_performanceFigures.wrapForEncode(m_buffer, count, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_performanceFigures;
    }

    static SBE_CONSTEXPR std::uint64_t performanceFiguresSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool performanceFiguresInActingVersion() const SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= performanceFiguresSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    static const char * manufacturerMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
            case MetaAttribute::PRESENCE: return "required";
        }

        return "";
    }

    static const char *manufacturerCharacterEncoding() SBE_NOEXCEPT
    {
        return "UTF-8";
    }

    static SBE_CONSTEXPR std::uint64_t manufacturerSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool manufacturerInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= manufacturerSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    static SBE_CONSTEXPR std::uint16_t manufacturerId() SBE_NOEXCEPT
    {
        return 18;
    }

    static SBE_CONSTEXPR std::uint64_t manufacturerHeaderLength() SBE_NOEXCEPT
    {
        return 4;
    }

    std::uint32_t manufacturerLength() const
    {
        std::uint32_t length;
        std::memcpy(&length, m_buffer + sbePosition(), sizeof(std::uint32_t));
        return SBE_LITTLE_ENDIAN_ENCODE_32(length);
    }

    const char *manufacturer()
    {
        std::uint32_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + sbePosition(), sizeof(std::uint32_t));
        const char *fieldPtr = m_buffer + sbePosition() + 4;
        sbePosition(sbePosition() + 4 + SBE_LITTLE_ENDIAN_ENCODE_32(lengthFieldValue));
        return fieldPtr;
    }

    std::uint64_t getManufacturer(char *dst, const std::uint64_t length)
    {
        std::uint64_t lengthOfLengthField = 4;
        std::uint64_t lengthPosition = sbePosition();
        sbePosition(lengthPosition + lengthOfLengthField);
        std::uint32_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint32_t));
        std::uint64_t dataLength = SBE_LITTLE_ENDIAN_ENCODE_32(lengthFieldValue);
        std::uint64_t bytesToCopy = length < dataLength ? length : dataLength;
        std::uint64_t pos = sbePosition();
        sbePosition(pos + dataLength);
        std::memcpy(dst, m_buffer + pos, bytesToCopy);
        return bytesToCopy;
    }

    Car &putManufacturer(const char *src, const std::uint32_t length)
    {
        std::uint64_t lengthOfLengthField = 4;
        std::uint64_t lengthPosition = sbePosition();
        std::uint32_t lengthFieldValue = SBE_LITTLE_ENDIAN_ENCODE_32(length);
        sbePosition(lengthPosition + lengthOfLengthField);
        std::memcpy(m_buffer + lengthPosition, &lengthFieldValue, sizeof(std::uint32_t));
        std::uint64_t pos = sbePosition();
        sbePosition(pos + length);
        std::memcpy(m_buffer + pos, src, length);
        return *this;
    }

    std::string getManufacturerAsString()
    {
        std::uint64_t lengthOfLengthField = 4;
        std::uint64_t lengthPosition = sbePosition();
        sbePosition(lengthPosition + lengthOfLengthField);
        std::uint32_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint32_t));
        std::uint64_t dataLength = SBE_LITTLE_ENDIAN_ENCODE_32(lengthFieldValue);
        std::uint64_t pos = sbePosition();
        const std::string result(m_buffer + pos, dataLength);
        sbePosition(pos + dataLength);
        return result;
    }

    #if __cplusplus >= 201703L
    std::string_view getManufacturerAsStringView()
    {
        std::uint64_t lengthOfLengthField = 4;
        std::uint64_t lengthPosition = sbePosition();
        sbePosition(lengthPosition + lengthOfLengthField);
        std::uint32_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint32_t));
        std::uint64_t dataLength = SBE_LITTLE_ENDIAN_ENCODE_32(lengthFieldValue);
        std::uint64_t pos = sbePosition();
        const std::string_view result(m_buffer + pos, dataLength);
        sbePosition(pos + dataLength);
        return result;
    }
    #endif

    Car &putManufacturer(const std::string& str)
    {
        if (str.length() > 1073741824)
        {
            throw std::runtime_error("std::string too long for length type [E109]");
        }
        std::uint64_t lengthOfLengthField = 4;
        std::uint64_t lengthPosition = sbePosition();
        std::uint32_t lengthFieldValue = SBE_LITTLE_ENDIAN_ENCODE_32(static_cast<std::uint32_t>(str.length()));
        sbePosition(lengthPosition + lengthOfLengthField);
        std::memcpy(m_buffer + lengthPosition, &lengthFieldValue, sizeof(std::uint32_t));
        std::uint64_t pos = sbePosition();
        sbePosition(pos + str.length());
        std::memcpy(m_buffer + pos, str.c_str(), str.length());
        return *this;
    }

    static const char * modelMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
            case MetaAttribute::PRESENCE: return "required";
        }

        return "";
    }

    static const char *modelCharacterEncoding() SBE_NOEXCEPT
    {
        return "UTF-8";
    }

    static SBE_CONSTEXPR std::uint64_t modelSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool modelInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= modelSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    static SBE_CONSTEXPR std::uint16_t modelId() SBE_NOEXCEPT
    {
        return 19;
    }

    static SBE_CONSTEXPR std::uint64_t modelHeaderLength() SBE_NOEXCEPT
    {
        return 4;
    }

    std::uint32_t modelLength() const
    {
        std::uint32_t length;
        std::memcpy(&length, m_buffer + sbePosition(), sizeof(std::uint32_t));
        return SBE_LITTLE_ENDIAN_ENCODE_32(length);
    }

    const char *model()
    {
        std::uint32_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + sbePosition(), sizeof(std::uint32_t));
        const char *fieldPtr = m_buffer + sbePosition() + 4;
        sbePosition(sbePosition() + 4 + SBE_LITTLE_ENDIAN_ENCODE_32(lengthFieldValue));
        return fieldPtr;
    }

    std::uint64_t getModel(char *dst, const std::uint64_t length)
    {
        std::uint64_t lengthOfLengthField = 4;
        std::uint64_t lengthPosition = sbePosition();
        sbePosition(lengthPosition + lengthOfLengthField);
        std::uint32_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint32_t));
        std::uint64_t dataLength = SBE_LITTLE_ENDIAN_ENCODE_32(lengthFieldValue);
        std::uint64_t bytesToCopy = length < dataLength ? length : dataLength;
        std::uint64_t pos = sbePosition();
        sbePosition(pos + dataLength);
        std::memcpy(dst, m_buffer + pos, bytesToCopy);
        return bytesToCopy;
    }

    Car &putModel(const char *src, const std::uint32_t length)
    {
        std::uint64_t lengthOfLengthField = 4;
        std::uint64_t lengthPosition = sbePosition();
        std::uint32_t lengthFieldValue = SBE_LITTLE_ENDIAN_ENCODE_32(length);
        sbePosition(lengthPosition + lengthOfLengthField);
        std::memcpy(m_buffer + lengthPosition, &lengthFieldValue, sizeof(std::uint32_t));
        std::uint64_t pos = sbePosition();
        sbePosition(pos + length);
        std::memcpy(m_buffer + pos, src, length);
        return *this;
    }

    std::string getModelAsString()
    {
        std::uint64_t lengthOfLengthField = 4;
        std::uint64_t lengthPosition = sbePosition();
        sbePosition(lengthPosition + lengthOfLengthField);
        std::uint32_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint32_t));
        std::uint64_t dataLength = SBE_LITTLE_ENDIAN_ENCODE_32(lengthFieldValue);
        std::uint64_t pos = sbePosition();
        const std::string result(m_buffer + pos, dataLength);
        sbePosition(pos + dataLength);
        return result;
    }

    #if __cplusplus >= 201703L
    std::string_view getModelAsStringView()
    {
        std::uint64_t lengthOfLengthField = 4;
        std::uint64_t lengthPosition = sbePosition();
        sbePosition(lengthPosition + lengthOfLengthField);
        std::uint32_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint32_t));
        std::uint64_t dataLength = SBE_LITTLE_ENDIAN_ENCODE_32(lengthFieldValue);
        std::uint64_t pos = sbePosition();
        const std::string_view result(m_buffer + pos, dataLength);
        sbePosition(pos + dataLength);
        return result;
    }
    #endif

    Car &putModel(const std::string& str)
    {
        if (str.length() > 1073741824)
        {
            throw std::runtime_error("std::string too long for length type [E109]");
        }
        std::uint64_t lengthOfLengthField = 4;
        std::uint64_t lengthPosition = sbePosition();
        std::uint32_t lengthFieldValue = SBE_LITTLE_ENDIAN_ENCODE_32(static_cast<std::uint32_t>(str.length()));
        sbePosition(lengthPosition + lengthOfLengthField);
        std::memcpy(m_buffer + lengthPosition, &lengthFieldValue, sizeof(std::uint32_t));
        std::uint64_t pos = sbePosition();
        sbePosition(pos + str.length());
        std::memcpy(m_buffer + pos, str.c_str(), str.length());
        return *this;
    }

    static const char * activationCodeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
            case MetaAttribute::PRESENCE: return "required";
        }

        return "";
    }

    static const char *activationCodeCharacterEncoding() SBE_NOEXCEPT
    {
        return "UTF-8";
    }

    static SBE_CONSTEXPR std::uint64_t activationCodeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool activationCodeInActingVersion() SBE_NOEXCEPT
    {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-compare"
#endif
        return m_actingVersion >= activationCodeSinceVersion();
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    }

    static SBE_CONSTEXPR std::uint16_t activationCodeId() SBE_NOEXCEPT
    {
        return 20;
    }

    static SBE_CONSTEXPR std::uint64_t activationCodeHeaderLength() SBE_NOEXCEPT
    {
        return 4;
    }

    std::uint32_t activationCodeLength() const
    {
        std::uint32_t length;
        std::memcpy(&length, m_buffer + sbePosition(), sizeof(std::uint32_t));
        return SBE_LITTLE_ENDIAN_ENCODE_32(length);
    }

    const char *activationCode()
    {
        std::uint32_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + sbePosition(), sizeof(std::uint32_t));
        const char *fieldPtr = m_buffer + sbePosition() + 4;
        sbePosition(sbePosition() + 4 + SBE_LITTLE_ENDIAN_ENCODE_32(lengthFieldValue));
        return fieldPtr;
    }

    std::uint64_t getActivationCode(char *dst, const std::uint64_t length)
    {
        std::uint64_t lengthOfLengthField = 4;
        std::uint64_t lengthPosition = sbePosition();
        sbePosition(lengthPosition + lengthOfLengthField);
        std::uint32_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint32_t));
        std::uint64_t dataLength = SBE_LITTLE_ENDIAN_ENCODE_32(lengthFieldValue);
        std::uint64_t bytesToCopy = length < dataLength ? length : dataLength;
        std::uint64_t pos = sbePosition();
        sbePosition(pos + dataLength);
        std::memcpy(dst, m_buffer + pos, bytesToCopy);
        return bytesToCopy;
    }

    Car &putActivationCode(const char *src, const std::uint32_t length)
    {
        std::uint64_t lengthOfLengthField = 4;
        std::uint64_t lengthPosition = sbePosition();
        std::uint32_t lengthFieldValue = SBE_LITTLE_ENDIAN_ENCODE_32(length);
        sbePosition(lengthPosition + lengthOfLengthField);
        std::memcpy(m_buffer + lengthPosition, &lengthFieldValue, sizeof(std::uint32_t));
        std::uint64_t pos = sbePosition();
        sbePosition(pos + length);
        std::memcpy(m_buffer + pos, src, length);
        return *this;
    }

    std::string getActivationCodeAsString()
    {
        std::uint64_t lengthOfLengthField = 4;
        std::uint64_t lengthPosition = sbePosition();
        sbePosition(lengthPosition + lengthOfLengthField);
        std::uint32_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint32_t));
        std::uint64_t dataLength = SBE_LITTLE_ENDIAN_ENCODE_32(lengthFieldValue);
        std::uint64_t pos = sbePosition();
        const std::string result(m_buffer + pos, dataLength);
        sbePosition(pos + dataLength);
        return result;
    }

    #if __cplusplus >= 201703L
    std::string_view getActivationCodeAsStringView()
    {
        std::uint64_t lengthOfLengthField = 4;
        std::uint64_t lengthPosition = sbePosition();
        sbePosition(lengthPosition + lengthOfLengthField);
        std::uint32_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint32_t));
        std::uint64_t dataLength = SBE_LITTLE_ENDIAN_ENCODE_32(lengthFieldValue);
        std::uint64_t pos = sbePosition();
        const std::string_view result(m_buffer + pos, dataLength);
        sbePosition(pos + dataLength);
        return result;
    }
    #endif

    Car &putActivationCode(const std::string& str)
    {
        if (str.length() > 1073741824)
        {
            throw std::runtime_error("std::string too long for length type [E109]");
        }
        std::uint64_t lengthOfLengthField = 4;
        std::uint64_t lengthPosition = sbePosition();
        std::uint32_t lengthFieldValue = SBE_LITTLE_ENDIAN_ENCODE_32(static_cast<std::uint32_t>(str.length()));
        sbePosition(lengthPosition + lengthOfLengthField);
        std::memcpy(m_buffer + lengthPosition, &lengthFieldValue, sizeof(std::uint32_t));
        std::uint64_t pos = sbePosition();
        sbePosition(pos + str.length());
        std::memcpy(m_buffer + pos, str.c_str(), str.length());
        return *this;
    }
};
}
#endif
