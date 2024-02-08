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
// https://atcoder.jp/contests/keyence2021/tasks/keyence2021_d

int main(){
    int n; cin >> n;
    cout << (1<<n)-1 << endl;
    vector<string> s((1<<n)-1);
    rep(i, 1, (1<<n)){
        rep(j, 1, (1<<n)+1){
            if(popcount((unsigned)(i&j))%2) s[i-1] += 'A';
            else s[i-1] += 'B';
        }        
    }
    rep(i, 0, (1<<n)-1){
        cout << s[i] << endl;
    }
    
    
    return 0;
}