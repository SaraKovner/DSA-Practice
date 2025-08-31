/*
 * Problem: You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
 * Return true if you can reach the last index, or false otherwise.
 * 
 * Example:
 * Input: nums = [2, 3, 1, 1, 4]
 * Output: true
 * 
 * Input: nums = [3, 2, 1, 0, 4]
 * Output: false
 * 
 * Explanation:
 * For the input [2, 3, 1, 1, 4], you can jump from index 0 to index 1 (jump length 2), then from index 1 to index 4 (jump length 3), thus reaching the last index.
 * For the input [3, 2, 1, 0, 4], you can jump from index 0 to index 1 (jump length 3), then from index 1 to index 2 (jump length 2), then from index 2 to index 3 (jump length 1), but you cannot move beyond index 3 because nums[3] is 0.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון מערך מספרים, כל מספר מייצג את אורך הקפיצה המקסימלי מהמיקום הזה, בדוק אם ניתן להגיע לאינדקס האחרון
 * 
 * Time Complexity: O(n²)
 * Space Complexity: O(n)
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;

// פונקציה ראשית לבדיקה אם ניתן להגיע לאינדקס האחרון במערך
// אלגוריתם: Dynamic Programming - מעקב אחר כל המיקומים הניתנים להגעה
string jump_game(ARR<int> nums) 
{
    int n=nums.elements.size();
    vector<bool> dp(n); // מערך לסימון מיקומים שניתן להגיע אליהם
    
    dp[0]=true; // תמיד מתחילים במיקום 0
    
    // מעבר על כל המיקומים במערך
    for(int i=0; i<n; i++)
    {
        if(!dp[i])
            continue; // אם לא הגענו למיקום הזה, לא יכולים לקפוץ ממנו
        
        // סימון כל המיקומים שניתן להגיע אליהם מהמיקום הנוכחי
        for(int j=1; j<=nums[i] && j<n; j++)
            dp[j+i]=true;
            
        // הדפסת מצב הטבלה (לדיבוג)
        for(int j=0; j<n; j++)
            cout<<dp[j]<<", ";
        cout<<endl;
    }
    
    return dp[n-1] ? string("true") : string("false"); // בדיקה אם הגענו לאינדקס האחרון
}