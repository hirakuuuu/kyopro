#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc331/tasks/abc331_a

int main(){
    int M, D; cin >> M >> D;
    int y, m, d; cin >> y >> m >> d;
    if(m == M && d == D){
        cout << y+1 << ' ' << 1 << ' ' << 1 << endl;
    }else if(d == D){
        cout << y << ' ' << m+1 << ' ' << 1 << endl;
    }else{
        cout << y << ' ' << m << ' ' << d+1 << endl;
    }

    
    return 0;
}