/*
 * Description: One way to serialize a binary tree is to use preorder traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
 * 
 * Given a string of comma-separated values preorder, return true if it is a correct preorder traversal serialization of a binary tree.
 * 
 * It is guaranteed that each comma-separated value in the string must be either an integer or a character # representing a null pointer.
 * 
 * You may assume that the input format is always valid.
 * 
 * For example, it could never contain two consecutive commas, such as "1,,3".
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
 * Output: true
 *  
 * 
 * Example 2:
 * 
 * Input: preorder = "1,#"
 * Output: false
 *  
 * 
 * Example 3:
 * 
 * Input: preorder = "9,#,#,1"
 * Output: false
 *  
 * 
 * Constraints:
 * 
 * 1 <= preorder.length <= 10^4
 * The input format is guaranteed to be valid.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: בדוק אם מחרוזת היא סידור preorder תקין של עץ בינארי
 * 
 * Time Complexity: O(n) - מעבר אחד על המחרוזת
 * Space Complexity: O(n) - רקורסיה
 */
#include "Question.h"

// פונקציית עזר רקורסיבית לבדיקת תקינות עץ בינארי
// אלגוריתם: רקורסיה עם מעקב אחר אינדקס במחרוזת
int rec(STR s, int* index)
{
    if(s[*index]=='\0')  // כלומר המחרוזת לא תקינה - נגמרה מוקדם מדי
        return 0;
    
    if(s[*index]==',' || s[*index]==' ') // במחרוזות הנתונות יש רווח בהתחלה
        (*index)++;    // קידום על גבי הפסיק
    
    if(s[*index]=='#') // הגעתי לסוף ענף שהוא תקין - צומת NULL
    {
        (*index)++;    
        return 1; // צומת NULL תקינה
    }
     
    // דילוג על המספר הנוכחי, שיכול להכיל כמה ספרות
    while(s[*index] && s[*index]!=',')
        (*index)++;   
            
    // בדיקה רקורסיבית של תת-העץ השמאלי     
    if(rec(s, index)==0)
        return 0;
    
    // בדיקה רקורסיבית של תת-העץ הימני   
    return rec(s, index);
}

// פונקציה ראשית לבדיקת תקינות סידור preorder של עץ בינארי
// אלגוריתם: רקורסיה לבניית העץ ובדיקת תקינות
STR validate_bt_preorder(STR  preorder) 
{
    int index=0;
    
    // בדיקה שהרקורסיה הצליחה ושעברנו על כל המחרוזת
    if(rec(preorder, &index)==1 && (preorder[index]=='\0' || preorder[index]=='\t' || preorder[index]=='\n' || preorder[index]==' '))
        return STR_Copy("true");
    
    return STR_Copy("false");  
}
