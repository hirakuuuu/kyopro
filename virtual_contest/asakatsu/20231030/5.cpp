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
// 

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


int main(){
    int n; cin >> n;
    vector<pair<ll, ll>> ab(n);
    vector<ll> a(n), b(n);
    rep(i, 0, n){
        cin >> a[i];
        ab[i].first = a[i];
    }
    rep(i, 0, n){
        cin >> b[i];
        ab[i].second = b[i];
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());



    map<ll, ll> ind_b, ind_a;
    rep(i, 0, a.size()) ind_a[a[i]] = i;
    rep(i, 0, b.size()) ind_b[b[i]] = i;

    sort(ab.begin(), ab.end());
    vector<vector<ll>> g(n);
    rep(i, 0, n){
        auto [A, B] = ab[i];
        g[ind_a[A]].push_back(ind_b[B]);
    }

    BIT bit(n+1);
    ll ans = 0;
    rep(i, 0, a.size()){
        for(auto ib: g[i]){
            bit.add(ib, 1);
        }
        for(auto ib: g[i]){
            ans += bit.sum(ib, n);
        }
    }
    cout << ans << endl;



    return 0;
}