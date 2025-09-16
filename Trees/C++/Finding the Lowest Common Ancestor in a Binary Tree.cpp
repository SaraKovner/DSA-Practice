/*
 * Description:
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 * According to the definition of LCA on Wikipedia: "The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself)."
 * 
 * Example 1:
 * Input:
 * root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]
 * p = 5
 * q = 1
 * Output: 3
 * Explanation: The LCA of nodes 5 and 1 is 3.
 * 
 * Example 2:
 * Input:
 * root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]
 * p = 5
 * q = 4
 * Output: 5
 * Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 * 
 * Constraints:
 * All nodes are unique.
 * p and q are different and both values will exist in the binary tree.
 * The number of nodes in the tree is in the range [2, 10^5].
 * -10^9 <= Node.val <= 10^9
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: מציאת הקודם המשותף הנמוך ביותר בעץ בינארי
 * 
 * Time Complexity: O(n) - ביצוע DFS על כל הצמתים במקרה הגרוע
 * Space Complexity: O(h) - עומק הרקורסיה (h = גובה העץ)
 */
#include "Question.hpp"
#include "Utils.hpp"
using std::shared_ptr;
#include <memory>

// פונקציית עזר רקורסיבית למציאת LCA
// אלגוריתם: DFS עם Post-Order Traversal - בדיקת תת-עצים לפני הצומת הנוכחי
int lowest_ancestor_rec(shared_ptr<BT<int>::Node> t, int p, int q)
{
    // מקרה בסיס: צומת ריק
    if(t == nullptr)
        return -1; // לא מצאנו אף אחד מהצמתים
    
    // אם הצומת הנוכחי הוא אחד מהצמתים המבוקשים
    if(t->data == p || t->data == q)
        return t->data; // החזרת הצומת שמצאנו
    
    // חיפוש רקורסיבי בתת-עצים
    int left = lowest_ancestor_rec(t->left, p, q);   // חיפוש בתת-עץ השמאלי
    int right = lowest_ancestor_rec(t->right, p, q); // חיפוש בתת-עץ הימני
    
    // אם מצאנו את שני הצמתים בתת-עצים שונים - הצומת הנוכחי הוא ה-LCA
    if((left == p && right == q) || (left == q && right == p))
        return t->data; // הצומת הנוכחי הוא הקודם המשותף הנמוך ביותר
    
    // אחרת, החזרת הצומת שמצאנו (או -1 אם לא מצאנו כלום)
    // אם מצאנו רק צומת אחד, נעביר אותו למעלה
    return left == -1 ? right : left;
}

// פונקציה ראשית למציאת הקודם המשותף הנמוך ביותר
// אלגוריתם: DFS Recursive - מעבר על העץ עד מציאת שני הצמתים
int lowest_ancestor(BT<int> tree, int p, int q)
{
    return lowest_ancestor_rec(tree.root, p, q);
}
