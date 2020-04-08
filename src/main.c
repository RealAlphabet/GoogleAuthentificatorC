#include <stdio.h>
#include <math.h>
#include <time.h>
#include "base32.h"
#include "sha1.h"
#include "hmac.h"
#include "str.h"
#include "bytes.h"

void get_2fa_code(char *secret, char code[7])
{
    char key[20];
    char hash[20];
    int key_len;
    uint64_t msg;

    str_upper(secret);                                                      // Transform to uppercase for a valid Base32 format.
    key_len = base32_decode((uint8_t *)secret, (uint8_t *)key, 20);         // Decode secret to an array of bytes
    msg = time(NULL) / 30;                                                  // TOTP is HOTP with a seed of 30 seconds.

    bytes_array_reverse((uint8_t*)&msg, 8);                                 // Revert endian
    hmac(hash, key, key_len, (uint8_t*)&msg, 8, sha1, 64, 20);              // Generate hmac hash

    int offset = hash[19] & 0xF;                                            // Get last nible (half-byte)
    int header = bytes_array_to_int((uint8_t*)hash, offset, offset + 4);    // Truncate 4 bytes starting at the offset
    header = header & 0x7fffffff;                                           // Remove the most significant bit
    header = header % 1000000;                                              // Generate a remainder less than 7 digits

    int_to_str(header, code, 7);    // Transform code into string
    str_pad_left(code, '0', 6);     // Pad code with 0 from the left until length of code is 6
}

int main(int argc, char **argv)
{
    char code[7];

    if (argc != 2) {
        printf("./ga [secret]\n");
        return (0);
    }

    get_2fa_code(argv[1], code);
    printf("Code :\n%s\n", code);
    return (0);
}