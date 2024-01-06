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
// https://atcoder.jp/contests/abc126/tasks/abc126_f

int main(){
    int m, k; cin >> m >> k;
    if(m == 1){
        if(k == 0){
            cout << "0 0 1 1" << endl;
        }else{
            cout << -1 << endl;
        }
    }else{
        if(k < pow(2, m)){
            cout << k;
            rep(i, 0, pow(2, m)){
                if(i == k) continue;
                cout << ' ' << i;
            }
            cout << ' ' << k;
            rrep(i, pow(2, m)-1, 0){
                if(i == k) continue;
                cout << ' ' << i;
            }
            cout << endl;
        }else{
            cout << -1 << endl;
        }
    }
    
    return 0;
}