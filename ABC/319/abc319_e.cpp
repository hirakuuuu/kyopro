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
// https://atcoder.jp/contests/abc319/tasks/abc319_e


// 余りを全パターン→最小公倍数

int main(){
    ll n, x, y; cin >> n >> x >> y;
    vector<ll> p(n), t(n);
    rep(i, 1, n) cin >> p[i] >> t[i];

    int max_ = 1;
    rep(i, 2, 9) max_ *= i;
    map<vector<int>, ll> ans;
    rep(i, 0, 841){
        vector<int> jun(8);
        rep(j, 1, 9) jun[j-1] = i%j;
        ll tmp = x;
        rep(j, 1, n){
            tmp += (p[j]-(jun[p[j]-1]+tmp)%p[j])%p[j];
            tmp += t[j];
        }
        tmp += y;
        ans[jun] = tmp;
    }
    int q; cin >> q;
    while(q--){
        ll s; cin >> s;
        vector<int> b(8);
        rep(i, 1, 9){
            b[i-1] = s%i;
        }
        cout << s+ans[b] << '\n';
    }

    

    
    return 0;
}