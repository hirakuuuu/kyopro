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
// https://atcoder.jp/contests/cf16-final/tasks/codefestival_2016_final_d

int main(){
    int n, m; cin >> n >> m;
    vector<int> x(n);
    rep(i, 0, n) cin >> x[i];
    vector<int> cnt(100005);
    rep(i, 0, n) cnt[x[i]]++;

    vector<int> odd(m), even(m);
    rep(i, 1, 100005){
        odd[i%m] += cnt[i]&1;
        even[i%m] += cnt[i]/2;
    }

    int ans = 0;
    ans += odd[0]/2;
    if(m%2 == 0) ans += odd[m/2]/2;
    rep(i, 1, (m+1)/2){
        int tmp = min(odd[i], odd[m-i]);
        ans += tmp;
        odd[i] -= tmp;
        odd[m-i] -= tmp;
    }


    rep(i, 1, m){
        if(m%2 == 0 and i == m/2) continue;
        int tmp = min(even[m-i]*2, odd[i]);
        ans += tmp;
        even[m-i] -= (tmp+1)/2;
        odd[i] -= tmp;
    }
    rep(i, 0, m){
        ans += even[i];
    }
    cout << ans << endl;

    return 0;
}