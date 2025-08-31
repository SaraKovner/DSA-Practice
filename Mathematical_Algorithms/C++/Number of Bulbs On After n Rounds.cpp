/*
 * Problem: There are n bulbs that are initially off. You first turn on all the bulbs, then you turn off every second bulb.
 * On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the i-th round, you toggle every i bulb. For the n-th round, you only toggle the last bulb.
 * Return the number of bulbs that are on after n rounds.
 * 
 * Example 1:
 * Input: n = 3
 * Output: 1
 * Explanation:
 * Round 1: All bulbs are turned on -> [on, on, on]
 * Round 2: Every second bulb is turned off -> [on, off, on]
 * Round 3: Every third bulb is toggled -> [on, off, off]
 * So you should return 1 because there is only one bulb that is on.
 * 
 * Example 2:
 * Input: n = 0
 * Output: 0
 * Explanation: There are no bulbs to toggle.
 * 
 * Example 3:
 * Input: n = 1
 * Output: 1
 * Explanation: There is only one bulb and it will be toggled on.
 * 
 * Constraints:
 * 0 <= n <= 10^9
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתונות n נורות כבויות בהתחלה, בכל סיבוב i מחליפים מצב של כל נורה i-ית, מצא כמה נורות דלוקות בסוף
 * 
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;
#include <cmath>

// פונקציה ראשית לחישוב מספר הנורות הדלוקות אחרי n סיבובים
// אלגוריתם: תובנה מתמטית - רק נורות במיקומים של ריבועים מושלמים יישארו דלוקות
int bulb_switcher(int n) 
{
    // תובנה: נורה במיקום i תוחלף מצב בכל סיבוב j כאשר i מתחלק ב-j
    // נורה תישאר דלוקה רק אם יש לה מספר אי-זוגי של מחלקים
    // זה קורה רק כאשר i הוא ריבוע מושלם (כי אז יש לו מחלק שהוא השורש שלו)
    return (int)sqrt(n); // מספר הריבועים המושלמים עד n
    
    // הפתרון הנאיבי (בערה)
    // vector<bool> bulds(n, true);    // סיבוב ראשון - הנורות נדלקות
    
    // // מתחילים מהסיבוב השני של הדילוגים
    // for(int i=2; i<=n; i++)
    //     for(int j=i-1; j<n; j+=i)   // החלפת מצב כל נורה i-ית
    //         bulds[j]=!bulds[j];

    // int count=0;
    // for(int i=0; i<n; i++)
    //     if(bulds[i])
    //         count++;
            
    // return count;  
}