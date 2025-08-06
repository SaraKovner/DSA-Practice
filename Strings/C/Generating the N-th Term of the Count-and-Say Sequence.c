/*
 * Problem: The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
 * countAndSay(1) = "1"
 * countAndSay(n) is the run-length encoding of countAndSay(n - 1).
 * Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251", we replace "33" with "23", replace "222" with "32", replace "5" with "15", and replace "1" with "11". Thus, the compressed string becomes "23321511".
 * Given a positive integer n, return the n-th element of the count-and-say sequence.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: רצף "Count-and-Say" - נתון מספר חיובי n, החזר את האיבר ה-n ברצף
 * 
 * Example:
 * Input: n = 4
 * Output: "1211"
 * 
 * Explanation:
 * countAndSay(1) is "1".
 * countAndSay(2) is the run-length encoding of "1", which is "11".
 * countAndSay(3) is the run-length encoding of "11", which is "21".
 * countAndSay(4) is the run-length encoding of "21", which is "1211".
 * 
 * Time Complexity: O(n * m) where m is the length of the string
 * Space Complexity: O(m)
 */
#include "Question.h"

STR count_and_say(STR s1)
{
    int amount=0, i, j=0, count=1;
    
    //ספירת מספר הרצפים
    for(i=0; i<s1.n; i++)
        if(s1.s[i]!=s1.s[i+1])
            amount++;
    
    STR str=STR_Create(amount*2);
    
    for(i=0; i<s1.n; i++)
    {
        if(s1.s[i]!=s1.s[i+1])
        {
            str.s[j]=count+'0';
            str.s[j+1]=s1.s[i];
            count=1;
            j+=2;
        }
        else
            count++;
    }
    
    return str;
}
STR generate_the_n_term(int  n)  
{
    if(n==1 || n==0)
    {
        STR s=STR_Create(n);
        if(n==1)
            s.s[0]='1';
            
        return s;
    }
    
    STR s=generate_the_n_term(n-1);
    
    return count_and_say(s);  
}


