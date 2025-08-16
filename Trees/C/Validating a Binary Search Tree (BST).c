/*
 * Problem Description:
 * Given the root of a binary tree, determine if it is a valid binary search tree (BST).
 * A valid BST is defined as follows:
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 *  Example:
 *  
 *     Input: root = [2,1,3]
 *     Output: true
 *  
 *     Input: root = [5,1,4,null,null,3,6]
 *     Output: false
 *  
 * Explanation:
 * For the input root = [2,1,3], the tree is a valid BST as all left nodes are less than the root and all right nodes are greater.
 * For the input root = [5,1,4,null,null,3,6], the tree is not a valid BST as the node with value 3 is in the right subtree of node 5 but is less than 5.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: בדוק אם עץ בינארי הוא עץ חיפוש בינארי תקין
 * 
 * Time Complexity: O(n) - ביקור בכל הצמתים
 * Space Complexity: O(h) - עומק הרקורסיה
 */
#include "Question.h"
#include <limits.h>

// פונקציית עזר רקורסיבית לבדיקת תקינות BST עם גבולות
int is_valid_bst(TreeNode* t, long min, long max)
{
    if(t==NULL)
        return 1; // עץ ריק הוא BST תקין
    
    // בדיקה שהערך בטווח המותר
    if(t->data<=min || t->data>=max)
        return 0;
        
    // בדיקה רקורסיבית של תתי העצים עם גבולות מעודכנים
    return is_valid_bst(t->left, min, t->data) && is_valid_bst(t->right, t->data, max);
}

// פונקציה ראשית לבדיקת תקינות עץ חיפוש בינארי
// אלגוריתם: רקורסיה עם גבולות מינימום ומקסימום
STR  validate_bst(Tree  *  tree) 
{
    if(tree==NULL || is_valid_bst(tree->root, LONG_MIN, LONG_MAX)==0)
        return STR_Copy("false");
    return STR_Copy("true");
}
