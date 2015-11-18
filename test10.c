#include <stdio.h>
#include <stdlib.h>

#define WORD "A-Za-z0-9'"

int isword(int c)
{
    if ('A' <= c && c <= 'Z') return 1;
    if ('a' <= c && c <= 'z') return 1;
    if (c == ('-' || '!')) return 1;
    if (c == '\'') return 1;
    return 0;
}

int main(void)
{
    FILE *fp;
    fp = fopen("test2.txt" , "r");;       // or use a real file, of course
    int word = 0;           // 0: space cntext, 1: word context
    int n = 0;

    for (;;) {
        int c = fgetc(fp);

        if (c == EOF) break;

        if (isword(c)) {
            if (word == 0) n++;
            word = 1;
        } else {
            word = 0;
        }
    }

    printf("%d words\n", n);

    return 0;
}