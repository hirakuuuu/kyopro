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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<int> x(n);
    vector<int> ans(n*n, -1);
    vector<pair<int, int>> p(n);
    rep(i, 0, n){
        cin >> x[i];
        x[i]--;
        p[i] = {x[i], i};
    }
    sort(p.begin(), p.end());
    rep(i, 0, n){
        auto [pos, val] = p[i];
        // [0, pos) に val が val 個, (pos, n*n-1] に n-1-val が入れるか？
        if()
    }

    vector<int> ans(n*n, -1);
    vector<int> rest(n);
    rep(i, 0, n){
        rest[i] = i;
    }

    rep(i, 0, n){
        auto [pos, val] = x[i];
        if(ans[pos] != -1){
            cout << "No" << endl;
            return 0;
        }
        ans[pos] = val;


    }
    return 0;
}