/*
 * Description: Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
 *  
 * Example 1:
 * Input: nums = [2, 3, 1, 2, 4, 3], target = 7
 * Output: 2
 * Explanation: The subarray [4, 3] has the minimal length under the problem constraints.
 *  
 * Example 2:
 * Input: nums = [1, 4, 4], target = 4
 * Output: 1
 *  
 * Example 3:
 * Input: nums = [1, 1, 1, 1, 1, 1, 1, 1], target = 11
 * Output: 0
 *  
 * Constraints:
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
 * 1 <= target <= 10^9
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון מערך מספרים חיוביים ומספר מטרה, החזר את האורך המינימלי של תת-מערך שסכומו גדול או שווה למטרה
 * 
 * Time Complexity: O(n) - Sliding Window
 * Space Complexity: O(1)
 */
//#define ARR_DATA_TYPE int

#include "Question.h"
#define MIN(a,b) ((a)>(b)?(b):(a))

// פונקציה ראשית למציאת אורך מינימלי של תת-מערך עם סכום >= target
// אלגוריתם: Sliding Window (Two Pointers) - חלון נע O(n)
int  min_sum_to_target(ARR  *  nums, int  target)  
{
    int n=ARR_TotalSize(nums), min_length=n+1, sum=0;
    int left=0, right=0; // אינדקסים למערך - מצביעי החלון הנע
    
    // אלגוריתם Sliding Window: מרחיבים את החלון ימינה, מצמצמים משמאל
    while(left<n && (right<n || sum>=target))   
    {
        // אם הסכום הנוכחי גדול או שווה למטרה
        if(sum>=target)
        {
            // עדכון האורך המינימלי אם מצאנו חלון קטן יותר
            min_length=MIN(min_length, right-left+1);
            
            // צמצום החלון משמאל: הוצאת האלמנט השמאלי ביותר
            sum-=nums->data[left];
            left++; // קידום האינדקס לאיבר הבא כדי להתחיל סדרה חדשה
            
            continue;
        }
        
        // הסכום עדיין קטן מהמטרה - הרחבת החלון ימינה
        sum+=nums->data[right];
        right++; // קידום האינדקס לאיבר הבא
    }
    
    // אם min_length נשאר בערך האתחול - לא נמצא תת-מערך מתאים
    return min_length==n+1 ? 0 : min_length;
}
