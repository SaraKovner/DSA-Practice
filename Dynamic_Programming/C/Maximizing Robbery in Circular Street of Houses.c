#include "Question.h"
#define MAX(a, b)((a)>(b)? (a) : (b))

int max_robbery(ARR  *  nums) 
{
    if(nums==NULL || nums->data==NULL)
        return 0;
    
    int len=nums->total_size;
    if(len==1)
        return nums->data[0];
        
    int* res=(int*)malloc(sizeof(int)*len);
    res[0]=nums->data[0];
    res[1]=MAX(res[0], nums->data[1]);
    for(int i=2; i<len-1; i++)  //בלי האחרון כדי שלא יווצר מעגל
        res[i]=MAX(res[i-1], nums->data[i]+res[i-2]);
    
    int max_sum=res[len-2];
    
    res[0]=0;
    for(int i=2; i<len; i++)  
        res[i]=MAX(res[i-1], nums->data[i]+res[i-2]);
    
    max_sum=MAX(max_sum, res[len-1]);
    free(res);
    return max_sum;  
}