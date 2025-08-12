/*
 * Description: Given an integer array nums, rotate the array to the right by k steps, where k is a non-negative integer. 
 *  
 * Example 1:
 * Input: nums = [1, 2, 3, 4, 5, 6, 7], k = 3
 * Output: [5, 6, 7, 1, 2, 3, 4]
 *  
 * Example 2:
 * Input: nums = [-1, -100, 3, 99], k = 2
 * Output: [3, 99, -1, -100]
 * The task is to create an efficient function to rotate the array in-place.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון מערך מספרים שלמים, סובב את המערך ימינה ב-k צעדים
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n) - מערך חדש
 */
//#define ARR_DATA_TYPE int

#include "Question.h"

// פונקציה ראשית לסיבוב מערך ימינה ב-k צעדים
// אלגוריתם: יצירת מערך חדש עם האלמנטים במקומות החדשים
ARR  *  rotate_array(ARR  *  nums, int  k)  
{
    int len=ARR_TotalSize(nums); // אורך המערך
    
    // יצירת מערך תוצאה חדש באותו גודל
    uint64_t d[1]={len};
    ARR* res=ARR_Create(d, 1);
    
    // אופטימיזציה: אם k גדול מאורך המערך, נקח שארית
    k=k%len;
    
    // מעבר על כל אלמנט ומעביר אותו למקום החדש שלו
    // נוסחה: אלמנט במיקום i עובר למיקום (i+k)%len
    for(int i=0; i<len; i++)
        res->data[(i+k)%len]=nums->data[i];
    
    return res;  
}
