/*
 * Given an unsorted integer array nums, return the smallest positive integer that is not present in nums.
 * You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
 * 
 * Example 1:
 *     Input: nums = [1,2,0]
 *     Output: 3
 * 
 * Example 2:
 *     Input: nums = [3,4,-1,1]
 *     Output: 2
 * 
 * Example 3:
 *     Input: nums = [7,8,9,11,12]
 *     Output: 1
 * 
 * Difficulty: 🔴 Hard
 * 
 * תרגום: מציאת המספר החיובי הקטן ביותר החסר במערך לא ממוין
 * 
 * Time Complexity: O(n) - שלושה מעברים על המערך
 * Space Complexity: O(1) - שימוש במערך הקיים כמבנה עזר
 */
#include "Question.hpp"
#include "Utils.hpp"

// פונקציה ראשית למציאת המספר החיובי הקטן ביותר החסר
// אלגוריתם: Array as Hash Table - שימוש בסימנים שליליים כמדדים
int first_missing_positive(ARR<int> nums) 
{
    int len=nums.elements.size();
    
    // שלב 1: ניקוי המערך - החלפת ערכים לא רלוונטיים
    // הערך המינימלי החיובי חייב להיות בין 1 לאורך המערך+1
    for(int i=0; i<len; i++)
        if(nums[i]<=0 || nums[i]>len) // ערכים שליליים, אפס, או גדולים מהאורך
            nums[i]=len+1; // החלפה בערך שלא יפריע (מחוץ לטווח)
            
    // שלב 2: סימון נוכחות - שימוש בסימנים שליליים
    // נסמן את כל המיקומים שהאינדקסים שלהם קיימים במערך
    for(int i=0; i<len; i++)
    {
        int num=abs(nums[i]); // הערך המקורי (ללא הסימן)
        if(num<=len) // אם הערך בטווח הרלוונטי
            nums[num-1]=-abs(nums[num-1]); // סימון המיקום כשלילי
    }
    
    // שלב 3: מציאת הראשון החסר
    // האינדקס הראשון שלא מסומן (חיובי) הוא המינימום החיובי שלא קיים
    for(int i=0; i<len; i++)
        if(nums[i]>0) // אם המיקום לא מסומן
            return i+1; // המספר החסר (אינדקס+1)
            
    // אם כל המספרים 1 עד len קיימים, התשובה היא len+1
    return len+1;
}