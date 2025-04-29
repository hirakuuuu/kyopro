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
    int n, r, c; cin >> n >> r >> c;
    string s; cin >> s;
    set<pair<int, int>> kemuri;
    kemuri.insert({0, 0});
    int mr = 0, mc = 0;
    string ans;
    rep(i, 0, n){
        if(s[i] == 'N'){
            mr--;
        }else if(s[i] == 'W'){
            mc--;
        }else if(s[i] == 'S'){
            mr++;
        }else{
            mc++;
        }

        if(!kemuri.count({-mr, -mc})){
            kemuri.insert({-mr, -mc});
        }
        if(kemuri.count({r-mr, c-mc})){
            ans += '1'; 
        }else{
            ans += '0';
        }
    }
    cout << ans << endl;
    
    return 0;
}