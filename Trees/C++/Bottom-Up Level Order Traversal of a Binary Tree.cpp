/*
 * Problem Description:
 * Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. This means traversing the tree level by level from left to right, starting from the leaf nodes and moving up to the root.
 * 
 * Example:
 * 
 *     Input: root = [3,9,20,null,null,15,7]
 *     Output: [[15,7], [9,20], [3]]
 * 
 *     Input: root = [1]
 *     Output: [[1]]
 * 
 *     Input: root = []
 *     Output: []
 * 
 * Explanation:
 * For the input root = [3,9,20,null,null,15,7], the bottom-up level order traversal is [[15,7], [9,20], [3]].
 * For the input root = [1], the bottom-up level order traversal is [[1]].
 * For the input root = [], the bottom-up level order traversal is [].
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: מעבר על עץ בינארי לפי רמות מלמטה למעלה - חזרה מהעלים לשורש
 * 
 * Time Complexity: O(n) - ביקור בכל צומת פעם אחת
 * Space Complexity: O(w) - w = רוחב מקסימלי של העץ (לתור BFS)
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;
#include <queue>
#include <algorithm>

// פונקציה ראשית למעבר על עץ בינארי לפי רמות מלמטה למעלה
// אלגוריתם: BFS (Breadth-First Search) עם היפוך סדר התוצאה
ARR<ARR<int>> levelOrderBottom(BT<int> root)
{
    ARR<ARR<int>> res; // מערך תוצאות - כל רמה בנפרד
    
    // מקרה קצה: עץ ריק
    if (!root.root)
        return res;
     
    // הגדרת סוג מצביע לצומת לקריאות נוחה
    using NodePtr = std::shared_ptr<typename BT<int>::Node>;
    queue<NodePtr> q; // תור BFS לעיבוד לפי רמות
    
    q.push(root.root);   // התחלה מהשורש
    q.push(nullptr);     // מפריד בין רמות - סימן לסיום רמה
   
    ARR<int> currentLevel; // רמה נוכחית בעיבוד
    
    // לולאת BFS ראשית - עיבוד כל הצמתים לפי רמות
    while(!q.empty())
    {
        NodePtr node = q.front(); q.pop(); // הוצאת הצומת הבאה מהתור
        
        if(node != nullptr) // צומת רגילה (לא מפריד)
        {
            // הוספת ערך הצומת לרמה הנוכחית
            currentLevel.elements.push_back(node->data);

            // הוספת הצאצאים לתור לעיבוד ברמה הבאה
            if(node->left)
                q.push(node->left);
            
            if(node->right)
                q.push(node->right);
        }
        else // מפריד רמות - סיימנו רמה אחת
        {
            // שמירת הרמה הנוכחית בתוצאות
            res.elements.push_back(currentLevel);
            currentLevel.elements.clear(); // איפוס לרמה הבאה
            
            // אם עוד יש צמתים בתור - הוספת מפריד חדש
            if(!q.empty())
                q.push(nullptr);
        }
    }
    
    // היפוך סדר הרמות: מעלה-למטה → מלמטה-למעלה
    reverse(res.elements.begin(), res.elements.end());
    
    return res; // החזרת התוצאה המסודרת מלמטה למעלה
}
