/*
 * Problem Description:
 * Given the head of a linked list and a value x, partition the list such that all nodes less than x come before nodes greater than or equal to x.
 * You should preserve the original relative order of the nodes in each of the two partitions.
 * 
 * Example:
 * 
 *     Input: head = [1,4,3,2,5,2], x = 3
 *     Output: [1,2,2,4,3,5]
 * 
 *     Input: head = [2,1], x = 2
 *     Output: [1,2]
 * 
 * Explanation:
 * For the input head = [1,4,3,2,5,2], x = 3, the nodes less than 3 are [1,2,2] and nodes greater than or equal to 3 are [4,3,5]. The final partitioned list is [1,2,2,4,3,5].
 * For the input head = [2,1], x = 2, the nodes less than 2 are [1] and nodes greater than or equal to 2 are [2]. The final partitioned list is [1,2].
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: חלוקת רשימה מקושרת סביב ערך נתון - ארגון צמתים לפי ערך השוואה
 * 
 * Time Complexity: O(n) - מעבר יחיד על כל הצמתים
 * Space Complexity: O(1) - שימוש במצביעים בלבד (ללא מקום נוסף)
 */
#include "Question.hpp"
#include "Utils.hpp"

// פונקציה ראשית לחלוקת רשימה מקושרת סביב ערך נתון
// אלגוריתם: Two Pointers עם שתי רשימות נפרדות
LL<int> partition_list(LL<int> head, int x)
{
    // יצירת צמתי dummy לשתי הרשימות (קטן מ-x וגדול/שווה ל-x)
    auto lessDummy = std::make_shared<LL<int>::Node>(0);      // ראש רשימת הערכים הקטנים
    auto greaterDummy = std::make_shared<LL<int>::Node>(0);   // ראש רשימת הערכים הגדולים/שווים
    
    // מצביעים לסוף כל רשימה
    auto lessPtr = lessDummy;        // מצביע לסוף רשימת הקטנים
    auto greaterPtr = greaterDummy;  // מצביע לסוף רשימת הגדולים/שווים
    
    // מעבר על כל הצמתים ברשימה המקורית
    auto cur = head.head;
    while (cur) 
    {
        if(cur->data < x) // אם הערך קטן מ-x
        {
            lessPtr->next = cur;  // הוספה לרשימת הקטנים
            lessPtr = cur;        // עדכון מצביע סוף הרשימה
        }
        else // אם הערך גדול או שווה ל-x
        {
            greaterPtr->next = cur;  // הוספה לרשימת הגדולים/שווים
            greaterPtr = cur;        // עדכון מצביע סוף הרשימה
        }
        cur = cur->next; // מעבר לצומת הבא
    }

    // חיבור שתי הרשימות: קטנים + גדולים/שווים
    lessPtr->next = greaterDummy->next; // חיבור סוף רשימת הקטנים לתחילת רשימת הגדולים
    greaterPtr->next = nullptr;         // סיום הרשימה המחולקת

    // יצירת התוצאה - רשימה מחולקת חדשה
    LL<int> result;
    result.head = lessDummy->next;  // התחלת התוצאה מרשימת הקטנים

    return result; // החזרת הרשימה המחולקת
}
