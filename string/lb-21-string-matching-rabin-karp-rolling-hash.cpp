// given a text and a pattern
// find pat in text
// use hashing function: take base as number of unique char.
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int power(int base, int times, int prime) {
    int ans = 1;
    for (int i = 0; i < times; i++) {
        ans = (ans * base) % prime;
    }
    return ans;
    // return pow(base, times); // not working 26^1 = 25;
}
int stringHash(string text, int base, int prime) {
    int hash_code = 0;
    int n = text.size();
    for (int i = 0; i < n; i++) {
        int char_code = text[n - i - 1] - 'a' + 1;
        hash_code = (hash_code + (char_code * power(base, i, prime)) % prime) % prime;
    }
    return hash_code;
}
bool compare(string text, string pat, int i) {
    for (int j = i; j < pat.size() + i; j++) {
        if (text[j] != pat[j - i]) {
            return false;
        }
    }
    return true;
}
void match(string text, string pat, vector<int>& ans) {
    // return index of pat in text if exists else -1;
    // find hash of pat;
    // find rolling hash of window size of pat in text;
    // if match then compare actual string;
    int prime = 101;
    int base = 26; // unique chars in text.
    int text_size = text.size();
    int pat_size = pat.size();
    // hashcode of pat and first window of text
    int pat_hash_code = stringHash(pat, base, prime);
    int window_hash_code = stringHash(text.substr(0, pat_size), base, prime);
    for (int i = pat_size; i < text_size; i++) {
        // cout<<text.substr(i - pat_size, pat_size)<<" "<<window_hash_code<<" "<<pat_hash_code<<"\n";
        if (pat_hash_code == window_hash_code) {
            int index = i - pat_size;
            if (compare(text, pat, index)) {
                ans.push_back(index + 1);
            } //return index;
        }
        // if pat not matched or code not matched then roll
        int out_char_code = text[i - pat_size] - 'a' + 1;
        int in_char_code = text[i] - 'a' + 1;

        window_hash_code -= (out_char_code * power(base, pat_size - 1, prime)) % prime;
        window_hash_code = ((window_hash_code * base) % prime + in_char_code) % prime;
        if (window_hash_code < 0)
            window_hash_code = window_hash_code + prime;
        // window_hash_code = (base * (window_hash_code + in_char_code) % prime) % prime;

    }
    // check last window
    if (pat_hash_code == window_hash_code) {
        int index = text_size - pat_size;
        if (compare(text, pat, index)) {
            ans.push_back(index + 1);
        } //return index;
    }
}
vector <int> search(string pat, string txt) {
    vector <int> ans;
    if (txt.size() < pat.size()) return { -1 };
    match(txt, pat, ans); // TLE
    if (!ans.size()) return { -1 };
    return ans;

}
int main() {

    string str = "AABAACBAA";
    string pat = "BAA";
    vector <int> ans = search(pat, str);
    for (auto x : ans) {
        cout << x << " ";
    }
    return 0;
}


// GFG
int power(int base, int times, int prime) {
    int ans = 1;
    for (int i = 0; i < times; i++) {
        ans = (ans * base) % prime;
    }
    return ans;
    // return pow(base, times); // not working 26^1 = 25;
}
bool compare(string text, string pat, int i) {
    for (int j = i; j < pat.size() + i; j++) {
        if (text[j] != pat[j - i]) {
            return false;
        }
    }
    return true;
}

vector <int> search(string pat, string text) {
    vector <int> ans;
    int prime = 101;
    int base = 26;
    int text_size = text.size();
    int pat_size = pat.size();
    int text_hash = 0;
    int pat_hash = 0;
    int to_be_removed_power = power(base, pat_size - 1, prime);
    // every multiplication increases the base;
    for (int i = 0; i < pat_size; i++) {
        pat_hash = (pat_hash * base + pat[i]) % prime;
        text_hash = (text_hash * base + text[i]) % prime;
    }
    for (int i = 0; i <= text_size - pat_size; i++) {
        if (pat_hash == text_hash) {
            if (compare(text, pat, i)) {
                ans.push_back(i + 1);
            }
        }
        else if (i < text_size - pat_size) {
            text_hash = ((text_hash - text[i] * to_be_removed_power) * base + text[i + pat_size]) % prime;
            if (text_hash < 0) text_hash += prime;

        }
    }
    if (!ans.size()) return { -1 };
    return ans;

}