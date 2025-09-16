/*
 * The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
 * By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.
 * 
 * Example 1:
 *     Input: n = 3, k = 3
 *     Output: "213"
 * 
 * Example 2:
 *     Input: n = 4, k = 9
 *     Output: "2314"
 * 
 * Example 3:
 *     Input: n = 3, k = 1
 *     Output: "123"
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: מציאת הפרמוטציה ה-k ברשימה המסודרת
 * 
 * Time Complexity: O(n²) - לולאת n עם erase של O(n)
 * Space Complexity: O(n) - מערכי עזר לפקטוריאל ואפשרויות
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;
#include<vector>

// פונקציית עזר לחישוב פקטוריאלים
void factorial(int n, vector<int>& fact)
{
    fact[0]=1;
    for(int i=1; i<=n; i++)
        fact[i]=fact[i-1]*i; // fact[i] = i!
}

// פונקציה ראשית למציאת הפרמוטציה ה-k ברשימה המסודרת
// אלגוריתם: Factorial Number System - חישוב מתמטי
string find_kth(int n, int k) 
{
    k--; // המרה לאינדקס 0-based
    vector<int> option(n); // רשימת המספרים הזמינים
    
    // אתחול רשימת האפשרויות [1,2,3,...,n]
    for(int i=0; i<n; i++)
        option[i]=i+1;
    
    vector<int> fact(n+1);
    factorial(n, fact); // חישוב כל הפקטוריאלים
    string res="";
    
    // בניית הפרמוטציה ספרה אחר ספרה
    for(int i=1; i<=n; i++)
    {
        int index=k/fact[n-i]; // אינדקס הספרה הנוכחית
        res+=to_string(option[index]); // הוספת הספרה לתוצאה
        option.erase(option.begin()+index); // הסרת הספרה מהאפשרויות
        k%=fact[n-i]; // עדכון k לספרה הבאה
    }
    
    return res;  
}