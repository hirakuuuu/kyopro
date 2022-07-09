#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc259/tasks/abc259_c

int main(){
    string s, t; cin >> s >> t;
    if(s.size() >  t.size()){
        cout << "No" << endl;
        return 0;
    }

    vector<tuple<char, int>> S, T;

    rep(i, 0, s.size()){
        char c = s[i];
        int j = i;
        while(i < s.size() and s[j] == s[i]) i++;
        S.push_back({s[j], i-j});
        i--;
    }

    rep(i, 0, t.size()){
        char c = t[i];
        int j = i;
        while(i < t.size() and t[j] == t[i]) i++;
        T.push_back({t[j], i-j});
        i--;
    }


    bool f = S.size()==T.size();

    rep(i, 0, S.size()){
        auto [sc, si] = S[i];
        auto [tc, ti] = T[i];

        if(si >= 2){
            if(tc != sc or si > ti) f = false;
        }else{
            if(tc != sc or si != ti) f = false;
        }
    }

    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;

    
    return 0;
}