#include <stdio.h>

void find_prime(char *nums, int n);
void marking(char *nums, int n, int min_prime);

int main()
{
    int n;
    printf("I want to find prime numbers 1 to n : ");
    scanf("%d", &n);

    char nums[n+1];
    for (int i = 0; i <= n; i++)
    {
        if ((i == 0) || (i == 1)) nums[i] = 1;
        else nums[i] = 0;
    }
    
    find_prime(nums, n);

    for (int i = 2; i <= n; i++)
    {
        if (nums[i] == 0) printf("%4d", i);
    }
    
    return 0;
}

void find_prime(char *nums, int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (nums[i] != 1) marking(nums, n, i);
    }
}
 
void marking(char *nums, int n, int min_prime)
{
    for (int i = (min_prime * min_prime); i <= n; i += min_prime) nums[i] = 1;
}