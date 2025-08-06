/*
 * Problem: Given a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתונה רשימה מקושרת יחידה ושני מספרים שלמים left ו-right, הפוך את הצמתים ממיקום left עד right
 * 
 * Example:
 * Input: list = [1,2,3,4,5], left = 2, right = 4
 * Output: [1,4,3,2,5]
 * 
 * Input: list = [5], left = 1, right = 1
 * Output: [5]
 * 
 * Explanation:
 * For the input list = [1,2,3,4,5], left = 2, right = 4, reversing the nodes from position 2 to 4 results in the list [1,4,3,2,5].
 * For the input list = [5], left = 1, right = 1, there is no change as there is only one node.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
//    #define LL_DATA_TYPE int
#include "Question.h"

// פונקציה להפיכת תת-רשימה ברשימה מקושרת
// מאינדקס left עד אינדקס right (כולל)
LL  *  reverse_ll(LL  *  list, int  left, int  right)  {
    // בדיקות קצה - רשימה ריקה או אינדקסים לא חוקיים
    if(list==NULL || list->head==NULL || left>=right)
        return list;
        
    // תיקון אינדקס ימין אם חורג מגדל הרשימה
    if(right>list->size)   
        right=list->size;
        
    // יצירת צומת דמי ומצביעי עבודה
    LLNode temp={0, list->head}, *curr, *next;
    LLNode *prev=&temp; // prev מצביע לצומת שלפני התת-רשימה

    // מעבר לצומת שלפני התחלת ההפיכה
    for(int i=1; i<left; i++)
        prev=prev->next;
    
    curr=prev->next; // צומת ראשונה להפיכה
    
    // אלגוריתם ההפיכה: מעביר כל צומת לראש התת-רשימה
    for(int i=left; i<right && curr->next!=NULL; i++)
    {
        next=curr->next; // שמירת הצומת הבאה
        curr->next=next->next; // קישור curr לצומת שאחרי next
        next->next=prev->next; // קישור next לראש התת-רשימה
        prev->next=next; // עדכון ראש התת-רשימה
    }
    
    list->head=temp.next; // עדכון ראש הרשימה
    return list;  
}
