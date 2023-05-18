#include <stdio.h>

int main(int argc, char *argv[])
{
    char **p = argv;
    int i =0;
    while (*p)
    {
        printf("argments %s\n", *p);
        p++;
	i++;
    }
    printf("coint : %d \n", i);

    return 0;
}

