#include "hmac.h"

#define OPAD 0x5C
#define IPAD 0x36

void hmac(
    void *dest,
    const void *key,
    uint32_t key_len,
    const void *msg,
    uint32_t msg_len,
    void (*hash)(char *dest, const char *str, int len),
    uint16_t block_size,
    uint16_t output_size
) {
    char __key[block_size];
    char o_key_pad[block_size];
    char i_key_pad[block_size];
    char result[block_size * 2];
    char tmp[2048];

    if (key_len > block_size)
        hash(__key, key, key_len);
    else
        memcpy(__key, key, key_len);

    if (key_len < block_size)
        memset(__key + key_len, 0, sizeof(char) * (block_size - key_len));

    // XOR

    for (uint32_t i = 0; i < block_size; i++) {
        o_key_pad[i] = __key[i] ^ OPAD;
        i_key_pad[i] = __key[i] ^ IPAD;
    }

    // MAGIC

    memcpy(result, i_key_pad, block_size);
    memcpy(result + block_size, msg, msg_len);
    hash(tmp, result, block_size + msg_len);

    memcpy(result, o_key_pad, block_size);
    memcpy(result + block_size, tmp, output_size);
    hash(tmp, result, block_size + output_size);

    memcpy(dest, tmp, output_size);
}