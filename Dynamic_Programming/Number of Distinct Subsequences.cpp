/*
 * Given two strings s and t, return the number of distinct subsequences of s which equals t.
 * The test cases are generated so that the answer fits on a 32-bit signed integer.
 * 
 * Constraints:
 * 1 <= s.length, t.length <= 1000
 * s and t consist of English letters.
 * 
 * Example:
 *         Input: s = "rabbbit" ,  t = "rabbit"
 *         Output:  3.
 *         Explanation: As shown below, there are 3 ways you can generate "rabbit" from s.
 *          rabbbit     rabbbit      rabbbit
 * 
 * Difficulty: 🔴 Hard
 * 
 * תרגום: מספר תת-רצפים נפרדים של s השווים ל-t
 * 
 * Time Complexity: O(n*m) - n = אורך s, m = אורך t
 * Space Complexity: O(n*m) - טבלת DP דו-ממדית
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;
#include <vector>

// פונקציה ראשית לחישוב מספר תת-רצפים נפרדים
// אלגוריתם: Dynamic Programming - בניית טבלה דו-ממדית
int numDistinct(string s, string t) 
{
    int n = s.length(); // אורך המחרוזת המקור
    int m = t.length(); // אורך המחרוזת המטרה
    
    // טבלת DP: dp[i][j] = מספר הדרכים ליצור t[0..j-1] מ-s[0..i-1]
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    // מקרה בסיס: מחרוזת ריקה יכולה להיווצר בדרך אחת (לא לבחור כלום)
    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;
        
    // מילוי הטבלה
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s[i-1] == t[j-1]) // אם התווים זהים
            {
                // שתי אפשרויות: להשתמש בתו הנוכחי או לא
                dp[i][j] = dp[i-1][j-1] +  // משתמשים בתו (מתקדמים בשתי המחרוזות)
                          dp[i-1][j];      // לא משתמשים בתו (מתקדמים רק ב-s)
            }
            else // אם התווים שונים
            {
                // רק אפשרות אחת: לא משתמשים בתו הנוכחי של s
                dp[i][j] = dp[i-1][j]; // מתקדמים רק ב-s
            }
        }
    }
    
    return dp[n][m]; // מספר הדרכים ליצור את כל t מכל s
}