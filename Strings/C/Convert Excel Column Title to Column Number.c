/*
 * Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.
 *  
 * Example 1:
 *     Input: columnTitle = "A"
 *     Output: 1
 *  
 * Example 2:
 *     Input: columnTitle = "AB"
 *     Output: 28
 *  
 * Example 3:
 *     Input: columnTitle = "ZY"
 *     Output: 701
 * 
 * Difficulty: 🟢 Easy
 * 
 * תרגום: המר כותרת עמודה באקסל למספר עמודה
 * 
 * Time Complexity: O(n) - אורך המחרוזת
 * Space Complexity: O(1)
 */
#include "Question.h"
// פונקציה ראשית להמרת כותרת עמודה באקסל למספר
// אלגוריתם: המרה מבסיס 26 (A=1, B=2, ..., Z=26)
int  convert_excel_col(STR  columnTitle)  
{
    if(columnTitle==NULL)
        return -1;
    int n=strlen(columnTitle);
    // ניקוי תווים מהסוף
    for(; n>0 && (columnTitle[n-1]==' ' || columnTitle[n-1]=='\n') ; n--);
    
    int number=0;
    
    // מעבר על כל תו ומחשב את הערך בבסיס 26
    for(int i=0; i<n; i++)
    {
        number*=26;                        // הכפלה בבסיס
        number+=(columnTitle[i]-'A'+1);    // כל תו שווה 1-26
    }
    
    return number;  
}
