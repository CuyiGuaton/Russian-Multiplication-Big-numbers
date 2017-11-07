#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *bigsum(char *res, const char *arg) {
    size_t pos1, pos2, pos3, len3;
    unsigned int carry;

    pos1 = strlen(res);
    pos2 = strlen(arg);
    len3 = pos3 = (pos1 < pos2) ? pos2 + 1 : pos1 + 1;
    /* reallocate the result array to one more than the larger operand */
    res = realloc(res, len3 + 1);
    /* set the terminating '\0' at the end of result */
    res[pos3] = '\0';
    for (carry = 0; pos3 > 0; carry /= 10) {
        if (pos1 > 0) carry += res[--pos1] - '0';
        if (pos2 > 0) carry += arg[--pos2] - '0';
        res[--pos3] = '0' + carry % 10;
    }
    while (res[0] == '0' && len3 > 1) {
        /* normalize the result: remove redundant initial zeroes */
        memmove(res, res + 1, len3--);
    }
    return res;
}

int main(int argc, const char **argv) {
    /* initialize the result to "0" as an allocated string */
    char *result = strcpy(malloc(2), "0");
    int i;

    for (i = 1; i < argc; i++) {
        result = bigsum(result, argv[i]);
    }
    printf("%s\n", result);
    return 0;
}