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
// https://atcoder.jp/contests/abc330/tasks/abc330_e

int main(){
    int n, q; cin >> n >> q;
    vector<int> cnt(n+1);
    vector<int> a(n);
    rep(i, 0, n){
        cin >> a[i];
        if(a[i] <= n) cnt[a[i]]++;
    }

    set<int> s;
    rep(i, 0, n+1){
        if(cnt[i] == 0) s.insert(i);
    }

    while(q--){
        int t, x; cin >> t >> x;
        t--;
        if(a[t] <= n) cnt[a[t]]--;
        if(x <= n) cnt[x]++;
        if(a[t] <= n && cnt[a[t]] == 0) s.insert(a[t]);
        if(x <= n && cnt[x] == 1 && s.find(x) != s.end()) s.erase(s.find(x));
        a[t] = x;
        cout << *s.begin() << '\n';
    }
    
    return 0;
}