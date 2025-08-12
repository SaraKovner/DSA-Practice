/*
 * Problem: In the context of array analysis, a peak element is defined as an element that is strictly greater than its immediate neighbors. Given a zero-indexed integer array nums, the objective is to locate a peak element and return its index. If the array contains multiple peak elements, any peak index can be returned.
 * For example:
 * In the array [1, 3, 20, 4, 1, 0], 20 is a peak element since it is greater than its neighbors 3 and 4.
 * In the array [10, 20, 15, 2, 23, 90, 67], 20 and 90 are peak elements.
 * Assume that elements outside the boundaries of the array are considered to have a value of negative infinity (-∞). This implies that any element in the array is considered greater than these boundary values.
 * The challenge is to design an algorithm that can find a peak element index efficiently, with a time complexity of O(log n).
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: אלמנט שיא הוא אלמנט שגדול בהחלט משכניו הישירים. נתון מערך מספרים שלמים, מצא אינדקס של אלמנט שיא
 * 
 * Examples:
 * Example 1:
 * Input: nums = [1, 2, 3, 1]
 * Output: 2
 * Explanation: 3 is a peak element and its index is 2.
 * 
 * Example 2:
 * Input: nums = [1, 2, 1, 3, 5, 6, 4]
 * Output: 5
 * Explanation: Both 2 and 6 are peak elements. The algorithm can return the index of either peak element.
 * 
 * Time Complexity: O(log n) - חיפוש בינארי
 * Space Complexity: O(1)
 */
//#define ARR_DATA_TYPE int
#include "Question.h"



// פונקציה למציאת אלמנט שיא במערך באמצעות חיפוש בינארי
int  peak_element(ARR  *  nums)  
{
    if(nums==NULL || nums->data==NULL)
        return -1;
    
    int len=ARR_TotalSize(nums);
    if(len==1)
        return 0;
    
    int from=0, to=len-1, mid;
    
    while(from<=to)
    {
        mid=(from+to)/2;
        // בדיקה אם האלמנט הנוכחי הוא שיא (גדול משכניו)
        if(mid==0 && nums->data[1]>nums->data[mid] || 
           mid==len-1 && nums->data[mid]>nums->data[len-2] ||
           nums->data[mid]>nums->data[mid+1] && nums->data[mid]>nums->data[mid-1])
           return mid;
         
        // אם המערך בעלייה - השיא חייב להמצא בצד הימני
        if(nums->data[mid]<nums->data[mid+1])
            from=mid+1;
        else
            to=mid;
    }
    
    return -1; 
}
