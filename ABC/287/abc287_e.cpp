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
// https://atcoder.jp/contests/abc287/tasks/abc287_e

int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];

    bool f = true;
    rep(i, 0, n-1){
        if(s[i] != s[i+1]) f = false;
    }
    if(f){
        rep(i, 0, n) cout << s[i].size() << "\n";
        return 0;
    }

    string t[n];
    rep(i, 0, n) t[i] = s[i];
    sort(t, t+n);
    rep(i, 0, n){
        string tmp = "";
        int cnt = 0, l = 0, r = n;
        rep(j, 0, s[i].size()){
            tmp += s[i][j];
            auto itr_l = lower_bound(t+l, t+r, tmp);
            tmp[j] = tmp[j]+1;
            auto itr_r = lower_bound(t+l, t+r, tmp);
            l = itr_l-t;
            r = itr_r-t;
            if(r-l >= 2) cnt++;
            else break;
            tmp[j] = s[i][j];
        }
        cout << cnt << "\n";
    }
    
    return 0;
}