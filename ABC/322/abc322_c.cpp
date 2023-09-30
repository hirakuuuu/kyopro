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
// https://atcoder.jp/contests/abc322/tasks/abc322_c

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(m);
    rep(i, 0, m) cin >> a[i];
    int ind = 0, cnt = a[0]-1;
    rep(i, 1, n){
        cout << cnt << endl;
        if(i == a[ind]){
            cnt = a[ind+1]-i-1;
            ind++;
        }else cnt--;
    }
    cout << 0 << endl;
    
    return 0;
}