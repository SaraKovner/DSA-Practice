/*
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a number of rows:
 * 
 * string convert(string s, int numRows);
 * Examples:
 *  
 * Example 1:
 * Input:
 * 
 * s = "PAYPALISHIRING", numRows = 3   
 * Output:
 * 
 * "PAHNAPLSIIGYIR"
 *     
 * Example 2:
 * Input:
 * 
 * s = "PAYPALISHIRING", numRows = 4
 * Output:
 * 
 * "PINALSIGYAHRPI"
 *     
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 *     
 * Example 3:
 * Input:
 * 
 * s = "A", numRows = 1
 * Output:
 * לא
 * "A"
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: המר מחרוזת לתבנית זיגזג עם מספר שורות נתון
 * 
 * Time Complexity: O(n) - אורך המחרוזת
 * Space Complexity: O(n) - מחרוזות לאחסון התווים
 */
#include "Question.h"
#include <ctype.h>

// פונקציה ראשית להמרת מחרוזת לתבנית זיגזג - גרסה אופטימלית
// אלגוריתם: מחרוזות נפרדות לכל שורה במקום מטריצה
STR string_to_zigzag(STR str, int numRows)  
{
    if(numRows == 1 || str == NULL) return STR_Copy(str);
    
    int n = strlen(str);
    if(n <= numRows) return STR_Copy(str);
    
    // יצירת numRows מחרוזות נפרדות
    STR* rows = (STR*)malloc(numRows * sizeof(STR));
    for(int i = 0; i < numRows; i++) {
        rows[i] = STR_Create(n + 1);
        rows[i][0] = '\0';  // אתחול כמחרוזת ריקה
    }
    
    int row = 0;
    int direction = 1;  // 1 = למטה, -1 = למעלה
    
    // הוספת תווים לשורות המתאימות לפי תבנית הזיגזג
    for(int i = 0; i < n; i++) {
        // הוספת תו לשורה הנוכחית
        int len = strlen(rows[row]);
        rows[row][len] = str[i];
        rows[row][len + 1] = '\0';
        
        // עדכון השורה הבאה
        row += direction;
        
        // שינוי כיוון בקצוות
        if(row == numRows) {
            row = numRows - 2;  // חזור לשורה לפני האחרונה
            direction = -1;     // שנה כיוון למעלה
        } else if(row == -1) {
            row = 1;            // חזור לשורה השנייה
            direction = 1;      // שנה כיוון למטה
        }
    }
    
    // חיבור כל השורות למחרוזת תוצאה אחת
    STR result = STR_Create(n + 1);
    result[0] = '\0';
    for(int i = 0; i < numRows; i++) {
        strcat(result, rows[i]);
        free(rows[i]);
    }
    free(rows);
    
    return result;
}
