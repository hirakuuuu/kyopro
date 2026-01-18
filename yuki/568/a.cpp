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
        vector<ll> a(n);
        vector<ll> p, m;
        int cnt_zero = 0;
        rep(i, 0, n){
            cin >> a[i];
            if(a[i] > 0){
                p.push_back(a[i]);
            }else if(a[i] < 0){
                m.push_back(a[i]);
            }else{
                cnt_zero++;
            }
        }
        sort(p.begin(), p.end());
        sort(m.begin(), m.end());
        if(cnt_zero){
            cout << 0 << endl;
        }else if(m.empty()){
            cout << p[0]*p.back() << endl;
        }else if(p.empty()){
            cout << m[0]*m.back() << endl;
        }else{
            cout << p[0]*m.back() << endl;
        }
    }
    return 0;
}