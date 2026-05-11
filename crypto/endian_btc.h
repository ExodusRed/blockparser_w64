
// #include <endian.h>

// portable_endian.h

#pragma once

#ifdef _WIN32

#include <winsock2.h>
#include <stdint.h>

#if defined(__GNUC__) || defined(__clang__)
    #define bswap16 __builtin_bswap16
    #define bswap32 __builtin_bswap32
    #define bswap64 __builtin_bswap64
#else
    #include <stdlib.h>
    #define bswap16 _byteswap_ushort
    #define bswap32 _byteswap_ulong
    #define bswap64 _byteswap_uint64
#endif

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

    #define htobe16(x) bswap16(x)
    #define htobe32(x) bswap32(x)
    #define htobe64(x) bswap64(x)

    #define be16toh(x) bswap16(x)
    #define be32toh(x) bswap32(x)
    #define be64toh(x) bswap64(x)

    #define htole16(x) (x)
    #define htole32(x) (x)
    #define htole64(x) (x)

    #define le16toh(x) (x)
    #define le32toh(x) (x)
    #define le64toh(x) (x)

#else

    #define htobe16(x) (x)
    #define htobe32(x) (x)
    #define htobe64(x) (x)

    #define be16toh(x) (x)
    #define be32toh(x) (x)
    #define be64toh(x) (x)

    #define htole16(x) bswap16(x)
    #define htole32(x) bswap32(x)
    #define htole64(x) bswap64(x)

    #define le16toh(x) bswap16(x)
    #define le32toh(x) bswap32(x)
    #define le64toh(x) bswap64(x)

#endif

#else

#include <endian.h>

#endif

