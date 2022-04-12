#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc122/tasks/abc122_d

bool content(string s){
    if(s.substr(0, 3) == "AGC") return true;
    if(s.substr(1, 3) == "AGC") return true;
    return false;
}

string f(string s, char c){
    string t = s+c;
    if(content(t)) return "";
    rep(i, 0, 3){
        string tes = t;
        swap(tes[i], tes[i+1]);
        if(content(tes)) return "";
    }

    return t.substr(1);
}

int main(){
    int n; cin >> n;
    map<string, ll> dp;
    dp["###"] = 1;
    string S = "AGCT";

    rep(i, 0, n){
        map<string, ll> pd;
        for(auto itr = dp.begin(); itr != dp.end(); ++itr){
            rep(j, 0, 4){
                string res = f(itr->first, S[j]);
                if(res != ""){
                    pd[res] += itr->second;
                    pd[res] %= MOD;
                }
            }
        }
        swap(dp, pd);
    }

    ll ans = 0;

    for(auto itr = dp.begin(); itr != dp.end(); ++itr){
        ans += itr->second;
        ans %= MOD;
    }

    cout << ans << endl;    
    return 0;
}