#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc276/tasks/abc276_f

vector<ll> inv(200005);

void init_inv(ll n){
    inv[1] = 1;
    rep(i, 2, n+1){
        inv[i] = mod - inv[mod%i]*(mod/i)%mod;
    }
}


struct SegmentTree {
    private:
        ll n;
        vector<ll> node;
    
    public:
        SegmentTree(vector<ll> a){
            // 配列のサイズを取得
            ll sz = a.size();
            // nはszを超える最小の2のべき乗
            n = 1;
            while(n < sz) n *= 2;
            // ノードの個数は2n-1
            node.resize(2*n-1, 0);

            // 再下段にaの値を格納
            rep(i, 0, sz) node[i+n-1] = a[i];
            // 親を更新
            for(ll j = n-2; j >= 0; j--) node[j] = node[2*j+1]+node[2*j+2];
        }

        // 更新処理
        void update(ll x, ll val){
            // 再下段の指定した位置の値を更新
            x += n-1;
            node[x] += val;
            // 親の値を更新しながら上る
            while(x > 0){
                x = (x-1)/2;
                node[x] += val;
            }
        }

        // 取得処理
        ll get_num(ll a, ll b, ll k=0, ll l=0, ll r=-1){
            if(r < 0) r = n;
            if(r <= a or b <= l) return 0;
            if(a <= l and r <= b) return node[k];

            ll v1 = get_num(a, b, 2*k+1, l, (l+r)/2);
            ll v2 = get_num(a, b, 2*k+2, (l+r)/2, r);
            return v1+v2;
        }
};


int main(){
    init_inv(200001);
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<ll> cnt(200005);
    SegmentTree st(cnt);
    SegmentTree st_cnt(cnt);
    vector<ll> b(n), c(n);

    rep(i, 0, n){
        b[i] = st.get_num(a[i]+1, 200001);
        b[i] %= mod;
        st.update(a[i], a[i]);
        c[i] = st_cnt.get_num(0, a[i]+1);
        st_cnt.update(a[i], 1);
    }

    ll s = a[0];
    vector<ll> e(n+1);
    e[1] = a[0];
    rep(i, 2, n+1){
        ll q = inv[i]*inv[i]%mod;
        s += c[i-1]*a[i-1]*2+a[i-1]+b[i-1]*2;
        s %= mod;
        e[i] = s*q%mod;
    }

    rep(i, 1, n+1){
        cout << e[i] << endl;
    }




    
    return 0;
}