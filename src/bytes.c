#include "bytes.h"

void bytes_array_reverse(uint8_t* bytes, int size)
{
    uint8_t i = 0;
    uint8_t j = size - 1;
    uint8_t tmp;

    while (i < j) {
        tmp = bytes[i];
        bytes[i++] = bytes[j];
        bytes[j--] = tmp;
    }
}

int bytes_array_to_int(const uint8_t* bytes, int start, int end)
{
    int n = 0;

    for (int i = start; i < end; i++) {
        n <<= 8;
        n |= bytes[i];
    }
    return (n);
}