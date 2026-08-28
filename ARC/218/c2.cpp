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

    int m = 2;
    cout << m << endl;
    rep(i, 0, n){
        if(i == 0) cout << 2 << ' ';
        else if(i == 1) cout << 1 << ' ';
        else cout << i+1 << ' ';
    }
    cout << endl;
    rep(i, 0, n){
        cout << (i-1+n)%n+1 << ' ';
    }
    cout << endl;

    vector<int> q(n);
    vector<int> rev(n);
    rep(i, 0, n){
        cin >> q[i];
        q[i]--;
        rev[q[i]] = i;
    }

    vector<int> r(n);
    iota(r.begin(), r.end(), 0);
    vector<int> a;
    while(r != q){
        if(rev[r[1]] != 0 && rev[r[0]] > rev[r[1]]){
            a.push_back(1);
            swap(r[0], r[1]);
        }else{
            a.push_back(2);
            vector<int> _r(n);
            rep(i, 0, n){
                _r[(i+1)%n] = r[i];
            }
            swap(r, _r);
        }
        //   cout << "q: ";
        // rep(i, 0, n){
        //     cout << q[i] << ' ';
        // }
        // cout << endl;      
        // cout << "r: ";
        // rep(i, 0, n){
        //     cout << r[i] << ' ';
        // }
        // cout << endl;
    }
    cout << a.size() << ' ';
    rep(i, 0, (int)a.size()){
        cout << a[i] << ' ';
    }
    cout << endl;

    return 0;
}