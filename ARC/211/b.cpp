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
    int x, y, z; cin >> x >> y >> z;
    vector<string> s(3);
    if(x == y && y == z){
        rep(i, 0, 3) s[i] = string(x, '0');
    }else if(x == y && x < z){
        s[0] = string(x, '0');
        s[1] = s[2] = string(z, '0');
    }else if(x == z && x < y){
        s[1] = string(x, '0');
        s[0] = s[2] = string(y, '0');
    }else if(y == z && y < x){
        s[2] = string(y, '0');
        s[0] = s[1] = string(x, '0');
    }else if(max({x, y, z}) == x){
        s[2] = string(max(y, z), '1');
        rep(i, 0, y) s[0] += '1';
        rep(i, 0, x) s[0] += '0';
        rep(i, 0, x) s[1] += '0';
        rep(i, 0, z) s[1] += '1';
    }else if(max({x, y, z}) == y){
        s[1] = string(max(x, z), '1');
        rep(i, 0, x) s[0] += '1';
        rep(i, 0, y) s[0] += '0';
        rep(i, 0, y) s[2] += '0';
        rep(i, 0, z) s[2] += '1';
    }else{
        s[0] = string(max(x, y), '1');
        rep(i, 0, x) s[1] += '1';
        rep(i, 0, z) s[1] += '0';
        rep(i, 0, z) s[2] += '0';
        rep(i, 0, y) s[2] += '1';
    }
    rep(i, 0, 3){
        cout << s[i].size() << ' ';
        rep(j, 0, s[i].size()){
            cout << s[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}