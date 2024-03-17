#include <immintrin.h>
#include "Add.h"

void AddC(uint16_t a[], uint16_t b[], uint16_t c[], size_t size)
{
    for (int i = 0; i < size; i++) {
        c[i] = a[i] + b[i];
    }
}

void AddWithM256i(uint16_t a[], uint16_t b[], uint16_t c[], size_t size)
{
    const int units = sizeof(__m256) / sizeof(uint16_t);
    const int max = size / units;
    int i = 0;

    /* C言語のデータ型からイントリンシックデータ型にコピー */
    __m256i* pa = (__m256i*)a;
    __m256i* pb = (__m256i*)b;

    for (i = 0; i < max; i++, pa++, pb++) {

        /* 16bit整数加算 */
        __m256i y = _mm256_add_epi16(*pa, *pb);

        /* イントリンシックデータ型からC言語のデータ型にコピー */
        _mm256_store_si256((__m256i*) & c[i * units], y);
    }
}