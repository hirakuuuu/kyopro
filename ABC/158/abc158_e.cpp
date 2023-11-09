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
// https://atcoder.jp/contests/abc158/tasks/abc158_e

int main(){
    int n, p; cin >> n >> p;
    string s; cin >> s;
    ll ans = 0;
    if(p == 2){
        rep(i, 0, n){
            if((s[i]-'0')%2 == 0) ans += i+1;
        }
    }else if(p == 5){
        rep(i, 0, n){
            if((s[i]-'0')%5 == 0) ans += i+1;
        }
    }else{
        reverse(s.begin(), s.end());
        vector<ll> cnt(p);
        cnt[0] = 1;
        ll sum = 0, base = 1;
        rep(i, 0, n){
            sum = (sum+(s[i]-'0')*base)%p;
            ans += cnt[sum];
            cnt[sum]++;
            base = (base*10)%p;
        }
    }
    cout << ans << endl;
    return 0;
}