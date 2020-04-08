#include "str.h"

int str_len(const char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

char* str_upper(char* str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] &= ~(0x20);
    return (str);
}

char* str_pad_left(char* str, char pad, int len)
{
    int i = str_len(str);
    int j = len - i;

    if (j)
        while (i >= 0) {
            str[i + j] = str[i];
            str[i--] = pad;
        }
    return (str);
}

char* str_pad_right(char* str, char pad, int len)
{
    int i = str_len(str);

    while (i != len)
        str[i++] = pad;
    str[i] = 0;
    return (str);
}

int str_truncate_to_int(const char* str, int start, int end)
{
    int n = 0;

    for (int i = start; i < end; i++) {
        n <<= 8;
        n |= str[i];
    }
    return (n);
}

int int_to_str(int i, char *buf, int buf_len)
{
    int j = 0;

    if (i == 0)
        buf[j++] = '0';
    else
        while (i && j < buf_len) {
            buf[j++] = (i % 10) | 0x30;
            i /= 10;
        }
    bytes_array_reverse((uint8_t*)buf, j);
    buf[j] = 0;
    return (j);
}