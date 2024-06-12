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
    int n, t; cin >> n >> t;
    vector<int> a(t);
    rep(i, 0, t){
        cin >> a[i];
        a[i]--;
    }
    vector<int> r(n), c(n), naname(2);
    rep(i, 0, t){
        r[a[i]/n]++;
        if(r[a[i]/n] == n){
            cout << i+1 << endl;
            return 0;
        }
        c[a[i]%n]++;
        if(c[a[i]%n] == n){
            cout << i+1 << endl;
            return 0;
        }
        if((a[i]/n) == (a[i]%n)) naname[0]++;
        if(naname[0] == n){
            cout << i+1 << endl;
            return 0;
        }
        if((a[i]/n) == n-1-(a[i]%n)) naname[1]++;
        if(naname[1] == n){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}