/*
 * Problem: Given two integers representing the numerator and denominator of a fraction, return the fraction in string format. If the fractional part is repeating, enclose the repeating part in parentheses. If multiple answers are possible, return any of them.
 * It is guaranteed that the length of the answer string is less than 104 for all the given inputs.
 *  Examples: Example 1:
 *     Input: numerator = 1, denominator = 2
 *     Output: "0.5"
 * Explanation: The fraction 1/2 is equal to 0.5.
 *  Example 2:
 *     Input: numerator = 2, denominator = 3
 *     Output: "0.(6)"
 * Explanation: The fraction 2/3 is equal to 0.666... with 6 repeating indefinitely.
 *  Example 3:
 *     Input: numerator = 4, denominator = 333
 *     Output: "0.(012)"
 * Explanation: The fraction 4/333 is equal to 0.012012... with 012 repeating indefinitely.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתונים שני מספרים שלמים המייצגים מונה ומכנה של שבר, החזר את השבר בפורמט מחרוזת
 * 
 * Time Complexity: O(denominator) - במקרה הרע
 * Space Complexity: O(denominator) - לשמירת השאריות
 */
#include "Question.h"
#include <string.h>
#include <stdlib.h>

// פונקציה ראשית להמרת שבר למחרוזת עם טיפול בחזרות
// אלגוריתם: חילוק ארוך עם מעקב אחר שאריות חוזרות
STR  fraction_to_recurring(int  numerator, int  denominator) 
{
    char str[50];    // מחרוזת עזר להמרות
    char res[10000]; // מחרוזת התוצאה הסופית
    res[0] = 0;      // אתחול כמחרוזת ריקה

    // טיפול בסימן
    int is_negative = (numerator < 0) ^ (denominator < 0);
    long long num = llabs((long long)numerator);
    long long den = llabs((long long)denominator);

    if (is_negative && num != 0) {
        strcat(res, "-");
    }

    sprintf(str, "%lld", num / den);
    strcat(res, str);

    if (num % den == 0) // אם אין שארית
        return STR_Copy_raw(res);

    strcat(res, ".");

    LL* list = LL_Create();
    LLNode* ptr;

    int remainder = num % den;
    while(remainder!=0)
    {
        remainder *= 10;
        int digit = remainder / den;
        remainder %= den;
        
        ptr=list->head;
        while(ptr!=NULL)
        {
            if(ptr->data==digit)
                break;
            ptr=ptr->next;
        }
        if(ptr!=NULL)
            break;
        LL_InsertBack(list,digit);
    }
    ptr=list->head;
    while(ptr!=NULL&&ptr->data!=numerator)
    {
        sprintf(str,"%d",ptr->data);
        strcat(res,str);   
        ptr=ptr->next;
    }
    if(ptr==NULL)
    {
         LL_Free(list);
        return STR_Copy_raw(res);
    }
    strcat(res,"(");
     while(ptr!=NULL)
    {
        sprintf(str,"%d",ptr->data);
        strcat(res,str);   
        ptr=ptr->next;
    }
    
    strcat(res,")");
    LL_Free(list);
    return STR_Copy_raw(res);
}

