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
    string s, t; cin >> s >> t;
    int n = (int)s.size();
    
    int pos_s = 0;
    int pos_t = 0;
    while(pos_s < n){
        if(t[pos_t] == s[pos_s]){
            cout << pos_t+1 << ' ';
            pos_t++;
            pos_s++;
        }else{
            pos_t++;
        }
    }
    cout << endl;
    return 0;
}