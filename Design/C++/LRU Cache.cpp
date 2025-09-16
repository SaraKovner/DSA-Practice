/*
 * Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
 * Implement the LRUCache class:
 * LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
 * int get(int key) Return the value of the key if the key exists, otherwise return -1.
 * void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
 * The functions get and put must each run in O(1) average time complexity.
 * 
 * Example 1:
 * Input
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1);
 * lRUCache.put(2, 2);
 * lRUCache.get(1);   
 * lRUCache.put(3, 3);
 * lRUCache.get(2);   
 * lRUCache.put(4, 4);
 * lRUCache.get(1);   
 * lRUCache.get(3);   
 * lRUCache.get(4);   
 * Output
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 * 
 * Explanation
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // cache is {1=1}
 * lRUCache.put(2, 2); // cache is {1=1, 2=2}
 * lRUCache.get(1);    // return 1
 * lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
 * lRUCache.get(2);    // returns -1 (not found)
 * lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
 * lRUCache.get(1);    // return -1 (not found)
 * lRUCache.get(3);    // return 3
 * lRUCache.get(4);    // return 4
 * 
 * Constraints:
 * 1 <= capacity <= 3000
 * 0 <= key <= 10^4
 * 0 <= value <= 10^5
 * At most 2 * 10^5 calls will be made to get and put.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: מבנה נתונים LRU Cache - מטמון עם פינוי הפריט הפחות שימושי לאחרונה
 * 
 * Time Complexity: O(1) - כל פעולה בזמן קבוע
 * Space Complexity: O(capacity) - גודל המטמון
 */
using namespace std;
#include <list>
#include <unordered_map>
#include <utility>

// מחלקת LRU Cache - מטמון עם פינוי הפריט הפחות שימושי לאחרונה
// אלגוריתם: Hash Map + Doubly Linked List
class LRUCache 
{
    private:
        unordered_map<int, list<pair<int, int>>::iterator> mp; // מיפוי key ל-iterator ברשימה
        list<pair<int, int>> value_lst; // רשימה מקושרת דו-כיוונית של זוגות (key, value)
        int capacity; // גודל המטמון
        
    public:
        // בנאי - אתחול המטמון עם גודל נתון
        LRUCache(int capacity) : capacity(capacity) {}
        
        // פונקציית get - החזרת עךר לפי key ועדכון סדר השימוש
        int get(int key) 
        {
            if(mp.find(key)!=mp.end()) // אם ה-key קיים
            {
                // העברת הפריט לראש הרשימה (הכי שימושי לאחרונה)
                value_lst.splice(value_lst.begin(), value_lst, mp[key]);
                return mp[key]->second; // החזרת הערך
            }
            return -1; // key לא נמצא
        }
        
        // פונקציית put - הוספת/עדכון פריט במטמון
        void put(int key, int value) 
        {
            if(mp.find(key)!=mp.end()) // אם ה-key כבר קיים - עדכון
            {
                mp[key]->second=value; // עדכון הערך
                value_lst.splice(value_lst.begin(), value_lst, mp[key]); // העברה לראש
                return;
            }  
            
            // אם המטמון מלא - פינוי הפריט הפחות שימושי (בסוף הרשימה)
            if(value_lst.size()==capacity)
            {
                auto last=value_lst.back(); // הפריט האחרון
                mp.erase(last.first); // הסרה מה-hash map
                value_lst.pop_back(); // הסרה מהרשימה
            }
            
            // הוספת הפריט החדש בראש הרשימה
            value_lst.push_front({key, value});
            mp[key]=value_lst.begin(); // עדכון ה-hash map
        }
};