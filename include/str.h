#pragma once

#include "bytes.h"

char* str_upper(char* str);
char* str_pad_left(char* str, char pad, int len);
char* str_pad_right(char* str, char pad, int len);
int int_to_str(int i, char *buf, int buf_len);