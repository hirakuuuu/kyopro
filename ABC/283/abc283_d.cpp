#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc283/tasks/abc283_d

int main(){
    string s; cin >> s;

    vector<int> flag(26);
    rep(i, 0, s.size()){
        if(s[i] == ')'){
            rep(j, 0, 26) flag[j] = 0;
        }else if(s[i] != '('){
            if(flag[s[i]-'a']){
                cout << "No" << endl;
                return 0;
            }
            flag[s[i]-'a']++;
        }
    }

    cout << "Yes" << endl;
    
    return 0;
}