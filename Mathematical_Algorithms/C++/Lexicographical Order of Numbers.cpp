/*
 * Problem Description:
 * Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
 * You must write an algorithm that runs in O(n) time and uses O(1) extra space.
 * 
 * Example 1:
 *     Input: n = 13
 *     Output: [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]
 * 
 * Example 2:
 *     Input: n = 2
 *     Output: [1, 2]
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: סידור לקסיקוגרפי - מיון מספרים לפי סדר אלפביתי (כמו מחרוזות)
 * 
 * Time Complexity: O(n) - מעבר יחיד על כל המספרים
 * Space Complexity: O(1) - שימוש במשתנים קבועים בלבד (ללא מערך תוצאה)
 */

#include "Question.hpp"
#include "Utils.hpp"

// פונקציה ראשית למיון מספרים בסדר לקסיקוגרפי
// אלגוריתם: דמיון DFS על עץ דיגיטלי - נסה להוסיף ספרה, אם לא ניתן עבור לאח הבא
ARR<int> lexicographical_numbers(int n) 
{
    ARR<int> res;
    int num = 1; // מתחילים מ-1 (הקטן ביותר לקסיקוגרפית)
    
    for (int i = 0; i < n; i++)
    {
        res.elements.push_back(num);
        
        // נסה להוסיף 0 בסוף (לרדת עמוק יותר בעץ)
        if (num * 10 <= n) 
            num *= 10;
        else
        {
            // אם לא ניתן להוסיף 0, נסה לעבור למספר הבא
            if (num >= n) // אם חרגנו מהטווח, חזור לרמה גבוהה יותר
                num /= 10;
            num++; // עבור למספר הבא
            
            // אם המספר מסתיים ב-0 (למשל 20), חזור לרמה גבוהה יותר (2)
            while (num % 10 == 0) 
                num /= 10;
        }
    }
    
    return res;  
}
