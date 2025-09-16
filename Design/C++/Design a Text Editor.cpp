/*
 * Design a text editor with a cursor that can do the following:
 * Add text to where the cursor is.
 * Delete text from where the cursor is (simulating the backspace key).
 * Move the cursor either left or right.
 * When deleting text, only characters to the left of the cursor will be deleted. The cursor will also remain within the actual text and cannot be moved beyond it. More formally, we have that 0 <= cursor.position <= currentText.length always holds.
 * Implement the TextEditor class:
 * TextEditor() Initializes the object with empty text.
 * void addText(string text) Appends text to where the cursor is. The cursor ends to the right of text.
 * int deleteText(int k) Deletes k characters to the left of the cursor. Returns the number of characters actually deleted.
 * string cursorLeft(int k) Moves the cursor to the left k times. Returns the last min(10, len) characters to the left of the cursor, where len is the number of characters to the left of the cursor.
 * string cursorRight(int k) Moves the cursor to the right k times. Returns the last min(10, len) characters to the left of the cursor, where len is the number of characters to the left of the cursor.
 * 
 * Example 1:
 * Input
 * TextEditor textEditor = new TextEditor();
 * textEditor.addText("meetnice");
 * textEditor.deleteText(4);
 * textEditor.addText("practice");
 * textEditor.cursorRight(3); 
 * textEditor.cursorLeft(8);
 * textEditor.deleteText(10);
 * textEditor.cursorLeft(2);
 * textEditor.cursorRight(6); 
 * Output
 * [null, null, 4, null, "etpractice", "meet", 4, "", "practi"]
 * 
 * Explanation
 * TextEditor textEditor = new TextEditor(); // The current text is "|". (The '|' character represents the cursor)
 * textEditor.addText("meetnice"); // The current text is "meetnice|".
 * textEditor.deleteText(4); // return 4
 *                           // The current text is "meet|". 
 *                           // 4 characters were deleted.
 * textEditor.addText("practice"); // The current text is "meetpractice|". 
 * textEditor.cursorRight(3); // return "etpractice"
 *                            // The current text is "meetpractice|". 
 *                            // The cursor cannot be moved beyond the actual text and thus did not move.
 *                            // "etpractice" is the last 10 characters to the left of the cursor.
 * textEditor.cursorLeft(8); // return "meet"
 *                           // The current text is "meet|practice".
 *                           // "meet" is the last min(10, 4) = 4 characters to the left of the cursor.
 * textEditor.deleteText(10); // return 4
 *                            // The current text is "|practice".
 *                            // Only 4 characters were deleted.
 * textEditor.cursorLeft(2); // return ""
 *                           // The current text is "|practice".
 *                           // The cursor cannot be moved beyond the actual text and thus did not move. 
 *                           // "" is the last min(10, 0) = 0 characters to the left of the cursor.
 * textEditor.cursorRight(6); // return "practi"
 *                            // The current text is "practi|ce".
 *                            // "practi" is the last min(10, 6) = 6 characters to the left of the cursor.
 * 
 * Constraints:
 * 1 <= text.length, k <= 40
 * text consists of lowercase English letters.
 * At most 2 * 10^4 calls in total will be made to addText, deleteText, cursorLeft and cursorRight.
 * 
 * Follow-up: Could you find a solution with time complexity of O(k) per call?
 * 
 * Difficulty: 🔴 Hard
 * 
 * תרגום: עיצוב עורך טקסט עם סמן - תמיכה בהוספה, מחיקה ותנועה
 * 
 * Time Complexity: O(k) per operation - k = מספר התווים/תנועות
 * Space Complexity: O(n) - n = סה"כ תווים בטקסט
 */
using namespace std;
#include <stack>
#include <string>
#include <algorithm>

// מחלקת TextEditor - עורך טקסט עם סמן
// אלגוריתם: Two Stacks - מחסנית שמאל ומחסנית ימין לסמן
class TextEditor 
{
    private:
        stack<char> left;  // מחסנית לתווים משמאל לסמן
        stack<char> right; // מחסנית לתווים מימין לסמן
        
        // פונקציית עזר להחזרת עד 10 תווים אחרונים מהמחסנית השמאלית
        string getLast10(stack<char>& s)
        {
            int count = 0;
            string result = "";
            
            // שליפת עד 10 תווים מהמחסנית
            while(!s.empty() && count < 10)
            {
                result += s.top();
                s.pop();
                count++;
            }
            
            // החזרת התווים למחסנית (בסדר הפוך)
            for(count--; count >= 0; count--)
                s.push(result[count]);
                
            // הפיכת המחרוזת לסדר הנכון
            reverse(result.begin(), result.end());
            return result;
        }
        
    public:
        // בנאי - אתחול עורך טקסט ריק
        TextEditor()
        {
            // אתחול ריק - שתי המחסניות ריקות
        }
        
        // פונקציית addText - הוספת טקסט במיקום הסמן
        void addText(string text)
        {
            // הוספת כל תו למחסנית השמאלית (הסמן נשאר בסוף)
            for(char ch : text)
                left.push(ch);
        }
        
        // פונקציית deleteText - מחיקת k תווים משמאל לסמן
        int deleteText(int k)
        {
            int i = 0;
            // מחיקת תווים עד שנגמרו או שהמחסנית ריקה
            for(i = 0; i < k && !left.empty(); left.pop(), i++);
            return i; // החזרת מספר התווים שנמחקו בפועל
        }
        
        // פונקציית cursorLeft - הזזת הסמן שמאלה k פעמים
        string cursorLeft(int k)
        {
            char ch;
            // העברת תווים מהמחסנית השמאלית לימנית
            while(k > 0 && !left.empty())
            {
                ch = left.top();
                left.pop();
                right.push(ch);
                k--;
            }
            
            // החזרת עד 10 תווים אחרונים משמאל לסמן
            return getLast10(left);
        }
        
        // פונקציית cursorRight - הזזת הסמן ימינה k פעמים
        string cursorRight(int k)
        {
            char ch;
            // העברת תווים מהמחסנית הימנית לשמאלית
            while(k > 0 && !right.empty())
            {
                ch = right.top();
                right.pop();
                left.push(ch);
                k--;
            }
            
            // החזרת עד 10 תווים אחרונים משמאל לסמן
            return getLast10(left);
        }
};