/*
 * Problem Description:
 * Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.
 * A concatenated word is defined as a string that is comprised entirely of at least two shorter words (not necessarily distinct) in the given array.
 * 
 * Example 1:
 *     Input: words = ["cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"]
 *     Output: ["catsdogcats", "dogcatsdog", "ratcatdogcat"]
 *     Explanation: "catsdogcats", "dogcatsdog", and "ratcatdogcat" are concatenated by "cats", "dog", "rat".
 * 
 * Example 2:
 *     Input: words = ["cat", "dog", "catdog"]
 *     Output: ["catdog"]
 *     Explanation: "catdog" is concatenated by "cat" and "dog".
 * 
 * Constraints:
 *     1 ≤ words.length ≤ 10^4
 *     1 ≤ words[i].length ≤ 30
 *     words[i] consists of only lowercase English letters.
 *     All the strings of words are unique.
 *     1 ≤ sum(words[i].length) ≤ 10^5
 * 
 * Difficulty: 🔴 Hard
 * 
 * תרגום: מציאת מילים מחוברות - מילים שמורכבות מחיבור של לפחות שתי מילים קצרות יותר
 * 
 * Time Complexity: O(n * m^3) - n מילים, m אורך ממוצע של מילה
 * Space Complexity: O(n * m) - memoization של תוצאות ביניים
 */

#include "Question.hpp"
#include "Utils.hpp"
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// פונקציה עזר לבדיקה אם מילה יכולה להיות מורכבת ממילים אחרות
// אלגוריתם: רקורסיה עם memoization למניעת חישובים כפולים
bool canForm(string word, unordered_set<string>& wordSet, unordered_map<string, bool>& memo) 
{
    if (memo.count(word)) return memo[word]; // אם כבר חישבנו - החזר תוצאה שמורה
    
    // נסה כל חלוקה אפשרית ל-prefix ו-suffix
    for (int i = 1; i < word.length(); i++) 
    {
        string prefix = word.substr(0, i);
        string suffix = word.substr(i);
        
        // אם ה-prefix קיים ברשימה
        if (wordSet.count(prefix)) 
            // וגם ה-suffix קיים או יכול להיות מורכב
            if (wordSet.count(suffix) || canForm(suffix, wordSet, memo)) 
            {
                memo[word] = true;
                return true;
            }
    }
    memo[word] = false;
    return false;
}

// פונקציה ראשית למציאת כל המילים המחוברות
// אלגוריתם: בדיקה לכל מילה אם היא יכולה להיות מורכבת
ARR<string> concatenated_words(ARR<string> words) 
{
    unordered_set<string> wordSet(words.elements.begin(), words.elements.end()); // הכנסת כל המילים ל-HashSet
    ARR<string> res;
    unordered_map<string, bool> memo; 
    
    // עבור כל מילה, בדוק אם היא מחוברת
    for(auto& word : words.elements)
    {
        if (canForm(word, wordSet, memo))
            res.elements.push_back(word);
    }

    return res;  
}