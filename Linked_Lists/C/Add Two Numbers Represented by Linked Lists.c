/*
 * Problem: Given two non-empty linked lists that represent two non-negative integers, where the digits are stored in reverse order and each node contains a single digit, write a function to add the two numbers. The function should return the sum as a linked list.
 * Assume that the two numbers do not have any leading zeros, except for the number 0 itself.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתונות שתי רשימות מקושרות לא-ריקות המייצגות שני מספרים לא-שליליים, חיבר אותם
 * 
 * Examples:
 * Example 1:
 * Input: l1 = [4, 5, 3], l2 = [5, 5, 2]
 * Output: [9, 0, 6]
 * Explanation: 255 + 354 = 609.
 * 
 * Example 2:
 * Input: l1 = [9, 9, 9], l2 = [1]
 * Output: [0, 0, 0, 1]
 * 
 * Example 3:
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 * 
 * Constraints:
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have leading zeros.
 * 
 * Time Complexity: O(max(n, m))
 * Space Complexity: O(max(n, m))
 */
#include "Question.h"

// פונקציה לחיבור שני מספרים המיוצגים כרשימות מקושרות
LL  *  add_two_ll_numbers(LL  *  l1, LL  *  l2)  
{
    int c=0, dig1, dig2, i=0; // c - נשא (carry), i - אינדקס נוכחי
    int size1=LL_Size(l1), size2=LL_Size(l2); // גדלי הרשימות
    LL* result=LL_Create(); // רשימת התוצאה
    
    // לולאה ראשונה: חיבור ספרות כל עוד יש ברשימות
    for( ; i<size1 && i<size2; i++)
    {
        LL_GetAt(l1, i, &dig1); // קבלת ספרה מרשימה ראשונה
        LL_GetAt(l2, i, &dig2); // קבלת ספרה מרשימה שנייה
        LL_InsertBack(result, (dig1+dig2+c)%10); // הוספת הספרה (מודולו 10)
        c=(dig1+dig2+c)/10; // חישוב הנשא החדש
    }
    
    // לולאה שנייה: טיפול בספרות הנותרות ברשימה הראשונה
    for( ; i<size1; i++)
    {
        LL_GetAt(l1, i, &dig1);
        LL_InsertBack(result, (dig1+c)%10);
        c=(dig1+c)/10;
    }
    
    // לולאה שלישית: טיפול בספרות הנותרות ברשימה השנייה
    for( ; i<size2; i++)
    {
        LL_GetAt(l2, i, &dig2);
        LL_InsertBack(result, (dig2+c)%10);
        c=(dig2+c)/10;
    }
    
    // אם נשאר נשא, הוספתו כספרה אחרונה
    if(c==1)
        LL_InsertBack(result, 1);
    
    return result;  
}
