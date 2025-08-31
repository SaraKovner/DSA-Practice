/*
 * Problem: Implement the insertion sort algorithm to sort a singly linked list. The algorithm should iterate through the list, gradually building a sorted sequence from the input elements. 
 * Each iteration involves removing an element from the unsorted part of the list, identifying its appropriate position in the sorted part, and inserting it accordingly.
 * This task requires you to:
 * Define a linked list node structure.
 * Implement the insertion sort logic within a function.
 * Return the head of the sorted linked list.
 * Consider the steps of insertion sort:
 * Start with an initially empty sorted list.
 * Remove one element from the input list during each iteration.
 * Locate the correct position in the sorted list and insert the element.
 * Repeat the process until all elements are sorted.
 * The function should effectively sort any given singly linked list with integer values, ensuring that the nodes are reordered without creating any new nodes.
 * 
 * Example:
 * Input: head = [-1,5,3,4,0]
 * Output: [-1,0,3,4,5]
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: מיון רשימה מקושרת יחידה באמצעות אלגוריתם Insertion Sort
 * 
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;
#include <climits> 

// פונקציה ראשית למיון רשימה מקושרת באמצעות Insertion Sort
// אלגוריתם: מעבר על כל צומת ומציאת המקום הנכון להכנסתו ברשימה הממוינת
LL<int> search_target(LL<int> list)
{
    if(list.head==nullptr || list.head->next==nullptr)
        return list; // רשימה ריקה או עם אלמנט אחד כבר ממוינת
        
    // יצירת צומת דמה לפני הראש לפישוט הקוד
    auto dummy=make_shared<LL<int>::Node>(INT_MIN);
    dummy->next=list.head;
    auto curr=dummy->next; // מצביע לצומת הנוכחי
    
    // מעבר על כל הצמתים ברשימה
    while(curr && curr->next)
    {
        auto target=curr->next; // הצומת שצריך למיין
        auto ptr=dummy; // מצביע לחיפוש המקום הנכון
        
        // חיפוש המקום הנכון להכנסת target ברשימה הממוינת
        while(ptr->next!=target && ptr->next->data<=target->data)
            ptr=ptr->next;
            
        if(ptr->next==target)   // target כבר במקום הנכון
            curr=curr->next;
        else // צריך להזיז את target למקום הנכון
        {
            curr->next=target->next; // הסרת target מהמקום הנוכחי
            target->next=ptr->next;  // הכנסת target למקום הנכון
            ptr->next=target;
        }
    }
    
    list.head=dummy->next; // עדכון ראש הרשימה
    
    return list; // החזרת הרשימה הממוינת
}