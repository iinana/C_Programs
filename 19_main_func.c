/* argument of main funciton */
#include <stdio.h>

int main(int argc, char **argv)
{
    int i;
    printf("number of argument inputted : %d\n", argc);
    for (i = 0; i < argc; i++) printf("argument this program inputted : %s\n", argv[i]);
    return 0;
}