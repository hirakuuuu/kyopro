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
// https://atcoder.jp/contests/abc326/tasks/abc326_a

int main(){
    int x, y; cin >> x >> y;
    if(x > y){
        if(x-y <= 3) cout << "Yes" << endl;
        else cout << "No" << endl;
    }else{
        if(y-x <= 2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}