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
    vector<int> w(n), x(n);
    rep(i, 0, n) cin >> w[i] >> x[i];
    int ans = 0;
    rep(i, 0, 24){
        int tmp = 0;
        rep(j, 0, n){
            if((x[j]+i)%24 < (x[j]+i+1)%24 && 9 <= (x[j]+i)%24 && (x[j]+i+1)%24 <= 18) tmp += w[j];
        }
        chmax(ans, tmp);
    }
    cout << ans << endl;
    
    return 0;
}