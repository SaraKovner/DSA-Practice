/*
 * Problem: Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
 * Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
 * The tests are generated such that there is exactly one solution. You may not use the same element twice.
 * Your solution must use only constant extra space.
 *  Examples: Example 1:
 *     Input: numbers = [2, 7, 11, 15], target = 9
 *     Output: [1, 2]
 * Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1 and index2 = 2.
 *  Example 2:
 *     Input: numbers = [2, 3, 4], target = 6
 *     Output: [1, 3]
 * Explanation: The sum of 2 and 4 is 6. Therefore, index1 = 1 and index2 = 3.
 *  Example 3:
 *     Input: numbers = [-1, 0], target = -1
 *     Output: [1, 2]
 * Explanation: The sum of -1 and 0 is -1. Therefore, index1 = 1 and index2 = 2.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון מערך ממוין עם אינדקסים מ-1, מצא שני מספרים שסכומם שווה למטרה
 * 
 * Time Complexity: O(n) - Two Pointers
 * Space Complexity: O(1)
 */
#include "Question.h"

// פונקציה ראשית למציאת שני מספרים במערך ממוין שסכומם שווה למטרה
// אלגוריתם: Two Pointers - מצביע מתחילת המערך ומצביע מסופו
ARR  *  two_sum(ARR  *  numbers, int  target) 
{
    int left=0, right=ARR_TotalSize(numbers)-1; // מצביעים בקצוות המערך
    
    // אלגוריתם Two Pointers: מקרבים את המצביעים עד שמוצאים את הסכום המבוקש
    while(left<right)
    {
        int sum = numbers->data[left] + numbers->data[right];
        
        if(sum == target)
            break; // מצאנו את הפתרון!
        
        if(sum > target)
            right--; // הסכום גדול מדי - מקטינים את המצביע הימני
        else
            left++; // הסכום קטן מדי - מגדילים את המצביע השמאלי
    }
    
    // יצירת מערך תוצאה עם 2 אלמנטים
    uint64_t d[1]={2};
    ARR* res=ARR_Create(d, 1);
    
    // בדיקה אם מצאנו פתרון
    if(left>=right)
        res->data[0]=res->data[1]=-1; // לא נמצא פתרון
    else
    {
        // החזרת האינדקסים כ-1-indexed (מתחילים מ-1)
        res->data[0]=left+1;  // כי הם רוצים את האינדקסים מתחילים מ-1
        res->data[1]=right+1;
    }
    
    return res;  
}
