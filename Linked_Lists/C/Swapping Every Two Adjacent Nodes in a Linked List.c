/*
 * Problem: Given a singly linked list, the task is to swap every two adjacent nodes and return the modified list's head. The problem must be solved without modifying the values in the nodes; only the nodes themselves may be changed.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתונה רשימה מקושרת יחידה, המשימה היא להחליף כל שני צמתים סמוכים ולהחזיר את ראש הרשימה המעודכנת
 * 
 * Example:
 * Input: head = [1, 2, 3, 4]
 * Output: [2, 1, 4, 3]
 * 
 * Explanation:
 * In the example above, the linked list is [1, 2, 3, 4]. After swapping every two adjacent nodes, the modified list is [2, 1, 4, 3].
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
//#define LL_DATA_TYPE int
#include "Question.h"

LL  *  swap_ll_nodes(LL  *  list)  {
    if(list==NULL || list->head==NULL || LL_Size(list)==1)
        return list;
        
    // יצירת צומת דמי לפני הראש - מקל על הטיפול בראש הרשימה 
    LLNode temp={0, list->head};
    LLNode *prev=&temp, *curr=list->head, *next;
    
    // מעבר על הרשימה ומחליף כל שני צמתים
    while(curr!=NULL && curr->next!=NULL)
    {
        next=curr->next; // שמירת הצומת השני
        
        // ביצוע החלפה: prev -> next -> curr -> next->next
        prev->next=next;        // prev מצביע ל-next
        curr->next=next->next;  // curr מצביע למה שאחרי next
        next->next=curr;        // next מצביע ל-curr
        
        // עדכון המצביעים לזוג הבא
        prev=curr;
        curr=curr->next;
    }
    
    // עדכון ראש הרשימה לראש החדש
    list->head=temp.next;
    return list;  
}
