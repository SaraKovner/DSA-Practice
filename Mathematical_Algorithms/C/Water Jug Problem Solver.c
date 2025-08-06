/*
 * Problem: You have two jugs with capacities x liters and y liters. With an infinite supply of water, determine if you can measure exactly target liters using the following operations:
 * Fill either jug completely.
 * Empty either jug completely.
 * Pour water from one jug into the other until one of the jugs is either full or empty.
 * Write a function to return whether it is possible to achieve exactly target liters.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: יש לך שני כדים בנפחים x ו-y ליטרים, קבע אם ניתן למדוד בדיוק target ליטרים
 * 
 * Example 1:
 * Input: x = 3, y = 5, target = 4
 * Output: true
 * Explanation: You can measure 4 liters by the following steps: Fill the 5-liter jug, pour into the 3-liter jug until it's full (3 liters), and you're left with exactly 2 liters in the 5-liter jug. Empty the 3-liter jug and pour the 2 liters into it. Fill the 5-liter jug again and pour water into the 3-liter jug until it's full. You are left with exactly 4 liters in the 5-liter jug.
 * 
 * Example 2:
 * Input: x = 2, y = 6, target = 5
 * Output: false
 * Explanation: It is impossible to measure 5 liters with these jugs.
 * 
 * Time Complexity: O(log(min(x,y)))
 * Space Complexity: O(1)
 */
#include "Question.h"

// פונקציה לחישוב המחלק המשותף הגדול ביותר (GCD) באלגוריתם אוקלידס
// אלגוריתם יעיל בזמן O(log(min(a,b)))
int GCD(int a, int b)
{
    int res;
    while(b!=0) // כל עוד b לא אפס
    {
        res=a%b; // שארית החלוקה
        a=b;     // a מקבל את הערך של b
        b=res;   // b מקבל את השארית
    }
    
    return a; // כאשר b=0, a הוא ה-GCD
}

// פתרון בעיית כדי המים (Water Jug Problem)
// בעיה קלאסית: האם ניתן למדוד target ליטרים עם שני כדים בגדלים x ו-y
STR  water_jug_problem(int  x, int  y, int  target)  
{
    // וידוא שx הוא הקטן יותר (לא חובה אבל מסדר)
    if(x>y)
    {
        int temp=x;
        x=y;
        y=temp;
    }
    
    // תנאי פתירות: target לא יכול להיות גדול מסכום הכדים
    // וחייב להיות כפולה של GCD(x,y) - תנאי מתמטי בסיסי
    if(target>x+y || target%GCD(y, x))
        return STR_Copy_raw("false");
    
    return STR_Copy_raw("true");
}


