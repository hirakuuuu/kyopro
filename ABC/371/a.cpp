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
    char sab, sac, sbc; cin >> sab >> sac >> sbc;
    if(sab == '<'){
        // a < b
        if(sbc == '<'){
            // a < b < c;
            cout << 'B' << endl;
        }else{
            // a < b && c < b;
            if(sac == '<'){
                // a < c < b
                cout << 'C' << endl;
            }else{
                // c < a < b
                cout << 'A' << endl;
            }
        }
    }else{
        // b < a
        if(sbc == '>'){
            // c < b < a;
            cout << 'B' << endl;
        }else{
            // b < a && b < c;
            if(sac == '>'){
                // b < c < a
                cout << 'C' << endl;
            }else{
                // b < a < c
                cout << 'A' << endl;
            }
        }
    }
    return 0;
}