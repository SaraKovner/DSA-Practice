/*
 * Description: Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
 * The first node is considered odd, and the second node is even, and so on.
 * Note that the relative order inside both the even and odd groups should remain as it was in the input.
 * You must solve the problem in O(1) extra space complexity and O(n) time complexity.
 *  
 * Example 1:
 * Input: head = [1, 2, 3, 4, 5]
 * Output: [1, 3, 5, 2, 4]
 *  
 * Example 2:
 * Input: head = [2, 1, 3, 5, 6, 4, 7]
 * Output: [2, 3, 6, 7, 1, 5, 4]
 *  
 * Constraints:
 * The number of nodes in the linked list is in the range [0, 10^4].
 * -10^6 <= Node.val <= 10^6
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: קבץ צמתים ברשימה מקושרת לפי אינדקסים אי-זוגיים וזוגיים
 * 
 * Time Complexity: O(n) - מעבר אחד על הרשימה
 * Space Complexity: O(1)
 */
#include "Question.h"


// פונקציה ראשית לקיבוץ צמתים ברשימה מקושרת לפי אינדקסים
// אלגוריתם: Two Pointers - בניית שתי רשימות נפרדות וחיבור
LL  *  group_nodes(LL  *  list) 
{
    if(list==NULL || list->head==NULL || list->size<3)
        return list;
    
    // הראש של הרשימה המקורית מצביע לאיבר הראשון (אי זוגי)
    LLNode* even_index_list=list->head->next; // ראש רשימת האינדקסים הזוגיים
    // מתחילים לרוץ מהאיבר השלישי, האיבר השני בטוח קיים בגלל התנאי בהתחלה
    LLNode* ptr=even_index_list->next, *ptr_even=even_index_list, *ptr_odd=list->head;
    
    // אלגוריתם: בניית שתי רשימות נפרדות במקביל
    while(ptr!=NULL)
    {
        ptr_odd->next=ptr;      // חיבור האי זוגי הבא
        ptr_odd=ptr_odd->next;  // התקדמות ברשימת האי זוגיים
        ptr=ptr->next;
        if(ptr) // אם יש עוד צומת
        {
            ptr_even->next=ptr;      // חיבור הזוגי הבא
            ptr_even=ptr_even->next; // התקדמות ברשימת הזוגיים
            ptr=ptr->next;
        }
    }
    
    ptr_even->next=NULL;    // קביעת סוף הרשימה הזוגית
    ptr_odd->next=even_index_list;  // חיבור הרשימה הזוגית לסוף האי זוגית
    
    return list; // החזרת הרשימה המסודרת  
}
