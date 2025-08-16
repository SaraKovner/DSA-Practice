/*
 * You are a product manager and currently leading a team to develop a new product.
 * Unfortunately, the latest version of your product fails the quality check.
 * Since each version is developed based on the previous version, all the versions after a bad version are also bad.
 * Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
 * You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
 *  
 * Example 1:
 *     Input: n = 5, bad = 4
 *     Output: 4
 *  
 * Example 2:
 *     Input: n = 1, bad = 1
 *     Output: 1
 * 
 * Difficulty: 🟢 Easy
 * 
 * תרגום: מצא את הגרסה הרעה הראשונה במוצר
 * 
 * Time Complexity: O(log n) - Binary Search
 * Space Complexity: O(1)
 */
#include "Question.h"

// פונקציה ראשית למציאת הגרסה הרעה הראשונה
// אלגוריתם: Binary Search למינימום קריאות ל-API
int  bad_version(int  n) 
{
    int low=1, hi=n, mid;
    
    // חיפוש בינארי למציאת הגרסה הרעה הראשונה
    while(low<=hi)
    {
        mid=(low+hi)/2;
        if(isBadVersion(mid)==0)
            low=mid+1;  // גרסה טובה - חפש בחצי הימני
        else
        {
            // אם לשמאלו הגרסה טובה זה אומר שזו הגרסה הגרועה הראשונה
            if(mid==0 || isBadVersion(mid-1)==0)
                return mid;
            hi=mid-1;   // גרסה רעה - חפש בחצי השמאלי
        }
    }
    return low;  
}
