#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc221/tasks/abc221_e

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

    // a[0]+a[1]+...+a[i] >= x となる最小のiを求める（任意のkでa[k]>=0が必要）
    ll lower_bound(ll x){
        if(x <= 0){
            return 0;
        }else{
            ll i = 0, len = 1;

            //最大としてありうる区間の長さを取得する
            //n以下の最小の二乗のべき(BITで管理する数列の区間で最大のもの)を求める
            while(len < n) len *= 2;

            //区間の長さは調べるごとに半分になる
            while(0 < len){
                //その区間を採用する場合
                if(i+len < n and a[i+len] < x){
                    x -= a[i+len];
                    i += len;
                }
            }
            return i;
        }
    }

};

// 繰り返し二乗法
ll power(ll a, ll b, ll m=998244353){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    priority_queue<pll> que;
    rep(i, 0, n){
        que.push({a[i], i});
    }

    vector<ll> cnt(n+1);
    BIT bit(n);
    rep(i, 0, n) bit.add(i, power(power(2, i), mod_num-2));
    // rep(i, 0, n){
    //     cout << bit.sum(i, i) << ' ';
    // }
    // cout << endl;

    ll ans = 0;

    while(!que.empty()){
        pll q = que.top(); que.pop();
        ll tmp = q.first, pos = q.second;
        bit.add(pos, -power(power(2, pos), mod_num-2));
        ll sum = bit.sum(0, pos)%mod_num;
        ans += power(2, pos-1)*sum%mod_num;
        ans %= mod_num;
        // cout << sum << endl;
        // rep(i, 0, n+1){
        //     cout << bit.sum(i, i) << ' ';
        // }
        // cout << endl;
    }

    cout << ans << endl;
    
   

    
    return 0;
}