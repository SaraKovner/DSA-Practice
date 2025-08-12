#include "Question.h"
#include <math.h>

int is_prime(int num)
{
    if(num<2)
        return 0;
    int sq=sqrt(num);
    // printf("%d", sq);
    for(int i=2; i<=sq; i++)
        if(num%i==0)
            return 0;
    return 1;
}

int  primes_less_than_integer(int  n) 
{
    // printf("aaa");
    int count=0;

    for(int i=1; i<n; i++)
        count+=is_prime(i);
    
    return count;  
}
