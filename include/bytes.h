#pragma once

#include <stdint.h>

void bytes_array_reverse(uint8_t* bytes, int size);
int bytes_array_to_int(const uint8_t* bytes, int start, int end);