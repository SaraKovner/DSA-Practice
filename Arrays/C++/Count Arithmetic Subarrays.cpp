/*
 * Problem: An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
 * For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
 * Given an integer array nums, return the number of arithmetic subarrays of nums.
 * A subarray is a contiguous subsequence of the array.
 * 
 * Example 1:
 * Input: nums = [1,2,3,4]
 * Output: 3
 * Explanation: The arithmetic subarrays are [1,2,3], [2,3,4] and [1,2,3,4] itself.
 * 
 * Example 2:
 * Input: nums = [1,3,5,7,9]
 * Output: 6
 * Explanation: The arithmetic subarrays are [1,3,5], [3,5,7], [5,7,9], [1,3,5,7], [3,5,7,9] and [1,3,5,7,9] itself.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון מערך מספרים, מצא את מספר תת-המערכים האריתמטיים (שההפרש בין איברים עוקבים קבוע)
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include "Question.hpp"
#include "Utils.hpp"

// פונקציה ראשית לספירת תת-מערכים אריתמטיים
// אלגוריתם: מעבר יחיד על המערך עם מעקב אחר אורך הרצף האריתמטי הנוכחי
int count_subarrays(ARR<int> nums)
{
    int n=nums.elements.size();
    if(n<3)
        return 0; // צריכים לפחות 3 אלמנטים לרצף אריתמטי
        
    int dif=nums[1]-nums[0], length=2, count_sub=0; // הפרש, אורך רצף נוכחי, מספר תת-מערכים
    
    // מעבר על המערך החל מהאלמנט השלישי
    for(int i=2; i<n; i++)
    {
        if(nums[i]-nums[i-1]!=dif)
        {
            // הפרש השתנה - התחלת רצף חדש
            length=2;
            dif=nums[i]-nums[i-1];
            continue;
        }
        
        // הפרש נשאר זהה - הארכת הרצף
        length++;
        if(length>=3)
            // כל הארכה ברצף מוסיפה (length-2) תת-מערכים חדשים
            count_sub+=(length-2);
    }
            
    return count_sub; // החזרת מספר תת-המערכים האריתמטיים
}