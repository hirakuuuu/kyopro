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
// https://atcoder.jp/contests/abc319/tasks/abc319_b

int main(){
    int n; cin >> n;
    string s; 
    rep(i, 0, n+1){
        bool f = false;
        rep(j, 1, 10){
            if(n%j == 0 && i%(n/j) == 0){
                s += '0'+j;
                f = true;
                break;
            }
        }

        if(!f) s += '-'; 
    }

    cout << s << endl;
    
    return 0;
}