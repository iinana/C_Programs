#include <stdio.h>
#pragma pack(1)
// make struct 1 byte unit
// prevent compiler to make struct 4 byte unit (unnecessary byte is wasted)

struct Weird
{
    char arr[2];
    int i;
};

int main()
{
    struct Weird a;
    printf("size of a : %d\n", sizeof(a));
    // if not pre-process "pragma", sizeof a = 8 (compiler want to make 4byte unit)

    return 0;
}