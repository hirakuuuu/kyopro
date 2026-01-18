#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}



int main(){
    int n, m; cin >> n >> m;

    vector<int> a(m);
    rep(i, 0, m) cin >> a[i], a[i]--;

    vector<int> end(n);
    iota(end.begin(), end.end(), 0);
    rep(i, 0, m){
        swap(end[a[i]], end[a[i]+1]);
    }

    vector<int> rev(n);
    rep(i, 0, n){
        rev[end[i]] = i;
        // cout << end[i] << ' ';
    }
    // cout << endl;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    // vector<int> s(m);
    rep(i, 0, m){
        if(p[a[i]] == 0){
            cout << rev[p[a[i]+1]]+1 << endl;
        }else if(p[a[i]+1] == 0){
            cout << rev[p[a[i]]]+1 << endl;
        }else{
            cout << rev[0]+1 << endl;
        }
        swap(p[a[i]], p[a[i]+1]);
    }
    return 0;
}