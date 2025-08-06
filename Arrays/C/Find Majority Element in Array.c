/*
 * Problem: Given an array nums of size n, return the majority element.
 * The majority element is the element that appears more than ⌊n / 2⌋ times.
 * You may assume that the majority element always exists in the array.
 * 
 * Difficulty: 🟢 Easy
 * 
 * תרגום: נתון מערך nums בגודל n, החזר את האלמנט הרוב
 * 
 * Example 1:
 * Input: nums = [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * Input: nums = [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n) - בשימוש בטבלת גיבוב
 */
// #define ARR_DATA_TYPE int
#include "Question.h"

// פונקציית גיבוב פשוטה - מחזירה מודולו כפול
uint64_t hash_func(HT_KEY_DATA_TYPE key, uint64_t size)
{
    return (key%size)%size;
}

// פונקציה למציאת אלמנט הרוב במערך
// אלמנט רוב = מופיע יותר מ-n/2 פעמים
int  find_majority(ARR  *  nums) 
{
    // בדיקת קצה - מערך ריק
    if(nums==NULL || nums->total_size==0)
        return 0;
        
    // יצירת טבלת גיבוב לספירת התרחשויות
    HT* hash=HT_Create(nums->total_size*2, hash_func);
    int max=1, keyMax=nums->data[0]; // מעקב אחר המקסימום הנוכחי
    HT_Insert(hash, nums->data[0], 1); // הכנסת האלמנט הראשון
    int val;
    
    // מעבר על שאר האלמנטים
    for(int i=1; i<nums->total_size; i++)
    {
        val=HT_Search(hash, nums->data[i]); // חיפוש האלמנט בטבלה
        
        // לוגיקה מתוקנת:
        if(val == 0) // אם האלמנט לא נמצא - התחלה מ-1
        {
            HT_Insert(hash, nums->data[i], 1);
        }
        else // אם האלמנט נמצא - הגדלת הספירה
        {
            HT_Insert(hash, nums->data[i], val+1);
            if(max < val+1)
            {
                max = val+1;
                keyMax = nums->data[i];
            }
        }
    }
    
    return keyMax;  
}
