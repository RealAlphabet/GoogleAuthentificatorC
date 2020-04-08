#pragma once

#include "bytes.h"

char* str_upper(char* str);
char* str_pad_left(char* str, char pad, int len);
char* str_pad_right(char* str, char pad, int len);
int str_truncate_to_int(const char* str, int start, int end);
int int_to_str(int i, char *buf, int buf_len);