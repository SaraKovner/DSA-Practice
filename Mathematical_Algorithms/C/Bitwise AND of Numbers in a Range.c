/*
 * Description: Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.
 *  
 * Example 1:
 * Input: left = 5, right = 7
 * Output: 4
 * Explanation: The bitwise AND of numbers 5, 6, and 7 is 4.
 *  
 * Example 2:
 * Input: left = 0, right = 0
 * Output: 0
 * Explanation: The bitwise AND of the only number 0 is 0.
 *  
 * Example 3:
 * Input: left = 1, right = 2147483647
 * Output: 0
 * Explanation: The bitwise AND of all numbers in this range is 0 because there is at least one 0 in every bit position.
 *  
 * Constraints:
 * 0 <= left <= right <= 2^31 - 1
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתונים שני מספרים שלמים left ו-right המייצגים טווח, החזר את ה-AND הביטי של כל המספרים בטווח
 * 
 * Time Complexity: O(log n) - מקסימום 32 איטרציות (32 ביט)
 * Space Complexity: O(1) - משתנים קבועים בלבד
 */
#include "Question.h"

// פונקציה יעילה לחישוב AND ביטי של כל המספרים בטווח [left, right]
// אלגוריתם: מציאת הקידומת הבינארית המשותפת הארוכה ביותר
// תובנה: רק הביטים שזהים ב-left וב-right יכולים להישאר 1 בתוצאה!
int  bitwise_and(int  left, int  right)
{
    int shift = 0; // מספר הביטים שהסטנו ימינה
    
    // מוצאים את הקידומת המשותפת הארוכה ביותר של left ו-right
    // כל עוד המספרים שונים - מסירים את הביט הימני ביותר
    while (left != right) 
    {
        // הסטה ימינה בביט אחד - מוחקים את הביט הימני ביותר
        left >>= 1;  // דוגמה: 101 בינארי הופך ל-10 בינארי
        right >>= 1; // דוגמה: 111 בינארי הופך ל-11 בינארי
        
        shift++; // סופרים כמה ביטים הסטנו כדי להחזיר אותם מאוחר יותר
        
        // דוגמה למה זה עובד:
        // left=5=101, right=7=111 שונים בביטים האחרונים
        // אחרי הסטה: left=2=10, right=3=11 עדיין שונים
        // אחרי הסטה נוספת: left=1=1, right=1=1 זהים!
    }
    
    // כעת left == right, זו הקידומת המשותפת
    // מחזירים אותה למקום המקורי על ידי הסטה שמאלה
    // דוגמה: אם left=1 ו-shift=2, אז 1<<2 = 100 בינארי = 4 דצימלי
    return left << shift;
    
    // מדוע זה עובד? כי בכל טווח [left,right], אם יש הבדל בביט מסוים,
    // אז בטווח יהיו מספרים עם 0 ועם 1 באותו ביט
    // לכן AND יהפוך את הביט הזה ל-0!
}
