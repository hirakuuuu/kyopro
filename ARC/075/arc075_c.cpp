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
// https://atcoder.jp/contests/arc075/tasks/arc075_c

class BIT {
public:
    ll n; // データの長さ
    vector<ll> a; // データの格納先

    BIT(ll n_): n(n_), a(n_+1, 0){} // コンストラクタ

    // a[i]をxに加算する
    void add(ll pos, ll x){
        pos++; // 1インデックスにしてる
        while(pos <= n){
            a[pos] += x;
            pos += pos&(-pos);
        }
    }

    // [0, i]を求める
    ll sum_sub(ll pos){
        pos++;
        ll res = 0;
        while(0 < pos){
            res += a[pos];
            pos -= pos&(-pos);
        }
        return res;
    }

    // [l, r]の和
    ll sum(ll l, ll r){
        return sum_sub(r)-sum_sub(l-1);
    }
};


int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n){
        cin >> a[i];
        a[i] -= k;
    }

    vector<ll> b(n+1);
    rrep(i, n-1, 0){
        b[i] = b[i+1]+a[i];
    }

    vector<ll> c = b;
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());

    map<ll, int> m;
    rep(i, 0, c.size()) m[c[i]] = i;

    ll ans = 0;
    BIT ft(n+1);
    rep(i, 0, n){
        ft.add(m[b[i]], 1);
        ans += ft.sum(m[b[i+1]], n);
    }
    cout << ans << endl;
    
    return 0;
}