/*
 * Problem Description:
 * Given an array nums of n integers, the task is to find all unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 * 0 ≤ a, b, c, d < n
 * a, b, c, and d are distinct.
 * nums[a] + nums[b] + nums[c] + nums[d] = target
 * Return the answer in any order.
 * Example:
 * Input: nums = [1, 0, -1, 0, -2, 2], target = 0
 * Output: [[1, 0, -1, -2], [0, 0, -1, 1], [-2, 2, -1, 1]]
 * Explanation:
 * In the example above, the unique quadruplets that sum to the target 0 are:
 * [1, 0, -1, -2]
 * [0, 0, -1, 1]
 * [-2, 2, -1, 1]
 * These quadruplets meet the criteria, and there are no duplicate quadruplets in the solution set.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: מצא כל הרביעיות הייחודיות במערך שסכומן שווה למטרה
 * 
 * Time Complexity: O(n³) - שלושה לולאות מקוננות
 * Space Complexity: O(1) - מקום קבוע נוסף
 */
#include "Question.h"

// פונקציית השוואה למיון המערך
int cmp_int(const void* a, const void* b)
{
    int a_int=*(const int*)a;
    int b_int=*(const int*)b;
    
    return (a_int>b_int)-(b_int>a_int);
}

// פונקציה ראשית למציאת כל הרביעיות הייחודיות שסכומן שווה למטרה
// אלגוריתם: מיון + Two Pointers עם דילוג על כפילויות
ARR  *  unique_sum(ARR  *  nums, int  target)
{
    if(nums==NULL || nums->total_size<4)
        return NULL;
    
    int n=nums->total_size;
    qsort(nums->data, n, sizeof(ARR_DATA_TYPE), cmp_int); // מיון המערך
        
    uint64_t d[2]={0, 4};
    ARR* res=ARR_Create(d, 2);
    
    for(int i=0; i<n-3; i++)
    {
        //כדי לדלג כל ערכים זהים כדי שלו יהיו כפיליות
        if(i>0 && nums->data[i]==nums->data[i-1])
            continue;
        for(int j=i+1; j<n-2; j++)
        {
            //כנ"ל
            if(j>i+1 && nums->data[j]==nums->data[j-1])
                continue;
                
            int left=j+1;
            int right=n-1;
            
            while(left<right)
            {
                int sum=nums->data[i]+nums->data[j]+nums->data[left]+nums->data[right];
                if(sum==target)
                {
                    res->data=realloc(res->data, (4+res->total_size)*sizeof(ARR_DATA_TYPE));
                    res->dimensions[0]++;   //כי יש רביעה חדשה כלומר שורה חדשה
                    res->data[res->total_size++]=nums->data[i];
                    res->data[res->total_size++]=nums->data[j];
                    res->data[res->total_size++]=nums->data[left];
                    res->data[res->total_size++]=nums->data[right];
                
                    //דילוג על כפיליות כדי שאותו איבר לא יהיה אותו ערך ובכל מקרה מעבר לזוג הבא
                    do
                        left++;
                    while(left<right && nums->data[left]==nums->data[left-1]);
                        
                    do
                        right--;
                    while(left<right && nums->data[right]==nums->data[right+1]);
                }
                else if(sum<target)
                        left++; //זה אומר שאני רוצה סכום יותר גדול לכן נקדם את הבסיס
                    else
                        right--;    //ולהפך
            }
        }
    }
    
    return res;  
}