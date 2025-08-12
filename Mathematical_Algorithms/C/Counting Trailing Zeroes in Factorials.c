/*
 * Problem: Given an integer n, return the number of trailing zeroes in n!.
 * Note that n! (n factorial) is defined as the product of all positive integers less than or equal to n:
 *  n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1  Examples: Example 1:
 *     Input: n = 5
 *     Output: 1
 * Explanation: 5! = 120, which has one trailing zero.
 *  Example 2:
 *     Input: n = 10
 *     Output: 2
 * Explanation: 10! = 3628800, which has two trailing zeroes.
 *  Example 3:
 *     Input: n = 25
 *     Output: 6
 * Explanation: 25! = 15511210043330985984000000, which has six trailing zeroes.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון מספר שלם n, החזר את מספר האפסים בסוף n!
 * 
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
#include "Question.h"


// פונקציה לספירת אפסים בסוף n! באמצעות ספירת גורמי 5
// אלגוריתם: אפסים נוצרים מכפל של 2*5, ויש יותר גורמי 2 מאשר גורמי 5
int  count_trailing_zeroes(int  n) 
{
    // ספירת כל הגורמים 5 ב-n! על ידי חלוקה בכל חזקות 5
    int diver=5, ans=0; // אתחול ans ל-0
    while(n/diver!=0)
    {
        ans+=n/diver; // הוספת מספר המספרים המתחלקים בחזקת 5 הנוכחית
        diver*=5; // מעבר לחזקת 5 הבאה (25, 125, 625...)
    }
    
    return ans;  
}
