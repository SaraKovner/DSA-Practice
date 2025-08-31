/*
 * Problem: A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative.
 * The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.
 * For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
 * 
 * In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.
 * A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.
 * Given an integer array nums, return the length of the longest wiggle subsequence of nums.
 * 
 * Example 1:
 * Input: nums = [1, 7, 4, 9, 2, 5]
 * Output: 6
 * Explanation: The entire sequence is a wiggle sequence.
 * 
 * Example 2:
 * Input: nums = [1, 4, 7, 2, 5]
 * Output: 4
 * Explanation: The longest wiggle subsequence is [1, 4, 2, 5].
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון מערך מספרים, מצא את אורך הרצף הארוך ביותר שבו ההפרשים בין מספרים עוקבים מתחלפים בין חיובי לשלילי
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include "Question.hpp"
#include "Utils.hpp"

// פונקציה ראשית למציאת אורך הרצף המתנדנד הארוך ביותר
// אלגוריתם: מעבר על המערך ומעקב אחר כיוון השינוי (עולה/יורד)
int wiggle_subsequence(ARR<int> nums)
{
    if(nums.elements.size()<2)
        return nums.elements.size(); // מערך עם פחות מ-2 אלמנטים הוא תמיד wiggle
    
    int length, max_length=0, n=nums.elements.size(); // אורך נוכחי, מקסימלי, גודל מערך
    bool flag; // דגל לכיוון השינוי: true=עולה, false=יורד
    
    // מעבר על כל האלמנטים במערך
    for(int i=1; i<n; )
    {
        length=2; // התחלה עם 2 אלמנטים
        flag=nums[i]>nums[i-1]; // קביעת הכיוון הראשוני
        i++;
        
        // המשך הרצף כל עוד השינוי מתחלף בין עולה ליורד
        while(i<n && (flag && nums[i]<nums[i-1] || !flag && nums[i]>nums[i-1]))
        {
            flag=!flag; // החלפת הכיוון
            i++;
            length++; // הגדלת אורך הרצף
        }
        
        if(length>max_length)
            max_length=length; // עדכון האורך המקסימלי
    }
    
    return max_length; // החזרת האורך הארוך ביותר
}