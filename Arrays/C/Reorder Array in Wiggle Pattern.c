/*
 * Description: Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3] ....
 * 
 * You may assume the input array always has a valid answer.
 * 
 * Example 1:
 * 
 * Input: nums = [3, 5, 2, 1, 6, 4]
 * Output: [3, 5, 1, 6, 2, 4]
 * Explanation: The array is reordered to satisfy the condition nums[0] < nums[1] > nums[2] < nums[3] ....
 *  
 * 
 * Example 2:
 * 
 * Input: nums = [1, 2, 3, 4, 5, 6]
 * Output: [1, 3, 2, 5, 4, 6]
 * Explanation: The array is reordered to satisfy the condition nums[0] < nums[1] > nums[2] < nums[3] ....
 *  
 * 
 * Constraints:
 * 
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 1000
 * It is guaranteed that there is always a valid answer.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: סדר מחדש מערך בתבנית זיגזג (קטן-גדול-קטן-גדול)
 * 
 * Time Complexity: O(n log n) - מיון המערך
 * Space Complexity: O(n) - מערך תוצאה
 */
#include "Question.h"
// פונקציית השוואה למיון המערך
int cpm_int(const void* a, const void * b)
{
    int a_int=*(const int*)a;
    int b_int=*(const int*)b;
    
    return (a_int>b_int)-(a_int<b_int); // מיון עולה
}

// פונקציה ראשית לסידור מערך בתבנית זיגזג
// אלגוריתם: מיון + חלוקה לשני חלקים ושזירה
ARR  *  reorder_array(ARR  *  nums)  
{
    if(nums==NULL || nums->total_size==0)
        return NULL;
        
    int len=nums->total_size;
    uint64_t d[1]={len};
    ARR* res=ARR_Create(d, 1);
    
    qsort(nums->data, len, sizeof(ARR_DATA_TYPE), cpm_int); // מיון המערך
    
    // חישוב האמצע בהתחשב אם המערך באורך זוגי או אי זוגי
    int mid=len/2+len%2;
    // אלגוריתם: שזירה - חלק קטן במקומות זוגיים, חלק גדול במקומות אי-זוגיים
    for(int i=0; i<mid; i++)
    {
        res->data[i*2]=nums->data[i];           // חלק קטן במקומות זוגיים
        if(mid+i<len) // בדיקת המקרה אחרון שלא תהיה גלישה במקרה שהמערך אי זוגי
            res->data[i*2+1]=nums->data[mid+i]; // חלק גדול במקומות אי-זוגיים
    }
    
    return res;  
}