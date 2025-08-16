/*
 * Given head, the head of a linked list, determine if the linked list has a cycle in it.
 * There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
 * Internally, pos is used to denote the index of the node that tail's next pointer is connected to.
 * Return true if there is a cycle in the linked list. Otherwise, return false.
 *  
 * Example 1:
 *     Input: head = [3,2,0,-4], pos = 1
 *     Output: true
 *     Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
 *  
 * Example 2:
 *     Input: head = [1,2], pos = 0
 *     Output: true
 *     Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
 *  
 * Example 3:
 *     Input: head = [1], pos = -1
 *     Output: false
 *     Explanation: There is no cycle in the linked list.
 * 
 * Difficulty: 🟢 Easy
 * 
 * תרגום: בדוק אם יש מעגל ברשימה מקושרת
 * 
 * Time Complexity: O(n) - Floyd's Cycle Detection
 * Space Complexity: O(1)
 */
#include "Question.h"

// פונקציה ראשית לבדיקת מעגל ברשימה מקושרת
// אלגוריתם: Floyd's Cycle Detection (Tortoise and Hare)
STR  ll_cycle(LL  *  list)  
{
    if(list==NULL || list->head==NULL || list->head->next==NULL)
        return STR_Copy("false");
        
    // המצביע הראשון מתקדם חוליה חוליה ואילו השני מתקדם שתי חוליות, אם הם יפגשו אז קיים מעגל ברשימה
    LLNode * a=list->head, *b=list->head->next;
    
    // אלגוריתם Floyd's: מצביע איטי (a) ומצביע מהיר (b)
    while(b!=NULL && a!=b)
    {
        a=a->next;        // מצביע איטי - צעד אחד
        b=b->next;
        if(b==NULL)
            break;
        b=b->next;        // מצביע מהיר - שני צעדים
    }
    
    return b==NULL ? STR_Copy("false") : STR_Copy("true");
}