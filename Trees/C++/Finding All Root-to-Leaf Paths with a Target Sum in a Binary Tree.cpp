/*
 * Problem: Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. 
 * Each path should be returned as a list of the node values, not node references.
 * A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
 * 
 * Example:
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * Output: [[5,4,11,2], [5,8,4,5]]
 * 
 * Input: root = [1,2,3], targetSum = 5
 * Output: []
 * 
 * Input: root = [1,2], targetSum = 0
 * Output: []
 * 
 * Explanation:
 * For the input root = [5,4,8,11,null,13,4,7,2,null,null,5,1] and targetSum = 22, the root-to-leaf paths that sum to 22 are [[5,4,11,2], [5,8,4,5]].
 * For the input root = [1,2,3] and targetSum = 5, there are no root-to-leaf paths that sum to 5, so the output is [].
 * For the input root = [1,2] and targetSum = 0, there are no root-to-leaf paths that sum to 0, so the output is [].
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון עץ בינארי וסכום מטרה, מצא את כל המסלולים משורש לעלה שסכומם שווה לסכום המטרה
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(h) where h is height of tree
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;

// פונקציה עזר רקורסיבית למציאת כל המסלולים משורש לעלה עם סכום מטרה
// אלגוריתם: DFS עם Backtracking - מעבר על כל המסלולים האפשריים
void findPaths(const shared_ptr<BT<int>::Node> t, int sum, ARR<ARR<int>>& res, ARR<int>& path)
{
    if(t==nullptr)
        return; // צומת ריק - חזרה
      
    path.elements.push_back(t->data); // הוספת הצומת הנוכחי למסלול
    
    // בדיקה אם הגענו לעלה והסכום תואם למטרה
    if(t->left==nullptr && t->right==nullptr && sum==t->data)
        res.elements.push_back(path); // הוספת המסלול לתוצאות

    // המשך חיפוש בתת-עצים עם סכום מעודכן
    findPaths(t->left, sum-t->data, res, path);
    findPaths(t->right, sum-t->data, res, path);
    
    path.elements.pop_back(); // Backtracking - הסרת הצומת הנוכחי מהמסלול
}

// פונקציה ראשית למציאת כל המסלולים משורש לעלה עם סכום מטרה
ARR<ARR<int>> root_to_leaf(BT<int> tree, int targetSum)
{
    ARR<ARR<int>> res; // מערך התוצאות
    ARR<int> path; // המסלול הנוכחי
    
    findPaths(tree.root, targetSum, res, path); // התחלת החיפוש
    return res; // החזרת כל המסלולים שנמצאו
}