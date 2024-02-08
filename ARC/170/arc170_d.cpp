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
// https://atcoder.jp/contests/arc170/tasks/arc170_d

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n), b(n);
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool f = false;
        rep(i, 0, n-1){
            if(abs(a[i]-a[i+1]) < b[0] && b[n-1] < a[i]+a[i+1]) f = true;
        }
        if(f) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
    
    return 0;
}