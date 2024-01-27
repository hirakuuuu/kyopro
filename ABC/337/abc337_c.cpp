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
// https://atcoder.jp/contests/abc337/tasks/abc337_c

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n){
        cin >> a[i];
    }
    vector<int> b(n+1, -1);
    rep(i, 0, n){
        if(a[i] == -1) b[0] = i+1;
        else b[a[i]] = i+1;
    }
    int s = 0;
    while(b[s] != -1){
        cout << b[s] << ' ';
        s = b[s];
    }
    cout << endl;
    
    
    return 0;
}