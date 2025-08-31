/*
 * Problem: Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
 * We will use the integers 0, 1, and 2 to represent the colors red, white, and blue, respectively.
 * You must solve this problem without using the library's sort function.
 * 
 * Example:
 * Input: nums = [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * 
 * Input: nums = [2,0,1]
 * Output: [0,1,2]
 * 
 * Explanation:
 * For the input [2,0,2,1,1,0], the sorted array should be [0,0,1,1,2,2] with all reds (0) first, followed by whites (1), then blues (2).
 * For the input [2,0,1], the sorted array should be [0,1,2] with all reds (0) first, followed by whites (1), then blues (2).
 * 
 * Difficulty: 🟢 Easy
 * 
 * תרגום: נתון מערך עם אובייקטים צבועים באדום, לבן או כחול (0,1,2), מיין אותם במקום לפי הצבעים
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;

// פונקציה ראשית למיון מערך צבעים במקום
// אלגוריתם: Counting Sort - ספירת כל צבע ובניית המערך הממוין
ARR<int> sort_array(ARR<int> nums)
{
    // מיון מנייה - ספירת מספר הופעות של כל צבע
    vector<int> counter(3, 0); // מונה לכל צבע: [0,1,2]
    
    // ספירת כל צבע במערך
    for(auto i=0; i<nums.elements.size(); i++)
        counter[nums[i]]++;
        
    int index=0; // אינדקס למילוי המערך הממוין
    
    // מילוי המערך לפי סדר הצבעים: אדום (0), לבן (1), כחול (2)
    for(int i=0; i<counter.size(); i++)
        for(int j=0; j<counter[i]; j++)
            nums[index++]=i; // הכנסת הצבע i בכמות counter[i]
    
    return nums; // החזרת המערך הממוין
}