/*
 * Problem: Given an integer array nums sorted in ascending order with distinct values, the array may have been rotated at an unknown pivot index k (1 ≤ k < nums.length) before being passed to your function. 
 * The resulting array is in the form [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
 * For example, the array [0, 1, 2, 4, 5, 6, 7] might be rotated at pivot index 3 and become [4, 5, 6, 7, 0, 1, 2].
 * Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * Example 1:
 * Input: nums = [4, 5, 6, 7, 0, 1, 2], target = 0
 * Output: 4
 * 
 * Example 2:
 * Input: nums = [4, 5, 6, 7, 0, 1, 2], target = 3
 * Output: -1
 * 
 * Explanation:
 * For the input [4, 5, 6, 7, 0, 1, 2], target = 0, the target 0 is at index 4.
 * For the input [4, 5, 6, 7, 0, 1, 2], target = 3, the target 3 is not in the array, so the output is -1.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון מערך ממוין שסובב בנקודת ציר לא ידועה, מצא את האינדקס של המטרה במערך המסובב
 * 
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
#include "Question.hpp"
#include "Utils.hpp"

// פונקציה ראשית לחיפוש מטרה במערך ממוין מסובב
// אלגוריתם: Binary Search מותאם - בדיקה איזה חלק ממוין ובו מתבצע החיפוש
int search_target(ARR<int> nums, int target) 
{
    int low=0, hi=nums.elements.size()-1, mid; // מצביעי תחילת וסוף המערך
    
    // חיפוש בינארי מותאם למערך מסובב
    while(low<=hi)
    {
        mid=(low+hi)/2; // חישוב האמצע
        if(nums[mid]==target)
            return mid; // מצאנו את המטרה!
            
        // בדיקה אם החלק השמאלי הוא הממוין
        if(nums[low]<=nums[mid])
        {
            // אם המטרה נמצאת בחלק השמאלי הממוין
            if(nums[low]<=target && nums[mid]>target)
                hi=mid-1; // חיפוש בחלק השמאלי
            else
                low=mid+1; // חיפוש בחלק הימני
        }
        else    // החלק הימני הוא הממוין
        {
            // אם המטרה נמצאת בחלק הימני הממוין
            if(nums[mid]<target && nums[hi]>=target)
                low=mid+1; // חיפוש בחלק הימני
            else
                hi=mid-1; // חיפוש בחלק השמאלי
        }
    }
    
    return -1; // המטרה לא נמצאה במערך
}