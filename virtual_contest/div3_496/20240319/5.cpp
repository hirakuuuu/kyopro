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
// div3_496

int main(){
    int n, m; cin >> n >> m;
    vector<int> p(n);
    int start = 0;
    rep(i, 0, n){
        cin >> p[i];
        if(p[i] == m) start = i;
        if(p[i] < m) p[i] = -1;
        else p[i] = 1;
    }
    vector<ll> acc(n+1);
    map<ll, ll> cnt;
    ll ans = 0;
    rep(i, 0, n) acc[i+1] = acc[i]+p[i];
    rep(i, 0, start+1) cnt[acc[i]]++;
    rep(i, start+1, n+1){
        ans += cnt[acc[i]-1]+cnt[acc[i]-2];
    }
    cout << ans << endl;
    
    return 0;
}