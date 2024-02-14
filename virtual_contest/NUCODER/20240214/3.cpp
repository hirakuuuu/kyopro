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
    int n, m; cin >> n >> m;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    set<int> notin;
    vector<int> cnt(1500005);
    rep(i, 0, m){
        cnt[a[i]]++;
    }
    rep(i, 0, 1500005){
        if(cnt[i] == 0) notin.insert(i);
    }
    int ans = *notin.begin();
    rep(i, m, n){
        cnt[a[i-m]]--;
        if(cnt[a[i-m]] == 0) notin.insert(a[i-m]);
        if(cnt[a[i]] == 0) notin.erase(a[i]);
        cnt[a[i]]++;
        chmin(ans, *notin.begin());
    }
    cout << ans << endl;
    
    return 0;
}