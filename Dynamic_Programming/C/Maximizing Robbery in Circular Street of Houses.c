/*
 * Description:
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses on this street are arranged in a circle, meaning the first house is the neighbor of the last one. Additionally, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses are broken into on the same night.
 * Given an integer array nums representing the amount of money in each house, return the maximum amount of money you can rob tonight without alerting the police.
 * 
 * Example 1:
 * Input: nums = [2, 3, 2]
 * Output: 3
 * Explanation: You cannot rob both house 1 (money = 2) and house 3 (money = 2), so the maximum money you can rob is 3.
 * 
 * Example 2:
 * Input: nums = [1, 2, 3, 1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3). Total amount = 1 + 3 = 4.
 * 
 * Example 3:
 * Input: nums = [1, 2, 3]
 * Output: 3
 * 
 * Constraints:
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 1000
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: מקסום שוד בתים ברחוב מעגלי - הבית הראשון שכן לאחרון
 * 
 * Time Complexity: O(n) - שני מעברים על המערך
 * Space Complexity: O(n) - מערך עזר לחישוב DP
 */
#include "Question.h"
#define MAX(a, b)((a)>(b)? (a) : (b))

// פונקציה ראשית למקסום שוד בתים ברחוב מעגלי
// אלגוריתם: Dynamic Programming - פתרון שני תתי-בעיות נפרדות
int max_robbery(ARR* nums) 
{
    // בדיקת מקרי קצה
    if(nums == NULL || nums->data == NULL)
        return 0;
    
    int len = nums->total_size;
    if(len == 1)
        return nums->data[0]; // רק בית אחד - שודדים אותו
        
    // יצירת מערך DP לחישוב המקסימום
    int* res = (int*)malloc(sizeof(int) * len);
    
    // תת-בעיה 1: שוד בתים 0 עד len-2 (בלי הבית האחרון)
    res[0] = nums->data[0];
    res[1] = MAX(res[0], nums->data[1]);
    for(int i = 2; i < len - 1; i++)  // בלי האחרון כדי שלא יווצר מעגל
        res[i] = MAX(res[i-1], nums->data[i] + res[i-2]);
    
    int max_sum = res[len-2]; // שמירת תוצאת תת-בעיה 1
    
    // תת-בעיה 2: שוד בתים 1 עד len-1 (בלי הבית הראשון)
    res[0] = 0; // לא שודדים את הבית הראשון
    res[1] = nums->data[1]; // מתחילים מהבית השני
    for(int i = 2; i < len; i++)  
        res[i] = MAX(res[i-1], nums->data[i] + res[i-2]);
    
    // החזרת המקסימום בין שתי תת-הבעיות
    max_sum = MAX(max_sum, res[len-1]);
    free(res); // שחרור זיכרון
    return max_sum;
}