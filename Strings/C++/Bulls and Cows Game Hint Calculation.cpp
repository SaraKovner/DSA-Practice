/*
 * Description: You are playing the Bulls and Cows game with your friend. You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following information:
 * The number of "bulls", which are digits in the guess that are in the correct position.
 * The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
 * Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.
 * The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.
 * 
 * Example 1:
 * Input: secret = "1807", guess = "7810"
 * Output: "1A3B"
 * Explanation: 1 bull (8) and 3 cows (1, 0, 7).
 * 
 * Example 2:
 * Input: secret = "1123", guess = "0111"
 * Output: "1A1B"
 * Explanation: 1 bull (1) and 1 cow (1).
 * 
 * Constraints:
 * 1 <= secret.length, guess.length <= 1000
 * secret.length == guess.length
 * secret and guess consist of digits only.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: משחק שוורים ופרות - חישוב רמז לניחוש
 * 
 * Time Complexity: O(n) - מעבר אחד על המחרוזות
 * Space Complexity: O(1) - מערך קבוע של 10 ספרות
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;
#include<vector>

// פונקציה ראשית לחישוב רמז במשחק שוורים ופרות
// אלגוריתם: ספירת תווים עם מערך counter
string game_hint(string secret, string guess)
{
    int bulls=0; // ספירת שוורים - ספרות במקום הנכון
    int cows=0;  // ספירת פרות - ספרות קיימות במקום הלא נכון
    vector<int> counter(10, 0); // מערך לספירת כל ספרה (0-9)
    
    // מעבר ראשון: ספירת שוורים ובניית counter של הסוד
    for(int i=0; i<secret.length(); i++)
        if(secret[i]==guess[i])
            bulls++; // ספרה במקום הנכון
        else
            counter[secret[i]-'0']++; // ספירת ספרות הסוד שאינן שוורים
    
    // מעבר שני: ספירת פרות מתוך הניחוש
    for(int i=0; i<guess.length(); i++)
        if(secret[i]!=guess[i] && counter[guess[i]-'0']>0) // רק אם לא שור וקיים בסוד
        {
            cows++; // מצאנו פרה
            counter[guess[i]-'0']--; // הקטנת המונה
        }
    
    // החזרת התוצאה בפורמט "xAyB"
    return to_string(bulls)+"A"+to_string(cows)+"B";
}
