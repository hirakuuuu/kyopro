#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc164/tasks/abc164_d

int main(){
    string s; cin >> s;
    int n = s.size();
    vector<ll> cnt(2019);
    cnt[0] = 1;
    ll ans = 0;
    rep(i, 0, n){
        int tmp = 2019-(s[i]-'0');

        vector<ll> cnt_(2019);
        rep(j, 0, 2019){
            cnt_[(j*10)%2019] += cnt[j];
        }

        ans += cnt_[tmp];
        vector<ll> cnt__(2019);
        rep(j, 0, 2019){
            cnt__[(j+(s[i]-'0'))%2019] += cnt_[j];
        }
        cnt__[0]++; 

        cnt = cnt__;

    }
    cout << ans << endl;
    
    return 0;
}