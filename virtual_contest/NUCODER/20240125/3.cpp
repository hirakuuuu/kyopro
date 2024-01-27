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
// 

int main(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<int> cnt(n+1);
    set<int> notin;
    rep(i, 0, n+1) notin.insert(i);
    rep(i, 0, n){
        if(a[i] > n) continue;
        cnt[a[i]]++;
        notin.erase(a[i]);
    }

    while(q--){
        int i, x; cin >> i >> x;
        i--;
        if(a[i] <= n){
            cnt[a[i]]--;
            if(cnt[a[i]] == 0) notin.insert(a[i]);
        }
        if(x <= n){
            cnt[x]++;
            if(cnt[x] == 1) notin.erase(x);
        }
        a[i] = x;
        cout << *notin.begin() << endl;
    }
    
    return 0;
}