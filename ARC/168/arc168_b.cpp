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
// https://atcoder.jp/contests/arc168/tasks/arc168_b

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    ll xa = 0;
    rep(i, 0, n){
        xa ^= a[i];
    }

    if(xa != 0){
        cout << -1 << endl;
    }else{
        map<ll, int> cnt;
        ll mx_a = 0;
        rep(i, 0, n){
            cnt[a[i]]++;
        }

        bool f = false;
        rep(i, 0, n){
            if(cnt[a[i]]%2){
                f = true;
                chmax(mx_a, a[i]);
            }
        }

        if(!f) cout << 0 << endl;
        else cout << mx_a-1 << endl;
    }
    
    return 0;
}