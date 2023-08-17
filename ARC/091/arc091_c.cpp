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
// https://atcoder.jp/contests/arc091/tasks/arc091_c

int main(){
    ll n, a, b; cin >> n >> a >> b;
    if(a-1 > n-b || b*(a-1) < n-b){
        cout << -1 << endl;
        return 0;
    }

    vector<ll> cnt(a);
    cnt[0] = b;
    int a_ = n-b, pos = 0;
    while(a_--){
        cnt[pos%(a-1)+1]++;
        pos++;
    }

    int l = 0;
    rep(i, 0, a){
        int tmp = l+cnt[i];
        rep(j, 0, cnt[i]){
            cout << tmp << ' ';
            tmp--;
        }
        l += cnt[i];
    }
    cout << endl;
    
    return 0;
}