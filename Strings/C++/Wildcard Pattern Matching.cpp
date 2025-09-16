/*
 * Given an input string s and a pattern p, implement wildcard pattern matching with support for '?' and '*' where:
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * The matching should cover the entire input string (not partial).
 * 
 * Example 1:
 *     Input: s = "aa", p = "a"
 *     Output: false
 * 
 * Example 2:
 *     Input: s = "adceb", p = "*a*b"
 *     Output: true
 * 
 * Example 3:
 *     Input: s = "acdcb", p = "a*c?b"
 *     Output: false
 * 
 * Difficulty: 🔴 Hard
 * 
 * תרגום: התאמת תבנית עם תווי כלליים - '?' לתו יחיד ו-'*' לרצף תווים
 * 
 * Time Complexity: O(n*m) - n = אורך המחרוזת, m = אורך התבנית
 * Space Complexity: O(n*m) - טבלת DP דו-ממדית
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;
#include <vector>
#include <algorithm>

// פונקציה ראשית להתאמת תבנית עם תווי כלליים
// אלגוריתם: Dynamic Programming - בניית טבלה מהסוף להתחלה
std::string wildcard_matching(string s, string p) 
{
    int n=s.length();
    int m=p.length();
    
    // הסרת רווחים מהמחרוזות (ניקוי קלט)
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    p.erase(remove(p.begin(), p.end(), ' '), p.end());
    
    // עדכון אורכים לאחר הניקוי
    n=s.length();
    m=p.length();
    
    // טבלת DP: dp[i][j] = האם s[i:] תואם ל-p[j:]
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    
    // מקרה בסיס: מחרוזת ריקה תואמת לתבנית ריקה
    dp[n][m]=true;
    
    // אתחול עמודה אחרונה: מחרוזת ריקה עם תבנית שמכילה רק '*'
    for(int j=m-1; j>=0; j--)
    {
        if(p[j]=='*')
            dp[n][j]=dp[n][j+1]; // '*' יכול להתאים למחרוזת ריקה
        else
            break; // תו רגיל לא יכול להתאים למחרוזת ריקה
    }
    
    // מילוי הטבלה מהסוף להתחלה
    for(int i=n-1; i>=0; i--)
        for(int j=m-1; j>=0; j--)
        {
            if(p[j]=='*') // תו כללי '*' - יכול להתאים לכל רצף
            {
                // שתי אפשרויות: '*' מתאים לתו הנוכחי או לא מתאים כלל
                dp[i][j]=dp[i][j+1] ||  // לא מתאים לתו הנוכחי (דילוג על '*')
                         dp[i+1][j];    // מתאים לתו הנוכחי (שימוש ב-'*' שוב)
            }
            else // תו רגיל או '?'
            {
                // התאמה רק אם התווים זהים (או '?') והשאר תואם
                dp[i][j]=(s[i]==p[j] || p[j]=='?') && dp[i+1][j+1];
            }
        }
    
    // התוצאה: האם כל המחרוזת תואמת לכל התבנית
    return dp[0][0] ? "true" : "false";  
}