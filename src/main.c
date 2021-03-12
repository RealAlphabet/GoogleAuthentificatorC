#include <stdio.h>
#include "totp.h"

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
