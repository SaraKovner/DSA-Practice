/*
 * Description: The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.
 * 
 * Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.
 * 
 * Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input:
 * 
 *     3
 *    / \
 *   2   3
 *    \   \
 *     3   1
 * 
 * Output: 7
 * Explanation: The thief can rob house 3 (root), then house 3 (left subtree), and then house 1 (right subtree).
 *  
 * 
 * Example 2:
 * 
 * Input:
 * 
 *     3
 *    / \
 *   4   5
 *  / \   \
 * 1   3   1
 * 
 * Output: 9
 * Explanation: The thief can rob house 4 (left subtree) and house 5 (right subtree), and then house 3 (right subtree).
 *  
 * 
 * Constraints:
 * 
 * The number of nodes in the binary tree is in the range [1, 10^4].
 * 0 <= Node.val <= 10^4
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: מצא את כמות הכסף המקסימלית שגנב יכול לגנוב מעץ בינארי ללא להפעיל אזעקה
 * 
 * Time Complexity: O(n) - ביקור בכל צומת פעם אחת
 * Space Complexity: O(h) - עומק הרקורסיה
 */
#include "Question.h"
#define MAX(a,b)(a>b ? a : b)

// מבנה לשמירת שני מצבים: לגנוב או לא לגנוב מצומת נוכחית
typedef struct
{
    int rob;    // הערך של אם שדדנו את הצומת הנוכחי
    int skip; // הערך הגבוה במקרה שלא שדדנו את הצומת הנוכחי
}Pair;

// פונקציית עזר רקורסיבית לחישוב מקסימום כסף שניתן לגנוב
// אלגוריתם: Dynamic Programming עם שני מצבים - לגנוב או לא לגנוב
Pair rec(TreeNode* t)
{
    if(t==NULL)
        return (Pair){0,0}; // עץ ריק - אין כסף לגנוב
    
    // שמירת האפשרויות עבור הילדים - חישוב רקורסיבי
    Pair left=rec(t->left);
    Pair right=rec(t->right);
    
    // בדיקה מה הסכום אם ניקח את הצומת הנוכחית (לא נוכל לקחת את הילדים)
    int rob=t->data+left.skip+right.skip;
     
    // ובמקרה שלא נבחר בצומת הנוכחית - נוכל לבחור את האופציה הטובה ביותר מכל ילד
    int skip=MAX(left.rob, left.skip)+MAX(right.rob, right.skip);
    
    return (Pair){rob, skip};    
}

// פונקציה ראשית לחישוב מקסימום כסף שגנב יכול לגנוב מעץ בינארי
// אלגוריתם: Dynamic Programming - בחירה אופטימלית בכל צומת
int  max_robbed_money(Tree  *  tree)  {
    if(tree==NULL)
        return 0;
    Pair res=rec(tree->root);
    return  MAX(res.rob, res.skip); // בחירת המקסימום בין שני המצבים
}
