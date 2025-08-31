/*
 * Problem: Given an integer array nums of length n and an integer target, your task is to find three integers in the array such that their sum is closest to the target.
 * Return the sum of these three integers.
 * You may assume that each input would have exactly one solution.
 * 
 * Example:
 * Input: nums = [-1, 2, 1, -4], target = 1
 * Output: 2
 * Explanation:
 * The sum that is closest to the target 1 is 2. The triplet that produces this sum is [-1, 2, 1].
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון מערך מספרים ומטרה, מצא שלושה מספרים במערך שסכומם הכי קרוב למטרה
 * 
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;
#include <algorithm>

// פונקציה ראשית למציאת סכום שלושה מספרים הקרוב ביותר למטרה
// אלגוריתם: Two Pointers עם מיון - עבור כל אלמנט, חיפוש זוג נוסף עם מצביעים
int sum_to_target(ARR<int> nums, int target) 
{
    int n=nums.elements.size();
    if(n<3)
        return 0; // צריכים לפחות 3 אלמנטים
        
    sort(nums.elements.begin(), nums.elements.end()); // מיון המערך
    
    long long sum_target=(long long)nums[0]+nums[1]+nums[2]; // הסכום הראשוני
    
    // מעבר על כל אלמנט כאלמנט ראשון בשלישייה
    for(int i=0; i<n-2; i++)
    {
        int left=i+1;   // מצביע שמאלי
        int right=n-1;  // מצביע ימני
        
        // חיפוש עם שני מצביעים
        while(left<right)
        {
            long long curr_sum=nums[i]+nums[left]+nums[right]; // הסכום הנוכחי
            
            // עדכון הסכום הקרוב ביותר אם מצאנו סכום קרוב יותר
            if(abs(target-sum_target)>abs(target-curr_sum))
                sum_target=curr_sum;
                
            // הזזת המצביעים לפי הצורך
            if(curr_sum<target)
                left++;  // צריך סכום גדול יותר
            else
                right--; // צריך סכום קטן יותר
        }
    }
    
    return (int)sum_target; // החזרת הסכום הקרוב ביותר
}