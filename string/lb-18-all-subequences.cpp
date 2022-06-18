#include<iostream>
using namespace std;
// Method: Include or Exclude, Backtracing
void subsequence(string s, int i, string &temp){
    if(i==s.size()){
        cout<<"["<<temp<<"]";
        return;
    }
    // include
    temp.push_back(s[i]);
    subsequence(s, i+1, temp);
    // exclude
    temp.pop_back();
    subsequence(s, i+1, temp);
}
int main(){
    string s, temp;
    cin>>s;
    subsequence(s, 0, temp);
    return 0;
}