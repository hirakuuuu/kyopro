#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
constexpr ll MOD = 998244353;

/*
問題 https://atcoder.jp/contests/abc331/tasks/abc331_f
modintをBITに乗せたかっただけ、WA出したので、作っときます
*/

class modBIT {
public:
    ll n; // データの長さ
    ll mod; // mod
    vector<ll> a; // データの格納先

    modBIT(ll n_, ll m_): n(n_), mod(m_), a(n_+1, 0){};

    // a[i]をxに加算する
    void add(ll pos, ll x){
        // xが負の場合は非負にする
        if(x < 0){
            x %= mod;
            x += mod;
        }

        pos++; // 1インデックスにしてる
        while(pos <= n){
            a[pos] += x;
            a[pos] %= mod;
            pos += pos&(-pos);
        }
    }

    // [0, i]を求める
    ll sum_sub(ll pos){
        pos++;
        ll res = 0;
        while(0 < pos){
            res += a[pos];
            res %= mod;
            pos -= pos&(-pos);
        }
        return res;
    }

    // [l, r]の和
    ll sum(ll l, ll r){
        return (sum_sub(r)-sum_sub(l-1)+mod)%mod;
    }

};

ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

ll modinv(ll n, ll m=MOD){
    return power(n, m-2, m);
}

int main(){
    int n, q; cin >> n >> q;
    string s; cin >> s;

    vector<ll> mod = {998244353, 1000000007};
    int m = (int)mod.size();
    vector<vector<ll>> m10(m, vector<ll>(n, 1));
    rep(i, 0, m){
        rep(j, 1, n){
            m10[i][j] = (m10[i][j-1]*10)%mod[i];
        }
    }
    vector<modBIT> bit, rev;
    rep(i, 0, m){
        bit.push_back(modBIT(n, mod[i]));
        rev.push_back(modBIT(n, mod[i]));
    }

    rep(i, 0, m){
        rep(j, 0, n){
            bit[i].add(j, m10[i][j]*(s[j]-'a'+1));
            rev[i].add(j, m10[i][j]*(s[n-j-1]-'a'+1));
        }
    }


    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x; cin >> x; x--;
            char c; cin >> c;

            rep(i, 0, m){
                bit[i].add(x, -m10[i][x]*(s[x]-'a'+1));
                rev[i].add(n-x-i, -m10[i][n-x-1]*(s[x]-'a'+1));
            }
            s[x] = c;
            rep(i, 0, m){
                bit[i].add(x, m10[i][x]*(s[x]-'a'+1));
                rev[i].add(n-x-i, m10[i][n-x-1]*(s[x]-'a'+1));
            }

        }else if(t == 2){
            int l, r; cin >> l >> r;
            l--, r--;
            bool ok = true;
            rep(i, 0, m){
                ll hash = (bit[i].sum(l, r)*modinv(m10[i][l], mod[i]))%mod[i];
                ll hash_rev = (rev[i].sum(n-r-1, n-l-1)*modinv(m10[i][n-r-1], mod[i]))%mod[i];
                if(hash != hash_rev) ok = false;
            }

            if(ok) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}