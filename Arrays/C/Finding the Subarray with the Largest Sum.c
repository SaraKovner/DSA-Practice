/*
 * Problem: Given an integer array nums, find the subarray with the largest sum, and return its sum.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון מערך מספרים שלמים, מצא את התת-מערך עם הסכום הגדול ביותר
 * 
 * Example:
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * 
 * Input: nums = [1]
 * Output: 1
 * 
 * Input: nums = [5,4,-1,7,8]
 * Output: 23
 * 
 * Explanation:
 * For the input [-2,1,-3,4,-1,2,1,-5,4], the subarray with the largest sum is [4,-1,2,1], which has a sum of 6.
 * For the input [1], the subarray with the largest sum is [1], which has a sum of 1.
 * For the input [5,4,-1,7,8], the subarray with the largest sum is [5,4,-1,7,8], which has a sum of 23.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1) - אם משתמשים באלגוריתם Kadane
 */
#include "Question.h"
#define MAX(a, b) ((a)>(b) ? (a) : (b))

// פונקציה למציאת תת-מערך עם הסכום המקסימלי (Kadane's Algorithm)
// אלגוריתם דינמי לפתרון בעיית Maximum Subarray
int  find_subarray_with_large_sum(ARR  *  nums) 
{
    // בדיקת קצה - מערך ריק או לא חד-מימדי
    if(nums==NULL || nums->num_dimensions!=1)
        return 0;
        
    int len=nums->dimensions[0], max; // אורך המערך ומשתנה למקסימום
        
    // יצירת מערך עזר לתכנות דינמי
    uint64_t* d=(uint64_t*)malloc(1*sizeof(uint64_t));
    d[0]=len;
    ARR* arr=ARR_Create(d, 1);
        
    // אלגוריתם דינמי: בנייה מהסוף לתחילה
    arr->data[len-1]=nums->data[len-1]; // תנאי בסיס - האלמנט האחרון
    
    // בניית הפתרון: לכל מיקום i, המקסימום הוא:
    // או רק האלמנט הנוכחי, או האלמנט + המקסימום מימינו
    for(int i=len-2; i>=0; i--)
        arr->data[i]=MAX(nums->data[i], nums->data[i]+arr->data[i+1]);
    
    // מציאת המקסימום הגלובלי מבין כל הפתרונות
    max=arr->data[0];
    for(int i=1; i<len; i++)
        max=MAX(max, arr->data[i]);
    
    // *** חסר שיחרור זיכרון! ***
    // צריך להוסיף: free(d); ו-ARR_Destroy(arr);
    
    return max;  
}
