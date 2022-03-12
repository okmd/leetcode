// this can be implemented using doubly linked 
// NOTE: head maintains the most recenlty used item.
// 1. if exits [atleast one node is present]
//      - remove from cache, insert at head and overwrite the map.
// 2. not exits
//      2.1 if full -> remove tail from list and mapping. insert at head and maintain mapping
//      2.2 if not full -> insert at head and add mapping

#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
    // doubly linked list and element can be removed from anywhere
    list<pair<int, int>> cache;
    // to store is key present in cache or not
    // if present to remove it from DLL cache as finding element will be O(N)
    // to reduce searching time map is used
    unordered_map<int, list<pair<int, int>>::iterator> ma;
    int csize;  // maximum capacity of cache

   public:
    LRUCache(int);
    void set(int, int);
    int get(int);
    void show();
};

// Declare the size
LRUCache::LRUCache(int n) {
    csize = n;
}

// Refers key x with in the LRU cache
void LRUCache::set(int key, int value) {
    // if not present in cache then
    // remove fast one(LRU) from list
    // and insert at the front
    // as front element is always the MRU so update mapping with begining element
    if (ma.find(key) == ma.end()) {
        // cache is full
        if (cache.size() == csize) {
            // delete least recently used element i.e last one
            pair<int, int> last = cache.back();
            // Pops the last element
            cache.pop_back();
            // Erase the last from mapping also
            ma.erase(last.first);
        }
    } else {
        // present in cache
        // and remove from the cache
        cache.erase(ma[key]);
    }

    // insert at the head
    cache.push_front({key, value});
    // as newly inserted element is at head then store its address in mapping.
    // if already present then override
    ma[key] = cache.begin();
}

int LRUCache::get(int key) {
    if (ma.find(key) != ma.end()) {
        list<pair<int, int>>::iterator ref = ma[key];
        int value = ref->second;
        cache.erase(ref); // NOTE: after erasing the value from cache iterator becomes invalid.
        cache.push_front({key, value});
        ma[key] = cache.begin(); // update the map as new element is created
        return value;
    }
    return -1;
}

// Function to display contents of cache
void LRUCache::show() {
    // Iterate in the deque and print
    // all the elements in it
    for (auto ele : cache)
        cout << ele.first << " - " << ele.second << " ";
    cout << endl;
}

int main() {
    LRUCache r(2);
    r.set(1,1);
    r.set(2, 2);
    cout << r.get(1)<<endl;
    r.set(3,3);
    cout << r.get(2)<<endl;
    r.show();
    r.set(4,4);
    cout << r.get(1)<<endl;
    cout << r.get(3)<<endl;
    cout << r.get(4)<<endl;
    r.show();
    return 0;
}