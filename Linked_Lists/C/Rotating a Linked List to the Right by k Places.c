/*
 * Problem: Given a linked list, rotate the list to the right by k places.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתונה רשימה מקושרת, סובב את הרשימה ימינה ב-k מקומות
 * 
 * Example:
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [4,5,1,2,3]
 * 
 * Input: head = [0,1,2], k = 4  
 * Output: [2,0,1]
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n) - יוצר רשימה חדשה
 */
#include "Question.h"

// פונקציה לסיבוב רשימה מקושרת ימינה ב-k מקומות
LL  *  rotate_ll_to_right(LL  *  head, int  k)  {
    LL *newHead;
    int size=LL_Size(head); // גודל הרשימה
    int index; // אינדקס התחלת הרשימה החדשה
    int val; // ערך זמני לשמירת נתונים
    
    // בדיקה: אם אין מה לסובב (רשימה ריקה או k כפולה של הגודל)
    if(size==0 || (index=size-k%size)==0)
        return head;
        
    newHead=LL_Create(); // יצירת רשימה חדשה
    
    // העתקת אלמנטים בסדר החדש: מאינדקס החדש ואז מהתחלה
    for(int i=index; i<size+index; i++)
    {
        LL_GetAt(head, i%size, &val); // שימוש במודולו לחזרה לתחילת הרשימה
        LL_InsertBack(newHead, val); // הוספה לסוף הרשימה החדשה
    }
    
    return newHead;
}
