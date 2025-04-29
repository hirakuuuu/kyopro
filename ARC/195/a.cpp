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
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];

    vector<int> l, r;
    int p = 0;
    rep(i, 0, n){
        if(p == m) break;
        if(a[i] == b[p]){
            l.push_back(i);
            p++;
        }
    }
    if(l.size() != m){
        cout << "No" << endl;
        return 0;
    }

    p = m-1;
    rrep(i, n-1, 0){
        if(p == -1) break;
        if(a[i] == b[p]){
            r.push_back(i);
            p--;
        }
    }
    reverse(r.begin(), r.end());

    if(l == r){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    
    return 0;
}