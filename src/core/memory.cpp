#include <rendermoon.h>


void *AllocAligned(size_t size)
{
#if defined(PBRT_IS_WINDOWS)
    return _aligned_malloc(size, PBRT_L1_CACHE_LINE_SIZE);
#elif defined (PBRT_IS_OPENBSD) || defined(PBRT_IS_APPLE)
    // Allocate excess memory to ensure an aligned pointer can be returned
    void *mem = malloc(size + (PBRT_L1_CACHE_LINE_SIZE-1) + sizeof(void*));
    char *amem = ((char*)mem) + sizeof(void*);
#if (PBRT_POINTER_SIZE == 8)
    amem += PBRT_L1_CACHE_LINE_SIZE - (reinterpret_cast<uint64_t>(amem) &
                                       (PBRT_L1_CACHE_LINE_SIZE - 1));
#else
    amem += PBRT_L1_CACHE_LINE_SIZE - (reinterpret_cast<uint32_t>(amem) &
                                       (PBRT_L1_CACHE_LINE_SIZE - 1));
#endif
    ((void**)amem)[-1] = mem;
    return amem;
#else
    return memalign(PBRT_L1_CACHE_LINE_SIZE, size);
#endif
}


void FreeAligned(void *ptr)
{
    if (!ptr) return;
#if defined(PBRT_IS_WINDOWS)
    _aligned_free(ptr);
#elif defined (PBRT_IS_OPENBSD) || defined(PBRT_IS_APPLE)
    free(((void**)ptr)[-1]);
#else
    free(ptr);
#endif
}


