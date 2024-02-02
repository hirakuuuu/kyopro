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
// https://atcoder.jp/contests/arc077/tasks/arc077_c

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i, 0, n){
        cin >> a[i];
        a[i]--;
    }
    vector<vector<ll>> add(m), del(m);
    rep(i, 0, n){
        if(i < n-1) add[(a[i]+2)%m].emplace_back(-1);
        if(0 < i){
            del[a[i]].emplace_back((m+a[i]-a[i-1])%m);
        }
    }


    ll tmp = 0, acc = 0, cnt = 0;
    rep(i, 0, n-1){
        if(a[i] < a[i+1]){
            tmp += a[i+1]-a[i];
            // if(a[i+1]-a[i] > (a[i+1]-0)+1) acc += -a[i]-1;
        }else{
            tmp += (m+a[i+1]-a[i])%m;
            if((m+a[i+1]-a[i])%m > (a[i+1]-0)+1){
                acc += (a[i+1]+1)-(m+a[i+1]-a[i])%m;
                cnt++;
            }
        }
    }

    ll ans = tmp+acc;
    rep(x, 1, m+1){
        for(auto dl: del[x-1]){
            acc += dl-1;
            cnt--;
        }
        for(auto ad: add[x%m]){
            cnt++;
        }
        acc -= cnt;
        //cout << tmp+acc << ' ' << tmp << ' ' << acc << ' ' << cnt << endl;
        chmin(ans, tmp+acc);

    }
    cout << ans << endl;
    return 0;
}