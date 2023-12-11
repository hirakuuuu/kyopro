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
// https://atcoder.jp/contests/abc332/tasks/abc332_c

int main(){
    int n, m; cin >> n >> m;
    string s; cin >> s;
    int ans = 0;
    vector<int> tmp(2);
    rep(i, 0, n){
        if(s[i] == '0'){
            chmax(ans, max(0, tmp[0]-m)+tmp[1]);
            tmp[0] = tmp[1] = 0;
        }else if(s[i] == '1'){
            tmp[0]++;
        }else if(s[i] == '2'){
            tmp[1]++;
        }
    }
    chmax(ans, max(0, tmp[0]-m)+tmp[1]);
    cout << ans << endl;
    
    return 0;
}