/*
 * You are given an array of integers nums representing the numbers written on a chalkboard.
 * Alice and Bob take turns erasing exactly one number from the chalkboard, with Alice starting first.
 * If erasing a number causes the bitwise XOR of all the remaining elements on the chalkboard to become 0, then that player loses.
 * The bitwise XOR of one element is that element itself, and the bitwise XOR of no elements is 0.
 * Additionally, if any player starts their turn with the bitwise XOR of all the elements on the chalkboard equal to 0, then that player wins.
 * Return true if and only if Alice wins the game, assuming both players play optimally.
 * 
 * Example:
 * Given nums = [1, 1, 2]
 * output = false
 * Explanation: 
 * Alice has two choices: erase 1 or erase 2. 
 * If she erases 1, the nums array becomes [1, 2]. 
 * The bitwise XOR of all the elements of the chalkboard is 1 XOR 2 = 3. 
 * Now Bob can remove any element he wants, 
 * because Alice will be the one to erase the last element and she will lose. 
 * If Alice erases 2 first, now nums become [1, 1]. 
 * The bitwise XOR of all the elements of the chalkboard is 1 XOR 1 = 0. 
 * Alice will lose.
 * 
 * Constraints:
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] < 2^16
 * 
 * Difficulty: 🔴 Hard
 * 
 * תרגום: משחק XOR על לוח - אליס נגד בוב
 * 
 * Time Complexity: O(n) - מעבר אחד לחישוב XOR
 * Space Complexity: O(1) - משתנים קבועים בלבד
 */
#include "Question.hpp"
#include "Utils.hpp"

// פונקציה ראשית לקביעה האם אליס מנצחת במשחק XOR
// אלגוריתם: Game Theory + Mathematical Analysis
std::string alice_game(ARR<int> nums) 
{
    // כלל 1: אם אליס מתחילה עם XOR = 0, היא מנצחת מיד
    int total_xor = 0;
    for(int i = 0; i < nums.elements.size(); i++)
        total_xor ^= nums[i];
    
    if(total_xor == 0)
        return "true"; // אליס מנצחת מיד
    
    // כלל 2: אם המערך זוגי, אליס תמיד מנצחת
    // הסיבה: אליס יכולה לשמור על מצב שהיא תמיד לא תוציא מספר שיגרום ל-XOR = 0
    // במערך זוגי, אליס יכולה להבטיח שבוב יישאר עם מספר אי-זוגי של אלמנטים
    if(nums.elements.size() % 2 == 0)
        return "true";
    
    // כלל 3: אם המערך אי-זוגי ו-XOR != 0, אליס מפסידה
    // במקרה זה, בוב יכול לכפות על אליס להגיע למצב מפסיד
    return "false";  
}