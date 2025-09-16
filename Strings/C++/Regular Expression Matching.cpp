/*
 * Description:
 * Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * The matching should cover the entire input string (not partial).
 * 
 * Example 1:
 *     Input: s = "aa", p = "a"
 *     Output: false
 *     Explanation: "a" does not match the entire string "aa".
 * 
 * Example 2:
 *     Input: s = "aa", p = "a*"
 *     Output: true
 *     Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
 * 
 * Example 3:
 *     Input: s = "ab", p = ".*"
 *     Output: true
 *     Explanation: '.' means any single character and '*' means zero or more of the preceding element. Therefore, ".*" means "zero or more (*) of any character (.)".
 * 
 * Constraints:
 * 1 <= s.length <= 20
 * 1 <= p.length <= 30
 * s contains only lowercase English letters.
 * p contains only lowercase English letters, '.', and '*'.
 * It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
 * 
 * Difficulty: 🔴 Hard
 * 
 * תרגום: התאמת ביטויים רגולריים - תמיכה בתווי כללי '.' וכוכבית '*'
 * 
 * Time Complexity: O(n*m) - n = אורך המחרוזת, m = אורך התבנית
 * Space Complexity: O(n*m) - מטריצת DP דו-ממדית
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;
#include <vector>

// פונקציה ראשית להתאמת ביטויים רגולריים
// אלגוריתם: Dynamic Programming (Bottom-Up) - בניית מטריצת התאמות
string matching(string s, string p)
{
    int n = s.length(); // אורך המחרוזת
    int m = p.length(); // אורך התבנית
    
    // מטריצת DP: dp[i][j] = האם s[i:] תואם ל-p[j:]
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    
    // מקרה בסיס: שתי המחרוזות ריקות - תמיד תואם
    dp[n][m] = true;
    
    // מילוי המטריצה מהסוף להתחלה (Bottom-Up)
    for(int i = n; i >= 0; i--) // עבור כל מיקום במחרוזת s
    {
        for(int j = m-1; j >= 0; j--) // עבור כל מיקום בתבנית p
        {
            // בדיקה האם התווים הנוכחיים תואמים
            // תואם אם: תו זהה או התבנית מכילה '.' (תו כללי)
            bool chars_match = (i < n && (s[i] == p[j] || p[j] == '.'));
            
            // אם התו הבא בתבנית הוא '*' - יש שני מצבים אפשריים
            if(j+1 < m && p[j+1] == '*')
            {
                // מצב 1: דילוג על הזוג (תו+'*') - 0 הופעות
                // מצב 2: שימוש בתו הנוכחי אם הוא תואם - 1+ הופעות
                dp[i][j] = dp[i][j+2] || (chars_match && dp[i+1][j]);
            }
            else
            {
                // אין '*' - התאמה רגילה: תו נוכחי תואם + המשך המחרוזת
                dp[i][j] = chars_match && dp[i+1][j+1];
            }
        }
    }
    
    // התוצאה: האם כל המחרוזת תואמת לכל התבנית
    return dp[0][0] ? "true" : "false";
}
