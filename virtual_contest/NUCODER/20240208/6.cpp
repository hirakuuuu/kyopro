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
// https://atcoder.jp/contests/arc169/tasks/arc169_c

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

// 繰り返し二乗法
ll power(ll a, ll b, ll m=998244353){
    ll res = 1;
    while(b){
        if(b&1) res = res*a%m;
        a = a*a%m;
        b >>= 1;
    }
    return res;
}

int main(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    string t = s;
    reverse(t.begin(), t.end());

    vector<ll> mod = {998244353, 1000000007};
    int base = 2;
    vector<BIT> b(base, BIT(n));
    vector<BIT> rev(2, BIT(n));

    vector<vector<ll>> ten(base, vector<ll>(n, 1));
    rep(i, 0, n){
        if(i){
            rep(j, 0, base) ten[j][i] = (ten[j][i-1]*10)%mod[j];
        }
        rep(j, 0, base){
            b[j].add(i, ((s[i]-'a')*ten[j][i])%mod[j]);
            rev[j].add(i, ((t[i]-'a')*ten[j][i])%mod[j]);
        }
    }

    while(q--){
        int o; cin >> o;
        if(o == 1){
            int x; cin >> x;
            char c; cin >> c;
            x--;
            rep(i, 0, base){
                b[i].add(x, (mod[i]-((s[x]-'a')*ten[i][x])%mod[i])%mod[i]);
                b[i].add(x, ((c-'a')*ten[i][x])%mod[i]);
                rev[i].add(n-x-1, (mod[i]-((t[n-x-1]-'a')*ten[i][n-x-1])%mod[i])%mod[i]);
                rev[i].add(n-x-1, ((c-'a')*ten[i][n-x-1])%mod[i]);
            }
            s[x] = c;
            t[n-x-1] = c;
        }else if(o == 2){
            int l, r; cin >> l >> r;
            l--, r--;
            bool ok = true;
            rep(i, 0, base){
                ll h1 = ((b[i].sum(l, r)%mod[i])*power(ten[i][l], mod[i]-2, mod[i]))%mod[i];
                ll h2 = ((rev[i].sum(n-r-1, n-l-1)%mod[i])*power(ten[i][n-r-1], mod[i]-2, mod[i]))%mod[i];
                if(h1 != h2) ok = false;
            }
            if(ok) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }



    return 0;
}