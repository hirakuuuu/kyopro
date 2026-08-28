#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
不要な部分を飛ばすのが定数倍高速化ではなく，計算量自体落ちる
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll x; cin >> x;
        vector<ll> a(n);
        rep(i, 0, n){
            cin >> a[i];
        }
        {
            vector<ll> _a = {a[0]};
            rep(i, 1, n){
                if(_a.back() <= a[i]) continue;
                _a.push_back(a[i]);
            }
            swap(a, _a);
            reverse(a.begin(), a.end());
            while(!a.empty() && a.back() > x){
                a.pop_back();
            }
            reverse(a.begin(), a.end());
        }

        if(a.empty()){
            cout << 0 << endl;
            continue;
        }

        n = (int)a.size();
        map<pair<int, ll>, ll> memo;
        auto f = [&](auto self, int pos, ll r) -> ll {
            // a[j] <= r となる最初の j を探す
            pos = lower_bound(a.begin()+pos, a.end(), r, greater<ll>())-a.begin();
            // 残りのすべての a[i] が r より大きい
            if(pos == n) return 0;
            if (memo.count({pos, r})) return memo[{pos, r}]; 

            ll q = r/a[pos];
            ll rem = r%a[pos];
            ll res = q;
            if(pos+1 < n) {
                res += self(self, pos+1, a[pos]-1)*q;
                if(rem != 0) res += self(self, pos+1, rem);
            }
            return memo[{pos, r}] = res;
        };

        cout << f(f, 0, x) << endl;



    }
    
    return 0;
}