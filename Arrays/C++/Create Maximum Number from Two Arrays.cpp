/*
 * Description:
 * You are given two integer arrays nums1 and nums2 of lengths m and n respectively.
 * The arrays represent the digits of two numbers. You are also given an integer k.
 * Your task is to create the maximum number of length k <= m + n from the digits of the two numbers.
 * The relative order of the digits from the same array must be preserved.
 * Return an array of the k digits representing the answer.
 * 
 * Example:
 * Given nums1 = [3, 4, 6, 5], nums2 = [9, 1, 2, 5, 8, 3], and k = 5, the maximum number is [9, 8, 6, 5, 3].
 * 
 * Constraints:
 * m == nums1.length
 * n == nums2.length
 * 1 <= m, n <= 500
 * 0 <= nums1[i], nums2[i] <= 9
 * 1 <= k <= m + n
 * 
 * Difficulty: 🔴 Hard
 * 
 * תרגום: יצירת המספר המקסימלי מאיחוד שני מערכים
 * 
 * Time Complexity: O(k * (m + n)^3) - לולאה על k אפשרויות, כל אחת עם עיבוד של O((m+n)^3)
 * Space Complexity: O(k) - אחסון התוצאות הזמניות
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;

// פונקציית עזר להשוואה לקסיקוגרפית בין שני מערכים
// מחזירה true אם nums1[i:] גדול מ-nums2[j:]
bool is_greater(const vector<int>& nums1, int i, const vector<int>& nums2, int j)
{
    // השוואה לקסיקוגרפית: מי גדול יותר כמספר
    int n = nums1.size(), m = nums2.size();
    
    // דילוג על ספרות זהות
    while(i < n && j < m && nums1[i] == nums2[j])
    {
        i++;
        j++;
    }
    
    // החזרת התוצאה: nums1 גדול אם nums2 נגמר או nums1[i] > nums2[j]
    return j == m || (i < n && nums1[i] > nums2[j]);
}

// פונקציה ליצירת תת-רצף מקסימלי בגודל k מתוך מערך נתון
// אלגוריתם: Monotonic Stack - שמירה על רצף יורד
vector<int> max_subsequence(const vector<int>& nums, int k)
{
    vector<int> stack; // מחסנית לבניית הרצף המקסימלי
    int drop = nums.size() - k; // מספר הספרות שצריך להשמיט
    
    for(int num : nums)
    {
        // הסרת ספרות קטנות יותר כדי לפנות מקום לספרה גדולה יותר
        // כל עוד יש מה להשמיט והספרה הנוכחית גדולה יותר מהאחרונה במחסנית
        while(!stack.empty() && drop > 0 && stack.back() < num)
        {
            stack.pop_back(); // הסרת הספרה הקטנה
            drop--; // עדכון מונה ההשמטות
        }
        stack.push_back(num); // הוספת הספרה הנוכחית
    }
    
    // חיתוך לגודל הרצוי (במקרה שלא השמטנו מספיק)
    stack.resize(k);
    return stack;
}

// פונקציה למיזוג שני מערכים למערך אחד מקסימלי
// אלגוריתם: Merge עם השוואה לקסיקוגרפית
vector<int> merge(const vector<int>& nums1, const vector<int>& nums2)
{
    vector<int> res; // התוצאה הממוזגת
    int i = 0, j = 0; // מצביעים על המערכים
    
    // מיזוג עם בחירת הספרה הטובה ביותר בכל שלב
    while(i < nums1.size() || j < nums2.size())
    {
        // בחירה בין שני המערכים לפי השוואה לקסיקוגרפית
        if(is_greater(nums1, i, nums2, j))
            res.push_back(nums1[i++]); // nums1 גדול יותר
        else
            res.push_back(nums2[j++]); // nums2 גדול יותר או שווה
    }
    
    return res;
}

// פונקציה ראשית ליצירת המספר המקסימלי מאיחוד שני מערכים
// אלגוריתם: חלוקה לכל האפשרויות + Greedy Selection
ARR<int> max_number(ARR<int> nums1, ARR<int> nums2, int k) 
{
    ARR<int> best; // התוצאה הטובה ביותר
    int n = nums1.elements.size();
    int m = nums2.elements.size();
    
    // בדיקת כל החלוקות האפשריות של k בין שני המערכים
    // i = מספר הספרות שניקח מ-nums1, k-i = מספר הספרות מ-nums2
    for(int i = max(0, k-m); i <= min(k, n); i++)
    {
        // יצירת תת-רצפים מקסימליים מכל מערך
        vector<int> part1 = max_subsequence(nums1.elements, i);     // i ספרות מ-nums1
        vector<int> part2 = max_subsequence(nums2.elements, k-i);   // k-i ספרות מ-nums2
        vector<int> candidate = merge(part1, part2);                // מיזוג לתוצאה
        
        // שמירת האפשרות הטובה ביותר
        if(is_greater(candidate, 0, best.elements, 0))
            best.elements = candidate;
    }
    
    return best;
}
