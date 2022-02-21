// Given Starting Health and Armor
// You have three option to go
// find maximum life span
// Air -> Health+3, Armor+3
// Water -> Health-5, Armor-10
// Fire -> Health-20, Armor+5

// when Health or Armor <= 0 then DIE

// memoization to find max
#include <iostream>
using namespace std;

int max_life_span(int health, int armor, int prev_call) {
    if (armor <= 0 or health <= 0) return 0;
    int air = 0, water = 0, fire = 0;  // 1, 2, 3
    if (prev_call != 1) air = max_life_span(health + 3, armor + 2, 1);
    if (prev_call != 2) water = max_life_span(health - 5, armor - 10, 2);
    if (prev_call != 3) fire = max_life_span(health - 20, armor + 5, 3);
    return max(max(air, water), fire) + 1;
}

int main() {
    int max_life = INT_MIN;
    int health = 20, armor = 8;
    max_life = max(max_life, max_life_span(health + 3, armor + 2, 1));
    max_life = max(max_life, max_life_span(health - 5, armor - 10, 2));
    max_life = max(max_life, max_life_span(health - 20, armor + 5, 3));
    cout << max_life << endl;
    return 0;
}