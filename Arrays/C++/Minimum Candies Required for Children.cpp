/*
 * There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
 * You are tasked with distributing candies to these children following these rules:
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * Return the minimum number of candies required to distribute among the children.
 * 
 * Example:
 * Given ratings = [1, 0, 2], the minimum number of candies required is 5 because the distribution [2, 1, 2] satisfies the conditions.
 * 
 * Constraints:
 * n == ratings.length
 * 1 <= n <= 2 * 10^4
 * 0 <= ratings[i] <= 2 * 10^4
 * 
 * Difficulty: 🔴 Hard
 * 
 * תרגום: מספר הסוכריות המינימלי הנדרש לחלוקה לילדים
 * 
 * Time Complexity: O(n) - שני מעברים על המערך
 * Space Complexity: O(n) - מערך DP לאחסון מספר הסוכריות
 */
#include "Question.hpp"
#include "Utils.hpp"
#include <vector>
using namespace std;

// פונקציה ראשית לחישוב מספר הסוכריות המינימלי הנדרש
// אלגוריתם: Two-Pass Greedy - מעבר שמאל-ימין ואז ימין-שמאל
int candies(ARR<int> ratings) 
{
    int n = ratings.elements.size();
    vector<int> dp(n, 0); // מערך לאחסון מספר הסוכריות לכל ילד
    
    // מעבר ראשון: משמאל לימין - טיפול בעליות
    dp[0] = 1; // הילד הראשון מקבל סוכריה אחת
    for(int i = 1; i < n; i++)
    {
        dp[i] = 1; // כל ילד מקבל לפחות סוכריה אחת
        if(ratings[i] > ratings[i-1]) // אם הדירוג גבוה יותר מהקודם
            dp[i] += dp[i-1]; // מקבל יותר סוכריות מהקודם
    }
    
    // מעבר שני: מימין לשמאל - טיפול בירידות ואיסוף סכום
    int min_num_candies = dp[n-1]; // התחלה עם הילד האחרון
    for(int i = n-2; i >= 0; i--)
    {
        if(ratings[i] > ratings[i+1]) // אם הדירוג גבוה יותר מהבא
            dp[i] = max(dp[i], dp[i+1] + 1); // מקבל לפחות אחד יותר מהבא
            
        min_num_candies += dp[i]; // הוספה לסכום הכולל
    }
    
    return min_num_candies;  
}