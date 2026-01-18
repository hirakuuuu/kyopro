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
        ll n; cin >> n;
        vector<int> b;
        ll m = n; 
        while(m){
            b.push_back(m%2);
            m /= 2;
        }

        {
            int cnt1 = 0;
            rep(i, 0, b.size()) cnt1 += b[i];
            if(cnt1 == 1){
                cout << -1 << endl;
                continue;
            }
        }

        int cnt1 = 0;
        bool f = false;
        rep(i, 0, (int)b.size()-1){
            if(b[i] == 1 && b[i+1] == 0){
                if(cnt1){
                    rep(j, 0, i+1) b[j] = 0;
                    b[i+1] = 1;
                    f = true;
                    break;
                }
            }
            if(b[i] == 1) cnt1++;
        }

        if(!f){
            rep(i, 0, b.size()) b[i] = 0;
            b.push_back(1);
        }

        ll nn = 0;
        rrep(i, (int)b.size()-1, 0){
            nn *= 2;
            nn += b[i];
        }
        // cout << nn << endl;
        cout << nn-n << endl;


    }
    
    return 0;
}