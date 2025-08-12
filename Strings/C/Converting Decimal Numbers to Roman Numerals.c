/*
 * Problem Description:
 * Roman numerals are represented by seven different symbols, each with a corresponding value:
 * I: 1
 * V: 5
 * X: 10
 * L: 50
 * C: 100
 * D: 500
 * M: 1000
 * The task is to convert a given integer into its Roman numeral representation, following these rules:
 * For values not starting with 4 or 9, use the largest possible symbol value and subtract it from the input, then convert the remainder.
 * For values starting with 4 or 9, use the subtractive form:
 * 4 is represented as "IV" (1 less than 5)
 * 9 is represented as "IX" (1 less than 10)
 * Similar patterns apply for other values: 40 (XL), 90 (XC), 400 (CD), and 900 (CM).
 * Powers of 10 (I, X, C, M) can be used consecutively up to three times, but symbols representing 5 (V, L, D) cannot be repeated. Use subtractive forms if a symbol needs to be appended four times.
 * Example:
 * Input: 3549
 * Output: MMMDXLIX
 *  
 * Explanation:
 * 3000 is represented by "MMM".
 * 500 is represented by "D".
 * 40 is represented by "XL".
 * 9 is represented by "IX".
 * The resulting Roman numeral is "MMMDXLIX".
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: המר מספר שלם לייצוג ברומי לפי הכללים הנתונים
 * 
 * Time Complexity: O(1) - מספר קבוע של איטרציות
 * Space Complexity: O(1) - מקום קבוע
 */
#include "Question.h"

// פונקציה ראשית להמרת מספר שלם לספרות רומיות
STR  convert_decimal_number(int  num)  
{
    int len=20, index=0;
    STR res=STR_Create(len);
    
    // מערך ערכים ממוין בסדר יורד (כולל צורות חיסור)
    int values[]={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    // מערך הסמלים המתאימים לערכים
    char* symbols[]={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    int n=sizeof(values)/sizeof(int); // 13 ערכים
    
    // מעבר על כל הערכים מהגדול לקטן
    for(int i=0; i<n; i++)
        // כל עוד המספר גדול מהערך הנוכחי - הוסף את הסמל
        while(num>=values[i])
        {
            // העתקת כל התווים של הסמל (למשל "CM" = 2 תווים)
            for(int j=0; symbols[i][j]; j++)
                res.s[index++]=symbols[i][j];
            num-=values[i]; // הורדת הערך מהמספר
        }
        
    // סיום המחרוזת והתאמת הגודל
    res.s[index]=0;
    res.s=(char*)realloc(res.s, sizeof(char)*(index+1));
    res.n=index;
    
    return res;  
}
