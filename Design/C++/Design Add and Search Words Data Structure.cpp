/*
 * Design a data structure that supports adding new words and finding if a string matches any previously added string.
 * Implement the WordDictionary class:
 * WordDictionary() Initializes the object.
 * void addWord(word) Adds word to the data structure, it can be matched later.
 * bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 * 
 * Example:
 * Input
 * WordDictionary wordDictionary = new WordDictionary();
 * wordDictionary.addWord("bad");
 * wordDictionary.addWord("dad");
 * wordDictionary.addWord("mad");
 * wordDictionary.search("pad");
 * wordDictionary.search("bad");
 * wordDictionary.search(".ad");
 * wordDictionary.search("b..");
 * Output
 * [null,null,null,null,false,true,true,true]
 * 
 * Constraints:
 * 1 <= word.length <= 25
 * word in addWord consists of lowercase English letters.
 * word in search consist of '.' or lowercase English letters.
 * There will be at most 2 dots in word for search queries.
 * At most 10^4 calls will be made to addWord and search.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: עיצוב מבנה נתונים להוספה וחיפוש מילים עם תמיכה בתווי כלליים
 * 
 * Time Complexity: O(m) for addWord, O(m*26^k) for search (m=word length, k=dots count)
 * Space Complexity: O(ALPHABET_SIZE * N * M) - N words, M average length
 */
#include <algorithm>
#include <unordered_map>
#include <memory>
#include <string>
using namespace std;

// מבנה עץ Trie לאחסון מילים
struct Tree
{
    struct Node 
    {
        bool isWord=false; // האם הצומת מסמן סוף מילה
        unordered_map<char, shared_ptr<Node>> children; // ילדים לפי תווים
    };
    
    shared_ptr<Node> root; // שורש העץ
};

// מחלקת WordDictionary - מילון מילים עם תמיכה בחיפוש עם תווי כלליים
// אלגוריתם: Trie + DFS עם Backtracking
class WordDictionary 
{
    private:
        Tree words; // עץ Trie לאחסון המילים
        
        // פונקציית עזר רקורסיבית לחיפוש עם תווי כלליים
        bool search(string word, int index, shared_ptr<Tree::Node> ptr)
        {
            if(index==word.length()) // הגענו לסוף המילה
                return ptr->isWord; // בדיקה אם זה סוף מילה תקפה
            
            if(word[index]=='.') // תו כללי - צריך לבדוק את כל הילדים
            {
                // DFS על כל הילדים האפשריים
                for(auto it=ptr->children.begin(); it!=ptr->children.end(); it++)
                    if(search(word, index+1, it->second)) // רקורסיה על הילד
                        return true; // מצאנו התאמה
                        
                return false; // לא מצאנו התאמה באף ילד
            }
            
            // תו רגיל - בדיקה אם הילד קיים
            if(ptr->children.find(word[index])==ptr->children.end())
                return false; // הילד לא קיים
                
            // המשך החיפוש בילד המתאים
            return search(word, index+1, ptr->children[word[index]]);
        }

    public:
        // בנאי - אתחול העץ
        WordDictionary() {
            words.root=make_shared<Tree::Node>();
        }
        
        // פונקציית addWord - הוספת מילה לעץ
        void addWord(string word)
        {
            auto ptr=words.root; // התחלה מהשורש
            
            // מעבר על כל תו במילה
            for(char c: word)
            {
                // אם הילד לא קיים - יצירתו
                if(ptr->children.find(c)==ptr->children.end())
                    ptr->children[c]=make_shared<Tree::Node>();
            
                ptr=ptr->children[c]; // מעבר לילד
            }
            
            ptr->isWord=true; // סימון סוף המילה
        }
        
        // פונקציית search - חיפוש מילה (עם תמיכה בתווי כלליים)
        bool search(string word) 
        {
            auto ptr=words.root;
            return search(word, 0, ptr); // קריאה לפונקציית העזר הרקורסיבית
        }
};