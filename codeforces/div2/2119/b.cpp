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
        vector<ll> p(2), q(2);
        rep(i, 0, 2) cin >> p[i];
        rep(i, 0, 2) cin >> q[i];
        ll d = (p[0]-q[0])*(p[0]-q[0])+(p[1]-q[1])*(p[1]-q[1]);

        ll tot = 0;
        vector<ll> a(n);
        rep(i, 0, n){
            cin >> a[i];
            tot += a[i];
        }
        if(n == 1){
            if(a[0]*a[0] == d){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }else{
            int id = -1;
            rep(i, 0, n){
                if(tot < 2*a[i]) id = i;
            }
            if(id == -1){
                if(tot*tot >= d){
                    cout << "Yes" << endl;
                }else{
                    cout << "No" << endl;
                }
            }else{
                // a[id], d, tot-a[id];
                if(a[id]*a[id] > d){
                    if(d >= (2*a[id]-tot)*(2*a[id]-tot)){
                        cout << "Yes" << endl;
                    }else{
                        cout << "No" << endl;
                    }
                }else{
                    if(tot*tot >= d){
                        cout << "Yes" << endl;
                    }else{
                        cout << "No" << endl;
                    }
                }
            }
        }

    }
    
    return 0;
}