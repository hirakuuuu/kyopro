#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<vector<int>> a(n);
    rep(i, 0, n){
        int k; cin >> k;
        rep(j, 0, k){
            int b; cin >> b; 
            a[b-1].push_back(i);
        }
    }
    rep(i, 0, n){
        sort(a[i].begin(), a[i].end());
        cout << a[i].size() << ' ';
        rep(j, 0, a[i].size()){
            cout << a[i][j]+1 << ' ';
        }
        cout << endl;
    }
    
    return 0;
}