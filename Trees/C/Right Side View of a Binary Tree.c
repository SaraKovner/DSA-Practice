/*
 * Description: Given the root of a binary tree, imagine yourself standing on the right side of it.
 * Return the values of the nodes you can see ordered from top to bottom.
 *  
 * Example 1:
 * Input: root = [1, 2, 3, null, 5, null, 4]
 * Output: [1, 3, 4]
 * Explanation: From the right side, you can see nodes 1, 3, and 4.
 *  
 * Example 2:
 * Input: root = [1, null, 3]
 * Output: [1, 3]
 *  
 * Example 3:
 * Input: root = []
 * Output: []
 *  
 * Constraints:
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון שורש של עץ בינארי, דמיין את עצמך עומד בצד הימני שלו. החזר את הערכים של הצמתים שאתה יכול לראות מלמעלה למטה
 * 
 * Time Complexity: O(n) - מעבר על כל הצמתים
 * Space Complexity: O(h) - גובה העץ (לרקורסיה)
 */
//#define ARR_DATA_TYPE int
//#define Tree_DATA_TYPE int

#include "Question.h"

// פונקציה ראשית למציאת התצוגה הימנית של עץ בינארי
// אלגוריתם פשוט ויעיל: מעבר בנתיב הימני ואוסף כל צומת
ARR  *  bt_right_view(Tree*  tree)  
{
    // בדיקת קצה - עץ ריק
    if(tree==NULL || tree->root==NULL)
        return NULL;
        
    // יצירת מערך תוצאה לפי גובה העץ
    uint64_t d[1]={tree->root->height};
    ARR* res=ARR_Create(d, 1);
    
    TreeNode* temp=tree->root;
    int index=0;
    
    // מעבר בנתיב הימני של העץ ואוסף כל צומת לתוצאה
    while(temp!=NULL)
    {
        res->data[index++]=temp->data; // הוספת הצומת לתוצאה
        temp=temp->right; // מעבר לצומת הימני הבא
    }
    
    // הקטנת המערך לגודל המתאים
    res->data=(ARR_DATA_TYPE*)realloc(res->data, index*sizeof(ARR_DATA_TYPE));
    res->total_size=index;
    res->dimensions[0]=index;
    
    return res;  
}
