#include <stdio.h>
#include "human.h"

int main()
{
    struct Human lee = Create_Human("Lee", 40, MALE);
    Print_Human(&lee);

    return 0;
}