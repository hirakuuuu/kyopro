#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://onlinejudge.u-aizu.ac.jp/problems/1172



int main(){
    while(true){
        string s;
        getline(cin, s);
        if(s == ".") break;
        bool f = true;

        stack<char> stc;
        for(auto ss: s){
            if(ss == '(' or ss == '[') stc.push(ss);
            if(ss == ')'){
                if(stc.size() and stc.top() == '(') stc.pop();
                else f = false;
            }
            if(ss == ']'){
                if(stc.size() and stc.top() == '[') stc.pop();
                else f = false;
            }
        }

        if(f and stc.empty()) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    
    return 0;
}