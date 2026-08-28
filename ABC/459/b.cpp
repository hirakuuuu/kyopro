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
    string ans;
    rep(i, 0, n){
        string s; cin >> s;
        if(inr('a', s[0], 'd')){
            cout << 2;
        }else if(inr('d', s[0], 'g')){
            cout << 3;
        }else if(inr('g', s[0], 'j')){
            cout << 4;
        }else if(inr('j', s[0], 'm')){
            cout << 5;
        }else if(inr('m', s[0], 'p')){
            cout << 6;
        }else if(inr('p', s[0], 't')){
            cout << 7;
        }else if(inr('t', s[0], 'w')){
            cout << 8;
        }else{
            cout << 9;
        }
    }
    cout << endl;
    return 0;
}