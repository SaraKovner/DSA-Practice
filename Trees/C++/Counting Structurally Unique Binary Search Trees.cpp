/*
 * Problem: Given an integer n, return the number of structurally unique BSTs (binary search trees) that have exactly n nodes with unique values from 1 to n.
 * 
 * Example:
 * Input: n = 3
 * Output: 5
 * 
 * Input: n = 1
 * Output: 1
 * 
 * Explanation:
 * For the input n = 3, there are 5 structurally unique BSTs that can be formed using nodes with values from 1 to 3.
 * For the input n = 1, there is 1 structurally unique BST that can be formed using a single node.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון מספר n, מצא כמה עצי BST שונים מבחינה מבנית ניתן לבנות עם n צמתים בעלי ערכים ייחודיים מ-1 עד n
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;

// פונקציה עזר לחישוב עצרת (factorial)
long long factorial(int n)
{
    long long f=1;
    while(n>1)
    {
        f*=n;
        n--;
    }
    return f;
}

// פונקציה ראשית לספירת מספר עצי BST ייחודיים מבחינה מבנית
// אלגוריתם: נוסחת קטלן - Catalan Number Formula
int count_unique_bst(int n) 
{
    if(n==0)
        return 1; // עץ ריק הוא BST יחיד
        
    // שימוש בנוסחת מספר קטלן: C(n) = (2n)! / ((n+1)! * n!)
    long long f_n=factorial(n);     // n!
    long long f_2n=factorial(2*n);  // (2n)!
    
    // חישוב לפי נוסחת קטלן:
    // C(n) = (2n choose n) - (2n choose n-1)
    // = (2n)!/(n!*n!) - (2n)!/((n+1)!*(n-1)!)
    int res=f_2n/(f_n*f_n)-f_2n/(f_n*(n+1)*(f_n/n)); // חלוקה ב-n להגעה לעצרת של (n-1)
    
    return res; // החזרת מספר העצים הייחודיים
}