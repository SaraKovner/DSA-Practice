/*
 * Problem Description:
 * You have a list arr of all integers in the range [1, n] sorted in a strictly increasing order. Apply the following algorithm on arr:
 * Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.
 * Repeat the previous step again, but this time from right to left, remove the rightmost number and every other number from the remaining numbers.
 * Keep repeating the steps again, alternating left to right and right to left, until a single number remains.
 * Given the integer n, return the last number that remains in arr.
 * 
 * Example 1:
 *     Input: n = 9
 *     Output: 6
 *     Explanation:
 *     Initial list : [1, 2, 3, 4, 5, 6, 7, 8, 9]
 *     After first pass (left to right): [2, 4, 6, 8]
 *     After second pass (right to left): [2, 6]
 *     After third pass (left to right): [6]
 * 
 * Example 2:
 *     Input: n = 1
 *     Output: 1
 *     Explanation: There is only one element in the list.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: משחק ההדחה - מציאת המספר האחרון שנותר אחרי הדחות חליפיות משמאל ומימין
 * 
 * Time Complexity: O(log n) - כל סיבוב מחצית את הרשימה
 * Space Complexity: O(1) - שימוש במשתנים קבועים בלבד
 */

#include "Question.hpp"
#include "Utils.hpp"

// פונקציה ראשית למשחק ההדחה - מציאת המספר האחרון שנותר
// אלגוריתם: מעקב אחר האלמנט הראשון והצעד במקום סימולציה מלאה
int elimination_game(int n) 
{
    int first = 1;    // האלמנט הראשון ברשימה הנוכחית
    int step = 1;     // המרחק בין אלמנטים רציפים
    
    while(n > 1)
    {
        // מעבר שמאלה-ימינה: תמיד מזיז את הראשון
        first += step;
        step *= 2;    // המרחק מכפיל כי מוחקים כל שני
        n /= 2;       // מחצית את מספר האלמנטים
        
        if(n > 1)
        {
            // מעבר ימינה-שמאלה: מזיז רק אם מספר האלמנטים אי-זוגי
            if(n % 2 == 1)
                first += step;
            step *= 2;
            n /= 2;
        }
    }
    return first;  
}
