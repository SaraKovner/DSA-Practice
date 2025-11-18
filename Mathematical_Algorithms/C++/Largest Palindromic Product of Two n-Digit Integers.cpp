/*
 * Problem Description:
 * Given an integer n, return the largest palindromic integer that can be represented as the product of two n-digit integers.
 * Since the answer can be very large, return it modulo 1337.
 * 
 * Example 1:
 *     Input: n = 2
 *     Output: 987
 *     Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
 * 
 * Example 2:
 *     Input: n = 1
 *     Output: 9
 *     Explanation: 3 x 3 = 9
 * 
 * Difficulty: 🔴 Hard
 * 
 * תרגום: מציאת המכפלה הפלינדרומית הגדולה ביותר - מציאת הפלינדרום הגדול ביותר שהוא מכפלה של שני מספרים n-ספרתיים
 * 
 * Time Complexity: O(10^n) - במקרה הרע
 * Space Complexity: O(n) - לפעולות מחרוזת
 */

#include "Question.hpp"
#include "Utils.hpp"
using namespace std;
#include <cmath>
#include <algorithm>
#include <string>

// פונקציה ראשית למציאת המכפלה הפלינדרומית הגדולة ביותר
// אלגוריתם: יצירת פלינדרומים מהגדול לקטן ובדיקה אם ניתן לפרק למכפלת שני n-ספרתיים
int largest_palindrome_product(int n) 
{
    if (n == 1) return 9; // מקרה בסיסי: 3 * 3 = 9

    long long upper = pow(10, n) - 1; // המספר הגדול ביותר עם n ספרות (למשל: 99 עבור n=2)
    long long lower = pow(10, n - 1); // המספר הקטן ביותר עם n ספרות (למשל: 10 עבור n=2)

    // יצירת פלינדרומים מהגדול לקטן על ידי שיקוף החלק השמאלי
    for (long long left = upper; left >= lower; --left) {
        string s = to_string(left);
        string rev = s;
        reverse(rev.begin(), rev.end());
        long long palin = stoll(s + rev); // יצירת פלינדרום זוגי אורך

        // בדיקה אם הפלינדרום ניתן לפירוק למכפלת שני n-ספרתיים
        for (long long i = upper; i * i >= palin; --i) {
            if (palin % i == 0) { // אם i מחלק את הפלינדרום
                long long j = palin / i;
                if (j >= lower && j <= upper) { // אם גם j הוא n-ספרתי
                    return palin % 1337;
                }
            }
        }
    }
    return 0; // לא אמור להגיע לכאן
}



