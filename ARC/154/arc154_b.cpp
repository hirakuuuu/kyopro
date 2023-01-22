#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/arc154/tasks/arc154_b

int main(){
    int n; cin >> n;
    string s, t; cin >> s >> t;
    if(s == t){
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> pos_s(26);
    vector<vector<int>> pos_t(26);
    rep(i, 0, n){
        pos_s[s[i]-'a'].push_back(i);
        pos_t[t[i]-'a'].push_back(i);
    }

    rep(i, 0, 26){
        if(pos_s[i].size() != pos_t[i].size()){
            cout << -1 << endl;
            return 0;
        }
    }

    vector<int> pt(26);
    rep(i, 0, 26) pt[i] = (int)pos_t[i].size()-1;
    int p = n-1;
    for(int i = n-1; i >= 0; i--){
        int j = s[i]-'a';
        while(pt[j] >= 0 and pos_t[j][pt[j]] >= p) pt[j]--;
        if(pt[j] == -1){
            cout << i+1 << endl;
            return 0;
        }
        p = pos_t[j][pt[j]];
    }
    cout << 0 << endl;

    return 0;
}