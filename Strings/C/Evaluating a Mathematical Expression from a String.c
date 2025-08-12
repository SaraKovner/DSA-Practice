/*
 * Description: Given a string s which represents a mathematical expression, evaluate this expression and return its value. The integer division should truncate toward zero. Assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
 *  
 * Example 1:
 * Input: s = "3+2*2"
 * Output: 7
 *  
 * Example 2:
 * Input: s = " 3/2 "
 * Output: 1
 *  
 * Example 3:
 * Input: s = " 3+5 / 2 "
 * Output: 5
 *  
 * Constraints:
 * 1 <= s.length <= 3 * 105
 * s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
 * s represents a valid expression.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתונה מחרוזת המייצגת ביטוי מתמטי, חשב את ערכו והחזר את התוצאה
 * 
 * Time Complexity: O(n) - מעבר על המחרוזת פעם אחת
 * Space Complexity: O(n) - מחסנית לאופרטורים ומספרים
 */
#include "Question.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// פונקציית עזר לבדיקה אם מחרוזת היא מספר בלבד
// אם לא, מחזירה ב-end_index את המיקום שבו נעצרה
int is_num(const char* str, int * end_index)
{
    if(!str || !(*str))
        return 0;
    int i=0;
    while(*(str+i))
    {
        if(!isdigit(*(str+i)))
        {
            *end_index=i; // מיקום התו שאינו ספרה
            return 0;
        }
        i++;
    }
    
    return 1; // כל המחרוזת היא מספר
}

// פונקציית עזר לביצוע פעולות מתמטיות בסיסיות
int math(int num1, int num2, char op)
{
    switch(op)
    {
        case '*': return num1*num2;                    // כפל
        case '/': return num2==0? 0: num1/num2;        // חילוק (עם בדיקת אפס)
        case '-': return num1-num2;                    // חיסור
        case '+': return num1+num2;                    // חיבור
        default: return 0;                             // אופרטור לא מוכר
    }
}

//פונקציה שמחזירה את אינדקס החלוקה לפי קדימות ביוטים
int find_split(char* s)
{
    int i, len=strlen(s);
    for(i=len-1; i>=0; i--)
        if(s[i]=='+' || s[i]=='-')
            return i;
            
    for(i=len-1; i>=0; i--)
        if(s[i]=='*' || s[i]=='/')
            return i;
            
    return -1;
}

int rec(char* s)
{
    //אם כל נמחרוזת היא מספר
    int end_index=0;
    if(is_num(s, &end_index))
        return atoi(s);
    
    int idx=find_split(s);  //חותך בין בטוים עם קדימיות
    if(idx==-1)
        return 0;   //אם הקלט לא היה חוקי
    
    char op=s[idx];
    s[idx]='\0';
    
    //שליחת ריקורסה לשני צידי הבטוי
    int left=rec(s);
    int right=rec(s+idx+1);
    
    s[idx]=op;
    
    return math(left, right, op);
}


int evaluating_expression(STR  s) 
{
    char* str=malloc(s.n-2);
    // printf("%s\n", s.s);
    memcpy(str, s.s+1, s.n-3);
    str[s.n-1]='\0';
    // printf("%s\n", str);
    int res=rec(str);
    free(str);
    return res;  
}
