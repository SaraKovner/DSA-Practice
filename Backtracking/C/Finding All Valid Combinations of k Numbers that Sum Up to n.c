/*
 * Description: Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
 * Only numbers 1 through 9 are used.
 * Each number is used at most once.
 * Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
 *  
 * Example 1:
 * Input: k = 3, n = 7
 * Output: [[1, 2, 4]]
 * Explanation: The only combination is [1, 2, 4].
 *  
 * Example 2:
 * Input: k = 3, n = 9
 * Output: [[1, 2, 6], [1, 3, 5], [2, 3, 4]]
 * Explanation: The combinations are [1, 2, 6], [1, 3, 5], and [2, 3, 4].
 *  
 * Example 3:
 * Input: k = 4, n = 1
 * Output: []
 * Explanation: There are no valid combinations.
 *  
 * Constraints:
 * 2 <= k <= 9
 * 1 <= n <= 60
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: מצא את כל הצירופים התקינים של k מספרים (1-9) שסכומם n
 * 
 * Time Complexity: O(2^9) - כל הצירופים האפשריים
 * Space Complexity: O(k) - עומק הרקורסיה
 */
#include "Question.h"

void rec(int k, int n, int number, ARR* res, int * arr, int index)
{
    if(k==index)
    {
        if(n==0)
        {
            //הכנסה לARR
            res->data=realloc(res->data, sizeof(int)*(res->total_size+k));
            memcpy(res->data+res->total_size, arr, k*sizeof(int));
            res->total_size+=k;
            res->dimensions[0]++;
        }
        return;
    }
    if(number>9)
        return;
    
    arr[index]=number;
    rec(k, n-number, number+1, res, arr, index+1); // צירוף המספר ומעבר לבא
    rec(k, n, number+1, res, arr, index); // לא לכלול את המספר הנוכחי
}

// פונקציה ראשית למציאת כל הצירופים התקינים של k מספרים שסכומם n
ARR  *  valid_combination(int  k, int  n) 
{
    // יצירת מערך תוצאה דו-מימדי: שורות של k אלמנטים
    uint64_t d[2]={0, k}; // 0 שורות בהתחלה, k עמודות
    ARR* res=ARR_Create(d, 2);
    
    // מערך עזר לשמירת צירוף נוכחי
    int* arr=malloc(k*sizeof(int));

    // התחלת החיפוש הרקורסיבי מהמספר 1
    rec(k, n, 1, res, arr, 0);

    // שחרור זיכרון
    free(arr);

    return res;
}
