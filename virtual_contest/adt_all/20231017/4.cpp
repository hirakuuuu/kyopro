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
    set<pair<int, int>> s;
    rep(i, 0, m){
        int k; cin >> k;
        vector<int> x(k);
        rep(j, 0, k) cin >> x[j];
        rep(j, 0, k){
            rep(l, j+1, k){
                int mn = x[j], mx = x[l];
                if(mn > mx) swap(mn, mx);
                s.insert({mn, mx});
            }
        }
    }
    if(s.size() == n*(n-1)/2) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}