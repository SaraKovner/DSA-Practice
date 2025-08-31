/*
 * Problem: An n-bit Gray code sequence is a sequence of 2^n integers where:
 * Every integer is in the inclusive range [0, 2^n - 1],
 * The first integer is 0,
 * An integer appears no more than once in the sequence,
 * The binary representation of every pair of adjacent integers differs by exactly one bit, and
 * The binary representation of the first and last integers differs by exactly one bit.
 * 
 * Given an integer n, return any valid n-bit Gray code sequence.
 * 
 * Example:
 * Input: n = 2
 * Output: [0, 1, 3, 2]
 * 
 * Input: n = 3
 * Output: [0, 1, 3, 2, 6, 7, 5, 4]
 * 
 * Explanation:
 * For the input n = 2, a valid 2-bit Gray code sequence is [0, 1, 3, 2].
 * For the input n = 3, a valid 3-bit Gray code sequence is [0, 1, 3, 2, 6, 7, 5, 4].
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון מספר n, צור רצף קוד גריי של n ביטים שבו כל שני מספרים סמוכים שונים בדיוק בביט אחד
 * 
 * Time Complexity: O(2^n)
 * Space Complexity: O(2^n)
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;
#include <unordered_set>

// פונקציה ראשית ליצירת רצף קוד גריי של n ביטים
// אלגוריתם: נוסחת קוד גריי - G(i) = i XOR (i >> 1)
ARR<int> gray_code(int n)
{
    ARR<int> res; // מערך התוצאות

    int len=1<<n; // 2^n - מספר האלמנטים ברצף
    
    // יצירת כל האלמנטים ברצף קוד גריי
    for(int i=0; i<len; i++)
        // נוסחת קוד גריי: G(i) = i XOR (i shifted right by 1)
        res.elements.push_back(i ^ (i>>1));
    
    return res; // החזרת רצף קוד גריי המלא
}