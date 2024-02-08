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


int main(){
    int n, m, q; cin >> n >> m >> q;
    vector<tuple<int, int, int, int>> a(q);
    rep(i, 0, q){
        int b, c, d, e; cin >> b >> c >> d >> e;
        b--, c--;
        a[i] = {b, c, d, e};
    }
    
    vector<int> vec;
    auto dfs = [&](auto f, int pos, int tmp, vector<int> &vec) -> ll {
        if(pos == n){
            ll res = 0;
            rep(i, 0, q){
                auto [b, c, d, e] = a[i];
                if(vec[c]-vec[b] == d) res += e;
            }
            return res;
        }

        ll res = 0;
        rep(i, tmp, m){
            vec.push_back(i);
            chmax(res, f(f, pos+1, i, vec));
            vec.pop_back();
        }
        return res;
    };

    cout << dfs(dfs, 0, 0, vec) << endl;


    
    return 0;
}