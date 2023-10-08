#include <stdio.h>

/* union : similar to sturcture but you only can store info in one field */
union A
{
    int i;
    char j;
};

int main()
{
    union A a;
    a.i = 0x12345678;
    printf("%x", a.j);
    /* in union, 
       i and j are sharing the memory. 
       and they store the end to the first
       => so in i = | 78 | 56 | 34 | 12
       => j is 78 (first to in i)
    */
    return 0;
}