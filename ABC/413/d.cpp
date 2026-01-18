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
        rep(i, 0, n){
            cin >> a[i];
            if(a[i] > 0) p.push_back(a[i]);
            else m.push_back(a[i]); 
        }
        sort(p.begin(), p.end());
        sort(m.rbegin(), m.rend());
        bool ok = false;
        {
            vector<ll> b;
            int sp = p.size(), sm = m.size();
            int ip = 0, im = 0;
            while(ip < sp || im < sm){
                if(ip == sp){
                    b.push_back(m[im++]);
                }else if(im == sm){
                    b.push_back(p[ip++]);
                }else{
                    if(b.empty() || b.back() < 0) b.push_back(p[ip++]);
                    else b.push_back(m[im++]);
                }
            }
            // rep(i, 0, n){
            //     cout << b[i] << ' ';
            // }
            // cout << endl;
            auto check = [&](vector<ll> c) -> bool {
                rep(i, 2, n){
                    if(c[1]*c[i-1] != c[0]*c[i]) return false;
                }
                return true;
            };
            ok |= check(b);
        }
        {
            vector<ll> b;
            int sp = p.size(), sm = m.size();
            int ip = 0, im = 0;
            while(ip < sp || im < sm){
                if(ip == sp){
                    b.push_back(m[im++]);
                }else if(im == sm){
                    b.push_back(p[ip++]);
                }else{
                    if(b.empty() || b.back() > 0) b.push_back(m[im++]);
                    else b.push_back(p[ip++]);
                }
            }
            // rep(i, 0, n){
            //     cout << b[i] << ' ';
            // }
            // cout << endl;
            auto check = [&](vector<ll> c) -> bool {
                rep(i, 2, n){
                    if(c[1]*c[i-1] != c[0]*c[i]) return false;
                }
                return true;
            };
            ok |= check(b);
        }

        if(ok) cout << "Yes" << endl;
        else cout << "No" << endl;


    }
    
    return 0;
}