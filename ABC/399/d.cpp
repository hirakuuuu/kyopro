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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(2*n);
        rep(i, 0, 2*n) cin >> a[i], a[i]--;
        vector<vector<int>> pos(n);
        rep(i, 0, 2*n){
            pos[a[i]].push_back(i);
        }

        set<pair<int, int>> s;
        rep(i, 0, 2*n-1){
            if(a[i] == a[i+1]) continue;
            int l1 = pos[a[i]][0], r1 = pos[a[i]][1];
            int l2 = pos[a[i+1]][0], r2 = pos[a[i+1]][1];
            if(abs(l1-l2) == 1 && abs(r1-r2) == 1 && abs(l1-r1) > 1 && abs(l2-r2) > 1){
                s.insert({min(a[i], a[i+1]), max(a[i], a[i+1])});
            }
        }
        cout << s.size() << endl;
    }
    
    return 0;
}