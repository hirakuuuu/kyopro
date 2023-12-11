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
// https://atcoder.jp/contests/abc332/tasks/abc332_b

int main(){
    int k, g, m; cin >> k >> g >> m;
    int cg = 0, cm = 0;
    rep(i, 0, k){
        if(cg == g){
            cg = 0;
        }else if(cm == 0){
            cm = m;
        }else{
            if(cm >= g-cg){
                cm -= g-cg;
                cg = g;
            }else{
                cg += cm;
                cm = 0;
            }
        }
        //cout << cg << ' ' << cm << endl;
    }
    
    cout << cg << ' ' << cm << endl;
    return 0;
}