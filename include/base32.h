#pragma once

#include <stdint.h>

int base32_decode(const uint8_t *encoded, uint8_t *result, int bufSize);