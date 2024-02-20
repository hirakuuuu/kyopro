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
// https://atcoder.jp/contests/arc172/taks/arc172_a

int main(){
    ll h, w, n; cin >> h >> w >> n;
    if(h > w) swap(h, w);
    vector<ll> a(26), t(26);
    ll mx = 0;
    t[0] = 1;
    rep(i, 1, 26){
        t[i] = 2*t[i-1];
    }
    rep(i, 0, n){
        int b; cin >> b;
        chmax(mx, b);
        a[b]++;
    }
    vector<ll> abl(26);
    auto dfs = [&](auto sfs, ll ch, ll cw, int start) -> void{
        rrep(i, start, 0){
            if(ch/t[i] && cw/t[i]){
                abl[i] += (ch/t[i])*(cw/t[i]);
                sfs(sfs, ch%t[i], t[i]*(cw/t[i]), i-1);
                sfs(sfs, t[i]*(ch/t[i]), cw%t[i], i-1);
                sfs(sfs, ch%t[i], cw%t[i], i-1);
                break;
            }
        }
    };
    dfs(dfs, h, w, 25);
    rrep(i, 25, 1){
        ll rest = abl[i]-a[i];
        if(rest < 0){
            cout << "No" << endl;
            return 0;
        }
        abl[i-1] += 4*rest;
    }
    if(a[0] <= abl[0]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}