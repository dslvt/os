#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *randomFile = fopen("/dev/random", "r");
    char res[20];
    for (int i = 0; i < 20; i++)
    {
        res[i] = fgetc(randomFile);
    }
    printf("%s\n", res);
    return 0;
}

