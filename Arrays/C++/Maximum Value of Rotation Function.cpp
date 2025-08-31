/*
 * Problem: You are given an integer array nums of length n.
 * Assume arrk to be an array obtained by rotating nums by k positions clock-wise.
 * We define the rotation function F on nums as follows:
 * F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
 * Return the maximum value of F(0), F(1), ..., F(n-1).
 * 
 * Example 1:
 * Input: nums = [4, 3, 2, 6]
 * Output: 26
 * Explanation:
 *         F(0) = 4*0 + 3*1 + 2*2 + 6*3 = 26
 *         F(1) = 6*0 + 4*1 + 3*2 + 2*3 = 16
 *         F(2) = 2*0 + 6*1 + 4*2 + 3*3 = 20
 *         F(3) = 3*0 + 2*1 + 6*2 + 4*3 = 22
 *         So the maximum value of F(0), F(1), ..., F(3) is 26.
 *         
 * Example 2:
 * Input: nums = [100]
 * Output: 0
 * Explanation: F(0) = 0.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון מערך מספרים, מצא את הערך המקסימלי של פונקציית הסיבוב F עבור כל הסיבובים האפשריים
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include "Question.hpp"
#include "Utils.hpp"
#define MAX(a,b) ((a)>(b) ? (a) : (b))

// פונקציה ראשית למציאת הערך המקסימלי של פונקציית הסיבוב
// אלגוריתם: חישוב יעיל באמצעות נוסחה מתמטית לקשר בין F(k) ל-F(k+1)
int max_rotation(ARR<int> nums) 
{
    int sum=0, max, prev=0; // סכום כל האלמנטים, מקסימום, ערך קודם
    int n=nums.elements.size();
    
    // חישוב הסכום הכולל ו-F(0)
    for(int i=0; i<n; i++)
    {
        sum+=nums[i]; // סכום כל האלמנטים
        prev+=(nums[i]*i); // חישוב F(0) = 0*nums[0] + 1*nums[1] + ... + (n-1)*nums[n-1]
    }
    
    max=prev; // F(0) הוא הערך הראשוני למקסימום
    
    // חישוב F(k) עבור k=1,2,...,n-1 באמצעות הנוסחה:
    // F(k) = F(k-1) + sum - n*nums[n-k]
    for(int k=1; k<n; k++)
    {
        prev=prev+sum-n*nums[n-k]; // חישוב F(k) מ-F(k-1)
        max=MAX(max, prev); // עדכון המקסימום
    }
    
    return max; // החזרת הערך המקסימלי
}