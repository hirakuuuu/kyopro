#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc219/tasks/abc219_e

class UnionFind {
    vector<ll> parent, maxi, mini;
    inline ll root(ll n){
        return (parent[n] < 0? n:parent[n] = root(parent[n]));
    }
public:
    UnionFind(ll n_ = 1): parent(n_, -1), maxi(n_), mini(n_){
        iota(maxi.begin(), maxi.end(), 0);
        iota(mini.begin(), mini.end(), 0);
    }

    inline bool same(ll x, ll y){
        return root(x) == root(y);
    }

    inline void unite(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        if(rx == ry) return;
        if(parent[rx] > parent[ry]) swap(rx, ry);
        parent[rx] += parent[ry];
        parent[ry] = rx;
        maxi[x] = std::max(maxi[x],maxi[y]);
        mini[x] = std::min(mini[x],mini[y]);
    }

    inline ll min(ll x){
        return mini[root(x)];
    }

    inline ll max(int x){
        return mini[root(x)];
    }

    inline ll size(ll x){
        return (-parent[root(x)]);
    }

    inline ll operator[](ll x){
        return root(x);
    }

    inline void print(){
        rep(i, 0, (ll)parent.size()) cout << root(i) << " ";
        cout << endl;
    }

    void clear(){
        rep(i, 0, (ll)parent.size()){
            parent[i] = -1;
        }
        iota(maxi.begin(), maxi.end(), 0);
        iota(mini.begin(), mini.end(), 0);
    }
};

vector<vector<int>> a(5, vector<int>(5));

int main(){
    vector<int> exist(16);
    rep(i, 0, 4){
        rep(j, 0, 4){
            cin >> a[i][j];
            if(a[i][j] == 1) exist[i*4+j] = 1;
        }
    }

    ll ans = 0;
    rep(i, 0, 1<<16){
        bool f = true;
        vector<vector<int>> bit(6, vector<int>(6));
        rep(j, 1, 5){
            rep(k, 1, 5){
                int p = (j-1)*4+(k-1);
                if(i&(1<<p)) bit[j][k] = 1;
                else if(exist[p]) f = false;
            }
        }
        if(!f) continue;

        // 全部連結かどうかを調べる
        UnionFind uf(36);
        rep(j, 0, 6){
            rep(k, 0, 6){
                int p = j*6+k;
                if(k != 5 and bit[j][k] == bit[j][k+1]){
                    uf.unite(p, p+1);
                }
                if(j != 5 and bit[j][k] == bit[j+1][k]){
                    uf.unite(p, p+6);
                }
            }
        }

        int cnt = 0;
        rep(j, 0, 6){
            rep(k, 0, 6) cnt += bit[j][k];
        }
        rep(j, 0, 36){
            if(bit[j/6][j%6] and uf.size(uf[j]) != cnt) f = false;
            if(!bit[j/6][j%6] and uf.size(uf[j]) != 36-cnt) f = false;
        }
        if(!f) continue;
        // rep(j, 0, 4){
        //     rep(k, 0, 4){
        //         cout << bit[j*4+k] << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        ans++;
    }

    cout << ans << endl;
    
    return 0;
}