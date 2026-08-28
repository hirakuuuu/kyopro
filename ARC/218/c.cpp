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

    int m = n-1;
    cout << m << endl;
    rep(i, 0, m){
        vector<int> p(n);
        iota(p.begin(), p.end(), 1);
        swap(p[i], p[i+1]);
        rep(j, 0, n){
            cout << p[j] << ' ';
        }
        cout << endl;
    }

    vector<int> q(n);
    rep(i, 0, n){
        cin >> q[i];
        q[i]--;
    }

    vector<int> r(n);
    vector<int> rev(n);
    iota(r.begin(), r.end(), 0);
    iota(rev.begin(), rev.end(), 0);
    vector<int> a;
    rep(i, 0, n){
        int pos = rev[q[i]];
        while(pos > i){
            a.push_back(pos);
            swap(r[pos], r[pos-1]);
            swap(rev[r[pos]], rev[r[pos-1]]);
            pos--;
        }
    }
    cout << a.size() << ' ';
    rep(i, 0, (int)a.size()){
        cout << a[i] << ' ';
    }
    cout << endl;

    return 0;
}