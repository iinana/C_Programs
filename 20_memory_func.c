#include <stdio.h>
#include <string.h>

void use_memcpy(void);
void use_memmove(void);
void use_memcmp(void);

int main()
{
    use_memcmp();
}

void use_memcpy(void)
{
    char str[50] = "I love Chewing C hahaha";
    char str2[50];
    char str3[50];

    memcpy(str2, str, strlen(str) + 1);
    memcpy(str3, "hello", 6);
    // memcpy(copy here, copy this memory, memory size)

    printf("str : %s\n", str);
    printf("str2 : %s\n", str2);
    printf("str3 : %s\n", str3);
}

void use_memmove(void)
{
    char str[50] = "I love Chewing C hahaha";

    printf("Before Memove : %s\n", str);

    // copy 6 character of str+17 to str+23
    memmove(str + 23, str + 17, 6);
    printf("After Memmove : %s\n", str);

}

void use_memcmp(void)
{
    int arr[10] = {1, 2, 3, 4, 5};
    int arr2[10] = {1, 2, 3, 7, 5};

    // memcmp() function compares two memory by 'byte' so if you want to compare by 'element', you have to write size properly
    if (memcmp(arr, arr2, sizeof(int)*3) == 0) printf("arr and arr2 are same\n");
    else printf("arr and arr2 are different\n");
}