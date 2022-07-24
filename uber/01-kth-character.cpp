#include<iostream>
#include<vector>
#define ll long long
using namespace std;

char kthCharacter(string s, string t, ll k){
    // start from s; append each time : index number of time string s and t alternatively;
    int n = s.size();
    int m = t.size();
    k--;
    for(int index=1; k>=0; index++){
        if(index&1){ // odd string s
            if(index*n>k) return s[k%n];
            k-=index*n;
        }else{ // even string t
            if(index*m>k) return t[k%m];
            k-=index*m;
        }
    }
    return '\0';

}
int main(){
    string s="a";
    string t="bc";
    ll k = 1e16; // upto 10^16
    // for(int i=1;i<=k; i++)
    cout<<kthCharacter(s,t,k)<<" ";
}