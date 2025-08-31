/*
 * Problem: Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree (BST).
 * A height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differs by more than one.
 * 
 * Example:
 * Input: head = [-10, -3, 0, 5, 9]
 * Output: The root of the height-balanced BST.
 * 
 * Input: head = []
 * Output: null
 * 
 * Explanation:
 * For the input head = [-10, -3, 0, 5, 9], the height-balanced BST is:
 *             0
 *            / \
 *          -10  5
 *            \   \
 *            -3   9
 *         
 * For the input head = [], the output is null.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתונה רשימה מקושרת ממוינת, המר אותה לעץ חיפוש בינארי מאוזן בגובה
 * 
 * Time Complexity: O(n log n)
 * Space Complexity: O(log n)
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;

// פונקציה עזר לחישוב אורך הרשימה המקושרת
int length(LL<int>& list)
{
    int count=0;
    auto curr=list.head;
    
    while(curr)
    {
        curr=curr->next;
        count++;
    }
    
    return count;
}

// פונקציה רקורסיבית לבניית עץ BST מאוזן מרשימה מקושרת
// אלגוריתם: Divide and Conquer - מציאת האמצע כשורש וחלוקה לתת-עצים
shared_ptr<BT<int>::Node> build_bts(shared_ptr<LL<int>::Node> head, int length)
{
    if(length<=0)
        return nullptr; // רשימה ריקה
       
    // מציאת האמצע של הרשימה בחלק הנוכחי - יהיה השורש
    auto mid=head;
    int even=abs(length%2-1); // אם האורך זוגי: 1, אחרת: 0
    for(int i=0; i<length/2; i++)
        mid=mid->next;
    
    // יצירת צומת חדש עם הערך מהאמצע
    auto node=make_shared<BT<int>::Node>(mid->data);
    
    // בניית תת-עץ שמאלי מהחלק השמאלי של הרשימה
    node->left=build_bts(head, length/2);  
    
    // בניית תת-עץ ימני מהחלק הימני של הרשימה
    node->right=build_bts(mid->next, length/2-even); // התאמה לאורך זוגי/אי-זוגי
    
    return node;
}

// פונקציה ראשית להמרת רשימה מקושרת ממוינת לעץ BST מאוזן
BT<int> ll_to_bst(LL<int> list) 
{
    BT<int> bts;
    bts.root=build_bts(list.head, length(list)); // בניית העץ
    
    return bts; // החזרת העץ המאוזן
}