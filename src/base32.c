#include "base32.h"

int base32_decode(const uint8_t *encoded, uint8_t *result, int bufSize)
{
    int buffer = 0;
    int bitsLeft = 0;
    int count = 0;

    for (const uint8_t *ptr = encoded; count < bufSize && *ptr; ++ptr) {
        uint8_t ch = *ptr;

        if (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n' || ch == '-')
            continue;

        buffer <<= 5;

        // Look up one base32 digit
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
            ch = (ch & 0x1F) - 1;
        else if (ch >= '2' && ch <= '7')
            ch -= '2' - 26;
        else
            return -1;

        buffer |= ch;
        bitsLeft += 5;

        if (bitsLeft >= 8) {
            result[count++] = buffer >> (bitsLeft - 8);
            bitsLeft -= 8;
        }
    }
    result[count] = 0;
    return count;
}