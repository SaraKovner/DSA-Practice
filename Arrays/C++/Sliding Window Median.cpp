/*
 * Problem Description:
 * The median is the middle value in an ordered integer list.
 * If the size of the list is even, there is no middle value. So the median is the mean of the two middle values.
 * You are given an integer array nums and an integer k.
 * There is a sliding window of size k which is moving from the very left of the array to the very right.
 * Return the median array for each window in the original array.
 * 
 * Example 1:
 *     Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
 *     Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
 * 
 * Example 2:
 *     Input: nums = [1,2,3,4,2,3,1,4,2], k = 4
 *     Output: [2.50000,2.50000,3.00000,2.50000,2.50000,2.50000]
 * 
 * Difficulty: 🔴 Hard
 * 
 * תרגום: מדיאן בחלון נע - חישוב מדיאן לכל חלון בגודל k שנע על המערך
 * 
 * Time Complexity: O(n log k) - n אלמנטים, כל פעולה על ה-BST לוקחת O(log k)
 * Space Complexity: O(k) - שמירת k אלמנטים ב-ordered set
 */

#include "Question.hpp"
#include "Utils.hpp"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#include <utility>

// הגדרת ordered set - BST מאוזן עם יכולת גישה לפי אינדקס
using ordered_set = tree<
    pair<int,int>,           // שמירת (ערך, אינדקס) לטיפול בערכים זהים
    null_type,
    less<pair<int,int>>,     // מיון עולה
    rb_tree_tag,
    tree_order_statistics_node_update  // מאפשר find_by_order
>;

// פונקציה ראשית לחישוב מדיאן בחלון נע
// אלגוריתם: שימוש ב-ordered set לשמירת אלמנטים ממוינים עם גישה מהירה למדיאן
ARR<double> sliding_window_median(ARR<int> nums, int k) 
{
    ARR<double> res;
    ordered_set avl;
    
    // איניציאליזציה של החלון הראשון
    for(int i = 0; i < k; i++)
        avl.insert({nums[i], i}); // הכנסת (ערך, אינדקס)
    
    // חישוב מדיאן ראשון
    double med = avl.find_by_order(k/2)->first; // אלמנט אמצעי (או עליון אם k זוגי)
    if(k % 2 == 0) { // אם k זוגי - ממוצע של שני האמצעיים
        med += avl.find_by_order(k/2 - 1)->first; 
        med /= 2;
    }
    res.elements.push_back(med);
    
    // העברת החלון וחישוב מדיאן לכל מיקום
    for(int i = k; i < nums.elements.size(); i++)
    {
        avl.erase({nums[i - k], i - k});  // הסרת האלמנט השמאלי ביותר
        avl.insert({nums[i], i});         // הוספת האלמנט החדש
        
        // חישוב מדיאן חדש
        med = avl.find_by_order(k/2)->first;
        if(k % 2 == 0) {
            med += avl.find_by_order(k/2 - 1)->first;
            med /= 2;
        }
        res.elements.push_back(med);
    }
    
    return res; 
}