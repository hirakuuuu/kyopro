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
        rep(i, 0, n) cin >> a[i];
        sort(a.rbegin(), a.rend());

        bool f = true;
        if(a.back() == 0){
            f = true;
            ll now = 0;
            while(!a.empty()){
                a.pop_back();
                if(a.empty()){
                    break;
                }
                if(a.back()-now == 0){
                    break;
                }

                if(a.back()-now > 1){
                    f = false;
                    break;
                }else{
                    now++;
                }
            }
        }else{
            f = false;
            ll now = 0;
            while(!a.empty()){
                if(a.back()-now > 1){
                    f = true;
                    break;
                }else{
                    now++;
                    a.pop_back();
                    if(a.empty()){
                        break;
                    }
                    if(a.back()-now == 0){
                        break;
                    }
                }
            }
        }

        if(f) cout << "Alice" << endl;
        else cout << "Bob" << endl;

    }
    
    return 0;
}