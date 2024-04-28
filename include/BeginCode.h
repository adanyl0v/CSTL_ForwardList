#pragma once
#ifndef CSTL_BEGIN_CODE_H
#define CSTL_BEGIN_CODE_H

#include <stddef.h>

#ifndef CSTL_DEPRECATED
#if (__GNUC__ >= 4)
    #define CSTL_DEPRECATED __attribute__((deprecated))
#else
    #define CSTL_DEPRECATED
#endif
#endif /* CSTL_DEPRECATED */

#ifndef DECLSPEC
#if defined(__WIN32__)
    #ifdef __BORLANDC__
        #ifdef BUILD_SDL
            #define DECLSPEC
        #else
            #define DECLSPEC __declspec(dllimport)
        #endif
        #else
            #define DECLSPEC __declspec(dllexport)
    #endif /* __BORLANDC__ */
#else
    #if defined(__GNUC__) && __GNUC__ >= 4
        #define DECLSPEC __attribute__ ((visibility("default")))
    #elif defined(__GNUC__) && __GNUC__ >= 2
        #define DECLSPEC __declspec(dllexport)
    #else
        #define DECLSPEC
    #endif
#endif
#endif /* DECLSPEC */

#ifndef CSTLCALL
    #if defined(__WIN32__) && !defined(__GNUC__)
        #define CSTLCALL __cdecl
    #else
        #define CSTLCALL
    #endif
#endif /* CSTLCALL */

#ifdef __SYMBIAN32__
#undef DECLSPEC
#define DECLSPEC
#endif /* __SYMBIAN32__ */

#ifndef CSTL_INLINE
#if defined(__GNUC__)
    #define CSTL_INLINE __inline__
#elif defined(_MSC_VER) || defined(__BORLANDC__) || \
        defined(__DMC__) || defined(__SC__) || \
        defined(__WATCOMC__) || defined(__LCC__) || \
        defined(__DECC)
    #define CSTL_INLINE __inline
    #ifndef __inline__
        #define __inline__ __inline
    #endif
#else
    #define CSTL_INLINE inline
    #ifndef __inline__
        #define __inline__ inline
    #endif
#endif
#endif /* CSTL_INLINE */

#ifndef CSTL_FORCE_INLINE
#if defined(_MSC_VER)
    #define CSTL_FORCE_INLINE __forceinline
#elif ( (defined(__GNUC__) && (__GNUC__ >= 4)) || defined(__clang__) )
    #define CSTL_FORCE_INLINE __attribute__((always_inline)) static __inline__
#else
    #define CSTL_FORCE_INLINE static CSTL_INLINE
#endif
#endif /* CSTL_FORCE_INLINE */

#if !defined(__MACH__)
#ifndef NULL
    #ifdef __cplusplus
        #define NULL 0
    #else
        #define NULL ((void *)0)
    #endif
#endif /* NULL */
#endif

#ifndef CSTL_BOOL
#define CSTL_BOOL
typedef enum CSTL_Bool {
    CSTL_FALSE = 0,
    CSTL_TRUE = 1
} CSTL_Bool;
#endif /* CSTL_BOOL */

#endif /* CSTL_BEGIN_CODE_H */
