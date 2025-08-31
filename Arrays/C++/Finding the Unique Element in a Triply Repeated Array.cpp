/*
 * Problem: You are provided with an integer array nums, where every element except one appears three times. The exception is a unique element that appears exactly once. 
 * Your goal is to find and return this single unique element.
 * The approach to solve this problem must adhere to a linear runtime complexity (O(n)) and utilize only constant extra space.
 * 
 * Example 1:
 * Input: nums = [2,2,3,2]
 * Output: 3
 * Explanation: The number 2 repeats three times, whereas the number 3 appears just once, making it the unique element.
 * 
 * Example 2:
 * Input: nums = [0,1,0,1,0,1,99] 
 * Output: 99
 * Explanation: Numbers 0 and 1 repeat three times each, but 99 stands out by appearing only once.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון מערך שבו כל אלמנט מופיע 3 פעמים חוץ מאחד שמופיע פעם אחת, מצא את האלמנט הייחודי
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include "Question.hpp"
#include "Utils.hpp"

// פונקציה ראשית למציאת האלמנט הייחודי במערך שבו כל אלמנט מופיע 3 פעמים חוץ מאחד
// אלגוריתם: Bit Manipulation - מעקב אחר מספר הופעות של כל ביט
int unique_element(ARR<int> nums)
{
    int ones=0, tows=0, threes=0; // מעקב אחר ביטים שהופיעו 1, 2, 3 פעמים
    
    // מעבר על כל האלמנטים במערך
    for(auto it=nums.elements.begin(); it!=nums.elements.end(); it++)
    {
        // עדכון ביטים שהופיעו פעמיים - אם ביט הופיע פעם אחת והוא מופיע שוב
        tows |= ones & (*it);
        
        // עדכון ביטים שהופיעו פעם אחת - XOR מוסיף ביטים חדשים ומסיר קיימים
        ones ^=(*it);
        
        // זיהוי ביטים שהופיעו פעם שלישית
        threes = ones & tows;
        
        // הסרת ביטים שהופיעו 3 פעמים מהמעקב (איפוס למחזור הבא)
        ones &= ~threes;
        tows &= ~threes;
    }

    return ones; // החזרת הביטים שהופיעו פעם אחת בלבד (האלמנט הייחודי)
}