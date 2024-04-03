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
    int n, k; cin >> n >> k;
    vector<int> p(n);
    rep(i, 0, n){
        rep(j, 0, 3){
            int q; cin >> q;
            p[i] += q;
        }
    }
    vector<int> q = p;
    sort(q.begin(), q.end());
    rep(i, 0, n){
        int pos = q.end()-upper_bound(q.begin(), q.end(), p[i]+300);
        if(pos <= k-1) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    
    
    return 0;
}