/*
 * You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it.
 * 
 * Example 1:
 *     Input: lists = [[1,4,5],[1,3,4],[2,6]]
 *     Output: [1,1,2,3,4,4,5,6]
 * 
 * Example 2:
 *     Input: lists = []
 *     Output: []
 * 
 * Example 3:
 *     Input: lists = [[]]
 *     Output: []
 * 
 * Difficulty: 🔴 Hard
 * 
 * תרגום: מיזוג k רשימות מקושרות ממוינות לרשימה אחת ממוינת
 * 
 * Time Complexity: O(n*log k) - n = סה"כ צמתים, k = מספר רשימות
 * Space Complexity: O(1) - לא כולל את הרשימה החדשה שנוצרת
 */
#include "Question.hpp"
#include "Utils.hpp"
#include<iostream>
using namespace std;

// פונקציית עזר למיזוג שתי רשימות מקושרות ממוינות
// אלגוריתם: Two Pointers - השוואה ומיזוג
LL<int> merge(shared_ptr<LL<int>::Node> list1, shared_ptr<LL<int>::Node> list2)
{
    LL<int> new_list;
    auto ptr=make_shared<LL<int>::Node>(-1); // צומת דמה לתחילת הרשימה
    new_list.head=ptr;
    
    // מיזוג כל עוד שתי הרשימות לא ריקות
    while(list1!=nullptr && list2!=nullptr)
    {
        if(list1->data<list2->data) // בחירת הערך הקטן יותר
        {
            ptr->next=make_shared<LL<int>::Node>(list1->data);
            ptr=ptr->next;
            list1=list1->next; // התקדמות ברשימה הראשונה
        }
        else
        {
            ptr->next=make_shared<LL<int>::Node>(list2->data);
            ptr=ptr->next;
            list2=list2->next; // התקדמות ברשימה השנייה
        }
    }
    
    // הוספת שאר הצמתים מהרשימה הראשונה (אם נותרו)
    while(list1!=nullptr)
    {
        ptr->next=make_shared<LL<int>::Node>(list1->data);
        ptr=ptr->next;
        list1=list1->next;
    }
    
    // הוספת שאר הצמתים מהרשימה השנייה (אם נותרו)
    while(list2!=nullptr)
    {
        ptr->next=make_shared<LL<int>::Node>(list2->data);
        ptr=ptr->next;
        list2=list2->next;
    }
    
    new_list.head=new_list.head->next; // דילוג על הצומת הדמה
    return new_list;
}

// פונקציה ראשית למיזוג k רשימות מקושרות ממוינות
// אלגוריתם: Divide and Conquer - מיזוג זוגי עד שנותרת רשימה אחת
LL<int> merge_k_list(ARR<LL<int>> lists)
{
    if(lists.elements.size()==0) // מקרה קצה: אין רשימות
        return LL<int>();
        
    // מיזוג זוגי עד שנותרת רשימה אחת
    while(lists.elements.size()>1)
    {
        // מיזוג כל זוג רשימות סמוכות
        for(int i=1; i<lists.elements.size(); i+=2)
            lists[i/2]=merge(lists[i-1].head, lists[i].head);

        // אם יש מספר אי-זוגי של רשימות, העתקת האחרונה
        if(lists.elements.size()%2==1)
            lists[lists.elements.size()/2]=lists[lists.elements.size()-1];

        // הקטנת גודל המערך לחצי (+ 1 אם אי-זוגי)
        lists.elements.resize(lists.elements.size()/2+lists.elements.size()%2);
    }
    
    return lists[0]; // החזרת הרשימה הממוזגת היחידה
}