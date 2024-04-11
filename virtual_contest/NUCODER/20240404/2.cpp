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
// 

int main(){
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i, 1, n+1) cin >> a[i];
    vector<int> b(n+1);
    int m = 0;
    rrep(i, n, 1){
        int sum = 0;
        for(int j = 2*i; j <= n; j += i){
            sum += b[j];
        }
        if(sum%2 != a[i]){
            b[i] = 1;
        }
        m += b[i];
    }
    cout << m << endl;
    if(m){
        rep(i, 1, n+1){
            if(b[i]) cout << i << ' ';
        }
        cout << endl;
    }

    
    return 0;
}