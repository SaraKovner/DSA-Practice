/*
 * Problem: You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
 * Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * Example 1:
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 * 
 * Example 2:
 * Input: coins = [2], amount = 1
 * Output: -1
 * 
 * Example 3:
 * Input: coins = [1], amount = 0
 * Output: 0
 * 
 * Constraints:
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון מערך מטבעות וסכום כסף, מצא את המספר המינימלי של מטבעות הדרוש ליצירת הסכום
 * 
 * Time Complexity: O(amount * coins.length)
 * Space Complexity: O(amount)
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;
#define MIN(a,b) ((a)<(b) ? (a) : (b))

// פונקציה ראשית למציאת המספר המינימלי של מטבעות ליצירת סכום נתון
// אלגוריתם: Dynamic Programming - בניית טבלה לשמירת המספר המינימלי של מטבעות לכל סכום
int fewest_coins(ARR<int> coins, int amount)
{
    if(amount==0)
        return 0; // אין צורך במטבעות לסכום 0
        
    vector<int> dp(amount+1, -1); // טבלת DP מאותחלת ל-1 (בלתי אפשרי)
    
    int n=coins.elements.size(); // מספר סוגי המטבעות
    
    // אתחול: לכל מטבע יש דרך אחת ליצור את הערך שלו
    for(int i=0; i<n; i++)
        if(coins[i]<=amount)
            dp[coins[i]]=1; // מטבע אחד מספיק ליצירת הערך שלו
    
    // מילוי הטבלה לכל הסכומים
    for(int i=0; i<=amount; i++)
    {
        // בדיקת כל המטבעות לסכום הנוכחי
        for(int j=0; j<n; j++)
            if(i-coins[j]>0 && dp[i-coins[j]]!=-1) // אם אפשר להשתמש במטבע זה
                // עדכון המינימום: אם עדיין לא מצאנו דרך או מצאנו דרך טובה יותר
                dp[i] = (dp[i]==-1 ? 1+dp[i-coins[j]] : MIN(dp[i], 1+dp[i-coins[j]]));
    }
    
    return dp[amount]; // החזרת המספר המינימלי של מטבעות לסכום המבוקש
}